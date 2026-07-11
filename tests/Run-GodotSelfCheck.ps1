[CmdletBinding()]
param(
    [string]$GodotBin = $env:GODOT_BIN,
    [string]$Configuration = "Debug",
    [string]$JUnitPath,
    [switch]$AllowKnownGodotThreadedLoaderLeak
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

$projectRoot = Split-Path -Parent $PSScriptRoot
if ([string]::IsNullOrWhiteSpace($GodotBin)) {
    throw "Pass -GodotBin or set GODOT_BIN to the Godot 4.7 Mono console executable."
}

$resolvedGodot = (Resolve-Path -LiteralPath $GodotBin).Path
if ([string]::IsNullOrWhiteSpace($JUnitPath)) {
    $JUnitPath = Join-Path $projectRoot "artifacts/test-results/manifest-ui-self-check.xml"
}
$JUnitPath = [System.IO.Path]::GetFullPath($JUnitPath, $projectRoot)
[System.IO.Directory]::CreateDirectory([System.IO.Path]::GetDirectoryName($JUnitPath)) | Out-Null

dotnet build (Join-Path $projectRoot "GodotUI.csproj") --configuration $Configuration
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

$previousJUnitPath = $env:MANIFEST_UI_JUNIT_PATH
try {
    $env:MANIFEST_UI_JUNIT_PATH = $JUnitPath
    $godotOutput = & $resolvedGodot --headless --verbose --path $projectRoot --scene "res://tests/SelfCheck.tscn" 2>&1
    $exitCode = $LASTEXITCODE
    $godotOutput | ForEach-Object { Write-Host $_ }
    $leakedInstances = @($godotOutput | Where-Object { $_ -match 'Leaked instance:' })
    $objectDbWarnings = @($godotOutput | Where-Object { $_ -match 'ObjectDB instance was leaked' })
    if ($leakedInstances.Count -gt 0 -or $objectDbWarnings.Count -gt 0) {
        $knownThreadedLoaderLeak = $leakedInstances.Count -ge 1 -and
            $leakedInstances.Count -le 4 -and
            @($leakedInstances | Where-Object { $_ -notmatch 'Leaked instance: RefCounted:.*Reference count: 0' }).Count -eq 0 -and
            $objectDbWarnings.Count -eq 1
        if ($AllowKnownGodotThreadedLoaderLeak -and $knownThreadedLoaderLeak) {
            Write-Warning 'Godot 4.7 reported the known threaded ResourceLoader LoadToken leak; alpha verification is continuing.'
        }
        else {
            Write-Host "Godot reported leaked ObjectDB instances." -ForegroundColor Red
            $exitCode = 1
        }
    }
}
finally {
    $env:MANIFEST_UI_JUNIT_PATH = $previousJUnitPath
}

if (-not (Test-Path -LiteralPath $JUnitPath)) {
    throw "Godot exited without writing the expected JUnit report: $JUnitPath"
}

Write-Host "JUnit: $JUnitPath"
exit $exitCode
