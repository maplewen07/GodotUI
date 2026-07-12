[CmdletBinding()]
param(
    [string]$Tag,
    [switch]$Release
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))

function Require-Condition {
    param(
        [bool]$Condition,
        [string]$Message
    )

    if (-not $Condition) {
        throw $Message
    }
}

function Read-Text {
    param([string]$RelativePath)

    $path = Join-Path $repoRoot $RelativePath
    Require-Condition (Test-Path -LiteralPath $path -PathType Leaf) "Missing required file: $RelativePath"
    return Get-Content -LiteralPath $path -Raw
}

$metadata = Read-Text 'manifest-ui-version.json' | ConvertFrom-Json
$version = [string]$metadata.version
$semVerPattern = '^(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)(?:-[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*)?(?:\+[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*)?$'
Require-Condition ($version -match $semVerPattern) "Invalid semantic version in manifest-ui-version.json: $version"
Require-Condition ([string]$metadata.tagPrefix -eq 'manifest-ui-v') 'Manifest UI tagPrefix must be manifest-ui-v.'
Require-Condition ([string]$metadata.godotVersion -eq '4.7.0') 'Manifest UI requires Godot 4.7.0.'
Require-Condition ([string]$metadata.dotnetTargetFramework -eq 'net8.0') 'Manifest UI requires net8.0.'

$expectedTag = "$($metadata.tagPrefix)$version"
if ($Tag) {
    Require-Condition ($Tag -eq $expectedTag) "Tag '$Tag' does not match version '$expectedTag'."
}

$isPrerelease = $version.Contains('-')
$releaseChannel = [string]$metadata.releaseChannel
if ($isPrerelease) {
    Require-Condition ($releaseChannel -in @('alpha', 'beta', 'rc')) 'A prerelease version must use the alpha, beta, or rc releaseChannel.'
    Require-Condition ($version -match "-$releaseChannel(?:[.-]|$)") "Version '$version' does not match releaseChannel '$releaseChannel'."
}
else {
    Require-Condition ($releaseChannel -eq 'stable') 'A version without a prerelease suffix must use releaseChannel stable.'
}

$plugin = Read-Text 'addons/manifest_ui/plugin.cfg'
$pluginVersionPattern = '(?m)^version="{0}"$' -f [regex]::Escape($version)
Require-Condition ($plugin -match $pluginVersionPattern) 'plugin.cfg version does not match release metadata.'
Require-Condition ($plugin -match '(?m)^author="maplewen"$') 'plugin.cfg author must be maplewen.'
Require-Condition ($plugin -match '(?m)^script="editor/manifest_ui_editor_plugin\.gd"$') 'plugin.cfg must use the runtime-safe GDScript editor shim.'

$editorShim = Read-Text 'addons/manifest_ui/editor/manifest_ui_editor_plugin.gd'
Require-Condition ($editorShim -match 'ManifestUiDock\.cs') 'The GDScript editor shim must load the C# dock directly.'
Require-Condition ($editorShim -match 'request_run_preview') 'The GDScript editor shim must own the delayed Run Preview launch boundary.'
Require-Condition (-not (Test-Path -LiteralPath (Join-Path $repoRoot 'addons/manifest_ui/editor/ManifestUiEditorPlugin.cs'))) 'The addon must not compile a C# EditorPlugin into the game assembly.'
$editorCsFiles = @(Get-ChildItem -LiteralPath (Join-Path $repoRoot 'addons/manifest_ui/editor') -Filter '*.cs' -File)
foreach ($editorCsFile in $editorCsFiles) {
    $editorCs = Get-Content -LiteralPath $editorCsFile.FullName -Raw
    Require-Condition ($editorCs -notmatch '\bEditorPlugin\b') "Editor source '$($editorCsFile.Name)' references EditorPlugin and can break runtime assembly loading."
    $managedGodotSignalPattern = '\.(Pressed|ItemSelected|Confirmed|Canceled|CloseRequested|TextChanged|Toggled|ValueChanged|TabChanged)\s*\+='
    Require-Condition ($editorCs -notmatch $managedGodotSignalPattern) "Editor source '$($editorCsFile.Name)' uses a managed Godot signal delegate and can block assembly unloading. Use an object-method Callable instead."
    Require-Condition ($editorCs -notmatch '\bCallable\.From\s*\(') "Editor source '$($editorCsFile.Name)' uses Callable.From and can block assembly unloading. Use an object-method Callable instead."
}
$editorDock = Read-Text 'addons/manifest_ui/editor/ManifestUiDock.cs'
Require-Condition ($editorDock -notmatch 'ManifestUiTool\.Execute\s*\(') 'The editor dock must not execute tooling inside Godot collectible AssemblyLoadContext.'
Require-Condition ($editorDock -match 'ManifestUi\.EditorHost\.csproj') 'The editor dock must use the isolated addon tooling host.'
Require-Condition (Test-Path -LiteralPath (Join-Path $repoRoot 'addons/manifest_ui/tooling/host/ManifestUi.EditorHost.csproj')) 'The isolated editor tooling host project is missing.'
Require-Condition (Test-Path -LiteralPath (Join-Path $repoRoot 'addons/manifest_ui/tooling/host/Program.cs.txt')) 'The isolated editor tooling host entry point is missing.'

$project = Read-Text 'project.godot'
$projectVersionPattern = '(?m)^config/version="{0}"$' -f [regex]::Escape($version)
Require-Condition ($project -match $projectVersionPattern) 'project.godot version does not match release metadata.'
Require-Condition ($project -match '(?m)^config/features=PackedStringArray\("4\.7", "C#"') 'project.godot must target Godot 4.7 C#.'

