[CmdletBinding()]
param(
    [string]$OutputDirectory = 'artifacts/release',
    [ValidateSet('Debug', 'Release')]
    [string]$Configuration = 'Release',
    [switch]$SkipCliPublish,
    [switch]$RequireExamples,
    [switch]$IncludeUntracked
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
$metadata = Get-Content -LiteralPath (Join-Path $repoRoot 'manifest-ui-version.json') -Raw | ConvertFrom-Json
$version = [string]$metadata.version

if ([System.IO.Path]::IsPathRooted($OutputDirectory)) {
    $outputPath = [System.IO.Path]::GetFullPath($OutputDirectory)
}
else {
    $outputPath = [System.IO.Path]::GetFullPath((Join-Path $repoRoot $OutputDirectory))
}

$repoPrefix = $repoRoot.TrimEnd([System.IO.Path]::DirectorySeparatorChar) + [System.IO.Path]::DirectorySeparatorChar
if (-not $outputPath.StartsWith($repoPrefix, [System.StringComparison]::OrdinalIgnoreCase)) {
    throw "Release output must stay inside the repository: $outputPath"
}

if (Test-Path -LiteralPath $outputPath) {
    Remove-Item -LiteralPath $outputPath -Recurse -Force
}
New-Item -ItemType Directory -Path $outputPath -Force | Out-Null
$stagingPath = Join-Path $outputPath '.staging'
New-Item -ItemType Directory -Path $stagingPath -Force | Out-Null

function Get-RepositoryFiles {
    param([string]$Subtree)

    $relativePaths = @(& git -C $repoRoot ls-files --cached -- $Subtree)
    if ($LASTEXITCODE -ne 0) {
        throw "git ls-files failed for $Subtree."
    }
    if ($IncludeUntracked) {
        $relativePaths += @(& git -C $repoRoot ls-files --others --exclude-standard -- $Subtree)
        if ($LASTEXITCODE -ne 0) {
            throw "git ls-files failed while collecting untracked development files for $Subtree."
        }
    }

    $result = foreach ($relativePath in ($relativePaths | Sort-Object -Unique)) {
        $sourcePath = [System.IO.Path]::GetFullPath((Join-Path $repoRoot $relativePath))
        if (-not $sourcePath.StartsWith($repoPrefix, [System.StringComparison]::OrdinalIgnoreCase)) {
            throw "Publishable file escaped the repository: $relativePath"
        }
        if (Test-Path -LiteralPath $sourcePath -PathType Leaf) {
            [PSCustomObject]@{
                Source = $sourcePath
                Entry = $relativePath.Replace('\', '/')
            }
        }
    }

    return @($result)
}

function New-DeterministicZip {
    param(
        [Parameter(Mandatory)]
        [object[]]$Files,
        [Parameter(Mandatory)]
        [string]$Destination
    )

    if ($Files.Count -eq 0) {
        throw "Cannot create an empty archive: $Destination"
    }

    Add-Type -AssemblyName System.IO.Compression
    $stream = [System.IO.File]::Open($Destination, [System.IO.FileMode]::CreateNew)
    try {
        $archive = [System.IO.Compression.ZipArchive]::new(
            $stream,
            [System.IO.Compression.ZipArchiveMode]::Create,
            $false
        )
        try {
            foreach ($file in ($Files | Sort-Object Entry)) {
                $entry = $archive.CreateEntry($file.Entry, [System.IO.Compression.CompressionLevel]::Optimal)
                $entry.LastWriteTime = [System.DateTimeOffset]::new(2000, 1, 1, 0, 0, 0, [System.TimeSpan]::Zero)
                $input = [System.IO.File]::OpenRead($file.Source)
                try {
                    $output = $entry.Open()
                    try {
                        $input.CopyTo($output)
                    }
                    finally {
                        $output.Dispose()
                    }
                }
                finally {
                    $input.Dispose()
                }
            }
        }
        finally {
            $archive.Dispose()
        }
    }
    finally {
        $stream.Dispose()
    }
}

& (Join-Path $PSScriptRoot 'Test-ReleaseMetadata.ps1')

$addonFiles = @(Get-RepositoryFiles 'addons/manifest_ui')
$addonArchive = Join-Path $outputPath "manifest-ui-$version.zip"
New-DeterministicZip -Files $addonFiles -Destination $addonArchive

$addonLength = (Get-Item -LiteralPath $addonArchive).Length
if ($addonLength -ge 2MB) {
    throw "Addon archive is $addonLength bytes; the release limit is below 2 MiB."
}

$artifacts = [System.Collections.Generic.List[string]]::new()
$artifacts.Add($addonArchive)

if (-not $SkipCliPublish) {
    $cliProject = Join-Path $repoRoot 'tools/ManifestUi.Cli/ManifestUi.Cli.csproj'
    if (-not (Test-Path -LiteralPath $cliProject -PathType Leaf)) {
        throw 'CLI project is missing. Use -SkipCliPublish only for local addon-only validation.'
    }

    $cliStage = Join-Path $stagingPath 'cli'
    New-Item -ItemType Directory -Path $cliStage -Force | Out-Null
    & dotnet publish $cliProject --configuration $Configuration --framework net8.0 --no-self-contained -p:UseAppHost=false -p:Version=$version --output $cliStage
    if ($LASTEXITCODE -ne 0) {
        throw 'CLI publish failed.'
    }

    $runtimeConfig = Get-ChildItem -LiteralPath $cliStage -Filter '*.runtimeconfig.json' | Select-Object -First 1
    if ($null -eq $runtimeConfig) {
        throw 'Published CLI has no runtimeconfig.json.'
    }
    $assemblyBaseName = $runtimeConfig.Name.Substring(0, $runtimeConfig.Name.Length - '.runtimeconfig.json'.Length)
    $assemblyFile = "$assemblyBaseName.dll"
    if (-not (Test-Path -LiteralPath (Join-Path $cliStage $assemblyFile))) {
        throw "Published CLI assembly is missing: $assemblyFile"
    }

    $cmdLauncher = "@echo off`r`n" + ('dotnet "%~dp0{0}" %*' -f $assemblyFile) + "`r`n"
    Set-Content -LiteralPath (Join-Path $cliStage 'manifest-ui.cmd') -Value $cmdLauncher -Encoding ascii -NoNewline
    $shLauncher = @'
#!/usr/bin/env sh
SCRIPT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
exec dotnet "$SCRIPT_DIR/{0}" "$@"
'@ -f $assemblyFile
    Set-Content -LiteralPath (Join-Path $cliStage 'manifest-ui') -Value $shLauncher -Encoding utf8 -NoNewline

    $cliFiles = foreach ($file in (Get-ChildItem -LiteralPath $cliStage -File -Recurse | Sort-Object FullName)) {
        [PSCustomObject]@{
            Source = $file.FullName
            Entry = [System.IO.Path]::GetRelativePath($cliStage, $file.FullName).Replace('\', '/')
        }
    }
    $cliArchive = Join-Path $outputPath "manifest-ui-cli-$version.zip"
    New-DeterministicZip -Files @($cliFiles) -Destination $cliArchive
    $artifacts.Add($cliArchive)
}

$exampleFiles = @(Get-RepositoryFiles 'examples')
if ($exampleFiles.Count -gt 0) {
    $exampleArchive = Join-Path $outputPath "manifest-ui-example-$version.zip"
    New-DeterministicZip -Files $exampleFiles -Destination $exampleArchive
    $artifacts.Add($exampleArchive)
}
elseif ($RequireExamples) {
    throw 'Release packaging requires publishable files under examples/.'
}

$checksumLines = foreach ($artifact in ($artifacts | Sort-Object)) {
    $hash = (Get-FileHash -LiteralPath $artifact -Algorithm SHA256).Hash.ToLowerInvariant()
    "$hash  $([System.IO.Path]::GetFileName($artifact))"
}
$checksumPath = Join-Path $outputPath 'SHA256SUMS.txt'
Set-Content -LiteralPath $checksumPath -Value ($checksumLines -join "`n") -Encoding utf8 -NoNewline

Remove-Item -LiteralPath $stagingPath -Recurse -Force

Write-Host "Release artifacts created in $outputPath"
Get-ChildItem -LiteralPath $outputPath -File | Sort-Object Name | ForEach-Object {
    Write-Host ("  {0} ({1} bytes)" -f $_.Name, $_.Length)
}
