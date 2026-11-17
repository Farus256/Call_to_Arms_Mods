// Local repair of the third-party Workshop mod Roll of Honour (3791314577).
// Its DLL ships for an older game build and opens Cyrillic save names as UTF-8.
// Its memorial layout gets a Russian title and larger text; the cells themselves are
// translated at run time by ufb_roh_ru.dll (tools/native/ufb_roh_ru.cpp).
// node tools/patch-roll-of-honour.cjs           report state, write nothing
// node tools/patch-roll-of-honour.cjs --apply   back up, then patch the installed mod
// The mod's author owns these files: never commit them. A Steam update of the mod or
// a game update makes this tool refuse until the offsets are checked again.
const fs=require('fs'),p=require('path'),crypto=require('crypto'),assert=require('assert/strict');
const workshop=p.resolve(__dirname,'../..'),mod=p.join(workshop,'3791314577');
const exe='D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/binaries/x64/call_to_arms.exe';
const dll=p.join(mod,'fallen_memorial.dll'),lua=p.join(mod,'resource/script/multiplayer/bot.main.lua');
const xml=p.join(mod,'resource/interface/layout/PageGameResult.xml');
const backup=p.join(workshop,'_ai_work/roll-of-honour-20261106/backup');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
const gameBuild='81a13de7';
const sources={dll:'cc2882beeb3f14402f8c',lua:'4b3032f7f27161961011',xml:'7ff9387c9b926d9432f4'};
const title='Погибшие в бою';
// File offset in fallen_memorial.dll. Earlier immediates are the published DLL and the 1.068 patch.
// Page stack is the static GUI manager at RVA 0x15628a0, vector begin/end at +0x30/+0x38.
const edits=[
 [0x10e41,[0x1531c80,0x153b150],0x15628d0,'GUI page stack begin'],
 [0x10ec5,[0x1531c88,0x153b158],0x15628d8,'GUI page stack end'],
 [0x1100e,[0x1039870,0x10403c0],0x10619d0,'eGUI_PageGameResult vtable'],
 [0x33919,0xfde9,0,'zip path size: ANSI instead of UTF-8'],
 [0x33947,0xfde9,0,'zip path text: ANSI instead of UTF-8']
];
// The native formatter still owns 25 string cells. Redistribute every casualty
// over the first three groups; the last two groups become empty compatibility widgets.
const columnEdits=[
 [0xf0ce,'48b8cdcccccccccccccc49f7e048c1ea02488d0492','48b8abaaaaaaaaaaaaaa49f7e048c1ea01488d0452','divide casualty count by three'],
 [0xf111,'33c04983f8030f97c04803c248894598488955a0','48c745980000000048c745a0000000000f1f4000','zero groups four and five'],
 [0xf471,'4983fc04','4983fc02','last visible separator'],
 [0x42e90,Buffer.from('[GUI] Five-column KIA memorial written: ').toString('hex'),Buffer.from('[GUI] Three-col.  KIA memorial written: ').toString('hex'),'layout log label']
];
function rvaOffset(buffer,rva){const pe=buffer.readUInt32LE(0x3c),count=buffer.readUInt16LE(pe+6),table=pe+24+buffer.readUInt16LE(pe+20);
 for(let i=0;i<count;i++){const at=table+i*40,va=buffer.readUInt32LE(at+12),size=buffer.readUInt32LE(at+16);if(rva>=va&&rva<va+size)return rva-va+buffer.readUInt32LE(at+20);}throw Error('Unmapped ROH RVA '+rva.toString(16));}
