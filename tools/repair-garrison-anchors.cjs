// Re-apply after every HF update: new HF maps overwrite these repairs silently.
// test-garrison-staging.cjs fails while any Conquest spawn disc leaves its forwardN selector.
// node tools/repair-garrison-anchors.cjs [--apply]
const fs=require('fs'),path=require('path');
const g=require('./garrison-layout.cjs'),st=require('./lib/garrison-staging.cjs');
const root=path.join(g.resource,'map/multi'),apply=process.argv.includes('--apply');
let files=0,moved=0;
for(const entry of fs.readdirSync(root,{withFileTypes:true}).filter(e=>e.isDirectory())){
 const file=path.join(root,entry.name,'campaign_capture_the_flag.mi');
 if(!fs.existsSync(path.join(root,entry.name,'ufb_garrison_layout.inc')))continue;
 const before=fs.readFileSync(file,'latin1');
 // Karvola ships forward zones away from its flags, so no anchor is ever inside them.
 const zoned=entry.name==='dcg_karvola_winter'?st.repairKarvolaZones(before,g.mapData(before)):before;
 const {text,records}=st.repairAddedAnchors(zoned,g.mapData(zoned));
 if(text===before)continue;
 files++;moved+=records.length;
 console.log(entry.name,records.map(r=>r.id+'->'+r.chosen).join(' ')||'zones only');
 if(apply)fs.writeFileSync(file,text,'latin1');
}
console.log(JSON.stringify({files,moved,applied:apply}));
