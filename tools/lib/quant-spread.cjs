// Spread polled trigger conditions over quants.
// GoH re-evaluates every armed trigger condition each quant (~0.25 s, measured with PresentMon: a 30 ms
// CPU frame 4x per second). A self-looping trigger whose heavy condition is polled can instead keep only
// its cheap terms as the condition and test the heavy terms as nested if/switch gates on a timer.
// Failed scans repeat after PERIOD seconds; successful scans also keep the original action delays.
// Phases are hashed from the source name, so instances of one macro template share a phase.
const s=require('./sdl.cjs');
const QUANT=0.25,HEAVY=new Set(['see_actors','entities','near']),BROAD=new Set(['bot','_bot']);
const raw=(t,n)=>t.slice(n.start,n.end);
const triggerName=n=>s.child(n,'name')?.tokens[1]?.value;
// Names other code starts or watches ("N.trigger" terms / {type trigger}) must keep running only on demand.
function externallyUsed(texts){
 const calls=new Map(),watched=new Set();
 for(const t of texts){
  for(const m of t.matchAll(/\{"trigger"\s*\{name\s+"([^"]+)"\}/g))calls.set(m[1],(calls.get(m[1])||0)+1);
  for(const m of t.matchAll(/(?:"\d+\.trigger"|\{type\s+trigger\})\s*\{name\s+"([^"]+)"\}/g))watched.add(m[1]);
 }
 return {calls,watched};
}
// period(name) -> seconds (multiple of QUANT) or 0 to leave the trigger alone.
const hash=t=>{let h=2166136261;for(const c of t)h=Math.imul(h^c.charCodeAt(0),16777619)>>>0;return h;}; // FNV-1a
function spread(text,{period,usage,allowTagPair=false,stats={}}){
 const tree=s.parse(text),edits=[];
 for(const n of s.all(tree,x=>x.kind==='{'&&s.child(x,'condition')&&s.child(x,'actions'))){
  const name=s.name(n),cond=s.child(n,'condition'),acts=s.child(n,'actions'),terms=s.child(cond,'terms');
  const last=acts.children.at(-1),P=period(name);
  if(!P||!terms||s.name(last)!=='trigger'||triggerName(last)!==name)continue;
  const selfCalls=s.all(acts,x=>s.name(x)==='trigger'&&triggerName(x)===name).length;
  if((usage.calls.get(name)||0)>selfCalls||usage.watched.has(name)){stats.external=(stats.external||0)+1;continue;}
  const expr=s.child(cond,'expression')?.tokens[1]?.value??(terms.children.length===1?'1':null);
  if(!expr||cond.children.some(c=>!['terms','expression'].includes(s.name(c))))continue;
  const lits=expr.split('&').map(x=>x.trim().match(/^(!?)(\d+)$/));if(lits.some(x=>!x))continue;
  const byId=new Map(terms.children.map(t=>[s.name(t).split('.')[0],t]));
  const parsed=lits.map(([,neg,id])=>{const t=byId.get(id),type=t&&s.name(t)?.split('.')[1];return {neg:!!neg,t,type};});
  if(parsed.some(l=>!l.t||l.t.tokens.length!==1))continue;
  const isHeavy=l=>{if(!HEAVY.has(l.type))return false;
   const sel=s.child(l.t,'selector'),group=sel&&s.child(sel,'group');
   // A job tag (_ufb_..._actor, _ai_medic_active...) narrows candidates to a few: cheap. "bot"/"_bot" or an
   // empty select is every bot unit, so it still scans the army.
   const select=group&&s.child(group,'select'),tags=select?s.all(select,x=>s.name(x)==='tag'&&x.children[0]).map(x=>x.children[0].tokens[1]?.value):[];
   if(tags.length&&!tags.some(t=>BROAD.has(t)))return false;
   const classic=sel&&!group&&s.all(sel,x=>s.name(x)==='tag').map(x=>x.tokens[1]?.value);
   if(classic&&classic.length&&!classic.some(t=>BROAD.has(t)))return false; // {selector {tag X}}: same
   if(!allowTagPair&&l.t.children.some(c=>s.name(c)==='tag')){stats.tagPairKept=(stats.tagPairKept||0)+1;return false;}
   return true;};
  const heavy=parsed.filter(isHeavy),cheap=parsed.filter(l=>!heavy.includes(l));
  if(!heavy.length)continue;
  const args=l=>l.t.children.map(c=>raw(text,c)).join(' ');
  let condition;
  if(!cheap.length)condition='{condition {terms {"1.rand" {value 1}}}}';
  else{const e=cheap.map((l,i)=>(l.neg?'!':'')+(i+1)).join(' & ');
   condition=`{condition ${cheap.length>1||cheap[0].neg?`{expression "${e}"} `:''}{terms ${cheap.map((l,i)=>`{"${i+1}.${l.type}" ${args(l)}}`).join(' ')}}}`;}
  let body=acts.children.slice(0,-1).map(c=>raw(text,c)).join('\n');
  for(const l of [...heavy].reverse()){const c=`{condition {type ${l.type}} ${args(l)}}`;
   body=l.neg?`{"switch" {"case" ${c}} {"default"\n${body}\n}}`:`{"if" ${c}\n${body}\n}`;}
  // Phase from the name, not file order: rebuilding from native HF gives the same phases.
  const slots=Math.round(P/QUANT),phase=cheap.length?0:(hash(name)%slots)*QUANT,rest=+(P-phase).toFixed(2);
  const out=`${condition}\n  {actions ; UFB quant spread: heavy terms checked every ${P}s, phase ${phase}s\n${phase?`{"delay" {time ${phase}}}\n`:''}${body}\n{"delay" {time ${rest}}}\n${raw(text,last)}\n  }`;
  edits.push({start:cond.start,end:acts.end,text:out});
  stats.converted=(stats.converted||0)+1;(stats.names||(stats.names=[])).push(name);
 }
 for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);
 s.parse(text);return text;
}
// Gates of a converted trigger, outermost first: [{condition node, negate}] (simulator and lints use this).
// text = the source the node was parsed from; only triggers carrying the spread marker qualify, since
// native ones (e.g. ufb/gun/release: delay 90, if, delay, retrigger) can have the same shape.
const MARK='; UFB quant spread';
function gates(n,text){
 const acts=s.child(n,'actions');if(!acts||!text||!text.slice(acts.start,acts.start+40).includes(MARK))return null;
 let i=0;const kids=acts.children;if(s.name(kids[0])==='delay')i=1;
 const out=[];let node=kids[i];
 if(!(kids.length===i+3&&s.name(kids[i+1])==='delay'&&s.name(kids.at(-1))==='trigger'))return null;
 while(node&&(s.name(node)==='if'||s.name(node)==='switch')){
  if(s.name(node)==='if'){out.push({condition:s.child(node,'condition'),negate:false});const inner=node.children.filter(c=>s.name(c)!=='condition');if(inner.length!==1)break;node=inner[0];}
  else{const cs=node.children.find(c=>s.name(c)==='case'),d=node.children.find(c=>s.name(c)==='default');
   if(!cs||!d||cs.children.length!==1||node.children.length!==2)break;out.push({condition:s.child(cs,'condition'),negate:true});if(d.children.length!==1)break;node=d.children[0];}
 }
 return out.length?out:null;
}
// The original action list of a trigger (inside the gates of a converted one).
function body(n,text){
 const kids=s.child(n,'actions').children,g=gates(n,text);if(!g)return kids;
 let node=kids[s.name(kids[0])==='delay'?1:0];
 for(let i=0;i<g.length;i++){const inner=s.name(node)==='if'?node.children.filter(c=>s.name(c)!=='condition'):node.children.find(c=>s.name(c)==='default').children;
  if(i===g.length-1)return inner;node=inner[0];}
}
module.exports={spread,gates,body,externallyUsed,QUANT};
if(require.main===module){ // self-check on a miniature trigger
 const assert=require('assert/strict');
 const src=`{"a/scan %team"\n {condition {expression "1 & !2 & 3"} {terms {"1.cmp_i" {var "x$"} {op "=="} {value 0}} {"2.near" {selector {source advanced} {group {include {prop {prop human}}}}} {distance 5}} {"3.see_actors" {selector {source advanced} {group {include {prop {prop human}}}}} {enemy {source advanced}} {distance {mode near_than} {meters 9}}}}}\n {actions\n {"con" {text "hit"}}\n {"delay" {time 2}}\n {"trigger" {name "a/scan %team"}}\n }\n}`;
 const st={},out=spread(src,{period:()=>0.5,usage:externallyUsed([src]),stats:st});
 assert.equal(st.converted,1);assert.equal(spread(out,{period:()=>0.5,usage:externallyUsed([out])}),out,'idempotent');
 const n=s.parse(out).children[0],g=gates(n,out);
 assert.equal(gates(s.parse(src).children[0],src),null,'a native trigger of the same shape is not a scan');
 assert.deepEqual(g.map(x=>[s.child(x.condition,'type').tokens[1].value,x.negate]),[['near',true],['see_actors',false]]);
 assert.match(out,/\{condition \{terms \{"1\.cmp_i" \{var "x\$"\}/);
 const ext=src+'\n{"b" {actions {"trigger" {name "a/scan %team"}}}}';assert.equal(spread(ext,{period:()=>0.5,usage:externallyUsed([ext])}),ext,'externally started trigger untouched');
 console.log('quant-spread self-check ok');
}
