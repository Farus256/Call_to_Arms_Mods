$ErrorActionPreference = 'Stop'
$workspace = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..\_survival_work'))
$fixture = Join-Path $workspace ('installer-test-' + [Guid]::NewGuid().ToString('N'))
$package = Join-Path $fixture 'package'
$target = Join-Path $fixture 'target'
foreach ($dir in @((Join-Path $package 'resource\nested'),$target)) { [IO.Directory]::CreateDirectory($dir) | Out-Null }
function Write-UTF8([string]$File,[string]$Value) { [IO.File]::WriteAllText($File,$Value,(New-Object Text.UTF8Encoding($false))) }
function SHA([string]$File) { (Get-FileHash -LiteralPath $File -Algorithm SHA256).Hash.ToLowerInvariant() }
function Check([bool]$Value,[string]$Message) { if (!$Value) { throw $Message } }
Write-UTF8 (Join-Path $target 'existing.set') 'original'
Write-UTF8 (Join-Path $package 'resource\existing.set') 'modified'
Write-UTF8 (Join-Path $package 'resource\nested\new.set') 'new'
$entries=@(
    @{file='existing.set';beforeSHA256=(SHA (Join-Path $target 'existing.set'));afterSHA256=(SHA (Join-Path $package 'resource\existing.set'))},
    @{file='nested/new.set';beforeSHA256=$null;afterSHA256=(SHA (Join-Path $package 'resource\nested\new.set'))}
)
@{files=$entries} | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $package 'manifest.json') -Encoding UTF8
$installer=Join-Path $PSScriptRoot 'Apply-TacticalPatch.ps1'
# The fixture is unrelated to a running game. Stub only the process check here.
function Get-Process { param($Name,$ErrorAction) return @() }
& $installer -Package $package -TargetResource $target
Check (([IO.File]::ReadAllText((Join-Path $target 'existing.set'))) -eq 'original') 'Dry run wrote data'
& $installer -Package $package -TargetResource $target -Apply
Check (([IO.File]::ReadAllText((Join-Path $target 'existing.set'))) -eq 'modified') 'Existing file not updated'
Check (Test-Path -LiteralPath (Join-Path $target 'nested\new.set')) 'New file absent'
& $installer -Package $package -TargetResource $target -Apply
$backups=@(Get-ChildItem -LiteralPath (Join-Path $package 'backups') -Directory)
Check ($backups.Count -eq 1) 'Idempotent install created another backup'
Write-UTF8 (Join-Path $target 'existing.set') 'user edit'
$rejected=$false
try { & $installer -Package $package -TargetResource $target -RollbackBackup $backups[0].FullName -Apply } catch { $rejected=$true }
Check $rejected 'Rollback overwrote a subsequent user edit'
Write-UTF8 (Join-Path $target 'existing.set') 'modified'
& $installer -Package $package -TargetResource $target -RollbackBackup $backups[0].FullName -Apply
Check (([IO.File]::ReadAllText((Join-Path $target 'existing.set'))) -eq 'original') 'Original not restored'
Check (!(Test-Path -LiteralPath (Join-Path $target 'nested\new.set'))) 'Introduced file not removed'
Write-UTF8 (Join-Path $target 'existing.set') 'user edit'
$rejected=$false
try { & $installer -Package $package -TargetResource $target -Apply } catch { $rejected=$true }
Check $rejected 'Install overwrote an unexpected baseline'
Check (!(Test-Path -LiteralPath (Join-Path $target 'nested\new.set'))) 'Conflict did not stop before writes'
@{files=@(@{file='../escape.set';beforeSHA256=$null;afterSHA256='invalid'})} | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $package 'manifest.json') -Encoding UTF8
$rejected=$false
try { & $installer -Package $package -TargetResource $target -Apply } catch { $rejected=$true }
Check $rejected 'Traversal was accepted'
Write-Output "Installer fixture passed: dry run, apply, repeat, rollback, conflicts, traversal. Retained at $fixture"