[xml]$godotProject = Read-Text 'GodotUI.csproj'
Require-Condition ([string]$godotProject.Project.Sdk -eq 'Godot.NET.Sdk/4.7.0') 'GodotUI.csproj must use Godot.NET.Sdk/4.7.0.'
Require-Condition ([string]$godotProject.Project.PropertyGroup.TargetFramework -eq 'net8.0') 'GodotUI.csproj must target net8.0.'

[xml]$buildProps = Read-Text 'Directory.Build.props'
Require-Condition ([string]$buildProps.Project.PropertyGroup.ManifestUiVersion -eq $version) 'Directory.Build.props version does not match release metadata.'

$tooling = Read-Text 'addons/manifest_ui/tooling/ManifestUiTool.cs'
$toolVersionPattern = 'public const string ToolVersion = "{0}";' -f [regex]::Escape($version)
Require-Condition ($tooling -match $toolVersionPattern) 'ManifestUiTool.ToolVersion does not match release metadata.'

$skillVersion = (Read-Text 'addons/manifest_ui/codex_skill/godot-manifest-ui/VERSION').Trim()
Require-Condition ($skillVersion -eq $version) 'The bundled Codex Skill VERSION does not match release metadata.'

$global = Read-Text 'global.json' | ConvertFrom-Json
Require-Condition ([string]$global.sdk.version -match '^8\.0\.') 'global.json must pin a .NET 8 SDK.'

$changelog = Read-Text 'CHANGELOG.md'
Require-Condition ($changelog.Contains("## [$version]")) "CHANGELOG.md has no entry for $version."
Require-Condition (Test-Path -LiteralPath (Join-Path $repoRoot 'LICENSE') -PathType Leaf) 'Root MIT LICENSE is missing.'
Require-Condition (Test-Path -LiteralPath (Join-Path $repoRoot 'addons/manifest_ui/LICENSE') -PathType Leaf) 'Addon MIT LICENSE is missing.'
Require-Condition (Test-Path -LiteralPath (Join-Path $repoRoot 'addons/manifest_ui/THIRD_PARTY_NOTICES.md') -PathType Leaf) 'Addon third-party notices are missing.'

$forbiddenTracked = @(& git -C $repoRoot ls-files -- 'CBLiquidGlass' 'Me')
Require-Condition ($LASTEXITCODE -eq 0) 'git ls-files failed while checking release exclusions.'
Require-Condition ($forbiddenTracked.Count -eq 0) 'CBLiquidGlass or Me contains tracked files and cannot be released.'

$forbiddenHistory = @(& git -C $repoRoot log --all --format= --name-only -- 'CBLiquidGlass' 'Me' |
    Where-Object { -not [string]::IsNullOrWhiteSpace($_) } |
    Sort-Object -Unique)
Require-Condition ($LASTEXITCODE -eq 0) 'git log failed while checking release history.'
Require-Condition ($forbiddenHistory.Count -eq 0) 'CBLiquidGlass or Me exists in Git history; publish from a new clean repository.'

$repositoryTextFiles = @(& git -C $repoRoot ls-files --cached --others --exclude-standard |
    Where-Object { [System.IO.Path]::GetExtension($_) -in @('.cs', '.csproj', '.cfg', '.gd', '.gdshader', '.json', '.md', '.props', '.ps1', '.py', '.tscn', '.tres', '.yaml', '.yml') })
Require-Condition ($LASTEXITCODE -eq 0) 'git ls-files failed while checking development paths.'
foreach ($relativePath in $repositoryTextFiles) {
    $fullPath = Join-Path $repoRoot $relativePath
    if (-not (Test-Path -LiteralPath $fullPath -PathType Leaf)) {
        continue
    }
    $content = Get-Content -LiteralPath $fullPath -Raw
    Require-Condition ($content -notmatch '(?i)(?:[A-Z]:\\(?:Godot|Github|Users)|/(?:Users|home)/[^/\s]+/)') "Repository file '$relativePath' contains a machine-specific absolute path."
}

if ($Release) {
    $cliProject = Join-Path $repoRoot 'tools/ManifestUi.Cli/ManifestUi.Cli.csproj'
    Require-Condition (Test-Path -LiteralPath $cliProject -PathType Leaf) 'Release requires tools/ManifestUi.Cli/ManifestUi.Cli.csproj.'

    $exampleFiles = @(& git -C $repoRoot ls-files --cached --others --exclude-standard -- 'examples')
    Require-Condition ($LASTEXITCODE -eq 0) 'git ls-files failed while checking examples.'
    Require-Condition ($exampleFiles.Count -gt 0) 'Release requires at least one publishable file under examples/.'

    $addonFiles = @(& git -C $repoRoot ls-files --cached --others --exclude-standard -- 'addons/manifest_ui')
    Require-Condition ($LASTEXITCODE -eq 0) 'git ls-files failed while checking the addon boundary.'
    foreach ($relativePath in $addonFiles) {
        $fullPath = Join-Path $repoRoot $relativePath
        if (-not (Test-Path -LiteralPath $fullPath -PathType Leaf)) {
            continue
        }

        $textExtensions = @('.cs', '.cfg', '.json', '.md', '.tscn', '.tres')
        if ([System.IO.Path]::GetExtension($fullPath) -notin $textExtensions) {
            continue
        }

        $content = Get-Content -LiteralPath $fullPath -Raw
        $referencesRepositorySource = $content -match 'res://(?:tools|tests|examples|demo|src)/' -or
            $content -match 'tools[\\/](?:ManifestUi\.Cli|ManifestUiGen)'
        if ($referencesRepositorySource) {
            throw "Addon file '$relativePath' references source outside addons/manifest_ui/."
        }
    }
}

Write-Host "Release metadata OK: Manifest UI $version ($releaseChannel)"
