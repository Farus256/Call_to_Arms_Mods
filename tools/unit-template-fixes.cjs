// Correct only the malformed HF squad template; preserve its ten men and all prices.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const repo=p.resolve(__dirname,'..'),reference=p.resolve(repo,'../_survival_work/hf-update-20261107/reference/resource');
const file='set/multiplayer/units/other_gamemodes/late/units_ger.set',unit='squad_waffen_sturmpio_late_def2';
const shape=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(shape)];
function expected(ref=reference){
 const base=fs.readFileSync(p.join(ref,file),'latin1'),tree=s.parse(base);
 const nodes=tree.children.filter(n=>n.kind==='('&&base.slice(n.start,n.end).includes(`name(${unit})`));assert.equal(nodes.length,1);
 const n=nodes[0],call=base.slice(n.start,n.end),token=n.tokens[0];
 assert.equal(token.value,'squad_with8types_doc');assert(!/\bc8\s*\(/.test(call));
 for(let i=1;i<=7;i++)assert(new RegExp('\\bc'+i+'\\s*\\(').test(call));
 const result=base.slice(0,token.start)+'"squad_with7types_doc"'+base.slice(token.end);
 const after=s.parse(result);after.children[tree.children.indexOf(n)].tokens[0].value=token.value;
 assert.deepEqual(shape(after),shape(tree),'Squad changes beyond the template name');
 return [{file,text:result}];
}
function verify(resource=p.join(repo,'mods/ultimate_frontline_bundle/resource'),ref=reference){
 for(const e of expected(ref))assert.equal(fs.readFileSync(p.join(resource,e.file),'latin1'),e.text);
 return {unexpandedCrewSlotFixed:true,unchangedSquadComposition:true};
}
if(require.main===module){if(process.argv.includes('--build'))for(const e of expected()){const dest=p.join(repo,'mods/ultimate_frontline_bundle/resource',e.file);fs.mkdirSync(p.dirname(dest),{recursive:true});fs.writeFileSync(dest,e.text,'latin1');}console.log(JSON.stringify(verify()));}
module.exports={expected,verify,file,unit};
