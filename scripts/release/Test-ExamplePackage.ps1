[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [string]$PackagePath,
    [Parameter(Mandatory)]
    [string]$AddonPackagePath,
    [string]$GodotBin = $env:GODOT_BIN,
    [switch]$AllowKnownGodotThreadedLoaderLeak
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

function Invoke-ProcessWithTimeout {
    param([string]$FilePath, [string[]]$ArgumentList, [int]$TimeoutSeconds = 180)

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
        $stdout = $process.StandardOutput.ReadToEndAsync()
        $stderr = $process.StandardError.ReadToEndAsync()
        $timedOut = -not $process.WaitForExit($TimeoutSeconds * 1000)
        if ($timedOut) {
            $process.Kill($true)
        }
        $process.WaitForExit()
        $output = [string]::Join([Environment]::NewLine, @($stdout.GetAwaiter().GetResult(), $stderr.GetAwaiter().GetResult()))
        if (-not [string]::IsNullOrWhiteSpace($output)) {
            Write-Host $output.TrimEnd()
        }
        if ($timedOut) {
            throw "$FilePath exceeded the $TimeoutSeconds second timeout."
        }
        return [PSCustomObject]@{ ExitCode = $process.ExitCode; Output = $output }
    }
    finally {
        $process.Dispose()
    }
}

function Assert-NoGodotErrors {
    param([object]$Result, [string]$Context)
    if ($Result.Output -match '(?im)^\s*(?:(?:SCRIPT|SHADER) )?ERROR:') {
        throw "$Context emitted a Godot error."
    }
    if ($Result.ExitCode -ne 0) {
        throw "$Context failed with exit code $($Result.ExitCode)."
    }
}

function Assert-KnownLeakOnly {
    param([object]$Result, [string]$Context)
    $lines = @($Result.Output -split '\r?\n')
    $instances = @($lines | Where-Object { $_ -match 'Leaked instance:' })
    $warnings = @($lines | Where-Object { $_ -match 'ObjectDB instance(?:s)? (?:was|were) leaked' })
    if ($instances.Count -eq 0 -and $warnings.Count -eq 0) {
        return
    }
    $known = $instances.Count -ge 1 -and $instances.Count -le 4 -and
        @($instances | Where-Object { $_ -notmatch 'Leaked instance: RefCounted:.*Reference count: 0' }).Count -eq 0 -and
        $warnings.Count -eq 1
    if ($AllowKnownGodotThreadedLoaderLeak -and $known) {
        Write-Warning "$Context reported the known Godot 4.7 threaded ResourceLoader LoadToken leak."
        return
    }
    throw "$Context leaked ObjectDB instances."
}

if ([string]::IsNullOrWhiteSpace($GodotBin)) {
    throw 'Pass -GodotBin or set GODOT_BIN.'
}
if (Test-Path -LiteralPath $GodotBin -PathType Leaf) {
    $GodotBin = (Resolve-Path -LiteralPath $GodotBin).Path
}
else {
    $command = Get-Command $GodotBin -ErrorAction SilentlyContinue
    if ($null -eq $command) {
        throw "Godot executable was not found: $GodotBin"
    }
    $GodotBin = $command.Source
}

