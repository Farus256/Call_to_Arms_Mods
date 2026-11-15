// Revalidate actors at the command, after tags, delays, boarding and deaths.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const invalid=['dead','inactive','linked'];
const value=(n,key)=>s.child(n,key)?.tokens[1]?.value;
const raw=(text,n)=>text.slice(n.start,n.end);
function guard(text,selector,{human=false,cannon=false}={}){
 const group=s.child(selector,'group'),changes=[];
 const invalidStates=cannon?[...invalid,'user_control']:invalid;
 const required=[...(human?[['prop','human']]:[]),...(cannon?[['prop','cannon'],['state','operatable'],['state','inhabited']]:[])];
 if(group){
  const include=s.child(group,'include'),exclude=s.child(group,'exclude');
  const append=body=>{const end=group.end-1,line=text.lastIndexOf('\n',end)+1,indent=text.slice(line,end);return /^[\t ]*$/.test(indent)?{start:line,end:line,text:indent+body+'\n'}:{start:end,end,text:'\n'+body+'\n'};};
  const has=(node,kind,key)=>node&&s.all(node,n=>s.name(n)===kind&&(n.tokens[1]?.value||value(n,kind))===key).length;
  const states=invalidStates.filter(state=>!has(exclude,'state',state)).map(state=>`{state {state ${state}}}`).join(' ');
  if(states)changes.push(exclude?{start:exclude.end-1,end:exclude.end-1,text:' '+states+' '}:append('{exclude '+states+'}'));
  const requirements=required.filter(([kind,key])=>!has(include,kind,key)).map(([kind,key])=>`{${kind} {${kind} ${key}}}`).join(' ');
  if(requirements)changes.push(include?{start:include.end-1,end:include.end-1,text:' '+requirements+' '}:append('{include '+requirements+'}'));
  let result=raw(text,selector);for(const e of changes.sort((a,b)=>b.start-a.start))result=result.slice(0,e.start-selector.start)+e.text+result.slice(e.end-selector.start);return result;
 }
 // Only the classic forms actually present in these command consumers are converted.
 const select=[],include=required.map(([kind,key])=>`{${kind} {${kind} ${key}}}`),exclude=invalidStates.map(state=>`{state {state ${state}}}`),top=[];
 for(const n of selector.children){const name=s.name(n),v=n.tokens[1]?.value;
  if(['amount','ignore_captured_by_user','sort'].includes(name))top.push(raw(text,n));
  else if(name==='source')assert.equal(v,'advanced');
  else if(name==='tag')select.push(`{tag {tag ${JSON.stringify(v)}}}`);
  else if(name==='state'){
   const words=v.split(/\s+/),neg=words[0]==='not';if(neg)words.shift();
   for(const word of words)(neg?exclude:include).push(`{state {state ${word}}}`);
  }else throw Error('Unreviewed classic command selector: '+raw(text,selector));
 }
 assert(select.length,'No classic tag scope in '+raw(text,selector));
 return `{selector {source advanced} ${top.join(' ')} {group {select ${select.join(' ')}} ${include.length?'{include '+include.join(' ')+'}':''} {exclude ${exclude.join(' ')}}}}`;
}
function repair(text){
 const changes=[],tree=s.parse(text);
 const consumer=n=>s.name(n)==='actor_to_cover'||s.name(n)==='actor_state'&&(s.child(n,'drop')||s.child(n,'cannon'))||s.name(n)==='effect'&&value(n,'effect')==='ufb_hf_cover_committed';
 for(const n of s.all(tree,consumer)){
  const selector=s.child(n,'selector');assert(selector,'Command selector missing');
  const next=guard(text,selector,{human:s.name(n)!=='actor_state',cannon:!!s.child(n,'cannon')});
  if(next!==raw(text,selector))changes.push({...selector,text:next});
 }
 // Do not tag passengers for an on-foot reaction in the first place. Command
 // guards remain necessary because boarding/death can happen during the delay.
 const reactions=new Set(['hf inf ai/near player','hf inf ai/under mg fire','hf inf ai/ai mgunner','hf inf ai/ai reloads']);
 for(const node of tree.children.filter(n=>reactions.has(s.name(n))))for(const selector of s.all(s.child(node,'condition'),n=>s.name(n)==='selector')){
  const next=guard(text,selector,{human:true});if(next!==raw(text,selector))changes.push({...selector,text:next});
 }
 for(const e of changes.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 s.parse(text);return text;
}
const files=['map/multi/HF-dcg_script.inc','map/multi/ufb_static_weapons.inc','map/multi/ufb_crew_safety.inc','map/multi/ufb_crew_skirmish.inc'];
function verify(root){let commands=0;
 for(const file of files){const text=fs.readFileSync(p.join(root,file),'latin1');assert.equal(repair(text),text,'Unsafe actor command: '+file);
  commands+=s.all(s.parse(text),n=>s.name(n)==='actor_to_cover'||s.name(n)==='actor_state'&&s.child(n,'drop')).length;
 }return {commandConsumersGuarded:commands,linkedInactiveActorsExcluded:true};
}
if(require.main===module){const root=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');if(process.argv.includes('--build'))for(const file of files){const dest=p.join(root,file);fs.writeFileSync(dest,repair(fs.readFileSync(dest,'latin1')),'latin1');}console.log(JSON.stringify(verify(root)));}
module.exports={repair,guard,verify,files};
