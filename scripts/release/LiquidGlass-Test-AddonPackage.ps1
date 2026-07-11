[CmdletBinding()]
param(
    [Parameter(Mandatory)] [string]$PackagePath,
    [string]$GodotBin = $env:GODOT_BIN,
    [switch]$SkipGodot,
    [switch]$KeepTemp
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

function Invoke-CheckedProcess {
    param(
        [Parameter(Mandatory)] [string]$FilePath,
        [Parameter(Mandatory)] [string[]]$ArgumentList,
        [int]$TimeoutSeconds = 180,
        [switch]$RejectGodotErrors
    )
    $startInfo = [System.Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $FilePath
    $startInfo.UseShellExecute = $false
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true
    foreach ($argument in $ArgumentList) { [void]$startInfo.ArgumentList.Add($argument) }

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
        $combined = @($output, $errorOutput) -join [Environment]::NewLine
        if (-not [string]::IsNullOrWhiteSpace($combined)) { Write-Host $combined.TrimEnd() }
        if ($timedOut) { throw "$FilePath exceeded the $TimeoutSeconds second timeout." }
        if ($process.ExitCode -ne 0) { throw "$FilePath exited with code $($process.ExitCode)." }
        if ($RejectGodotErrors -and $combined -match '(?im)^\s*(?:SCRIPT |SHADER )?ERROR:|Shader compilation failed') {
            throw "$FilePath emitted a Godot script or shader error."
        }
        return $combined
    }
    finally { $process.Dispose() }
}

$resolvedPackage = (Resolve-Path -LiteralPath $PackagePath).Path
Add-Type -AssemblyName System.IO.Compression
$archive = [System.IO.Compression.ZipFile]::OpenRead($resolvedPackage)
try {
    $fileEntries = @($archive.Entries | Where-Object { -not [string]::IsNullOrEmpty($_.Name) })
    if ($fileEntries.Count -eq 0) { throw 'Liquid Glass addon archive is empty.' }
    foreach ($entry in $fileEntries) {
        if ($entry.FullName.Contains('\') -or $entry.FullName.Contains('../') -or -not $entry.FullName.StartsWith('addons/liquid_glass/', [System.StringComparison]::Ordinal)) {
            throw "Invalid Liquid Glass addon archive entry: $($entry.FullName)"
        }
    }
    if ($fileEntries.FullName -notcontains 'addons/liquid_glass/plugin.cfg') {
        throw 'Addon archive does not contain addons/liquid_glass/plugin.cfg.'
    }
}
finally { $archive.Dispose() }
if ((Get-Item -LiteralPath $resolvedPackage).Length -ge 2MB) { throw 'Liquid Glass addon ZIP must remain below 2 MiB.' }

$tempBase = [System.IO.Path]::GetFullPath([System.IO.Path]::GetTempPath())
$tempRoot = Join-Path $tempBase ("liquid-glass-install-test-" + [System.Guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $tempRoot -Force | Out-Null

try {
    [System.IO.Compression.ZipFile]::ExtractToDirectory($resolvedPackage, $tempRoot)
    $projectFile = @'
; Generated Liquid Glass clean-install project.
config_version=5

[application]
config/name="Liquid Glass Install Test"
run/main_scene="res://RuntimeSmoke.tscn"
config/features=PackedStringArray("4.7", "C#", "Compatibility")

[dotnet]
project/assembly_name="LiquidGlassInstallTest"

[rendering]
renderer/rendering_method="gl_compatibility"
renderer/rendering_method.mobile="gl_compatibility"
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'project.godot') -Value $projectFile -Encoding utf8 -NoNewline
    $csproj = @'
<Project Sdk="Godot.NET.Sdk/4.7.0">
  <PropertyGroup>
    <TargetFramework>net8.0</TargetFramework>
    <EnableDynamicLoading>true</EnableDynamicLoading>
    <Nullable>enable</Nullable>
  </PropertyGroup>
</Project>
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'LiquidGlassInstallTest.csproj') -Value $csproj -Encoding utf8 -NoNewline
    $runtimeSmoke = @'
using System;
using Godot;
using GodotUi.LiquidGlass;

public partial class RuntimeSmoke : Control
{
    public override async void _Ready()
    {
        try
        {
            var style = new LiquidGlassStyle
            {
                Shape = LiquidGlassShape.Superellipse,
                SuperellipseExponent = 4.5f,
            };
            style.ApplyPreset(LiquidGlassPreset.Frosted);
            if (style.Shape != LiquidGlassShape.Superellipse || Math.Abs(style.SuperellipseExponent - 4.5f) > 0.001f)
            {
                throw new InvalidOperationException("Superellipse style contract failed.");
            }

            var panel = new LiquidGlassPanel { Size = new Vector2(240, 120), Style = style };
            AddChild(panel);
            var presses = 0;
            var button = new LiquidGlassButton { Text = "Apply", AccessibilityName = "Apply glass", Size = new Vector2(140, 48) };
            button.Pressed += () => presses++;
            AddChild(button);
            var sliderChanges = 0;
            var slider = new LiquidGlassSlider { MinValue = 0, MaxValue = 1, Step = 0.1, Value = 0.5, AccessibilityName = "Intensity" };
            slider.ValueChanged += _ => sliderChanges++;
            AddChild(slider);
            await ToSignal(GetTree(), SceneTree.SignalName.ProcessFrame);

            using (var down = new InputEventAction { Action = "ui_accept", Pressed = true })
            using (var up = new InputEventAction { Action = "ui_accept", Pressed = false })
            {
                button._GuiInput(down);
                button._GuiInput(up);
            }
            using (var right = new InputEventAction { Action = "ui_right", Pressed = true })
            using (var left = new InputEventAction { Action = "ui_left", Pressed = true })
            {
                slider._GuiInput(right);
                slider._GuiInput(left);
            }
            if (presses != 1 || sliderChanges != 2 || Math.Abs(slider.Value - 0.5) > 0.000001)
            {
                throw new InvalidOperationException("Action input contract failed.");
            }
            button.Disabled = true;
            slider.Disabled = true;
            if (!button.Disabled || !slider.Disabled)
            {
                throw new InvalidOperationException("Disabled accessibility state failed.");
            }
            GD.Print("Liquid Glass clean runtime OK.");
            GetTree().Quit(0);
        }
        catch (Exception exception)
        {
            GD.PushError(exception.ToString());
            GetTree().Quit(1);
        }
    }
}
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'RuntimeSmoke.cs') -Value $runtimeSmoke -Encoding utf8 -NoNewline
    $runtimeScene = @'
[gd_scene load_steps=2 format=3]

[ext_resource type="Script" path="res://RuntimeSmoke.cs" id="1_runtime"]

[node name="RuntimeSmoke" type="Control"]
layout_mode = 3
anchors_preset = 15
anchor_right = 1.0
anchor_bottom = 1.0
grow_horizontal = 2
grow_vertical = 2
script = ExtResource("1_runtime")
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'RuntimeSmoke.tscn') -Value $runtimeScene -Encoding utf8 -NoNewline

    [void](Invoke-CheckedProcess -FilePath 'dotnet' -ArgumentList @('build', (Join-Path $tempRoot 'LiquidGlassInstallTest.csproj'), '--configuration', 'Release'))

    if (-not $SkipGodot) {
        if ([string]::IsNullOrWhiteSpace($GodotBin)) {
            $godotCommand = Get-Command godot -ErrorAction SilentlyContinue
            if ($null -eq $godotCommand) { throw 'Godot was not found. Pass -GodotBin or use -SkipGodot.' }
            $GodotBin = $godotCommand.Source
        }
        if (Test-Path -LiteralPath $GodotBin -PathType Leaf) {
            $resolvedGodot = (Resolve-Path -LiteralPath $GodotBin).Path
        }
        else {
            $godotCommand = Get-Command $GodotBin -ErrorAction SilentlyContinue
            if ($null -eq $godotCommand) { throw "Godot executable was not found: $GodotBin" }
            $resolvedGodot = $godotCommand.Source
        }
        $versionOutput = Invoke-CheckedProcess -FilePath $resolvedGodot -ArgumentList @('--version')
        if ($versionOutput -notmatch '^4\.7(?:\.|\s)') { throw "Liquid Glass clean install requires Godot 4.7, got: $versionOutput" }

        [void](Invoke-CheckedProcess -FilePath 'dotnet' -ArgumentList @('build', (Join-Path $tempRoot 'LiquidGlassInstallTest.csproj'), '--configuration', 'Debug'))
        [void](Invoke-CheckedProcess -FilePath $resolvedGodot -ArgumentList @('--headless', '--path', $tempRoot, '--import') -RejectGodotErrors)

        $enabledProject = $projectFile + @'

[editor_plugins]
enabled=PackedStringArray("res://addons/liquid_glass/plugin.cfg")
'@
        Set-Content -LiteralPath (Join-Path $tempRoot 'project.godot') -Value $enabledProject -Encoding utf8 -NoNewline
        [void](Invoke-CheckedProcess -FilePath $resolvedGodot -ArgumentList @('--headless', '--path', $tempRoot, '--import') -RejectGodotErrors)
        [void](Invoke-CheckedProcess -FilePath $resolvedGodot -ArgumentList @('--headless', '--path', $tempRoot, '--scene', 'res://RuntimeSmoke.tscn', '--quit-after', '120') -TimeoutSeconds 120 -RejectGodotErrors)
    }

    Write-Host "Clean Liquid Glass addon install OK: $resolvedPackage"
}
finally {
    $resolvedTempRoot = [System.IO.Path]::GetFullPath($tempRoot)
    if ($KeepTemp -and (Test-Path -LiteralPath $resolvedTempRoot)) {
        Write-Warning "Retained Liquid Glass clean-install project: $resolvedTempRoot"
    }
    elseif ($resolvedTempRoot.StartsWith($tempBase, [System.StringComparison]::OrdinalIgnoreCase) -and (Test-Path -LiteralPath $resolvedTempRoot)) {
        Remove-Item -LiteralPath $resolvedTempRoot -Recurse -Force
    }
}
