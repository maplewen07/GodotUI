[CmdletBinding()]
param(
    [string]$GodotBin = $env:GODOT_BIN,
    [string]$ScreenshotDirectory,
    [double]$FrameBudgetMilliseconds = 50.0,
    [ValidateRange(10, 600)]
    [int]$ProcessTimeoutSeconds = 120,
    [switch]$SkipBuild
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

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
    $started = $false
    try {
        [void]$process.Start()
        $started = $true
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
        if ($timedOut) {
            throw "Godot exceeded the $TimeoutSeconds second visual-test timeout; its process tree was terminated."
        }
        return [PSCustomObject]@{
            ExitCode = $process.ExitCode
            Output = @($output, $errorOutput) -join [Environment]::NewLine
        }
    }
    catch {
        if ($started -and -not $process.HasExited) {
            $process.Kill($true)
            $process.WaitForExit()
        }
        throw
    }
    finally {
        $process.Dispose()
    }
}

$projectRoot = Split-Path -Parent $PSScriptRoot
if ([string]::IsNullOrWhiteSpace($GodotBin)) {
    throw 'Pass -GodotBin or set GODOT_BIN to the Godot 4.7 Mono executable.'
}
$resolvedGodot = (Resolve-Path -LiteralPath $GodotBin).Path
if ([string]::IsNullOrWhiteSpace($ScreenshotDirectory)) {
    $ScreenshotDirectory = Join-Path $projectRoot 'artifacts/test-results/liquid-glass'
}
$ScreenshotDirectory = [System.IO.Path]::GetFullPath($ScreenshotDirectory, $projectRoot)
[System.IO.Directory]::CreateDirectory($ScreenshotDirectory) | Out-Null

if (-not $SkipBuild) {
    & dotnet build (Join-Path $projectRoot 'GodotUI.csproj') --configuration Debug
    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

$resolutions = @(
    [PSCustomObject]@{ Width = 640; Height = 360 },
    [PSCustomObject]@{ Width = 960; Height = 540 },
    [PSCustomObject]@{ Width = 1440; Height = 810 }
)

foreach ($resolution in $resolutions) {
    $label = "$($resolution.Width)x$($resolution.Height)"
    $screenshotPath = Join-Path $ScreenshotDirectory "liquid-glass-$label.png"
    $environment = @{
        LIQUID_GLASS_SCREENSHOT = $screenshotPath
        LIQUID_GLASS_EXPECTED_WIDTH = [string]$resolution.Width
        LIQUID_GLASS_EXPECTED_HEIGHT = [string]$resolution.Height
        LIQUID_GLASS_FRAME_BUDGET_MS = $FrameBudgetMilliseconds.ToString([System.Globalization.CultureInfo]::InvariantCulture)
    }

    $result = Invoke-GodotWithTimeout `
        -FilePath $resolvedGodot `
        -ArgumentList @(
            '--path', $projectRoot,
            '--scene', 'res://tests/LiquidGlassVisualCheck.tscn',
            '--resolution', $label,
            '--rendering-method', 'gl_compatibility',
            '--audio-driver', 'Dummy',
            '--quit-after', '240'
        ) `
        -Environment $environment `
        -TimeoutSeconds $ProcessTimeoutSeconds
    if (-not [string]::IsNullOrWhiteSpace($result.Output)) {
        Write-Host $result.Output.TrimEnd()
    }
    if ($result.ExitCode -ne 0) {
        throw "Liquid Glass visual check failed at $label (exit $($result.ExitCode))."
    }
    $renderLog = [string]$result.Output
    if ($renderLog -match '(?im)^\s*(?:SHADER )?ERROR:|Shader compilation failed|SCRIPT ERROR:') {
        throw "Liquid Glass emitted a Godot runtime or shader error at $label. See the output above."
    }
    if (-not (Test-Path -LiteralPath $screenshotPath -PathType Leaf)) {
        throw "Liquid Glass did not write the expected screenshot: $screenshotPath"
    }
    if ((Get-Item -LiteralPath $screenshotPath).Length -lt 4096) {
        throw "Liquid Glass screenshot is unexpectedly small at $label."
    }
    if ($renderLog -notmatch 'LIQUID_GLASS_METRIC average_frame_ms=') {
        throw "Liquid Glass did not report a frame-time metric at $label."
    }
}

Write-Host "Liquid Glass visual gate passed at 640x360, 960x540, and 1440x810."
