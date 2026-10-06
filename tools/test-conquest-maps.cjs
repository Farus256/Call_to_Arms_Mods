const fs=require('fs'),path=require('path'),assert=require('assert/strict'),crypto=require('crypto');
const s=require('./lib/sdl.cjs'),NavGrid=require('./lib/gem-nav.cjs'),g=require('./garrison-layout.cjs');
const report=require('../docs/realism/CONQUEST_MAPS_ADDED.json');
const work=path.resolve(process.argv[2]||'../_survival_work/conquest-maps-20261007');
const sha=b=>crypto.createHash('sha256').update(b).digest('hex');
const read=p=>fs.readFileSync(p,'latin1'),name=s.name;
const val=(n,key)=>s.child(n,key)?.tokens[1]?.value;
const p=n=>(s.child(n,'Position')||s.child(n,'position')).tokens.slice(1).map(t=>Number(t.value));
const references=a=>s.all(a,n=>['transition','waypoint','target_waypoint'].includes(name(n))&&n.tokens.length===2).map(n=>n.tokens[1].value);
const known=[['4v4_fields',[-645.418,-94.5603],1,5],['4v4_grassland',[857.831,-4013.31],96,5],
    ['4v4_grassland',[-1221.6,3731.43],-120,5],['4v4_winter_walk',[-7770.62,-6398.75],107,10]];
