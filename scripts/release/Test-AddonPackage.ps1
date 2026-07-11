[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [string]$PackagePath,
    [string]$GodotBin = $env:GODOT_BIN,
    [switch]$SkipGodot,
    [switch]$AllowKnownGodotThreadedLoaderLeak,
    [switch]$KeepTemp
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

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
        return [PSCustomObject]@{
            ExitCode = $process.ExitCode
            Output = [string]::Join([Environment]::NewLine, @($output, $errorOutput))
        }
    }
    finally {
        $process.Dispose()
    }
}

function Assert-GodotOutputHasNoErrors {
    param(
        [Parameter(Mandatory)]
        [object]$Result,
        [Parameter(Mandatory)]
        [string]$Context
    )

    if ($Result.Output -match '(?im)^\s*(?:(?:SCRIPT|SHADER) )?ERROR:') {
        throw "$Context emitted a Godot error."
    }
}

$resolvedPackage = (Resolve-Path -LiteralPath $PackagePath).Path
Add-Type -AssemblyName System.IO.Compression
$archive = [System.IO.Compression.ZipFile]::OpenRead($resolvedPackage)
try {
    $fileEntries = @($archive.Entries | Where-Object { -not [string]::IsNullOrEmpty($_.Name) })
    if ($fileEntries.Count -eq 0) {
        throw 'Addon archive is empty.'
    }

    foreach ($entry in $fileEntries) {
        if ($entry.FullName.Contains('\') -or $entry.FullName.Contains('../') -or -not $entry.FullName.StartsWith('addons/manifest_ui/', [System.StringComparison]::Ordinal)) {
            throw "Invalid addon archive entry: $($entry.FullName)"
        }
    }

    if (-not ($fileEntries.FullName -contains 'addons/manifest_ui/plugin.cfg')) {
        throw 'Addon archive does not contain addons/manifest_ui/plugin.cfg.'
    }
}
finally {
    $archive.Dispose()
}

if ((Get-Item -LiteralPath $resolvedPackage).Length -ge 2MB) {
    throw 'Addon archive must remain below 2 MiB.'
}

$tempBase = [System.IO.Path]::GetFullPath([System.IO.Path]::GetTempPath())
$tempRoot = Join-Path $tempBase ("godotui-install-test-" + [System.Guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $tempRoot -Force | Out-Null

try {
    [System.IO.Compression.ZipFile]::ExtractToDirectory($resolvedPackage, $tempRoot)

    $projectFile = @'
; Generated clean-install verification project.
config_version=5

[application]
config/name="Manifest UI Install Test"
run/main_scene="res://RuntimeSmoke.tscn"
config/features=PackedStringArray("4.7", "C#", "Compatibility")

[dotnet]
project/assembly_name="ManifestUiInstallTest"
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'project.godot') -Value $projectFile -Encoding utf8 -NoNewline

    $csproj = @'
<Project Sdk="Godot.NET.Sdk/4.7.0">
  <PropertyGroup>
    <TargetFramework>net8.0</TargetFramework>
    <EnableDynamicLoading>true</EnableDynamicLoading>
    <Nullable>enable</Nullable>
  </PropertyGroup>
  <ItemGroup>
    <Compile Remove=".install-test\**\*.cs" />
  </ItemGroup>
</Project>
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'ManifestUiInstallTest.csproj') -Value $csproj -Encoding utf8 -NoNewline

    $harnessDirectory = Join-Path $tempRoot '.install-test'
    New-Item -ItemType Directory -Path $harnessDirectory -Force | Out-Null
    $harnessProject = @'
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>net8.0</TargetFramework>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
    <EnableDefaultCompileItems>false</EnableDefaultCompileItems>
  </PropertyGroup>
  <ItemGroup>
    <Compile Include="ToolHarness.cs" />
    <Compile Include="..\addons\manifest_ui\tooling\ManifestUiTool.cs" Link="ManifestUiTool.cs" />
  </ItemGroup>
</Project>
'@
    Set-Content -LiteralPath (Join-Path $harnessDirectory 'ToolHarness.csproj') -Value $harnessProject -Encoding utf8 -NoNewline
    $harnessProgram = @'
using GodotUi.Manifest.Tooling;

return ManifestUiTool.Run(args);
'@
    Set-Content -LiteralPath (Join-Path $harnessDirectory 'ToolHarness.cs') -Value $harnessProgram -Encoding utf8 -NoNewline

    $packageDirectory = Join-Path $tempRoot 'ui/smoke'
    New-Item -ItemType Directory -Path $packageDirectory -Force | Out-Null
    $packageFiles = @{
        'package.json' = @'
{
  "schemaVersion": 1,
  "packageId": "install.smoke",
  "displayName": "Install Smoke",
  "designResolution": [640, 360],
  "assets": "assets.json",
  "layout": "layout.json",
  "bindings": "bindings.json",
  "codegen": "codegen.json",
  "validation": "validation.json",
  "strings": "strings.json",
  "runtime": { "controllerScope": "instance" },
  "godot": {
    "systemName": "install_smoke",
    "widgetClass": "InstallSmokeWidget",
    "controllerClass": "InstallSmoke.SmokeController",
    "namespace": "InstallSmoke.Generated",
    "outputDir": "generated/ui/install_smoke",
    "scenePath": "res://generated/ui/install_smoke/InstallSmokeWidget.tscn"
  }
}
'@
        'assets.json' = '{ "assets": [] }'
        'layout.json' = @'
{
  "root": {
    "id": "root",
    "type": "Control",
    "name": "InstallSmokeWidget",
    "properties": {},
    "children": [
      {
        "id": "title",
        "type": "Label",
        "name": "Title",
        "properties": {},
        "localization": { "text": "install.title" },
        "children": []
      }
    ]
  }
}
'@
        'bindings.json' = @'
{
  "mvvm": { "updatePolicy": "immediate", "fields": [] },
  "bindings": {},
  "repeaters": [],
  "inputs": [],
  "controls": [],
  "events": { "channels": [] }
}
'@
        'codegen.json' = '{ "schemaVersion": 1, "generator": "ManifestUi" }'
        'validation.json' = @'
{
  "commandletInputWhitelist": ["assets.json", "layout.json", "bindings.json", "codegen.json", "validation.json", "strings.json"],
  "checks": {}
}
'@
        'strings.json' = @'
{
  "schemaVersion": 1,
  "defaultLocale": "en",
  "locales": ["en"],
  "strings": { "install.title": { "en": "Clean install smoke" } }
}
'@
    }
    foreach ($entry in $packageFiles.GetEnumerator()) {
        Set-Content -LiteralPath (Join-Path $packageDirectory $entry.Key) -Value $entry.Value -Encoding utf8 -NoNewline
    }

    $controller = @'
using GodotUi.Manifest;

namespace InstallSmoke;

public sealed class SmokeController : ManifestControllerBase
{
}
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'SmokeController.cs') -Value $controller -Encoding utf8 -NoNewline

    foreach ($toolArguments in @(
        @('validate', (Join-Path $packageDirectory 'package.json'), '--format', 'json'),
        @('generate', (Join-Path $packageDirectory 'package.json'), '--clean'),
        @('verify', (Join-Path $packageDirectory 'package.json'))
    )) {
        & dotnet run --project (Join-Path $harnessDirectory 'ToolHarness.csproj') -- @toolArguments
        if ($LASTEXITCODE -ne 0) {
            throw "The addon tooling core failed: $($toolArguments -join ' ')"
        }
    }

    $runtimeSmoke = @'
using System;
using Godot;
using GodotUi.Manifest;
using InstallSmoke.Generated;

public partial class RuntimeSmoke : Node
{
    public override async void _Ready()
    {
        try
        {
            var manager = GodotUi.Manifest.ManifestUiManager.Instance;
            if (GodotUi.Manifest.ManifestMessageBus.Instance is null ||
                GodotUi.Manifest.ManifestUiRoot.Instance is null ||
                manager is null)
            {
                throw new InvalidOperationException("Manifest UI autoloads were not initialized.");
            }
            InstallSmokeWidgetManifestCatalog.Register(manager, replace: true);
            var handle = await manager.OpenAsync("install.smoke");
            var title = handle.Widget?.GetNodeOrNull<Label>("Title");
            if (handle.State != ManifestUiState.Open || title?.Text != "Clean install smoke")
            {
                throw new InvalidOperationException("Generated scene or localization did not run correctly.");
            }
            await manager.CloseAsync(handle, ManifestUiCloseReason.Programmatic);
            await manager.ReleaseAsync("install.smoke", closeInstances: true);
            GD.Print("Manifest UI clean runtime OK.");
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

[node name="RuntimeSmoke" type="Node"]
script = ExtResource("1_runtime")
'@
    Set-Content -LiteralPath (Join-Path $tempRoot 'RuntimeSmoke.tscn') -Value $runtimeScene -Encoding utf8 -NoNewline

    & dotnet build (Join-Path $tempRoot 'ManifestUiInstallTest.csproj') --configuration Release
    if ($LASTEXITCODE -ne 0) {
        throw 'The addon failed to compile in a clean project.'
    }

    if (-not $SkipGodot) {
        if ([string]::IsNullOrWhiteSpace($GodotBin)) {
            $godotCommand = Get-Command godot -ErrorAction SilentlyContinue
            if ($null -eq $godotCommand) {
                $godotCommand = Get-Command godot4 -ErrorAction SilentlyContinue
            }
            if ($null -eq $godotCommand) {
                throw 'Godot was not found. Set GODOT_BIN or use -SkipGodot for archive/build validation only.'
            }
            $GodotBin = $godotCommand.Source
        }
        elseif (-not (Test-Path -LiteralPath $GodotBin -PathType Leaf) -and $null -eq (Get-Command $GodotBin -ErrorAction SilentlyContinue)) {
            throw "Godot executable was not found: $GodotBin"
        }

        & dotnet build (Join-Path $tempRoot 'ManifestUiInstallTest.csproj') --configuration Debug
        if ($LASTEXITCODE -ne 0) {
            throw 'The addon failed to compile its editor configuration in a clean project.'
        }

        $godotResult = Invoke-ProcessWithTimeout -FilePath $GodotBin -ArgumentList @(
            '--headless', '--path', $tempRoot, '--import'
        )
        Assert-GodotOutputHasNoErrors -Result $godotResult -Context 'Clean project import'
        if ($godotResult.ExitCode -ne 0) {
            throw "Godot failed to import the clean project before plugin activation (exit $($godotResult.ExitCode))."
        }

        $enabledProjectFile = $projectFile + @'


[editor_plugins]
enabled=PackedStringArray("res://addons/manifest_ui/plugin.cfg")
'@
        Set-Content -LiteralPath (Join-Path $tempRoot 'project.godot') -Value $enabledProjectFile -Encoding utf8 -NoNewline

        $godotResult = Invoke-ProcessWithTimeout -FilePath $GodotBin -ArgumentList @(
            '--headless', '--path', $tempRoot, '--import'
        )
        Assert-GodotOutputHasNoErrors -Result $godotResult -Context 'Plugin activation'
        if ($godotResult.ExitCode -ne 0) {
            throw "Godot failed to enable the addon after the clean project import (exit $($godotResult.ExitCode))."
        }

        $enabledProject = Get-Content -LiteralPath (Join-Path $tempRoot 'project.godot') -Raw
        $expectedAutoloads = [ordered]@{
            ManifestMessageBus = 'res://addons/manifest_ui/autoload/ManifestMessageBus.cs'
            ManifestUiRoot = 'res://addons/manifest_ui/autoload/ManifestUiRoot.cs'
            ManifestUiManager = 'res://addons/manifest_ui/autoload/ManifestUiManager.cs'
        }
        foreach ($autoloadName in $expectedAutoloads.Keys) {
            $expectedPath = $expectedAutoloads[$autoloadName]
            $uidPath = Join-Path $tempRoot ($expectedPath.Substring('res://'.Length) + '.uid')
            $acceptedValues = @($expectedPath)
            if (Test-Path -LiteralPath $uidPath -PathType Leaf) {
                $acceptedValues += (Get-Content -LiteralPath $uidPath -Raw).Trim()
            }
            $valuePattern = ($acceptedValues | ForEach-Object { [regex]::Escape($_) }) -join '|'
            $autoloadPattern = '(?m)^{0}="\*(?:{1})"$' -f [regex]::Escape($autoloadName), $valuePattern
            if ($enabledProject -notmatch $autoloadPattern) {
                throw "Plugin activation did not install the expected $autoloadName autoload path."
            }
            if ($enabledProject -notmatch "(?m)^editor/owned_autoloads/$autoloadName=true$") {
                throw "Plugin activation did not record ownership for the $autoloadName autoload."
            }
        }

        $runtimeResult = Invoke-ProcessWithTimeout -FilePath $GodotBin -ArgumentList @(
            '--headless', '--verbose', '--path', $tempRoot, '--scene', 'res://RuntimeSmoke.tscn', '--quit-after', '120'
        ) -TimeoutSeconds 120
        Assert-GodotOutputHasNoErrors -Result $runtimeResult -Context 'Clean-project runtime smoke test'
        if ($runtimeResult.ExitCode -ne 0) {
            throw "The addon failed its clean-project runtime smoke test (exit $($runtimeResult.ExitCode))."
        }

        $runtimeLines = @($runtimeResult.Output -split '\r?\n')
        $leakedInstances = @($runtimeLines | Where-Object { $_ -match 'Leaked instance:' })
        $objectDbWarnings = @($runtimeLines | Where-Object { $_ -match 'ObjectDB instance(?:s)? (?:was|were) leaked' })
        if ($leakedInstances.Count -gt 0 -or $objectDbWarnings.Count -gt 0) {
            $knownThreadedLoaderLeak = $leakedInstances.Count -ge 1 -and
                $leakedInstances.Count -le 4 -and
                @($leakedInstances | Where-Object { $_ -notmatch 'Leaked instance: RefCounted:.*Reference count: 0' }).Count -eq 0 -and
                $objectDbWarnings.Count -eq 1
            if ($AllowKnownGodotThreadedLoaderLeak -and $knownThreadedLoaderLeak) {
                Write-Warning 'Godot 4.7 reported the known threaded ResourceLoader LoadToken leak during clean-install smoke testing.'
            }
            else {
                throw 'The clean-project runtime smoke test leaked ObjectDB instances.'
            }
        }

        $uninstallDriverDirectory = Join-Path $tempRoot 'addons/uninstall_driver'
        New-Item -ItemType Directory -Path $uninstallDriverDirectory -Force | Out-Null
        $uninstallDriverConfig = @'
[plugin]

name="Manifest UI Uninstall Driver"
description="Temporary clean-install test driver."
author="maplewen"
version="1.0.0"
script="uninstall_driver.gd"
'@
        Set-Content -LiteralPath (Join-Path $uninstallDriverDirectory 'plugin.cfg') -Value $uninstallDriverConfig -Encoding utf8 -NoNewline
        $uninstallDriver = @'
@tool
extends EditorPlugin

func _enter_tree() -> void:
	call_deferred("_disable_manifest_ui")

func _disable_manifest_ui() -> void:
	for _frame in range(12):
		await get_tree().process_frame
	EditorInterface.set_plugin_enabled("manifest_ui", false)
	ProjectSettings.save()
'@
        Set-Content -LiteralPath (Join-Path $uninstallDriverDirectory 'uninstall_driver.gd') -Value $uninstallDriver -Encoding utf8 -NoNewline

        $uninstallProject = $enabledProject -replace
            '(?m)^enabled=PackedStringArray\(.+\)$',
            'enabled=PackedStringArray("res://addons/manifest_ui/plugin.cfg", "res://addons/uninstall_driver/plugin.cfg")'
        Set-Content -LiteralPath (Join-Path $tempRoot 'project.godot') -Value $uninstallProject -Encoding utf8 -NoNewline

        $uninstallResult = Invoke-ProcessWithTimeout -FilePath $GodotBin -ArgumentList @(
            '--headless', '--path', $tempRoot, '--editor', '--quit-after', '60'
        ) -TimeoutSeconds 90
        Assert-GodotOutputHasNoErrors -Result $uninstallResult -Context 'Plugin uninstall'
        if ($uninstallResult.ExitCode -ne 0) {
            throw "Godot failed to disable the addon during clean-project uninstall testing (exit $($uninstallResult.ExitCode))."
        }

        $uninstalledProject = Get-Content -LiteralPath (Join-Path $tempRoot 'project.godot') -Raw
        foreach ($autoloadName in $expectedAutoloads.Keys) {
            if ($uninstalledProject -match "(?m)^$([regex]::Escape($autoloadName))=") {
                throw "Plugin uninstall left the $autoloadName autoload configured."
            }
            if ($uninstalledProject -match "(?m)^editor/owned_autoloads/$([regex]::Escape($autoloadName))=") {
                throw "Plugin uninstall left the $autoloadName ownership marker configured."
            }
        }
    }

    Write-Host "Clean addon install OK: $resolvedPackage"
}
finally {
    $resolvedTempRoot = [System.IO.Path]::GetFullPath($tempRoot)
    if ($KeepTemp -and (Test-Path -LiteralPath $resolvedTempRoot)) {
        Write-Warning "Retained clean-install test project: $resolvedTempRoot"
    }
    elseif ($resolvedTempRoot.StartsWith($tempBase, [System.StringComparison]::OrdinalIgnoreCase) -and (Test-Path -LiteralPath $resolvedTempRoot)) {
        Remove-Item -LiteralPath $resolvedTempRoot -Recurse -Force
    }
}
