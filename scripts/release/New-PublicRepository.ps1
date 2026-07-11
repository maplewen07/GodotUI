[CmdletBinding()]
param(
    [string]$DestinationPath,
    [switch]$SkipGitInitialization
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$sourceRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
if ([string]::IsNullOrWhiteSpace($DestinationPath)) {
    $DestinationPath = Join-Path (Split-Path -Parent $sourceRoot) 'GodotUI-public'
}
$destinationRoot = [System.IO.Path]::GetFullPath($DestinationPath)
if ($destinationRoot.Equals($sourceRoot, [StringComparison]::OrdinalIgnoreCase)) {
    throw 'The public repository destination must differ from the source repository.'
}
if (Test-Path -LiteralPath $destinationRoot) {
    throw "The public repository destination already exists: $destinationRoot"
}

$rootFiles = @(
    '.gitattributes',
    '.gitignore',
    'CHANGELOG.md',
    'CONTRIBUTING.md',
    'Directory.Build.props',
    'global.json',
    'GodotUI.csproj',
    'LICENSE',
    'liquid-glass-version.json',
    'manifest-ui-version.json',
    'project.godot',
    'README.md',
    'SECURITY.md',
    'THIRD_PARTY_NOTICES.md'
)
$subtrees = @(
    '.github',
    'addons/manifest_ui',
    'addons/liquid_glass',
    'demo',
    'docs',
    'examples',
    'generated',
    'schemas/manifest-ui',
    'scripts',
    'src',
    'tests',
    'tools/ManifestUi.Cli',
    'ui'
)

$pathspecs = @($rootFiles + $subtrees)
$relativePaths = @(& git -C $sourceRoot ls-files --cached --others --exclude-standard -- @pathspecs)
if ($LASTEXITCODE -ne 0) {
    throw 'git ls-files failed while collecting the public repository boundary.'
}

$forbiddenPatterns = @(
    '^(?:CBLiquidGlass|Me)(?:/|$)',
    '^(?:artifacts|\.godot|\.mono)(?:/|$)',
    '(?:^|/)(?:bin|obj|Intermediate|Binaries|Saved)(?:/|$)',
    '^ui/[^/]+/(?:export|schemas)(?:/|$)',
    '\.(?:uasset|umap|pdb|dll|lib|exp|obj|sarif|rsp|import)$'
)

$publishable = @($relativePaths |
    ForEach-Object { $_.Replace('\', '/') } |
    Where-Object {
        $relativePath = $_
        -not ($forbiddenPatterns | Where-Object { $relativePath -match $_ })
    } |
    Sort-Object -Unique)
if ($publishable.Count -eq 0) {
    throw 'The public repository boundary is empty.'
}

New-Item -ItemType Directory -Path $destinationRoot -Force | Out-Null
$sourcePrefix = $sourceRoot.TrimEnd([System.IO.Path]::DirectorySeparatorChar) + [System.IO.Path]::DirectorySeparatorChar
$destinationPrefix = $destinationRoot.TrimEnd([System.IO.Path]::DirectorySeparatorChar) + [System.IO.Path]::DirectorySeparatorChar
foreach ($relativePath in $publishable) {
    $sourcePath = [System.IO.Path]::GetFullPath((Join-Path $sourceRoot $relativePath))
    if (-not $sourcePath.StartsWith($sourcePrefix, [StringComparison]::OrdinalIgnoreCase) -or -not (Test-Path -LiteralPath $sourcePath -PathType Leaf)) {
        continue
    }
    $destination = [System.IO.Path]::GetFullPath((Join-Path $destinationRoot $relativePath))
    if (-not $destination.StartsWith($destinationPrefix, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Publishable path escaped the destination: $relativePath"
    }
    $parent = Split-Path -Parent $destination
    New-Item -ItemType Directory -Path $parent -Force | Out-Null
    Copy-Item -LiteralPath $sourcePath -Destination $destination
}

$forbiddenFiles = @(Get-ChildItem -LiteralPath $destinationRoot -File -Recurse | Where-Object {
    $relativePath = [System.IO.Path]::GetRelativePath($destinationRoot, $_.FullName).Replace('\', '/')
    $forbiddenPatterns | Where-Object { $relativePath -match $_ }
})
if ($forbiddenFiles.Count -gt 0) {
    throw "Forbidden files entered the public repository: $($forbiddenFiles.FullName -join ', ')"
}

if (-not $SkipGitInitialization) {
    & git -C $destinationRoot init --initial-branch=main
    if ($LASTEXITCODE -ne 0) {
        throw 'git init failed for the public repository.'
    }
}

Write-Host "Public repository candidate created: $destinationRoot"
Write-Host "Copied $($publishable.Count) allowlisted files without the source .git history."