for(const [map,point,z,step] of known){const grid=new NavGrid(fs.readFileSync(path.join(work,'multi',map,'map.net')));assert.equal(grid.step,step);assert.equal(grid.cell(...point).height,z);assert.equal(grid.cell(1e9,1e9),null);}
assert.throws(()=>new NavGrid(Buffer.alloc(100)));
let actors=0,waypoints=0,cover=0,entrances=0;
const template=s.parse(read(path.join(work,'template-before.mi'))).children[0];
const originalActorCount=template.children.filter(n=>['Entity','Human'].includes(name(n))).length;
const originalTags=template.children.filter(n=>name(n)==='Tags').map(n=>n.tokens.slice(0,-1).map(t=>t.value));
const sharedRefs=['ufb_garrison_functions.inc','ufb_garrison_script.inc'].flatMap(f=>references(s.parse(read(path.join(g.resource,'map/multi',f))))).filter(x=>Number(x)>=11000);
for(const m of report.maps){
    const dir=path.join(g.resource,'map/multi',m.name),mission=read(path.join(dir,'campaign_capture_the_flag.mi'));
    const root=s.parse(mission).children[0],data=g.mapData(mission),grid=new NavGrid(fs.readFileSync(path.join(work,'multi',m.name,'map.net')));
    const currentMP=fs.readFileSync(path.join(dir,'battle_zones.mi'));assert.equal(sha(currentMP),m.sourceMissionSHA256,'MP mission changed');
    assert.equal(sha(grid.b),m.sourceNavigationSHA256);
    const info=s.parse(read(path.join(dir,'campaign_capture_the_flag.info'))).children[0];
    assert.equal(val(info,'maxPlayers'),'8');assert.equal(val(info,'mapSelection'),'1');assert.equal(val(info,'landscape'),m.landscape);
    assert.equal(m.garrison.unresolved,0,'This map must satisfy both configured range profiles');
    const zoneNames=data.script.children.filter(n=>name(n)==='zone').map(n=>val(n,'Name'));
    for(const key of ['gamezone','combat','fpc1','fpc2','fpc3','fpc4','fpc5','forward1','forward2','forward3','forward4','forward5',...['a','b'].flatMap(s=>[1,2,3,4].map(i=>s+'_'+i))])assert(zoneNames.includes(key),'Missing native zone '+key);
    assert.equal(new Set(zoneNames).size,zoneNames.length);
    for(const [id,start] of Object.entries(m.entries))assert.deepEqual(data.entries[id].slice(0,2),start.slice(0,2),'Stock spawn entry shifted');
    for(let i=1;i<=5;i++)assert.deepEqual(data.flags[i].slice(0,2),m.objectives[i-1].point.slice(0,2),'Stock objective shifted');
    const nodes=root.children.filter(n=>['Entity','Human'].includes(name(n))),ids=new Set(nodes.map(n=>n.tokens.at(-1).value));
    assert.equal(nodes.length,originalActorCount);assert.equal(ids.size,nodes.length);actors+=nodes.length;
    assert.deepEqual(root.children.filter(n=>name(n)==='Tags').map(n=>n.tokens.slice(0,-1).map(t=>t.value)),originalTags,'Defense-stage or role tags changed');
    const world=s.parse(read(path.join(work,'multi',m.name,'map'))),worldIds=new Set(s.all(world,n=>['Entity','Human'].includes(name(n))).map(n=>n.tokens.at(-1).value));
    for(const id of ids)assert(!worldIds.has(id),'Actor ID collides with native terrain object');
    const tags=new Map(root.children.filter(n=>name(n)==='Tags').map(n=>[n.tokens.at(-1).value,n.tokens.slice(1,-1).map(t=>t.value)]));
    const air=new Set([...tags].filter(([,v])=>v.includes('air_vehicle')).map(([id])=>id));
    for(const l of root.children.filter(n=>name(n)==='Link'))if(l.children.some(c=>c.tokens.some(t=>air.has(t.value))))air.add(l.tokens[1].value);
    for(const n of nodes){const id=n.tokens.at(-1).value;if(!air.has(id)){const point=p(n);assert.equal(point.length,3);assert(grid.suitable(...point),'Ground actor not on dry, gentle terrain '+m.name+' '+id);assert.equal(point[2],grid.cell(...point).height);}
        if(tags.get(id)?.includes('cmp_def')&&(name(n)==='Human'||n.tokens[1]?.value==='spawn_point')){
            const kind=name(n)==='Human'?'infantry':'vehicle';
            const required=g.config.weaponEnvelopeMetres[kind]*g.config.botRangeScale+g.config.startZoneMetres+g.config.marginMetres+g.config.randomScatterMetres;
            for(const entry of Object.values(data.entries))assert(g.distance(p(n),entry)>=required,'Native scene defender can fire on an entry');
        }
        const c=s.child(n,'Cover');if(c){cover++;
            for(const link of s.all(c,n=>name(n)==='link'))assert(ids.has(link.tokens[1].value),'Cover points to foreign map');
            for(const sector of s.all(c,n=>name(n)==='sector'))assert(grid.dry(Number(sector.tokens[1].value),Number(sector.tokens[2].value)),'Cover sector on water');
        }
    }
    for(const n of root.children.filter(n=>['Tags','Inventory','Brain','Link'].includes(name(n)))) {
        const own=name(n)==='Tags'?n.tokens.at(-1).value:n.tokens[1]?.value;assert(ids.has(own),'Dangling actor record '+name(n));
        if(name(n)==='Link')for(const c of n.children)assert(ids.has(c.tokens[0].value),'Dangling crew vehicle');
    }
    const layout=s.parse(read(path.join(dir,'ufb_garrison_layout.inc'))),allIds=new Set([...data.points.keys(),...layout.children.map(name)]);
    assert(!mission.includes('(include "../HF-dcg_waypoints.inc")'),'Foreign fixed HF waypoint coordinates retained');
    assert.equal([...data.points.keys()].filter(id=>Number(id)>=1007&&Number(id)<=1090).length,m.localHFWaypoints);
    assert.equal(allIds.size,data.points.size+layout.children.length,'Duplicate waypoint IDs');
    for(const ref of [...sharedRefs,...references(layout)])assert(allIds.has(ref),'Dangling garrison destination '+ref);
    for(const wp of data.points.values())for(const ref of references(wp))assert(allIds.has(ref),'Dangling native/HF destination '+ref);
    for(const wp of [...data.points.values(),...layout.children]){const point=p(wp);assert(grid.suitable(...point),'Waypoint outside navigable terrain');assert.equal(point[2],grid.cell(...point).height);waypoints++;}
    for(let spawn=1;spawn<=8;spawn++){const entry=(spawn<=4?'a':'b')+((spawn-1)%4+1);entrances++;
        for(const wp of layout.children.filter(n=>Math.floor((Number(name(n))-10000)/1000)===spawn)){
            const oldId=String((Number(name(wp))-10000)%1000),group=data.groups.get(oldId),kind=group.endsWith('_inf')||/^[1-5]$/.test(oldId)?'infantry':'vehicle';
            const spread=Number(val(wp,'radius')||0)/20,random=Number(val(wp,'RandomPosition')||0)>0?g.config.randomScatterMetres:0;
            const required=g.config.weaponEnvelopeMetres[kind]*g.config.botRangeScale+g.config.startZoneMetres+g.config.marginMetres+spread+random;
            assert(g.distance(p(wp),data.entries[entry])>=required-1e-8,'Unprotected initial waypoint '+name(wp));
            for(const ref of references(wp))assert.equal(Math.floor((Number(ref)-10000)/1000),spawn,'Garrison chain crosses player entries');
        }
    }
}
assert.equal(report.maps.length,3);assert.equal(report.files.length,9);
console.log(JSON.stringify({maps:3,entrances,actors,waypoints,retainedCoverLinks:cover,navigationReferenceSamples:known.length,nativeDefenseSlotsAndStagesPreserved:true,multiplayerMissionsPreserved:true}));
