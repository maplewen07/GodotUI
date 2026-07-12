[CmdletBinding()]
param(
    [string]$OutputDirectory = 'artifacts/release/liquid-glass',
    [switch]$SkipExample,
    [switch]$Release
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$repoRoot = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
$repoPrefix = $repoRoot.TrimEnd([System.IO.Path]::DirectorySeparatorChar) + [System.IO.Path]::DirectorySeparatorChar
$metadata = Get-Content -LiteralPath (Join-Path $repoRoot 'liquid-glass-version.json') -Raw | ConvertFrom-Json
$version = [string]$metadata.version

if ($Release) {
    $workingTreeChanges = @(& git -C $repoRoot status --porcelain=v1 --untracked-files=all)
    if ($LASTEXITCODE -ne 0) {
        throw 'git status failed before formal Liquid Glass packaging.'
    }
    if ($workingTreeChanges.Count -gt 0) {
        throw 'Formal Liquid Glass packaging requires a clean worktree; untracked or modified files are not allowed.'
    }
}

if ([System.IO.Path]::IsPathRooted($OutputDirectory)) {
    $outputPath = [System.IO.Path]::GetFullPath($OutputDirectory)
}
else {
    $outputPath = [System.IO.Path]::GetFullPath((Join-Path $repoRoot $OutputDirectory))
}
if (-not $outputPath.StartsWith($repoPrefix, [System.StringComparison]::OrdinalIgnoreCase)) {
    throw "Release output must stay inside the repository: $outputPath"
}
if (Test-Path -LiteralPath $outputPath) {
    Remove-Item -LiteralPath $outputPath -Recurse -Force
}
New-Item -ItemType Directory -Path $outputPath -Force | Out-Null

function Get-PublishableFiles {
    param(
        [Parameter(Mandatory)] [string]$Subtree,
        [switch]$StripSubtree
    )

    $relativePaths = if ($Release) {
        @(& git -C $repoRoot ls-files --cached -- $Subtree)
    }
    else {
        @(& git -C $repoRoot ls-files --cached --others --exclude-standard -- $Subtree)
    }
    if ($LASTEXITCODE -ne 0) {
        throw "git ls-files failed for $Subtree."
    }
    $normalizedSubtree = $Subtree.TrimEnd('/', '\').Replace('\', '/') + '/'
    $files = foreach ($relativePathValue in ($relativePaths | Sort-Object -Unique)) {
        $relativePath = $relativePathValue.Replace('\', '/')
        if ($relativePath -match '(?i)(?:^|/)(?:bin|obj|\.godot)(?:/|$)|\.import$') {
            continue
        }
        $sourcePath = [System.IO.Path]::GetFullPath((Join-Path $repoRoot $relativePath))
        if (-not $sourcePath.StartsWith($repoPrefix, [System.StringComparison]::OrdinalIgnoreCase)) {
            throw "Publishable file escaped the repository: $relativePath"
        }
        if (Test-Path -LiteralPath $sourcePath -PathType Leaf) {
            $entry = if ($StripSubtree) { $relativePath.Substring($normalizedSubtree.Length) } else { $relativePath }
            [PSCustomObject]@{ Source = $sourcePath; Entry = $entry }
        }
    }
    return @($files)
}

function New-DeterministicZip {
    param(
        [Parameter(Mandatory)] [object[]]$Files,
        [Parameter(Mandatory)] [string]$Destination
    )
    if ($Files.Count -eq 0) {
        throw "Cannot create an empty archive: $Destination"
    }
    $duplicates = @($Files | Group-Object Entry | Where-Object Count -gt 1)
    if ($duplicates.Count -gt 0) {
        throw "Archive has duplicate entries: $($duplicates.Name -join ', ')"
    }

    Add-Type -AssemblyName System.IO.Compression
    $stream = [System.IO.File]::Open($Destination, [System.IO.FileMode]::CreateNew)
    try {
        $archive = [System.IO.Compression.ZipArchive]::new($stream, [System.IO.Compression.ZipArchiveMode]::Create, $false)
        try {
            foreach ($file in ($Files | Sort-Object Entry)) {
                $entry = $archive.CreateEntry($file.Entry, [System.IO.Compression.CompressionLevel]::Optimal)
                $entry.LastWriteTime = [System.DateTimeOffset]::new(2000, 1, 1, 0, 0, 0, [System.TimeSpan]::Zero)
                $input = [System.IO.File]::OpenRead($file.Source)
                try {
                    $output = $entry.Open()
                    try { $input.CopyTo($output) } finally { $output.Dispose() }
                }
                finally { $input.Dispose() }
            }
        }
        finally { $archive.Dispose() }
    }
    finally { $stream.Dispose() }
}

if ($Release) {
    & (Join-Path $PSScriptRoot 'LiquidGlass-Test-ReleaseMetadata.ps1') -Release
}
else {
    & (Join-Path $PSScriptRoot 'LiquidGlass-Test-ReleaseMetadata.ps1')
}

$addonFiles = @(Get-PublishableFiles -Subtree 'addons/liquid_glass')
$addonArchive = Join-Path $outputPath "liquid-glass-$version.zip"
New-DeterministicZip -Files $addonFiles -Destination $addonArchive
if ((Get-Item -LiteralPath $addonArchive).Length -ge 2MB) {
    throw 'Liquid Glass addon ZIP must remain below 2 MiB.'
}

$artifacts = [System.Collections.Generic.List[string]]::new()
$artifacts.Add($addonArchive)
if (-not $SkipExample) {
    $exampleFiles = @(Get-PublishableFiles -Subtree 'examples/LiquidGlass' -StripSubtree)
    if ($exampleFiles.Count -eq 0) {
        throw 'Liquid Glass example files are missing.'
    }
    $exampleArchive = Join-Path $outputPath "liquid-glass-example-$version.zip"
    New-DeterministicZip -Files @($exampleFiles + $addonFiles) -Destination $exampleArchive
    $artifacts.Add($exampleArchive)
}

$checksumLines = foreach ($artifact in ($artifacts | Sort-Object)) {
    $hash = (Get-FileHash -LiteralPath $artifact -Algorithm SHA256).Hash.ToLowerInvariant()
    "$hash  $([System.IO.Path]::GetFileName($artifact))"
}
$checksumPath = Join-Path $outputPath 'SHA256SUMS.txt'
Set-Content -LiteralPath $checksumPath -Value ($checksumLines -join "`n") -Encoding utf8 -NoNewline

Write-Host "Liquid Glass release artifacts created in $outputPath"
Get-ChildItem -LiteralPath $outputPath -File | Sort-Object Name | ForEach-Object {
    Write-Host ("  {0} ({1} bytes)" -f $_.Name, $_.Length)
}
