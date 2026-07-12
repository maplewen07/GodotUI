[CmdletBinding()]
param(
    [string]$Tag,
    [switch]$Release
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))

function Require-Condition {
    param([bool]$Condition, [string]$Message)
    if (-not $Condition) {
        throw $Message
    }
}

function Read-RepositoryText {
    param([string]$RelativePath)
    $path = Join-Path $repoRoot $RelativePath
    Require-Condition (Test-Path -LiteralPath $path -PathType Leaf) "Missing required file: $RelativePath"
    return Get-Content -LiteralPath $path -Raw
}

$metadata = Read-RepositoryText 'liquid-glass-version.json' | ConvertFrom-Json
$version = [string]$metadata.version
$semVerPattern = '^(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)(?:-[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*)?(?:\+[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*)?$'
Require-Condition ($version -match $semVerPattern) "Invalid semantic version in liquid-glass-version.json: $version"
Require-Condition ([string]$metadata.tagPrefix -eq 'liquid-glass-v') 'Liquid Glass tagPrefix must be liquid-glass-v.'
Require-Condition ([string]$metadata.godotVersion -eq '4.7.0') 'Liquid Glass requires Godot 4.7.0.'
Require-Condition ([string]$metadata.dotnetTargetFramework -eq 'net8.0') 'Liquid Glass requires net8.0.'
Require-Condition ([string]$metadata.implementation -eq 'clean-room') 'Liquid Glass implementation metadata must be clean-room.'

$expectedTag = "$($metadata.tagPrefix)$version"
if ($Tag) {
    Require-Condition ($Tag -eq $expectedTag) "Tag '$Tag' does not match '$expectedTag'."
}

$isPrerelease = $version.Contains('-')
$releaseChannel = [string]$metadata.releaseChannel
if ($isPrerelease) {
    Require-Condition ($releaseChannel -in @('alpha', 'beta', 'rc')) 'A prerelease must use alpha, beta, or rc releaseChannel.'
    Require-Condition ($version -match "-$releaseChannel(?:[.-]|$)") "Version '$version' does not match releaseChannel '$releaseChannel'."
}
else {
    Require-Condition ($releaseChannel -eq 'stable') 'A stable version must use releaseChannel stable.'
}

$plugin = Read-RepositoryText 'addons/liquid_glass/plugin.cfg'
Require-Condition ($plugin -match ('(?m)^version="{0}"$' -f [regex]::Escape($version))) 'Liquid Glass plugin.cfg version does not match release metadata.'
Require-Condition ($plugin -match '(?m)^author="maplewen"$') 'Liquid Glass plugin author must be maplewen.'
Require-Condition ($plugin -match '(?m)^script="editor/liquid_glass_editor_plugin\.gd"$') 'Liquid Glass plugin must use its GDScript editor registration shim.'

$requiredAddonFiles = @(
    'addons/liquid_glass/LICENSE',
    'addons/liquid_glass/README.md',
    'addons/liquid_glass/CHANGELOG.md',
    'addons/liquid_glass/THIRD_PARTY_NOTICES.md',
    'addons/liquid_glass/PROVENANCE.md',
    'addons/liquid_glass/BEHAVIOR_SPEC.md',
    'addons/liquid_glass/shaders/liquid_glass.gdshader'
)
foreach ($requiredFile in $requiredAddonFiles) {
    [void](Read-RepositoryText $requiredFile)
}

$changelog = Read-RepositoryText 'addons/liquid_glass/CHANGELOG.md'
Require-Condition ($changelog.Contains("## [$version]")) "Liquid Glass CHANGELOG has no entry for $version."
$provenance = Read-RepositoryText 'addons/liquid_glass/PROVENANCE.md'
Require-Condition ($provenance -match '(?i)clean-room') 'Liquid Glass provenance does not record the clean-room boundary.'

