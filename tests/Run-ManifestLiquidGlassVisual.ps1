[CmdletBinding()]
param(
    [string]$GodotBin = $env:GODOT_BIN,
    [string]$ScreenshotDirectory,
    [ValidateRange(10, 600)]
    [int]$ProcessTimeoutSeconds = 120,
    [switch]$SkipBuild
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

function Resolve-GodotExecutable {
    param([Parameter(Mandatory)] [string]$Value)

    if (Test-Path -LiteralPath $Value -PathType Leaf) {
        return (Resolve-Path -LiteralPath $Value).Path
    }
    $command = Get-Command $Value -ErrorAction SilentlyContinue
    if ($null -eq $command) {
        throw "Godot executable was not found: $Value"
    }
    return $command.Source
}

function Invoke-GodotWithTimeout {
    param(
        [Parameter(Mandatory)] [string]$FilePath,
        [Parameter(Mandatory)] [string[]]$ArgumentList,
        [Parameter(Mandatory)] [hashtable]$Environment,
        [Parameter(Mandatory)] [int]$TimeoutSeconds
    )

    $startInfo = [System.Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $FilePath
    $startInfo.UseShellExecute = $false
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true
    foreach ($argument in $ArgumentList) {
        [void]$startInfo.ArgumentList.Add($argument)
    }
    foreach ($entry in $Environment.GetEnumerator()) {
        $startInfo.Environment[[string]$entry.Key] = [string]$entry.Value
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
            $process.WaitForExit()
        }
        $process.WaitForExit()
        if ($timedOut) {
            throw "Godot exceeded the $TimeoutSeconds second Manifest Liquid Glass visual-test timeout."
        }
        return [PSCustomObject]@{
            ExitCode = $process.ExitCode
            Output = @($stdout.GetAwaiter().GetResult(), $stderr.GetAwaiter().GetResult()) -join [Environment]::NewLine
        }
    }
    finally {
        $process.Dispose()
    }
}

$projectRoot = Split-Path -Parent $PSScriptRoot
if ([string]::IsNullOrWhiteSpace($GodotBin)) {
    throw 'Pass -GodotBin or set GODOT_BIN to the Godot 4.7 Mono executable.'
}
$resolvedGodot = Resolve-GodotExecutable -Value $GodotBin
if ([string]::IsNullOrWhiteSpace($ScreenshotDirectory)) {
    $ScreenshotDirectory = Join-Path $projectRoot 'artifacts/test-results/manifest-liquid-glass'
}
$ScreenshotDirectory = [System.IO.Path]::GetFullPath($ScreenshotDirectory, $projectRoot)
[System.IO.Directory]::CreateDirectory($ScreenshotDirectory) | Out-Null

if (-not $SkipBuild) {
    & dotnet build (Join-Path $projectRoot 'GodotUI.csproj') --configuration Debug
    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

foreach ($resolution in @(
    [PSCustomObject]@{ Width = 640; Height = 360 },
    [PSCustomObject]@{ Width = 960; Height = 540 },
    [PSCustomObject]@{ Width = 1440; Height = 810 }
)) {
    $label = "$($resolution.Width)x$($resolution.Height)"
    $screenshotPath = Join-Path $ScreenshotDirectory "manifest-liquid-glass-$label.png"
    $result = Invoke-GodotWithTimeout `
        -FilePath $resolvedGodot `
        -ArgumentList @(
            '--path', $projectRoot,
            '--scene', 'res://tests/ManifestLiquidGlassVisualCheck.tscn',
            '--resolution', $label,
            '--rendering-method', 'gl_compatibility',
            '--audio-driver', 'Dummy',
            '--quit-after', '240'
        ) `
        -Environment @{
            MANIFEST_LIQUID_GLASS_SCREENSHOT = $screenshotPath
            MANIFEST_LIQUID_GLASS_EXPECTED_WIDTH = [string]$resolution.Width
            MANIFEST_LIQUID_GLASS_EXPECTED_HEIGHT = [string]$resolution.Height
        } `
        -TimeoutSeconds $ProcessTimeoutSeconds

    if (-not [string]::IsNullOrWhiteSpace($result.Output)) {
        Write-Host $result.Output.TrimEnd()
    }
    if ($result.ExitCode -ne 0) {
        throw "Manifest Liquid Glass visual check failed at $label (exit $($result.ExitCode))."
    }
    if ($result.Output -match '(?im)^\s*(?:SHADER )?ERROR:|Shader compilation failed|SCRIPT ERROR:') {
        throw "Manifest Liquid Glass emitted a Godot runtime or shader error at $label."
    }
    if ($result.Output -notmatch 'Manifest Liquid Glass visual check passed\.') {
        throw "Manifest Liquid Glass did not reach its completion marker at $label."
    }
    if (-not (Test-Path -LiteralPath $screenshotPath -PathType Leaf) -or (Get-Item -LiteralPath $screenshotPath).Length -lt 4096) {
        throw "Manifest Liquid Glass screenshot is missing or unexpectedly small at $label."
    }
}

Write-Host 'Manifest Liquid Glass visual gate passed at 640x360, 960x540, and 1440x810.'
