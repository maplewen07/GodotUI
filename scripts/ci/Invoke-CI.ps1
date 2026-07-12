[CmdletBinding()]
param(
    [string]$GodotBin = $env:GODOT_BIN,
    [ValidateSet('Debug', 'Release')]
    [string]$Configuration = 'Release',
    [switch]$SkipGodot,
    [switch]$SkipInstallTest,
    [switch]$SkipGitDiff
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))

function Invoke-DotNet {
    param([Parameter(ValueFromRemainingArguments)][string[]]$Arguments)

    & dotnet @Arguments
    if ($LASTEXITCODE -ne 0) {
        throw "dotnet $($Arguments -join ' ') failed with exit code $LASTEXITCODE."
    }
}

function Invoke-ProcessWithTimeout {
    param(
        [Parameter(Mandatory)]
        [string]$FilePath,
        [Parameter(Mandatory)]
        [string[]]$ArgumentList,
        [int]$TimeoutSeconds = 180
    )

    $startInfo = [System.Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $FilePath
    $startInfo.UseShellExecute = $false
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true
    foreach ($argument in $ArgumentList) {
        [void]$startInfo.ArgumentList.Add($argument)
    }

    $process = [System.Diagnostics.Process]::new()
    $process.StartInfo = $startInfo
    try {
        [void]$process.Start()
        $standardOutput = $process.StandardOutput.ReadToEndAsync()
        $standardError = $process.StandardError.ReadToEndAsync()
        $timedOut = -not $process.WaitForExit($TimeoutSeconds * 1000)
        if ($timedOut) {
            $process.Kill($true)
            $process.WaitForExit()
        }
        $process.WaitForExit()
        $output = $standardOutput.GetAwaiter().GetResult()
        $errorOutput = $standardError.GetAwaiter().GetResult()
        if (-not [string]::IsNullOrWhiteSpace($output)) {
            Write-Host $output.TrimEnd()
        }
        if (-not [string]::IsNullOrWhiteSpace($errorOutput)) {
            Write-Host $errorOutput.TrimEnd()
        }
        if ($timedOut) {
            throw "$FilePath exceeded the $TimeoutSeconds second timeout."
        }
        return $process.ExitCode
    }
    finally {
        $process.Dispose()
    }
}

function Resolve-Godot {
    if (-not [string]::IsNullOrWhiteSpace($GodotBin)) {
        if (Test-Path -LiteralPath $GodotBin -PathType Leaf) {
            return (Resolve-Path -LiteralPath $GodotBin).Path
        }
        $command = Get-Command $GodotBin -ErrorAction SilentlyContinue
        if ($null -ne $command) {
            return $command.Source
        }
        throw "Godot executable was not found: $GodotBin"
    }

    foreach ($name in @('godot', 'godot4')) {
        $command = Get-Command $name -ErrorAction SilentlyContinue
        if ($null -ne $command) {
            return $command.Source
        }
    }

    throw 'Godot was not found. Set GODOT_BIN or pass -GodotBin.'
}

Push-Location $repoRoot
try {
    Invoke-DotNet --version
    Invoke-DotNet restore 'GodotUI.csproj'
    Invoke-DotNet build 'GodotUI.csproj' --configuration $Configuration --no-restore

    $cliProject = Join-Path $repoRoot 'tools/ManifestUi.Cli/ManifestUi.Cli.csproj'
    if (Test-Path -LiteralPath $cliProject -PathType Leaf) {
        Invoke-DotNet restore $cliProject
        Invoke-DotNet build $cliProject --configuration $Configuration --no-restore
    }

    $testProjects = @(Get-ChildItem -LiteralPath (Join-Path $repoRoot 'tests') -Filter '*.csproj' -File -Recurse |
        Where-Object { $_.FullName -notmatch '[\\/](?:bin|obj)[\\/]' } |
        Sort-Object FullName)
    foreach ($testProject in $testProjects) {
        Invoke-DotNet test $testProject.FullName --configuration $Configuration
    }

    & (Join-Path $repoRoot 'scripts/release/Test-ReleaseMetadata.ps1')

    $resolvedGodot = $null
    $releaseChannel = (Get-Content -LiteralPath (Join-Path $repoRoot 'manifest-ui-version.json') -Raw | ConvertFrom-Json).releaseChannel
    if (-not $SkipGodot) {
        $resolvedGodot = Resolve-Godot
        Invoke-DotNet build 'GodotUI.csproj' --configuration Debug --no-restore
        & $resolvedGodot --version
        if ($LASTEXITCODE -ne 0) {
            throw 'Godot version check failed.'
        }

        $editorExitCode = Invoke-ProcessWithTimeout -FilePath $resolvedGodot -ArgumentList @(
            '--headless', '--path', $repoRoot, '--import'
        )
        if ($editorExitCode -ne 0) {
            throw 'Godot solution build/import failed.'
        }

        if (Test-Path -LiteralPath (Join-Path $repoRoot 'tests/SelfCheck.tscn')) {
            $runtimeTestArgs = @{
                GodotBin = $resolvedGodot
                Configuration = $Configuration
            }
            if ($releaseChannel -eq 'alpha') {
                $runtimeTestArgs.AllowKnownGodotThreadedLoaderLeak = $true
            }
            & (Join-Path $repoRoot 'tests/Run-GodotSelfCheck.ps1') @runtimeTestArgs
            if ($LASTEXITCODE -ne 0) {
                throw 'Godot headless self-check failed.'
            }
        }

        $manifestLiquidGlassVisual = Join-Path $repoRoot 'tests/Run-ManifestLiquidGlassVisual.ps1'
        if (Test-Path -LiteralPath $manifestLiquidGlassVisual -PathType Leaf) {
            & $manifestLiquidGlassVisual -GodotBin $resolvedGodot -SkipBuild
            if ($LASTEXITCODE -ne 0) {
                throw 'Manifest Liquid Glass visual check failed.'
            }
        }
    }

    if (-not $SkipInstallTest) {
        $buildArgs = @{ SkipCliPublish = $true }
        if (Test-Path -LiteralPath $cliProject -PathType Leaf) {
            $buildArgs = @{}
        }
        $untrackedReleaseInputs = @(& git -C $repoRoot ls-files --others --exclude-standard -- 'addons/manifest_ui' 'examples')
        if ($LASTEXITCODE -ne 0) {
            throw 'Could not inspect untracked release inputs.'
        }
        if ($untrackedReleaseInputs.Count -gt 0) {
            $buildArgs.IncludeUntracked = $true
        }
        & (Join-Path $repoRoot 'scripts/release/Build-Release.ps1') @buildArgs

        $version = (Get-Content -LiteralPath (Join-Path $repoRoot 'manifest-ui-version.json') -Raw | ConvertFrom-Json).version
        $addonArchive = Join-Path $repoRoot "artifacts/release/manifest-ui-$version.zip"
        $installArgs = @{ PackagePath = $addonArchive }
        if ($SkipGodot) {
            $installArgs.SkipGodot = $true
        }
        else {
            $installArgs.GodotBin = $resolvedGodot
            if ($releaseChannel -eq 'alpha') {
                $installArgs.AllowKnownGodotThreadedLoaderLeak = $true
            }
        }
        & (Join-Path $repoRoot 'scripts/release/Test-AddonPackage.ps1') @installArgs

        $cliArchive = Join-Path $repoRoot "artifacts/release/manifest-ui-cli-$version.zip"
        if (Test-Path -LiteralPath $cliArchive -PathType Leaf) {
            & (Join-Path $repoRoot 'scripts/release/Test-CliPackage.ps1') -PackagePath $cliArchive -ExpectedVersion $version
        }

        $exampleArchive = Join-Path $repoRoot "artifacts/release/manifest-ui-example-$version.zip"
        if (-not $SkipGodot -and (Test-Path -LiteralPath $exampleArchive -PathType Leaf)) {
            $exampleArgs = @{
                PackagePath = $exampleArchive
                AddonPackagePath = $addonArchive
                GodotBin = $resolvedGodot
            }
            if ($releaseChannel -eq 'alpha') {
                $exampleArgs.AllowKnownGodotThreadedLoaderLeak = $true
            }
            & (Join-Path $repoRoot 'scripts/release/Test-ExamplePackage.ps1') @exampleArgs
        }
    }

    if (-not $SkipGitDiff) {
        & git diff --exit-code
        if ($LASTEXITCODE -ne 0) {
            throw 'Verification changed tracked files.'
        }
    }

    Write-Host 'GodotUI CI verification passed.'
}
finally {
    Pop-Location
}