[xml]$compileProject = Read-RepositoryText 'tests/LiquidGlass.Compile.csproj'
Require-Condition ([string]$compileProject.Project.Sdk -eq 'Godot.NET.Sdk/4.7.0') 'Liquid Glass compile test must use Godot.NET.Sdk/4.7.0.'
Require-Condition ([string]$compileProject.Project.PropertyGroup.TargetFramework -eq 'net8.0') 'Liquid Glass compile test must target net8.0.'

$global = Read-RepositoryText 'global.json' | ConvertFrom-Json
Require-Condition ([string]$global.sdk.version -match '^8\.0\.') 'global.json must pin a .NET 8 SDK.'

$publishableAddonFiles = @(& git -C $repoRoot ls-files --cached --others --exclude-standard -- 'addons/liquid_glass')
Require-Condition ($LASTEXITCODE -eq 0) 'git ls-files failed while checking Liquid Glass.'
Require-Condition ($publishableAddonFiles.Count -gt 0) 'No publishable Liquid Glass addon files were found.'
foreach ($relativePath in $publishableAddonFiles) {
    $fullPath = Join-Path $repoRoot $relativePath
    if (-not (Test-Path -LiteralPath $fullPath -PathType Leaf)) {
        continue
    }
    if ($relativePath -match '(?i)(?:^|/)(?:bin|obj|\.godot)(?:/|$)|\.import$') {
        continue
    }
    if ([System.IO.Path]::GetExtension($fullPath) -in @('.cs', '.cfg', '.gd', '.gdshader', '.json', '.md', '.tscn', '.tres')) {
        $content = Get-Content -LiteralPath $fullPath -Raw
        Require-Condition ($content -notmatch '(?i)res://addons/manifest_ui|GodotUi\.Manifest') "Addon file '$relativePath' creates a Manifest UI dependency."
        Require-Condition ($content -notmatch '(?i)[A-Z]:\\Godot|[A-Z]:\\Github') "Addon file '$relativePath' contains an absolute development path."
    }
}

if ($Release) {
    $forbiddenIndexPaths = @(& git -C $repoRoot ls-files -- 'CBLiquidGlass' 'Me' |
        Where-Object { $_ -match '^(?:CBLiquidGlass|Me)(?:[\\/]|$)' })
    Require-Condition ($LASTEXITCODE -eq 0) 'git ls-files failed while checking the clean-room index boundary.'
    Require-Condition ($forbiddenIndexPaths.Count -eq 0) 'Formal Liquid Glass release is blocked because CBLiquidGlass or Me paths exist in the Git index.'

    $forbiddenHistoryPaths = @(& git -C $repoRoot log --all --name-only --format= -- 'CBLiquidGlass' 'Me' |
        Where-Object { $_ -match '^(?:CBLiquidGlass|Me)(?:[\\/]|$)' } |
        Sort-Object -Unique)
    Require-Condition ($LASTEXITCODE -eq 0) 'git log failed while checking the clean-room history boundary.'
    Require-Condition ($forbiddenHistoryPaths.Count -eq 0) 'Formal Liquid Glass release is blocked because CBLiquidGlass or Me paths exist in reachable Git history. Publish only from the sanitized repository with a new .git history.'

    $exampleProject = Join-Path $repoRoot 'examples/LiquidGlass/project.godot'
    Require-Condition (Test-Path -LiteralPath $exampleProject -PathType Leaf) 'Liquid Glass release requires its original example.'
    $workflow = Join-Path $repoRoot '.github/workflows/liquid-glass-release.yml'
    Require-Condition (Test-Path -LiteralPath $workflow -PathType Leaf) 'Liquid Glass release workflow is missing.'
    $ciWorkflow = Join-Path $repoRoot '.github/workflows/liquid-glass-ci.yml'
    Require-Condition (Test-Path -LiteralPath $ciWorkflow -PathType Leaf) 'Liquid Glass independent CI workflow is missing.'
}

Write-Host "Release metadata OK: Liquid Glass $version ($releaseChannel)"
