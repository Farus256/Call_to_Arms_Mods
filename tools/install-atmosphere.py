"""Reversible local installation; validates the built package before profile activation."""
import argparse,csv,datetime,hashlib,json,os,pathlib,re,shutil,subprocess
ROOT=pathlib.Path(__file__).resolve().parents[2]
WORK=ROOT/'_ai_work/workshop-atmosphere-20261107'
SOURCE=WORK/'package/ufb_atmosphere'
GAME=ROOT.parents[2]/'common/Call to Arms - Gates of Hell'
TARGET=GAME/'mods/ufb_atmosphere'
PROFILE=pathlib.Path(os.environ['LOCALAPPDATA'])/'digitalmindsoft/gates of hell/profiles/290653400/options.set'
parser=argparse.ArgumentParser();parser.add_argument('--rollback',action='store_true');args=parser.parse_args()
processes=list(csv.reader(subprocess.check_output(['tasklist','/FO','CSV','/NH'],text=True).splitlines()))
assert not any(row and row[0].lower() in {'call_to_arms.exe','call_to_arms_ed.exe','call_to_arms_server.exe'} for row in processes),'Close game/editor/server before changing mods'
def digest(path):
    h=hashlib.sha256()
    with path.open('rb') as file:
        for chunk in iter(lambda:file.read(4*1024*1024),b''):h.update(chunk)
    return h.hexdigest()
def mods(data):
    found=re.search(rb'\{mods\s+[^{}]*\}',data);assert found,'Profile mods block missing';return found
def atomic_profile(data):
    temp=PROFILE.with_suffix('.atmosphere.tmp');assert not temp.exists()
    temp.write_bytes(data);os.replace(temp,PROFILE)
original=PROFILE.read_bytes();block=mods(original)
if args.rollback:
    entry=b'"ufb_atmosphere:0"'
    updated=re.sub(rb'[ \t]*'+re.escape(entry)+rb'\r?\n',b'',block.group())
    assert updated!=block.group(),'Atmosphere is not active'
    atomic_profile(original[:block.start()]+updated+original[block.end():])
    print(json.dumps({'rolledBack':True,'modFilesRetained':str(TARGET)}));raise SystemExit
expected=(WORK/'options-before.set').read_bytes()
assert block.group()==mods(expected).group(),'Active mods changed during build; review load order before installation'
assert not TARGET.exists(),'Target already exists; refuse to overwrite an installed local mod'
assert TARGET.resolve().is_relative_to((GAME/'mods').resolve())
manifest=json.loads((WORK/'text-manifest.json').read_text(encoding='utf-8'))
for item in manifest:assert digest(SOURCE/'resource'/item['file'])==item['sha256'],item['file']
asset_report=json.loads((WORK/'asset-report.json').read_text(encoding='utf-8'));pak=SOURCE/'resource/atmosphere.pak'
assert digest(pak)==asset_report['archiveSHA256'],'Asset archive drift'
stamp=datetime.datetime.now().strftime('%Y%m%d-%H%M%S')
backup=WORK/'backups'/stamp;backup.mkdir(parents=True)
shutil.copy2(PROFILE,backup/'options.set')
stage=GAME/'mods'/('ufb_atmosphere.installing-'+stamp)
assert stage.resolve().is_relative_to((GAME/'mods').resolve()) and not stage.exists()
shutil.copytree(SOURCE,stage)
for item in manifest:assert digest(stage/'resource'/item['file'])==item['sha256'],item['file']
assert digest(stage/'resource/atmosphere.pak')==asset_report['archiveSHA256']
stage.rename(TARGET)
assert PROFILE.read_bytes()==original,'Profile changed while assets were copied'
needle=b'"ultimate_frontline_bundle:0"';assert block.group().count(needle)==1
replacement=block.group().replace(needle,b'"ufb_atmosphere:0"\r\n\t\t'+needle)
atomic_profile(original[:block.start()]+replacement+original[block.end():])
record={'installed':str(TARGET),'profile':str(PROFILE),'backup':str(backup),'textFiles':len(manifest),'assets':asset_report['files'],'pakSHA256':asset_report['archiveSHA256'],'loadBefore':'ultimate_frontline_bundle','installedAt':stamp}
(WORK/'installation.json').write_text(json.dumps(record,indent=2),encoding='utf-8');print(json.dumps(record))
