// Package only the nine added mode files; require the reviewed UFB dependencies.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const g=require('./garrison-layout.cjs'),report=require('../docs/realism/CONQUEST_MAPS_ADDED.json');
const {execFileSync}=require('child_process');
const target='D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/mods/ultimate_frontline_bundle/resource';
const output=path.resolve(process.argv[2]||'../_survival_work/conquest-maps-20261007/package');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
const equal=file=>assert.equal(sha(fs.readFileSync(path.join(target,file))),sha(fs.readFileSync(path.join(g.resource,file))),'Installed dependency differs: '+file);
const dependencies=new Set(['map/multi/HF-dcg_script.inc']),archiveDependencies=new Map();
const hfArchive=path.resolve(__dirname,'../../3359417100/resource/map/multi.pak');
const nativeArchive='D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/resource/map/multi.pak';
for(const m of report.maps){
    const folder='map/multi/'+m.name;
    equal(folder+'/battle_zones.mi');
    const text=fs.readFileSync(path.join(g.resource,folder,'campaign_capture_the_flag.mi'),'latin1');
    for(const match of text.matchAll(/\(include "([^"]+)"\)/g)){
        if(match[1]==='ufb_garrison_layout.inc')continue;
        const file=path.posix.normalize(folder+'/'+match[1]);
        assert(file.startsWith('map/multi/'),'Unexpected dependency path');
        if(fs.existsSync(path.join(g.resource,file)))dependencies.add(file);
        else {
            const leaf=path.posix.basename(file);
            assert(['dcg_vars.inc','HF-dcg_entities.inc','HF-dcg_functions.inc','HF-dcg_dynamic_weather.inc','HF-dcg_dynamic_weather_winter.inc'].includes(leaf),'Missing custom dependency: '+file);
            archiveDependencies.set(leaf,leaf==='dcg_vars.inc'?nativeArchive:hfArchive);
        }
    }
}
for(const file of dependencies)equal(file);
// Read-only ZIP lookup; HF and native includes remain in their existing archives.
const archiveCheck="import sys,json,zipfile; pairs=json.loads(sys.argv[1]); " +
    "missing=[leaf for leaf,p in pairs if not any(n.replace(chr(92),'/').lower().endswith('/'+leaf.lower()) or n.lower()==leaf.lower() for n in zipfile.ZipFile(p).namelist())]; assert not missing, missing";
execFileSync('py',['-3.12','-c',archiveCheck,JSON.stringify([...archiveDependencies])],{stdio:'pipe'});
assert.equal(report.files.length,9);
const previous=fs.existsSync(path.join(output,'manifest.json'))?JSON.parse(fs.readFileSync(path.join(output,'manifest.json'))):null;
const prior=new Map(previous?.files.map(entry=>[entry.file,entry])||[]);
const files=report.files.map(file=>{
    assert(/^map\/multi\/4v4_(fields|Rikila|Sikovitsy)\/(campaign_capture_the_flag\.(mi|info)|ufb_garrison_layout\.inc)$/.test(file));
    const source=fs.readFileSync(path.join(g.resource,file)),dest=path.join(target,file),afterSHA256=sha(source);
    const beforeSHA256=fs.existsSync(dest)?sha(fs.readFileSync(dest)):null;
    assert(beforeSHA256===null||beforeSHA256===afterSHA256||beforeSHA256===prior.get(file)?.afterSHA256,'Existing mode differs: '+file);
    return {file,beforeSHA256,afterSHA256};
});
for(const entry of files){const dest=path.join(output,'resource',entry.file);fs.mkdirSync(path.dirname(dest),{recursive:true});fs.copyFileSync(path.join(g.resource,entry.file),dest);}
fs.writeFileSync(path.join(output,'manifest.json'),JSON.stringify({target,baseline:'No pre-existing Conquest mode files in these three folders',files},null,2)+'\n');
console.log(JSON.stringify({output,files:files.length,verifiedCustomDependencies:dependencies.size,verifiedArchiveDependencies:archiveDependencies.size}));
