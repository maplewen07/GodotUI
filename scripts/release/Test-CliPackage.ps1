[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [string]$PackagePath,
    [string]$ExpectedVersion,
    [string]$TestManifest
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
if ([string]::IsNullOrWhiteSpace($ExpectedVersion)) {
    $ExpectedVersion = [string](Get-Content -LiteralPath (Join-Path $repoRoot 'manifest-ui-version.json') -Raw | ConvertFrom-Json).version
}
if ([string]::IsNullOrWhiteSpace($TestManifest)) {
    $TestManifest = Join-Path $repoRoot 'examples/Basic/ui/basic/package.json'
}

$resolvedPackage = (Resolve-Path -LiteralPath $PackagePath).Path
$resolvedManifest = (Resolve-Path -LiteralPath $TestManifest).Path
$tempBase = [System.IO.Path]::GetFullPath([System.IO.Path]::GetTempPath())
$tempRoot = Join-Path $tempBase ('manifest-ui-cli-test-' + [Guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $tempRoot -Force | Out-Null

try {
    Add-Type -AssemblyName System.IO.Compression
    $archive = [System.IO.Compression.ZipFile]::OpenRead($resolvedPackage)
    try {
        foreach ($entry in $archive.Entries) {
            if ($entry.FullName.Contains('\') -or $entry.FullName.Contains('../') -or [System.IO.Path]::IsPathRooted($entry.FullName)) {
                throw "Invalid CLI archive entry: $($entry.FullName)"
            }
        }
    }
    finally {
        $archive.Dispose()
    }

    [System.IO.Compression.ZipFile]::ExtractToDirectory($resolvedPackage, $tempRoot)
    $runtimeConfigs = @(Get-ChildItem -LiteralPath $tempRoot -Filter '*.runtimeconfig.json' -File)
    if ($runtimeConfigs.Count -ne 1) {
        throw 'CLI archive must contain exactly one runtimeconfig.json.'
    }
    $assemblyName = $runtimeConfigs[0].BaseName.Replace('.runtimeconfig', '')
    $assemblyPath = Join-Path $tempRoot "$assemblyName.dll"
    if (-not (Test-Path -LiteralPath $assemblyPath -PathType Leaf)) {
        throw "CLI assembly is missing: $assemblyName.dll"
    }
    foreach ($launcher in @('manifest-ui', 'manifest-ui.cmd')) {
        if (-not (Test-Path -LiteralPath (Join-Path $tempRoot $launcher) -PathType Leaf)) {
            throw "CLI launcher is missing: $launcher"
        }
    }

    $productVersion = [System.Diagnostics.FileVersionInfo]::GetVersionInfo($assemblyPath).ProductVersion
    if ([string]::IsNullOrWhiteSpace($productVersion) -or -not $productVersion.StartsWith($ExpectedVersion, [StringComparison]::Ordinal)) {
        throw "Published CLI version '$productVersion' does not match '$ExpectedVersion'."
    }

    $validateOutput = @(& dotnet $assemblyPath validate $resolvedManifest --format json 2>&1)
    $validateExitCode = $LASTEXITCODE
    $validateOutput | ForEach-Object { Write-Host $_ }
    if ($validateExitCode -ne 0) {
        throw "Published CLI validate failed with exit code $validateExitCode."
    }
    $validateResult = ($validateOutput -join [Environment]::NewLine) | ConvertFrom-Json
    if (-not $validateResult.success -or [int]$validateResult.exitCode -ne 0) {
        throw 'Published CLI returned an invalid success result.'
    }

    & dotnet $assemblyPath schema check --project $repoRoot
    if ($LASTEXITCODE -ne 0) {
        throw 'Published CLI schema check failed.'
    }

    Write-Host "CLI package OK: $resolvedPackage"
}
finally {
    $resolvedTemp = [System.IO.Path]::GetFullPath($tempRoot)
    if ($resolvedTemp.StartsWith($tempBase, [StringComparison]::OrdinalIgnoreCase) -and (Test-Path -LiteralPath $resolvedTemp)) {
        Remove-Item -LiteralPath $resolvedTemp -Recurse -Force
    }
}
