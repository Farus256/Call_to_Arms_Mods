param(
    [Parameter(Mandatory=$true)][string]$Package,
    [string]$TargetResource = 'D:\Programs\Steam\steamapps\common\Call to Arms - Gates of Hell\mods\ultimate_frontline_bundle\resource',
    [switch]$Apply,
    [string]$RollbackBackup
)
$ErrorActionPreference = 'Stop'
function Resolve-Child([string]$Root, [string]$Relative) {
    $base = [IO.Path]::GetFullPath($Root).TrimEnd('\','/')
    $full = [IO.Path]::GetFullPath((Join-Path $base $Relative))
    if (!$full.StartsWith($base + '\', [StringComparison]::OrdinalIgnoreCase)) { throw "Path outside target: $Relative" }
    return $full
}
function Get-HashOrNull([string]$File) {
    if (Test-Path -LiteralPath $File -PathType Leaf) { return (Get-FileHash -LiteralPath $File -Algorithm SHA256).Hash.ToLowerInvariant() }
    if (Test-Path -LiteralPath $File) { throw "Expected a file: $File" }
    return $null
}
$packageRoot = (Resolve-Path -LiteralPath $Package).Path
$manifest = Get-Content -LiteralPath (Join-Path $packageRoot 'manifest.json') -Raw -Encoding UTF8 | ConvertFrom-Json
$targetRoot = [IO.Path]::GetFullPath($TargetResource)
if ($Apply -and (Get-Process -Name 'call_to_arms','call_to_arms_ed' -ErrorAction SilentlyContinue)) { throw 'Close the game/editor before applying or rolling back resources.' }
if ($RollbackBackup) {
    $backupRoot = (Resolve-Path -LiteralPath $RollbackBackup).Path
    $saved = Get-Content -LiteralPath (Join-Path $backupRoot 'rollback.json') -Raw -Encoding UTF8 | ConvertFrom-Json
    if ($saved.target -ne $targetRoot) { throw 'Backup belongs to another target resource folder.' }
    foreach ($entry in $saved.files) {
        $dest = Resolve-Child $targetRoot $entry.file
        $current = Get-HashOrNull $dest
        if ($current -ne $entry.beforeSHA256 -and $current -ne $entry.afterSHA256) { throw "Changed since installation: $($entry.file)" }
        if ($entry.beforeSHA256) {
            $copy = Resolve-Child (Join-Path $backupRoot 'before') $entry.file
            if ((Get-HashOrNull $copy) -ne $entry.beforeSHA256) { throw "Invalid backup: $($entry.file)" }
        }
    }
    if (!$Apply) { Write-Output "Rollback preflight passed: $($saved.files.Count) files. Add -Apply to restore."; return }
    foreach ($entry in $saved.files) {
        $dest = Resolve-Child $targetRoot $entry.file
        if ((Get-HashOrNull $dest) -eq $entry.beforeSHA256) { continue }
        if ($entry.beforeSHA256) {
            Copy-Item -LiteralPath (Resolve-Child (Join-Path $backupRoot 'before') $entry.file) -Destination $dest -Force
        } else {
            # Only the exact new file verified above; never delete a directory tree.
            Remove-Item -LiteralPath $dest
        }
    }
    Write-Output 'Rollback completed. Empty directories are retained.'
    return
}
$changes = @()
foreach ($entry in $manifest.files) {
    $source = Resolve-Child (Join-Path $packageRoot 'resource') $entry.file
    $dest = Resolve-Child $targetRoot $entry.file
    if ((Get-HashOrNull $source) -ne $entry.afterSHA256) { throw "Package content changed: $($entry.file)" }
    $current = Get-HashOrNull $dest
    if ($current -eq $entry.afterSHA256) { continue }
    if ($current -ne $entry.beforeSHA256) { throw "Target differs from reviewed baseline; merge first: $($entry.file)" }
    $changes += $entry
}
if (!$Apply) { Write-Output "Preflight passed: $($changes.Count) files to update; nothing written. Add -Apply to install."; return }
if (!$changes.Count) { Write-Output 'Package already installed.'; return }
$backupRoot = Join-Path $packageRoot ('backups\' + [DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss-fffffff'))
[IO.Directory]::CreateDirectory($backupRoot) | Out-Null
# Save every old file before changing the first destination.
foreach ($entry in $changes) {
    if ($entry.beforeSHA256) {
        $copy = Resolve-Child (Join-Path $backupRoot 'before') $entry.file
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($copy)) | Out-Null
        Copy-Item -LiteralPath (Resolve-Child $targetRoot $entry.file) -Destination $copy
        if ((Get-HashOrNull $copy) -ne $entry.beforeSHA256) { throw "Backup mismatch: $($entry.file)" }
    }
}
@{target=$targetRoot; files=@($changes)} | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath (Join-Path $backupRoot 'rollback.json') -Encoding UTF8
foreach ($entry in $changes) {
    $dest = Resolve-Child $targetRoot $entry.file
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($dest)) | Out-Null
    Copy-Item -LiteralPath (Resolve-Child (Join-Path $packageRoot 'resource') $entry.file) -Destination $dest -Force
    if ((Get-HashOrNull $dest) -ne $entry.afterSHA256) { throw "Copy verification failed: $($entry.file). Backup: $backupRoot" }
}
Write-Output "Installed $($changes.Count) files. Backup: $backupRoot"
