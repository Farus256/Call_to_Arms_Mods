// Actual Lua execution for the DLL bootstrap, plus deployment selector geometry.
// Usage: node tools/test-postmatch-honour.cjs ../_ai_work/postmatch-honour-fix-20261009
const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const {lua,lauxlib,lualib,to_luastring,to_jsstring}=require('fengari'),luaparse=require('luaparse');
const g=require('./garrison-layout.cjs'),s=require('./lib/sdl.cjs'),staging=require('./lib/garrison-staging.cjs');
const pkg=path.resolve(process.argv[2]),saved=JSON.parse(fs.readFileSync(path.join(pkg,'baseline-manifest.json')));
const read=f=>fs.readFileSync(f,'latin1'),fixed=read(path.join(__dirname,'compat/roll-of-honour/bot.main.lua')),old=read(path.join(pkg,'honour-bootstrap-before.lua'));
luaparse.parse(fixed,{luaVersion:'5.1'});
assert.equal(fixed.slice(fixed.indexOf('-- Original GEM2')),old.slice(old.indexOf('-- Original GEM2')).replace(/\r\n/g,'\n'),'Native AI bootstrap changed');
let luaScenarios=0;
function run(label,source,setup,checks){
 const L=lauxlib.luaL_newstate();lualib.luaL_openlibs(L);
 const harness=String.raw`
 logs={};loads=0;starts=0;modeCalls=0;aiCalls=0
 print=function(text) logs[#logs+1]=text end
 BotApi={Instance={gameMode='campaign_capture_the_flag'}}
 package.cpath=[[D:\Programs\Steam\steamapps\common\Call to Arms - Gates of Hell\binaries\x64\?.dll]]
 package.loaded.fallen_memorial=nil
 require=function(name) if name~='fallen_memorial' then assert(name=='resource/script/multiplayer/modes/conquest');modeCalls=modeCalls+1 end end
 initialize=function() aiCalls=aiCalls+1 end
 package.loadlib=function(file,symbol)
  loads=loads+1
  assert(file==[[D:\Programs\Steam\steamapps\workshop\content\400750\3791314577\fallen_memorial.dll]])
  assert(symbol=='luaopen_fallen_memorial')
  return function() starts=starts+1 end
 end
 `;
 const status=lauxlib.luaL_dostring(L,to_luastring(harness+'\n'+setup+'\ndo\n'+source+'\nend\n'+checks));
 const error=status===lua.LUA_OK?null:to_jsstring(lua.lua_tostring(L,-1));lua.lua_close(L);assert.equal(error,null,label+': '+error);luaScenarios++;
}
run('reproduce GEM require false success',old,'','assert(loads==0 and starts==0 and modeCalls==1 and aiCalls==1);assert(logs[#logs]:find("SUCCESS",1,true))');
run('actual DLL export invoked',fixed,'','assert(loads==1 and starts==1 and modeCalls==1 and aiCalls==1);assert(package.loaded.fallen_memorial==true);assert(logs[#logs]:find("DLL entry point executed",1,true))');
run('repeat bootstrap does not restart DLL',fixed+'\n'+fixed,'','assert(loads==1 and starts==1 and modeCalls==2 and aiCalls==2)');
run('DLL load fails but native AI runs',fixed,"package.loadlib=function() return nil,'missing DLL' end",'assert(starts==0 and modeCalls==1 and aiCalls==1);assert(not package.loaded.fallen_memorial);assert(logs[#logs]:find("missing DLL",1,true))');
run('loadlib throws but native AI runs',fixed,"package.loadlib=function() error('loader failure') end",'assert(modeCalls==1 and aiCalls==1);assert(logs[#logs]:find("loader failure",1,true))');
run('initialization throws but native AI runs',fixed,"package.loadlib=function() return function() error('init failure') end end",'assert(modeCalls==1 and aiCalls==1);assert(not package.loaded.fallen_memorial);assert(logs[#logs]:find("init failure",1,true))');
run('loadlib unavailable',fixed,'package.loadlib=nil','assert(modeCalls==1 and aiCalls==1);assert(logs[#logs]:find("unavailable",1,true))');
run('Steam path unavailable',fixed,"package.cpath='./?.dll'",'assert(loads==0 and modeCalls==1 and aiCalls==1);assert(logs[#logs]:find("ERROR",1,true))');
const currentScript=read(path.join(g.resource,'map/multi/ufb_garrison_script.inc'));
const previousScript=read(path.join(pkg,'baseline/map/multi/ufb_garrison_script.inc'));
const unwrapped=staging.nativeSpawnRouting(previousScript);assert.equal(unwrapped.count,30);assert.equal(currentScript,unwrapped.text);
const owners=s.all(s.parse(currentScript),n=>/^dcg2\/botdefend\/start[23]flags$/.test(s.name(n)));
const stageRefs=owners.flatMap(n=>s.all(n,n=>s.name(n)==='target_waypoint')).map(n=>n.tokens[1].value);
assert(stageRefs.length>0);assert(stageRefs.every(id=>Number(id)>=15&&Number(id)<=24),'Spawn markers must use native staging');
let maps=0,stagingChecks=0,oldOutside=0,newOutside=0,oldNativeOutside=0,lysovoReproduced=false;
for(const entry of fs.readdirSync(path.join(g.resource,'map/multi'),{withFileTypes:true}).filter(e=>e.isDirectory())){
 const folder=path.join(g.resource,'map/multi',entry.name),layoutFile=path.join(folder,'ufb_garrison_layout.inc');if(!fs.existsSync(layoutFile))continue;maps++;
 const rel='map/multi/'+entry.name+'/campaign_capture_the_flag.mi',current=read(path.join(g.resource,rel)),before=fs.existsSync(path.join(pkg,'baseline',rel))?read(path.join(pkg,'baseline',rel)):current;
 const data=g.mapData(current),beforeData=g.mapData(before),forward=staging.zones(data),oldForward=staging.zones(beforeData),layout=s.parse(read(layoutFile));
 for(let spawn=1;spawn<=8;spawn++)for(let flag=1;flag<=5;flag++){
  const id=String((spawn<=4?19:14)+flag),zone=forward.get('forward'+flag),oldZone=oldForward.get('forward'+flag),native=data.points.get(id),alias=layout.children.find(n=>s.name(n)===g.alias(spawn,id));assert(zone&&native&&alias);
  stagingChecks++;
  const radius=Number(s.child(native,'radius')?.tokens[1]?.value||s.child(native,'Radius')?.tokens[1]?.value||0);
  if(!staging.contains(zone,staging.xyz(native),radius))newOutside++;
  if(!staging.contains(oldZone,staging.xyz(beforeData.points.get(id))))oldNativeOutside++;
  if(!staging.contains(oldZone,staging.xyz(alias))){oldOutside++;if(entry.name==='dcg_f_bridges_of_lysovo'&&flag===5)lysovoReproduced=true;}
 }
 if(entry.name==='dcg_karvola_winter'){
  const corrected=staging.repairKarvolaZones(before,g.mapData(before));assert.equal(current,staging.repairAddedAnchors(corrected,g.mapData(corrected)).text,'Karvola changes outside zones and staging');
 }else assert.equal(current,staging.repairAddedAnchors(before,g.mapData(before)).text,'Map changes outside staging anchors');
}
assert.equal(maps,117);assert.equal(newOutside,0);assert.equal(oldOutside,3501);assert.equal(oldNativeOutside,64);assert(lysovoReproduced);
// Replay the decisive selector: a newly spawned operatable defender must be
// inside its intended forward zone before flagN_bots_d can clear _garrison_todo+.
// Existing battle positions and all tag-removal commands stay unchanged.
console.log(JSON.stringify({luaScenarios,nativeAIInitializationPreserved:true,maps,stagingChecks,oldOutside,newOutside,oldNativeOutside,lysovoTimeoutCauseReproduced:true,restoredNativePlacements:unwrapped.count}));
