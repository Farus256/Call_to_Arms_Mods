"""Pack only the explicit asset allowlist; retain Workshop source ownership and hashes."""
import collections, hashlib, json, pathlib, struct, zipfile
ROOT=pathlib.Path(__file__).resolve().parents[2]
WORK=ROOT/'_ai_work/workshop-atmosphere-20261107'
PLAN=json.loads((WORK/'assets-plan.json').read_text(encoding='utf-8'))
DEST=WORK/'package/ufb_atmosphere/resource/atmosphere.pak'
archives={}; manifest=[]; stats=collections.Counter(); audio=collections.Counter()
with zipfile.ZipFile(DEST,'w',compression=zipfile.ZIP_STORED,allowZip64=True) as out:
    for item in PLAN:
        name=item['file']; assert '..' not in pathlib.PurePosixPath(name).parts
        if 'loose' in item: data=pathlib.Path(item['loose']).read_bytes()
        else:
            archive=item['archive']
            if archive not in archives: archives[archive]=zipfile.ZipFile(archive)
            data=archives[archive].read(item['member'])
        assert len(data)==item['size'],name
        if name.endswith('.wav'):
            assert data[:4]==b'RIFF' and data[8:12]==b'WAVE',name
            offset=12; found=False
            while offset+8<=len(data):
                tag,size=struct.unpack_from('<4sI',data,offset)
                if tag==b'fmt ':
                    fmt,channels,rate=struct.unpack_from('<HHI',data,offset+8)
                    audio[str((fmt,channels,rate))]+=1;found=True;break
                offset+=8+size+(size%2)
            assert found,name
        if name.endswith('.anm'): assert data.startswith(b'EANM'),name
        if name.endswith('.dds'): assert data.startswith(b'DDS '),name
        out.writestr(name,data)
        manifest.append({'file':name,'source':item['id'],'size':len(data),'sha256':hashlib.sha256(data).hexdigest()})
        stats[str(item['id'])]+=len(data)
for archive in archives.values(): archive.close()
with zipfile.ZipFile(DEST) as z:
    assert len(z.namelist())==len(set(z.namelist()))==len(PLAN)
    assert z.testzip() is None
(WORK/'asset-manifest.json').write_text(json.dumps(manifest,indent=2))
(WORK/'asset-report.json').write_text(json.dumps({'files':len(PLAN),'bytesBySource':stats,'wavFormats':audio,'archiveSHA256':hashlib.sha256(DEST.read_bytes()).hexdigest()},indent=2))
print(json.dumps({'files':len(PLAN),'bytesBySource':stats,'wavFormats':audio,'pakBytes':DEST.stat().st_size}))
