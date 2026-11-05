param(
 [string]$ResourceRoot=(Join-Path $PSScriptRoot '../mods/ultimate_frontline_bundle/resource'),
 [string]$Schema=(Join-Path $PSScriptRoot '../../_survival_work/mod-load-audit-20261105/schema/layoutschema.xsd')
)
$ErrorActionPreference='Stop'
$issues=[Collections.Generic.List[string]]::new()
foreach($relative in @('interface/layout/pagemain.xml','interface/layout/components/changelog.xml')) {
 $settings=[Xml.XmlReaderSettings]::new()
 $settings.ValidationType=[Xml.ValidationType]::Schema
 # The shipped schema has overlapping content models; keep validation but allow its compilation.
 $settings.Schemas.CompilationSettings.EnableUpaCheck=$false
 [void]$settings.Schemas.Add('http://www.digitalmindsoft.eu/xmllayout',[IO.Path]::GetFullPath($Schema))
 $settings.add_ValidationEventHandler({param($sender,$event) $issues.Add($relative+': '+$event.Message)}.GetNewClosure())
 $reader=[Xml.XmlReader]::Create([IO.Path]::GetFullPath((Join-Path $ResourceRoot $relative)),$settings)
 try {while($reader.Read()) {}} finally {$reader.Dispose()}
}
if($issues.Count){$issues | ForEach-Object {Write-Output $_};throw "Native menu schema: $($issues.Count) errors."}
Write-Output 'Native GEM schema: both HF menu XML files valid.'
