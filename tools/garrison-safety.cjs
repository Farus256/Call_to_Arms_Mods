// Keep each garrison placement batch and its delayed tag changes in one worker.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
const resource=p.resolve(__dirname,'../mods/ultimate_frontline_bundle/resource');
const marker='; UFB_GARRISON_SERIAL_20261109_V3';
const workers=['dcg2/botdefend/setup','dcg2/botdefend/cartank_to_set'];
const owners=['dcg2/init','dcg2/botdefend/start2flags',...workers];
const raw=(text,n)=>text.slice(n.start,n.end);
function remainingCondition(text,condition){
 if(s.child(condition,'type')){assert.equal(s.child(condition,'type').tokens[1]?.value,'entities');return raw(text,condition);}
 const terms=s.child(condition,'terms');assert(terms&&!s.child(condition,'expression'),'Only conjunctive garrison gates are reviewed');
 const work=terms.children.filter(n=>s.name(n).split('.')[1]==='entities');assert.equal(work.length,1);
 // These guards cannot change during a placement batch: defender side and
 // flags_set are fixed; garrison_ready itself waits for this worker to stop.
 for(const t of terms.children.filter(n=>n!==work[0])){
  const type=s.name(t).split('.')[1];
  if(type==='cmp_i'){assert(['garrison_ready$','user_is_defender$'].includes(s.child(t,'var')?.tokens[1]?.value));assert.equal(s.child(t,'op')?.tokens[1]?.value,'==');assert.equal(s.child(t,'value')?.tokens[1]?.value,'0');}
  else{assert.equal(type,'event');assert.equal(s.child(t,'id')?.tokens[1]?.value,'dcg2/flags_set');}
 }
 // Commands use a typed condition; trigger-only {terms}/{expression} syntax
 // must not be inserted into a native while command.
 return '{condition {type entities}\n'+work[0].children.map(n=>raw(text,n)).join('\n')+'}';
}
function expandCall(text,node,functions){
 const name=s.child(node,'function')?.tokens[1]?.value,definition=functions.get(name);assert(definition,'Unknown garrison call '+name);
 assert.equal(definition.node.tokens.length,1,'Unexpected function arguments');
 assert.equal(s.all(definition.node,n=>s.name(n)==='call').length,0,'Nested call requires a reviewed expansion');
 let body=definition.node.children.map(n=>raw(definition.text,n)).join('\n');
 const context=s.child(node,'context');
 if(context){
  assert.equal(name,'bot_mobiles_stop','Unreviewed scoped garrison function');assert(s.child(context,'specified'));
  const selector=s.child(context,'selector');assert(selector);
  const edits=[];
  for(const command of s.all(s.parse(body),n=>s.name(n)==='action')){
   // {action rotate} is a parameter of an outer action, not another command.
   if(command.tokens.length!==1)continue;
   assert(!s.child(command,'selector'));
   edits.push({start:command.tokens[0].end,end:command.tokens[0].end,text:' '+raw(text,selector)});
  }
  assert.equal(edits.length,4);
  for(const e of edits.sort((a,b)=>b.start-a.start))body=body.slice(0,e.start)+e.text+body.slice(e.end);
 }
 return body;
}
function repair(text,functionText){
 if(text.includes(marker)){verifyText(text);return text;}
 const functions=new Map(s.parse(functionText).children.map(n=>[s.name(n),{node:n,text:functionText}]));
 let tree=s.parse(text),edits=[];
 for(const name of owners){
  const node=tree.children.find(n=>s.name(n)===name);assert(node,'Missing garrison owner '+name);
  for(const call of s.all(s.child(node,'actions'),n=>s.name(n)==='call'))edits.push({start:call.start,end:call.end,text:expandCall(text,call,functions)});
 }
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 tree=s.parse(text);edits=[];
 for(const name of workers){
  const node=tree.children.find(n=>s.name(n)===name),condition=s.child(node,'condition'),actions=s.child(node,'actions'),tail=actions.children.at(-1);
  assert.equal(s.name(tail),'trigger');assert.equal(s.child(tail,'name')?.tokens[1]?.value,name);
  const body=actions.children.slice(0,-1);assert(s.all({children:body},n=>s.name(n)==='delay'&&Number(s.child(n,'time')?.tokens[1]?.value)>0).length,'Worker needs a yield');
  // Re-arm only after the loop has observed no eligible work. The old thread
  // then terminates before a later purchase can satisfy the trigger again.
  const replacement=`{actions {"while" ${remainingCondition(text,condition)}\n${body.map(n=>raw(text,n)).join('\n')}\n}\n${raw(text,tail)}}`;
  edits.push({start:actions.start,end:actions.end,text:replacement});
 }
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 tree=s.parse(text);const ready=tree.children.find(n=>s.name(n)==='dcg2/botdefend/garrison_ready');
 if(ready){
  const condition=s.child(ready,'condition'),expression=s.child(condition,'expression'),terms=s.child(condition,'terms');
  assert.equal(expression.tokens[1]?.value,'1 & !2 & !3 & !4 & 5','Unexpected garrison completion gate');assert.equal(terms.children.length,5);
  const term='{ "6.trigger" {name "dcg2/botdefend/cartank_to_set"}}';
  text=text.slice(0,terms.end-1)+'\n'+term+text.slice(terms.end-1);
  text=text.slice(0,expression.tokens[1].start)+'"1 & !2 & !3 & !4 & 5 & !6"'+text.slice(expression.tokens[1].end);
 }
 text=marker+'\n'+text;verifyText(text);return text;
}
function verifyText(text){
 const tree=s.parse(text);
 for(const name of owners){const node=tree.children.find(n=>s.name(n)===name);assert(node);assert.equal(s.all(s.child(node,'actions'),n=>s.name(n)==='call').length,0,'Asynchronous garrison calls remain: '+name);}
 for(const name of workers){
  const node=tree.children.find(n=>s.name(n)===name),actions=s.child(node,'actions');assert.deepEqual(actions.children.map(s.name),['while','trigger']);
  const normalize=n=>[n.kind,n.tokens.map(t=>t.value),n.children.map(normalize)];
  assert.deepEqual(normalize(s.child(actions.children[0],'condition')),normalize(s.parse(remainingCondition(text,s.child(node,'condition'))).children[0]),'Worker queue gate changed');
  assert.equal(s.all(actions.children[0],n=>s.name(n)==='trigger').length,0,'Worker recursively starts itself');
  assert.equal(s.child(actions.children[1],'name')?.tokens[1]?.value,name);
 }
 const ready=tree.children.find(n=>s.name(n)==='dcg2/botdefend/garrison_ready');
 if(ready){const condition=s.child(ready,'condition');assert.equal(s.child(condition,'expression')?.tokens[1]?.value,'1 & !2 & !3 & !4 & 5 & !6');assert.equal(s.child(s.child(s.child(condition,'terms'),'6.trigger'),'name')?.tokens[1]?.value,'dcg2/botdefend/cartank_to_set');}
 return {serialGarrisonOwners:owners.length,singleGarrisonWorkers:workers.length,latePurchasesRearm:true,garrisonCompletionWaitsForVehiclePlacement:!!ready};
}
function verify(root=resource){
 const current=fs.readFileSync(p.join(root,'map/multi/ufb_garrison_script.inc'),'latin1'),source=fs.readFileSync(p.join(root,'map/multi/dcg_script.inc'),'latin1'),functions=fs.readFileSync(p.join(root,'map/multi/ufb_garrison_functions.inc'),'latin1');
 assert.equal(current,repair(source,functions),'Garrison differs beyond the reviewed serial expansion');return verifyText(current);
}
function build(root=resource){const dir=p.join(root,'map/multi'),source=fs.readFileSync(p.join(dir,'dcg_script.inc'),'latin1'),functions=fs.readFileSync(p.join(dir,'ufb_garrison_functions.inc'),'latin1');fs.writeFileSync(p.join(dir,'ufb_garrison_script.inc'),repair(source,functions),'latin1');}
if(require.main===module){if(process.argv.includes('--build'))build();console.log(JSON.stringify(verify()));}
module.exports={repair,build,verify,verifyText,expandCall,remainingCondition,workers,owners};
