// Package only the reviewed Conquest placement files. Refuse changed installed maps.
const fs=require('fs'),path=require('path'),crypto=require('crypto'),assert=require('assert/strict');
const g=require('./garrison-layout.cjs');
const baseline=path.resolve(process.argv[2]||'../_survival_work/garrison-safe-20261007/baseline');
const output=path.resolve(process.argv[3]||'../_survival_work/garrison-safe-20261007/package');
const target='D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/mods/ultimate_frontline_bundle/resource';
const report=require('../docs/realism/GARRISON_LAYOUT_REPORT.json');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
const files=['map/multi/ufb_garrison_functions.inc','map/multi/ufb_garrison_script.inc'];
for(const m of report.maps) files.push('map/multi/'+m.map+'/campaign_capture_the_flag.mi','map/multi/'+m.map+'/ufb_garrison_layout.inc');
const previous=fs.existsSync(path.join(output,'manifest.json'))?JSON.parse(fs.readFileSync(path.join(output,'manifest.json'))):null;
const prior=new Map(previous?.files.map(x=>[x.file,x])||[]),entries=[];
for(const file of files) {
    const source=fs.readFileSync(path.join(g.resource,file)),installed=path.join(target,file);
    const before=fs.existsSync(installed)?sha(fs.readFileSync(installed)):null;
    const old=path.join(baseline,file),expected=fs.existsSync(old)?sha(fs.readFileSync(old)):null;
    assert(before===expected||before===sha(source)||before===prior.get(file)?.afterSHA256,'Installed resource changed: '+file);
    entries.push({file,beforeSHA256:before,afterSHA256:sha(source)});
}
for(const e of entries){const dest=path.join(output,'resource',e.file);fs.mkdirSync(path.dirname(dest),{recursive:true});fs.copyFileSync(path.join(g.resource,e.file),dest);}
fs.writeFileSync(path.join(output,'manifest.json'),JSON.stringify({target,baseline,files:entries},null,2)+'\n');
console.log(JSON.stringify({output,files:entries.length,note:'Package built; not installed'}));