function patchColumns(buffer){const out=Buffer.from(buffer);for(const [rva,before,after,label]of columnEdits){const a=Buffer.from(before,'hex'),b=Buffer.from(after,'hex'),offset=rvaOffset(out,rva);assert.equal(a.length,b.length,label);const value=out.subarray(offset,offset+a.length);assert(value.equals(a)||value.equals(b),'Unknown formatter: '+label);b.copy(out,offset);}return out;}
const columnsDone=buffer=>columnEdits.every(([rva,,after])=>{const value=Buffer.from(after,'hex'),offset=rvaOffset(buffer,rva);return buffer.subarray(offset,offset+value.length).equals(value);});
const modeLine='        ammunition = "battlezones", -- ammuntion aka "domination"\n';
const addedMode='        annihilation = "battlezones",\n';
function accepted(value){return Array.isArray(value)?value:[value];}
function patchDll(buffer){
 const out=Buffer.from(buffer);
 for(const [offset,before,after,what]of edits){
  const value=out.readUInt32LE(offset);
  if(value===after)continue;
  assert(accepted(before).includes(value),what);
  out.writeUInt32LE(after,offset);
 }
 return out;
}
function patchLua(text){
 const eol=text.includes('\r\n')?'\r\n':'\n',line=modeLine.replace('\n',eol);
 assert(text.includes(line),'bot.main.lua changed');
 return text.replace(line,line+addedMode.replace('\n',eol));
}
// Only the five memorial columns: the score table above keeps the game's sizes.
function patchXml(text){
 assert(text.includes('<Text value="Killed In Action"/>')||text.includes(title),'PageGameResult.xml changed');
 text=text.replace(/<Text value="Killed In Action"\/>(\s*)<TextStyle value="x\.s\(18\)/,(_,gap)=>'<Text value="'+title+'"/>'+gap+'<TextStyle value="x.s(24)');
 let columns=0;
 text=text.replace(/<FlowPanel id="fallen_person_col_(\d)"[\s\S]*?<\/FlowPanel>/g,(block,index)=>{columns++;block=block
  .replace('<PreferredSize x="390"/>','<PreferredSize x="460"/>').replace('<PreferredSize x="60"/>','<PreferredSize x="90"/>')
  .replace('<PreferredSize x="170"/>','<PreferredSize x="190"/>').replace('<PreferredSize x="130"/>','<PreferredSize x="150"/>')
  .replaceAll('x.s(10)','x.s(12)');
  if(Number(index)>3&&!block.includes('<Visible value="false"/>'))block=block.replace(/(<FlowPanel[^>]+>)/,'$1\n<Visible value="false"/>');
  if(Number(index)<=3)block=block.replace(/(<TextStyle[^>]+\/>)(\s*<\/StaticText>)/g,'$1\n<TextClip value="true" showHint="true"/>$2');
  return block;});
 assert.equal(columns,5,'memorial columns');assert(text.includes(title),'title');
 return text;
}
function siteKnown(buffer){
 // The three address immediates stay inside the same instructions across our patches.
 const ops=[[0x10e3e,'488d9f'],[0x10ec2,'4881c7'],[0x1100b,'4981c6']];
 return ops.every(([off,hex])=>buffer.subarray(off,off+3).toString('hex')===hex)
  && edits.every(([o,before,after])=>{const value=buffer.readUInt32LE(o);return value===after||accepted(before).includes(value);});
}
function state(){
 const d=fs.readFileSync(dll),l=fs.readFileSync(lua,'latin1');
 const patched=edits.every(([o,,after])=>d.readUInt32LE(o)===after);
 assert(patched||siteKnown(d)||sha(d).startsWith(sources.dll),'Unknown fallen_memorial.dll: the mod was updated, recheck the offsets');
 const luaDone=l.includes('annihilation = "battlezones"');
 assert(luaDone||sha(Buffer.from(l,'latin1')).startsWith(sources.lua),'Unknown bot.main.lua: the mod was updated');
 const x=fs.readFileSync(xml,'utf8'),xmlDone=x.includes(title);
 assert(xmlDone||sha(Buffer.from(x,'utf8')).startsWith(sources.xml),'Unknown PageGameResult.xml: the mod was updated');
 const groups=[...x.matchAll(/<FlowPanel id="fallen_person_col_(\d)"[\s\S]*?<\/FlowPanel>/g)];
 const threeColumns=columnsDone(d),xmlThreeColumns=groups.length===5&&groups.every(m=>m[0].includes('<Visible value="false"/>')===(Number(m[1])>3));
 return {gameBuildMatches:sha(fs.readFileSync(exe)).startsWith(gameBuild),dllPatched:patched,luaPatched:luaDone,xmlPatched:xmlDone,threeColumns,xmlThreeColumns};
}
if(require.main===module){
 const now=state();
 assert(now.gameBuildMatches,'Game build changed: find the two addresses again before patching');
 if(process.argv.includes('--apply')){
  fs.mkdirSync(backup,{recursive:true});
  if(!now.dllPatched){const d=fs.readFileSync(dll);fs.writeFileSync(p.join(backup,'fallen_memorial.dll'),d);fs.writeFileSync(dll,patchDll(d));}
  if(!now.threeColumns){const d=fs.readFileSync(dll);if(!fs.existsSync(p.join(backup,'fallen_memorial-before-three-columns.dll')))fs.writeFileSync(p.join(backup,'fallen_memorial-before-three-columns.dll'),d);fs.writeFileSync(dll,patchColumns(d));}
  if(!now.luaPatched){const l=fs.readFileSync(lua,'latin1');fs.writeFileSync(p.join(backup,'bot.main.lua'),l,'latin1');fs.writeFileSync(lua,patchLua(l),'latin1');}
  if(!now.xmlPatched||!now.xmlThreeColumns){const x=fs.readFileSync(xml,'utf8');if(!fs.existsSync(p.join(backup,'PageGameResult-before-three-columns.xml')))fs.writeFileSync(p.join(backup,'PageGameResult-before-three-columns.xml'),x,'utf8');fs.writeFileSync(xml,patchXml(x),'utf8');}
 }
 console.log(JSON.stringify(state()));
}
module.exports={edits,columnEdits,rvaOffset,patchDll,patchColumns,columnsDone,patchLua,patchXml,state};
