// Adapt selected installed 4v4 maps, keeping their original terrain and navigation.
const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),NavGrid=require('./lib/gem-nav.cjs'),g=require('./garrison-layout.cjs');
const work=path.resolve(process.argv[2]||'../_survival_work/conquest-maps-20261007');
const maps=[{name:'4v4_fields',title:'Fields',landscape:'desert',tex:'camo'},
    {name:'4v4_Rikila',title:'Rikila',landscape:'wood',tex:'camo'},
    {name:'4v4_Sikovitsy',title:'Sikovitsy',landscape:'winter',tex:'winter'}];
const templatePath=path.join(g.resource,'map/multi/dcg_shaforovo/campaign_capture_the_flag.mi');
const template=fs.readFileSync(templatePath,'latin1'),original=s.parse(template).children[0],old=g.mapData(template);
const oldNav=new NavGrid(fs.readFileSync(path.join(work,'multi/dcg_shaforovo/map.net')));
const name=n=>s.name(n),value=(n,key)=>s.child(n,key)?.tokens[1]?.value;
const position=n=>s.child(n,'Position')||s.child(n,'position');
const xyz=n=>position(n).tokens.slice(1).map(t=>Number(t.value));
const distance=(a,b)=>Math.hypot(a[0]-b[0],a[1]-b[1]);
const avg=points=>[0,1].map(i=>points.reduce((a,p)=>a+p[i],0)/points.length);
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
function edit(text,edits){for(const e of edits.sort((a,b)=>b.start-a.start))text=text.slice(0,e.start)+e.text+text.slice(e.end);return text;}
function pickFlags(flags,entries) {
    const eligible=flags.filter(f=>entries.every(e=>distance(f.point,e)>5000));
    assert(eligible.length>=5,'Not enough objectives clear of all deployment points');
    const centre=avg(entries);eligible.sort((a,b)=>distance(a.point,centre)-distance(b.point,centre));
    const first=eligible.shift(),selected=[first];
    while(selected.length<5){eligible.sort((a,b)=>Math.min(...selected.map(f=>distance(f.point,b.point)))-Math.min(...selected.map(f=>distance(f.point,a.point))));selected.push(eligible.shift());}
    return selected;
}
function build(spec) {
    const folder=path.join(work,'multi',spec.name),effective=path.join(g.resource,'map/multi',spec.name,'battle_zones.mi');
    const source=fs.readFileSync(fs.existsSync(effective)?effective:path.join(folder,'battle_zones.mi'),'latin1');
    const map=fs.readFileSync(path.join(folder,'map'),'latin1'),nav=new NavGrid(fs.readFileSync(path.join(folder,'map.net')));
    const m=s.parse(source).children[0],entities=m.children.filter(n=>name(n)==='Entity');
    const entries={};
    for(const n of entities){const ext=s.child(n,'Extender'),id=ext&&value(ext,'name');if(/^[ab][1-4]$/.test(id))entries[id]=xyz(n);}
    assert.equal(Object.keys(entries).length,8);
    const flags=pickFlags(entities.filter(n=>/^flag_point_\d+$/.test(n.tokens[1].value)).map(n=>({name:value(s.child(n,'Extender'),'name'),zone:value(s.child(s.child(n,'Extender'),'zone'),'zoneId'),point:xyz(n)})).filter(f=>nav.suitable(...f.point)),Object.values(entries));
    const clip=s.all(s.parse(map),n=>name(n)==='pather')[0].tokens.slice(1).map(t=>Number(t.value));
    const bounds=[clip[0]+400,clip[1]+400,clip[2]-400,clip[3]-400];
    const oldA=avg(Object.entries(old.entries).filter(([k])=>k[0]==='a').map(([,p])=>p));
    const oldB=avg(Object.entries(old.entries).filter(([k])=>k[0]==='b').map(([,p])=>p));
    const newA=avg(Object.entries(entries).filter(([k])=>k[0]==='a').map(([,p])=>p));
    const newB=avg(Object.entries(entries).filter(([k])=>k[0]==='b').map(([,p])=>p));
    const rotation=Math.atan2(newB[1]-newA[1],newB[0]-newA[0])-Math.atan2(oldB[1]-oldA[1],oldB[0]-oldA[0]);
    const rotate=p=>[Math.cos(rotation)*p[0]-Math.sin(rotation)*p[1],Math.sin(rotation)*p[0]+Math.cos(rotation)*p[1]];
    const project=(p,flag)=>{const o=old.flags[String(flag)],n=flags[flag-1].point,r=rotate([p[0]-o[0],p[1]-o[1]]);return [n[0]+r[0],n[1]+r[1]];};
    const tags=new Map(original.children.filter(n=>name(n)==='Tags').map(n=>[n.tokens.at(-1).value,n.tokens.slice(1,-1).map(t=>t.value)]));
    const actorNodes=original.children.filter(n=>['Entity','Human'].includes(name(n))),actorById=new Map(actorNodes.map(n=>[n.tokens.at(-1).value,n]));
    const reserved=new Set(s.all(s.parse(map),n=>['Entity','Human'].includes(name(n))).map(n=>n.tokens.at(-1).value.toLowerCase()));
    const ids=new Map();let next=0x100000;
    for(const n of actorNodes){while(reserved.has('0x'+next.toString(16)))next++;ids.set(n.tokens.at(-1).value,'0x'+(next++).toString(16));}
    const actors=new Map(),airIds=new Set(),flagsById=new Map(),startsById=new Map();
    for(const n of actorNodes){const id=n.tokens.at(-1).value,ts=tags.get(id)||[];
        const flag=ts.find(t=>/^fpc[1-5]$/.test(t));if(flag)flagsById.set(id,Number(flag.slice(-1)));
        const start=ts.find(t=>/^[ab][1-4]$/.test(t));if(start)startsById.set(id,start);
        if(ts.includes('air_vehicle'))airIds.add(id);
    }
    for(const link of original.children.filter(n=>name(n)==='Link'))if(link.children.some(c=>c.tokens.some(t=>airIds.has(t.value))))airIds.add(link.tokens[1].value);
    let snapped=0;
    for(const n of actorNodes){
        const id=n.tokens.at(-1).value,p=xyz(n),ts=tags.get(id)||[];
        if(airIds.has(id)){actors.set(id,{point:p,raw:p,air:true});continue;}
        let target;
        if(flagsById.has(id))target=flags[flagsById.get(id)-1].point;
        else if(startsById.has(id))target=entries[startsById.get(id)];
        else {
            const arrow=ts.find(t=>/^[ab]_[1-4]$/.test(t));
            if(arrow)target=entries[arrow.replace('_','')];
            else {const f=Number(ts.map(t=>t.match(/^([1-5])_[ab](?:_|$)|^mines_([1-5])_/)).find(Boolean)?.slice(1).find(Boolean)||
                Object.keys(old.flags).sort((a,b)=>distance(p,old.flags[a])-distance(p,old.flags[b]))[0]);target=project(p,f);}
        }
        let point;
        if(flagsById.has(id)||startsById.has(id)){
            assert(nav.dry(...target),'Native flag or spawn is not on dry ground');
            point=[...target.slice(0,2),nav.cell(...target).height];
        } else point=nav.nearest(target,bounds);
        if(distance(point,target)>1)snapped++;
        actors.set(id,{point,raw:target});
    }
    // Native scene defenders are separate from the Lua-bought opening garrison.
    // Their preview slots exist before player_spawn_name is set, so keep them clear
    // of every possible player entry rather than leaving a first-frame firing loophole.
    let reserves=null,staticRelocated=0;const occupied=new Map();
    for(const n of actorNodes){
        const id=n.tokens.at(-1).value,a=actors.get(id),ts=tags.get(id)||[];
        if(!ts.includes('cmp_def')||!(name(n)==='Human'||n.tokens[1]?.value==='spawn_point'))continue;
        const kind=name(n)==='Human'?'infantry':'vehicle';
        const required=g.config.weaponEnvelopeMetres[kind]*g.config.botRangeScale+g.config.startZoneMetres+g.config.marginMetres+g.config.randomScatterMetres;
        if(Object.values(entries).every(e=>distance(a.point,e)/20>=required))continue;
        if(!reserves){reserves=[];for(let x=bounds[0];x<=bounds[2];x+=200)for(let y=bounds[1];y<=bounds[3];y+=200)
            if(nav.suitable(x,y))reserves.push([x,y,nav.cell(x,y).height]);}
        const safe=reserves.filter(p=>Object.values(entries).every(e=>distance(p,e)/20>=required));
        assert(safe.length,'No safe native defense reserve for '+spec.name+' '+kind);
        const score=p=>distance(p,a.point)/20+(occupied.get(g.occupancyKey(p))||0)*35;
        safe.sort((a,b)=>score(a)-score(b));a.point=safe[0];a.movedGuard=true;staticRelocated++;
        const key=g.occupancyKey(a.point);occupied.set(key,(occupied.get(key)||0)+1);
    }
    const output=[],removedCover=[];
    for(const n of original.children){
        if(name(n)==='Helpers')continue;
        let body=template.slice(n.start,n.end);
        if(['Entity','Human'].includes(name(n))){
            const id=n.tokens.at(-1).value,a=actors.get(id),local=s.parse(body).children[0],edits=[];
            if(!a.air){
                const cover=s.child(local,'Cover'),link=cover&&s.all(cover,x=>name(x)==='link')[0],linked=link&&actors.get(link.tokens[1].value);
                if(cover&&(!linked||a.movedGuard)){
                    edits.push({start:cover.start,end:cover.end,text:''});const state=s.child(local,'FsmState');if(state)edits.push({start:state.start,end:state.end,text:''});removedCover.push(id);
                } else if(cover) {
                    // Keep wall/sector geometry aligned with its retained sandbag, including terrain relocation.
                    const linkedNode=actorById.get(link.tokens[1].value),oldPoint=xyz(linkedNode),delta=rotate(oldPoint);
                    const transform=p=>{const r=rotate(p);return [r[0]-delta[0]+linked.point[0],r[1]-delta[1]+linked.point[1]];};
                    const coverEdits=[];let coverSafe=true;
                    const footRequired=g.config.weaponEnvelopeMetres.infantry*g.config.botRangeScale+g.config.startZoneMetres+g.config.marginMetres+g.config.randomScatterMetres;
                    for(const c of s.all(cover,x=>['sector','wall'].includes(name(x)))) {
                        const nums=c.tokens.slice(1).map(t=>Number(t.value));const pairs=[];
                        for(let i=0;i<nums.length;i+=2)pairs.push(...transform(nums.slice(i,i+2)));
                        if(name(c)==='sector')coverSafe=coverSafe&&nav.suitable(...pairs)&&Object.values(entries).every(e=>distance(pairs,e)/20>=footRequired);
                        for(let i=0;i<pairs.length;i++)coverEdits.push({start:c.tokens[i+1].start,end:c.tokens[i+1].end,text:String(pairs[i])});
                    }
                    const offset=rotate([xyz(n)[0]-oldPoint[0],xyz(n)[1]-oldPoint[1]]);
                    const adjusted=[linked.point[0]+offset[0],linked.point[1]+offset[1]];
                    if(coverSafe&&nav.suitable(...adjusted)&&adjusted[0]>=bounds[0]&&adjusted[0]<=bounds[2]&&adjusted[1]>=bounds[1]&&adjusted[1]<=bounds[3]){
                        a.point=[...adjusted,nav.cell(...adjusted).height];edits.push(...coverEdits);
                    } else {
                        edits.push({start:cover.start,end:cover.end,text:''});const state=s.child(local,'FsmState');if(state)edits.push({start:state.start,end:state.end,text:''});removedCover.push(id);
                    }
                }
                const p=position(local);edits.push({start:p.start,end:p.end,text:'{Position '+a.point.join(' ')+'}'});
                const xform=s.child(local,'xform');
                if(xform){for(let i=1;i<xform.tokens.length-1;i++){
                    const key=xform.tokens[i].value,token=xform.tokens[i+1];
                    if(key==='zl')edits.push({start:token.start,end:token.end,text:String(Number(token.value)+rotation*180/Math.PI)});
                    if(key==='zw'){const oldHeight=oldNav.cell(...xyz(n))?.height;assert(oldHeight!==undefined);edits.push({start:token.start,end:token.end,text:String(a.point[2]+Number(token.value)-oldHeight)});}
                }}
            }
            body=edit(body,edits);
        }
        const ast=s.parse(body),edits=[];
        for(const c of [ast,...s.all(ast,()=>true)])for(const t of c.tokens)if(ids.has(t.value))edits.push({start:t.start,end:t.end,text:ids.get(t.value)});
        output.push(edit(body,edits));
    }
    const helper=s.child(original,'Helpers'),helperParts=[];
    const hfWaypoints=fs.readFileSync(path.join(g.resource,'map/multi/HF-dcg_waypoints.inc'),'latin1');
    const localHF=[];
    for(const wp of s.parse(hfWaypoints).children){
        const oldPoint=xyz(wp),id=name(wp);let target;
        if(s.all(wp,x=>name(x)==='delete').length){
            // HF exit markers describe the edge of its original 800 m square.
            // Retain their edge role on this map rather than moving them to an objective.
            target=[(clip[0]+clip[2])/2+oldPoint[0]/8000*(clip[2]-clip[0])/2,
                (clip[1]+clip[3])/2+oldPoint[1]/8000*(clip[3]-clip[1])/2];
        } else if(id==='1090')target=avg(flags.map(f=>f.point));
        else {const flag=Object.keys(old.flags).sort((a,b)=>distance(oldPoint,old.flags[a])-distance(oldPoint,old.flags[b]))[0];target=project(oldPoint,Number(flag));}
        const point=nav.nearest(target,bounds),p=position(wp);
        localHF.push(edit(hfWaypoints.slice(wp.start,wp.end),[{start:p.start-wp.start,end:p.end-wp.start,text:'{position '+point.join(' ')+'}'}]));
    }
    for(const n of helper.children){
        if(name(n)==='zone')continue;
        let body=template.slice(n.start,n.end);
        if(name(n)==='waypoints') {
            body=body.replace(/\(include "ufb_garrison_layout\.inc"\)/,'');
            const edits=[];
            for(const wp of n.children.filter(x=>position(x))){const id=name(wp),group=n.tokens[1]?.value;let target;
                if(id==='0'||id==='6')target=avg(flags.map(f=>f.point));
                else {let flag=group?.match(/_f([1-5])_/)?.[1]||(/^[1-5]$/.test(id)?id:String(Number(id)-(group==='a_def_spawns'?14:19)));assert(old.flags[flag]);target=project(xyz(wp),Number(flag));}
                const p=position(wp),point=nav.nearest(target,bounds);
                edits.push({start:p.start-n.start,end:p.end-n.start,text:'{position '+point.join(' ')+'}'});
            }
            // Offsets must be applied before deleting the old include.
            body=edit(template.slice(n.start,n.end),edits).replace(/\(include "ufb_garrison_layout\.inc"\)/,'');
            body=body.replace('(include "../HF-dcg_waypoints.inc")',localHF.join('\r\n'));
        }
        if(name(n)==='triggers'&&spec.landscape==='winter')body=body.replace('../HF-dcg_dynamic_weather.inc','../HF-dcg_dynamic_weather_winter.inc');
        helperParts.push(body);
    }
    const rectangle=(name,rect)=>'{zone "poly" {position 0 0 0}{Name "'+name+'"}'+[[rect[0],rect[1]],[rect[0],rect[3]],[rect[2],rect[3]],[rect[2],rect[1]]].map(p=>'{Point '+p.join(' ')+'}').join('')+'}';
    helperParts.push(rectangle('gamezone',clip),rectangle('combat',clip));
    for(let i=1;i<=5;i++){
        const originalZone=s.all(m,n=>name(n)==='zone'&&value(n,'Name')===flags[i-1].zone)[0];assert(originalZone,'Missing MP objective polygon '+flags[i-1].zone);
        helperParts.push(source.slice(originalZone.start,originalZone.end).replace('{Name "'+flags[i-1].zone+'"}','{Name "fpc'+i+'"}'));
        const p=nav.nearest(flags[i-1].point,bounds);helperParts.push('{zone "circle" {position '+p.join(' ')+'}{Name "forward'+i+'"}{Radius 1600}}');
    }
    for(const [id,p] of Object.entries(entries))helperParts.push('{zone "circle" {position '+p.slice(0,2).join(' ')+' '+nav.cell(...p).height+'}{Name "'+id[0]+'_'+id[1]+'"}{Radius 800}}');
    for(let i=1;i<=3;i++)helperParts.push('{zone "circle" {position 0 0 0}{Name "_bridge'+i+'"}{Radius 0}}');
    const base='{mission\r\n'+output.join('\r\n')+'\r\n{Helpers\r\n'+helperParts.join('\r\n')+'\r\n}\r\n}\r\n';
    const built=g.layout(base),data=g.mapData(base),group=data.script.children.find(n=>name(n)==='waypoints');
    const mission=base.slice(0,group.end-1)+'\r\n(include "ufb_garrison_layout.inc")\r\n'+base.slice(group.end-1);
    const info=';SDL\r\n{game {maxPlayers 8}{mapSelection 1}{landscape '+spec.landscape+'}'+(spec.tex?'{texMod '+spec.tex+'}':'')+'}\r\n';
    return {mission,info,layout:built.text,base,report:{...spec,sourceMissionSHA256:sha(Buffer.from(source,'latin1')),templateSHA256:sha(Buffer.from(template,'latin1')),
        sourceNavigationSHA256:sha(nav.b),objectives:flags,entries,actorCount:actorNodes.length,snappedActors:snapped,localHFWaypoints:localHF.length,staticDefenseSlotsRelocated:staticRelocated,removedCoverLinks:removedCover.length,rotationDegrees:rotation*180/Math.PI,garrison:built.report}};
}
if(require.main===module){
    const reports=[],files=[];fs.mkdirSync(path.join(work,'baseline'),{recursive:true});
    const builds=maps.map(spec=>({spec,b:build(spec)}));
    for(const {spec,b} of builds){const rel='map/multi/'+spec.name;reports.push(b.report);
        const baseFile=path.join(work,'generated-baseline',rel,'campaign_capture_the_flag.mi');fs.mkdirSync(path.dirname(baseFile),{recursive:true});fs.writeFileSync(baseFile,b.base,'latin1');
        for(const [leaf,text] of [['campaign_capture_the_flag.mi',b.mission],['campaign_capture_the_flag.info',b.info],['ufb_garrison_layout.inc',b.layout]]){
            const file=rel+'/'+leaf,dest=path.join(g.resource,file);assert(!fs.existsSync(dest)||process.argv.includes('--rebuild'),'Existing source file: '+file);
            fs.mkdirSync(path.dirname(dest),{recursive:true});fs.writeFileSync(dest,text,'latin1');files.push(file);
        }
    }
    fs.writeFileSync(path.join(__dirname,'../docs/realism/CONQUEST_MAPS_ADDED.json'),JSON.stringify({maps:reports,files},null,2)+'\n');
    console.log(JSON.stringify({maps:reports.map(r=>r.name),files:files.length,rangeShortfalls:reports.map(r=>({map:r.name,positions:r.garrison.unresolved}))}));
}
module.exports={build,maps,work};