$exampleArchive = (Resolve-Path -LiteralPath $PackagePath).Path
$addonArchive = (Resolve-Path -LiteralPath $AddonPackagePath).Path
$tempBase = [System.IO.Path]::GetFullPath([System.IO.Path]::GetTempPath())
$tempRoot = Join-Path $tempBase ('manifest-ui-examples-test-' + [Guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $tempRoot -Force | Out-Null

try {
    Add-Type -AssemblyName System.IO.Compression
    foreach ($archivePath in @($exampleArchive, $addonArchive)) {
        $archive = [System.IO.Compression.ZipFile]::OpenRead($archivePath)
        try {
            foreach ($entry in $archive.Entries) {
                if ($entry.FullName.Contains('\') -or $entry.FullName.Contains('../') -or [System.IO.Path]::IsPathRooted($entry.FullName)) {
                    throw "Invalid release archive entry: $($entry.FullName)"
                }
            }
        }
        finally {
            $archive.Dispose()
        }
    }

    $exampleStage = Join-Path $tempRoot 'examples-stage'
    $addonStage = Join-Path $tempRoot 'addon-stage'
    [System.IO.Compression.ZipFile]::ExtractToDirectory($exampleArchive, $exampleStage)
    [System.IO.Compression.ZipFile]::ExtractToDirectory($addonArchive, $addonStage)
    $addonSource = Join-Path $addonStage 'addons/manifest_ui'
    if (-not (Test-Path -LiteralPath (Join-Path $addonSource 'plugin.cfg') -PathType Leaf)) {
        throw 'Addon archive is missing addons/manifest_ui/plugin.cfg.'
    }

    foreach ($exampleName in @('Basic', 'Inventory')) {
        $exampleRoot = Join-Path $exampleStage "examples/$exampleName"
        $projectFile = Join-Path $exampleRoot 'project.godot'
        if (-not (Test-Path -LiteralPath $projectFile -PathType Leaf)) {
            throw "Example archive is missing examples/$exampleName/project.godot."
        }
        $addonDestinationParent = Join-Path $exampleRoot 'addons'
        New-Item -ItemType Directory -Path $addonDestinationParent -Force | Out-Null
        Copy-Item -LiteralPath $addonSource -Destination (Join-Path $addonDestinationParent 'manifest_ui') -Recurse

        $project = Get-ChildItem -LiteralPath $exampleRoot -Filter '*.csproj' -File | Select-Object -First 1
        if ($null -eq $project) {
            throw "$exampleName example has no C# project."
        }
        foreach ($configuration in @('Release', 'Debug')) {
            & dotnet build $project.FullName --configuration $configuration
            if ($LASTEXITCODE -ne 0) {
                throw "$exampleName example failed to build in $configuration."
            }
        }

        $importResult = Invoke-ProcessWithTimeout -FilePath $GodotBin -ArgumentList @('--headless', '--path', $exampleRoot, '--import')
        Assert-NoGodotErrors -Result $importResult -Context "$exampleName example import"

        $projectText = Get-Content -LiteralPath $projectFile -Raw
        if ($projectText -match '(?m)^enabled=.*manifest_ui') {
            throw "$exampleName example must ship with Manifest UI disabled for its first C# import."
        }
        $enabledProject = $projectText.TrimEnd() + @'


[editor_plugins]

enabled=PackedStringArray("res://addons/manifest_ui/plugin.cfg")
'@
        Set-Content -LiteralPath $projectFile -Value $enabledProject -Encoding utf8 -NoNewline
        $activationResult = Invoke-ProcessWithTimeout -FilePath $GodotBin -ArgumentList @('--headless', '--path', $exampleRoot, '--import')
        Assert-NoGodotErrors -Result $activationResult -Context "$exampleName example plugin activation"

        $previousSmoke = $env:MANIFEST_UI_EXAMPLE_SMOKE
        try {
            $env:MANIFEST_UI_EXAMPLE_SMOKE = '1'
            $runtimeResult = Invoke-ProcessWithTimeout -FilePath $GodotBin -ArgumentList @(
                '--headless', '--verbose', '--path', $exampleRoot, '--scene', 'res://Main.tscn', '--quit-after', '600'
            ) -TimeoutSeconds 120
        }
        finally {
            $env:MANIFEST_UI_EXAMPLE_SMOKE = $previousSmoke
        }
        Assert-NoGodotErrors -Result $runtimeResult -Context "$exampleName example runtime"
        Assert-KnownLeakOnly -Result $runtimeResult -Context "$exampleName example runtime"
        if ($runtimeResult.Output -notmatch "Manifest UI $([regex]::Escape($exampleName)) example smoke OK\.") {
            throw "$exampleName example did not reach its smoke-test completion marker."
        }
    }

    Write-Host "Example package OK: $exampleArchive"
}
finally {
    $resolvedTemp = [System.IO.Path]::GetFullPath($tempRoot)
    if ($resolvedTemp.StartsWith($tempBase, [StringComparison]::OrdinalIgnoreCase) -and (Test-Path -LiteralPath $resolvedTemp)) {
        Remove-Item -LiteralPath $resolvedTemp -Recurse -Force
    }
}
