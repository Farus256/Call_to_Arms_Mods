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
const gameBuild='4b6a807a';
const sources={dll:'cc2882beeb3f14402f8c',lua:'4b3032f7f27161961011',xml:'7ff9387c9b926d9432f4'};
const title='Погибшие в бою';
// File offset in fallen_memorial.dll, value for the build it targets, value for gameBuild.
const edits=[
 [0x10e41,0x1531c80,0x153b150,'GUI page stack begin'],
 [0x10ec5,0x1531c88,0x153b158,'GUI page stack end'],
 [0x1100e,0x1039870,0x10403c0,'eGUI_PageGameResult vtable'],
 [0x33919,0xfde9,0,'zip path size: ANSI instead of UTF-8'],
 [0x33947,0xfde9,0,'zip path text: ANSI instead of UTF-8']
];
const modeLine='        ammunition = "battlezones", -- ammuntion aka "domination"\n';
const addedMode='        annihilation = "battlezones",\n';
function patchDll(buffer){
 const out=Buffer.from(buffer);
 for(const [offset,before,after,what]of edits){assert.equal(out.readUInt32LE(offset),before,what);out.writeUInt32LE(after,offset);}
 return out;
}
function patchLua(text){
 const eol=text.includes('\r\n')?'\r\n':'\n',line=modeLine.replace('\n',eol);
 assert(text.includes(line),'bot.main.lua changed');
 return text.replace(line,line+addedMode.replace('\n',eol));
}
// Only the five memorial columns: the score table above keeps the game's sizes.
function patchXml(text){
 assert(text.includes('<Text value="Killed In Action"/>'),'PageGameResult.xml changed');
 text=text.replace(/<Text value="Killed In Action"\/>(\s*)<TextStyle value="x\.s\(18\)/,(_,gap)=>'<Text value="'+title+'"/>'+gap+'<TextStyle value="x.s(24)');
 let columns=0;
 text=text.replace(/<FlowPanel id="fallen_person_col_\d"[\s\S]*?<\/FlowPanel>/g,block=>{columns++;return block
  .replace('<PreferredSize x="390"/>','<PreferredSize x="460"/>').replace('<PreferredSize x="60"/>','<PreferredSize x="90"/>')
  .replace('<PreferredSize x="170"/>','<PreferredSize x="190"/>').replace('<PreferredSize x="130"/>','<PreferredSize x="150"/>')
  .replaceAll('x.s(10)','x.s(12)');});
 assert.equal(columns,5,'memorial columns');assert(text.includes(title),'title');
 return text;
}
function state(){
 const d=fs.readFileSync(dll),l=fs.readFileSync(lua,'latin1');
 const patched=edits.every(([o,,after])=>d.readUInt32LE(o)===after);
 assert(patched||sha(d).startsWith(sources.dll),'Unknown fallen_memorial.dll: the mod was updated, recheck the offsets');
 const luaDone=l.includes('annihilation = "battlezones"');
 assert(luaDone||sha(Buffer.from(l,'latin1')).startsWith(sources.lua),'Unknown bot.main.lua: the mod was updated');
 const x=fs.readFileSync(xml,'utf8'),xmlDone=x.includes(title);
 assert(xmlDone||sha(Buffer.from(x,'utf8')).startsWith(sources.xml),'Unknown PageGameResult.xml: the mod was updated');
 return {gameBuildMatches:sha(fs.readFileSync(exe)).startsWith(gameBuild),dllPatched:patched,luaPatched:luaDone,xmlPatched:xmlDone};
}
if(require.main===module){
 const now=state();
 assert(now.gameBuildMatches,'Game build changed: find the two addresses again before patching');
 if(process.argv.includes('--apply')){
  fs.mkdirSync(backup,{recursive:true});
  if(!now.dllPatched){const d=fs.readFileSync(dll);fs.writeFileSync(p.join(backup,'fallen_memorial.dll'),d);fs.writeFileSync(dll,patchDll(d));}
  if(!now.luaPatched){const l=fs.readFileSync(lua,'latin1');fs.writeFileSync(p.join(backup,'bot.main.lua'),l,'latin1');fs.writeFileSync(lua,patchLua(l),'latin1');}
  if(!now.xmlPatched){const x=fs.readFileSync(xml,'utf8');fs.writeFileSync(p.join(backup,'PageGameResult.xml'),x,'utf8');fs.writeFileSync(xml,patchXml(x),'utf8');}
 }
 console.log(JSON.stringify(state()));
}
module.exports={edits,patchDll,patchLua,patchXml,state};
