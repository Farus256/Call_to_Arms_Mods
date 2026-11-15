"""Inventory the subscribed sources, including the single passenger head clip."""
import hashlib,json,pathlib,zipfile
ROOT=pathlib.Path(__file__).resolve().parents[2]
WORK=ROOT/'_ai_work/workshop-atmosphere-20261107'
IDS=[3805812451,3341685402,2894538979,3661578543,3514735223,3825215999,3438057060,3350281452]
TEXT={'.inc','.ext','.def','.set','.mtl','.mi','.info','.txt','.lua','.dl','.pattern','.weapon','.ammo','.grenade','.presets'}
for id in IDS:
    resource=ROOT/str(id)/'resource';assert resource.is_dir(),resource
    target=WORK/'extracted'/str(id)/'resource';entries={}
    def add(name,data,size,**location):
        name=name.replace('\\','/').lower().removeprefix('resource/')
        if not name or name.endswith('/'):return
        assert '..' not in pathlib.PurePosixPath(name).parts
        record={'file':name,'size':size,**location}
        if pathlib.Path(name).suffix in TEXT or not pathlib.Path(name).suffix:
            value=data()
            if b'\0' not in value[:256]:
                dest=target/name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes(value)
                record['textSHA256']=hashlib.sha256(value).hexdigest()
        entries[name]=record
    for pak in sorted(resource.rglob('*.pak')):
        assert zipfile.is_zipfile(pak),pak
        prefix=pak.parent.relative_to(resource).as_posix()
        with zipfile.ZipFile(pak) as z:
            for info in z.infolist():
                if info.is_dir():continue
                name=info.filename.replace('\\','/').lower().removeprefix('resource/')
                name=name if prefix=='.' else prefix+'/'+name
                add(name,lambda:z.read(info),info.file_size,archive=str(pak),member=info.filename)
    for file in sorted(resource.rglob('*')):
        if file.is_file() and file.suffix.lower()!='.pak':add(file.relative_to(resource).as_posix(),file.read_bytes,file.stat().st_size,loose=str(file))
    manifest=target.parent/'files.json';manifest.parent.mkdir(parents=True,exist_ok=True)
    manifest.write_text(json.dumps(list(entries.values()),indent=2))
    print(id,len(entries))
