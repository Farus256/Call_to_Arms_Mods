// The DLL patches one function pointer, so every assumption about the game build is checked here.
// node tools/verify-hatch-dll.cjs   (rebuild with tools/native/build.cmd after a game update)
const fs=require('fs'),p=require('path'),assert=require('assert/strict');
const repo=p.resolve(__dirname,'..');
const exe=fs.readFileSync('D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/binaries/x64/call_to_arms.exe');
const source=fs.readFileSync(p.join(__dirname,'native/ufb_hatch.cpp'),'latin1');
const dllPath=p.join(repo,'mods/ultimate_frontline_bundle/ufb_hatch.dll');
const pe=exe.readUInt32LE(0x3c),sections=exe.readUInt16LE(pe+6),optional=exe.readUInt16LE(pe+20),imageBase=exe.readBigUInt64LE(pe+48);
function offset(rva){
 for(let i=0;i<sections;i++){const s=pe+24+optional+i*40,va=exe.readUInt32LE(s+12),size=exe.readUInt32LE(s+8);
  if(rva>=va&&rva<va+size)return rva-va+exe.readUInt32LE(s+20);}
 throw Error('Unmapped RVA '+rva.toString(16));
}
const constant=name=>Number(source.match(new RegExp(`constexpr DWORD ${name} = (0x[0-9a-f]+)`))[1]);
const signature=name=>Buffer.from(source.match(new RegExp(`${name}\\[\\] = \\{([^}]+)\\}`))[1].split(',').map(x=>Number(x.trim())));
const execute=constant('kExecute'),setSealed=constant('kSetSealed');
const slot=Number(source.match(/kExecuteSlot = (0x[0-9a-f]+) \+ 9 \* 8/)[1])+9*8;
assert.equal(exe.readBigUInt64LE(offset(slot))-imageBase,BigInt(execute),'eCrewEnable vtable slot moved: game updated?');
for(const [name,rva]of [['kExecuteStart',execute],['kSetSealedStart',setSealed]]){const want=signature(name);assert(exe.subarray(offset(rva),offset(rva)+want.length).equals(want),name+' changed: game updated?');}
// Button handler: entity from the command, 0x1a means sealed, tail call to SetSealed.
const handler=exe.subarray(offset(0xb7b2d0),offset(0xb7b2d0)+0x25);
assert.equal(handler.subarray(0x12,0x16).toString('hex'),'80794'.slice(0,4)+'421a','Hatch command code changed');
assert.equal(handler.readInt32LE(0x21)+0xb7b2f5,setSealed,'Button no longer calls SetSealed');
const dll=fs.readFileSync(dllPath);
assert(dll.includes('luaopen_ufb_hatch'),'Missing Lua entry');
assert.equal(dll.readUInt16LE(dll.readUInt32LE(0x3c)+4),0x8664,'DLL must be x64');
const lua=fs.readFileSync(p.join(repo,'mods/ultimate_frontline_bundle/resource/script/multiplayer/ufb_order_guard.lua'),'latin1');
assert(lua.includes('ufb_hatch.dll')&&lua.includes('pcall(package.loadlib'),'Guarded Lua loader missing');
console.log(JSON.stringify({gameBuildMatches:true,dllBytes:dll.length}));
