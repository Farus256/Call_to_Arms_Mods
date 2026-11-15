// Compile real sound paths while keeping HF/UFB event conditions outside this file.
const fs=require('fs'),p=require('path'),assert=require('assert/strict'),s=require('./lib/sdl.cjs');
function compile({talk,tables,events,paths}){
 const defs=new Map();
 for(const text of [talk,...tables])for(const n of s.all(s.parse(text),n=>s.name(n)==='define'))defs.set(n.tokens[1].value,n);
 function expand(name,args,depth=0){assert(depth<8,name);const def=defs.get(name);assert(def,name);
  const sub=t=>t.replace(/%(\d+)/g,(_,n)=>{assert(args[+n]!==undefined,name+' arg '+n);return args[+n];});
  return def.children.flatMap(n=>n.kind==='('?expand(sub(n.tokens[0].value),n.tokens.slice(2).map(t=>sub(t.value)),depth+1):s.name(n)==='phrase'?[Object.fromEntries(n.children.filter(n=>['language','voice','sound'].includes(s.name(n))).map(n=>[s.name(n),sub(n.tokens[1].value)]))]:[]);
 }
 const folders=new Set(),physical=[];
 for(const path of paths){if(!path.startsWith('sound/talk/')||!path.endsWith('.wav'))continue;const dir=p.posix.dirname(path);if(!folders.has(dir)){folders.add(dir);const m=/^sound\/talk\/(human|tank|cannon)\/([^/]+)\/([^/]+)\/v(\d+)$/.exec(dir);if(m)physical.push({actor:m[1],family:m[2],action:m[3],voice:m[4],sound:dir.slice(6)});}}
 const generated=[],patches=[],report={phrases:0,repairedMissingPaths:0,unavailable:0,unavailableActions:{}};
 for(const actor of ['human','tank','cannon']){
  const wrapper=actor+'_phrases',actions=new Set(s.all(s.parse(events[actor]),n=>n.kind==='('&&s.name(n)===wrapper).map(n=>n.tokens[2].value));
  for(const action of actions){
   const phrases=expand(wrapper,[action]),valid=phrases.filter(n=>folders.has('sound/'+n.sound)),out=[],seen=new Set();
   for(const phrase of phrases){const key=phrase.language+'|'+phrase.voice;if(seen.has(key))continue;seen.add(key);
    if(!folders.has('sound/'+phrase.sound)){
     // Same event only. Prefer that voice family, then its own nationality.
     const family=phrase.language,base=family.split('_')[0];
     const exact=valid.find(n=>n.language===family);
     const candidates=physical.filter(n=>n.action===action&&[actor,'human'].includes(n.actor));
     const selected=candidates.find(n=>n.family===family&&n.actor===actor)||candidates.find(n=>n.family===family)||candidates.find(n=>n.family===base&&n.actor===actor)||candidates.find(n=>n.family===base);
     if(exact)phrase.sound=exact.sound;
     else if(selected)phrase.sound=selected.sound;
     else {report.unavailable++;const k=actor+'/'+action;report.unavailableActions[k]=(report.unavailableActions[k]||0)+1;continue;}
     report.repairedMissingPaths++;
    }
    assert(folders.has('sound/'+phrase.sound));
    out.push(`{phrase {language "${phrase.language}"} {voice ${phrase.voice}} {sound "${phrase.sound}"}}`);report.phrases++;
   }
   generated.push(`(define "ufb_${actor}_${action}"\n${out.join('\n')}\n)`);
  }
  const def=s.all(s.parse(talk),n=>s.name(n)==='define'&&n.tokens[1]?.value===wrapper)[0];assert(def,wrapper);
  patches.push({...def,text:`(define "${wrapper}" ("ufb_${actor}_%0"))`});
 }
 for(const e of patches.sort((a,b)=>b.start-a.start))talk=talk.slice(0,e.start)+e.text+talk.slice(e.end);
 const at=talk.indexOf('(define "human_phrases"');assert(at>=0);
 talk=talk.slice(0,at)+generated.join('\n')+'\n'+talk.slice(at);
 s.parse(talk);return {text:talk,report};
}
module.exports={compile};
