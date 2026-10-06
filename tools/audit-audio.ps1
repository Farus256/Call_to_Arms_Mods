param([string]$Output = '../_survival_work/task-20261006/audio')
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.IO.Compression.FileSystem
$game = 'D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell'
$workspace = Split-Path (Split-Path $PSScriptRoot)
$roots = @("$game/resource")
foreach ($id in @('2562731625','3079405930','3139610501','3408719680','3540580405','2922646932','3196505779','3562631215','3359417100','3566110308','3791314577','3548575715')) {
    $roots += Join-Path $workspace "$id/resource"
}
$roots += Join-Path (Split-Path $PSScriptRoot) 'mods/ultimate_frontline_bundle/resource'
$vfs = @{}; $wobble = @{}
function Record-Audio($virtual, $origin) {
    $virtual = $virtual.ToLowerInvariant()
    if ($virtual -notmatch '^sound/') { return }
    $vfs[$virtual] = $origin
    if ($origin.root -match '3408719680') { $wobble[$virtual] = $origin }
}
foreach ($root in $roots) {
    if (!(Test-Path -LiteralPath $root)) { continue }
    $files = @(Get-ChildItem -LiteralPath $root -Recurse -File)
    foreach ($file in $files | Where-Object { $_.Extension -in '.pak','.pat' }) {
        $relative = $file.FullName.Substring($root.Length+1).Replace('\','/')
        $prefix = $relative.Substring(0,$relative.LastIndexOf('/')+1)
        $zip = [IO.Compression.ZipFile]::OpenRead($file.FullName)
        try { foreach ($entry in $zip.Entries) {
            if ($entry.Name -eq '') { continue }
            Record-Audio ($prefix+$entry.FullName.Replace('\','/')) @{root=$root; archive=$file.FullName; entry=$entry.FullName; length=$entry.Length}
        }} finally { $zip.Dispose() }
    }
    foreach ($file in $files | Where-Object { $_.Extension -notin '.pak','.pat' }) {
        Record-Audio ($file.FullName.Substring($root.Length+1).Replace('\','/')) @{root=$root; file=$file.FullName; length=$file.Length}
    }
}
$conflicts = @()
foreach ($virtual in $wobble.Keys) {
    $winner = $vfs[$virtual]
    if ($winner.root -ne $wobble[$virtual].root) { $conflicts += @{file=$virtual; original=$wobble[$virtual]; winner=$winner} }
}
$out = [IO.Path]::GetFullPath((Join-Path (Get-Location).Path $Output))
[IO.Directory]::CreateDirectory($out) | Out-Null
@{order=$roots; wobbleFiles=$wobble.Count; conflicts=$conflicts; effective=$vfs} | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath "$out/index.json" -Encoding utf8
Write-Output "Audio: $($vfs.Count) effective files; Wobble $($wobble.Count) files; $($conflicts.Count) paths overwritten by later mods."
$conflicts | Group-Object { $_.winner.root } | Select-Object Count,Name | Format-Table -AutoSize
