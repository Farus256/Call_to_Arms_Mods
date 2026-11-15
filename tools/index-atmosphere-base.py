import json,pathlib,zipfile
ROOT=pathlib.Path(__file__).resolve().parents[2]
GAME=ROOT.parents[2]/'common/Call to Arms - Gates of Hell/resource'
WORK=ROOT/'_ai_work/workshop-atmosphere-20261107'
paths=set()
roots=[GAME]+[ROOT/str(i)/'resource' for i in [3408719680,3540580405,2922646932,3196505779,3562631215,3359417100,3566110308,3079405930,3139610501,2562731625,3791314577,3548575715]]
for resource in roots:
    assert resource.is_dir(),resource
    for pak in resource.rglob('*.pak'):
        if not zipfile.is_zipfile(pak):continue
        prefix=pak.parent.relative_to(resource).as_posix()
        with zipfile.ZipFile(pak) as z:
            for name in z.namelist():
                if name.endswith('/'):continue
                name=name.replace('\\','/').lower().removeprefix('resource/')
                paths.add((name if prefix=='.' else prefix+'/'+name).lower())
    for f in resource.rglob('*'):
        if f.is_file() and f.suffix.lower()!='.pak':paths.add(f.relative_to(resource).as_posix().lower())
(WORK/'base-paths.json').write_text(json.dumps(sorted(paths)))
print(json.dumps({'basePaths':len(paths)}))
