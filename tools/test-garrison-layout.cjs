const fs=require('fs'),path=require('path'),assert=require('assert/strict');
const s=require('./lib/sdl.cjs'),g=require('./garrison-layout.cjs');
const wp=require('./lib/gem-waypoints.cjs');
const staging=require('./lib/garrison-staging.cjs');
const baseline=path.resolve(process.argv[2]||'../_survival_work/garrison-safe-20261007/baseline');
const reports=JSON.parse(fs.readFileSync(path.join(__dirname,'../docs/realism/GARRISON_LAYOUT_REPORT.json')));
const read=p=>fs.readFileSync(p,'latin1');
function tree(n,convert=x=>x) {return {kind:n.kind,tokens:n.tokens.map(t=>convert(t.value,n)),children:n.children.map(c=>tree(c,convert))};}
function unrouted(n) {
    const cases=n.children.filter(c=>s.name(c)==='case');
    const routed=s.name(n)==='switch' && cases.length===4 && cases.every(c=>
        s.child(s.child(c,'condition'),'var')?.tokens[1]?.value==='player_spawn_name$');
    if(routed){const children=s.child(n,'default').children;assert.equal(children.length,1);return unrouted(children[0]);}
    return {kind:n.kind,tokens:n.tokens.map(t=>t.value),children:n.children.map(unrouted)};
}
let variants=0,points=0,unsafe=0,infantryUnsafe=0;
const refs=[];
for(const [source,dest] of [['dcg_functions.inc','ufb_garrison_functions.inc'],['dcg_script.inc','ufb_garrison_script.inc']]) {
    const original=read(path.join(baseline,source)), changed=read(path.join(g.resource,'map/multi',dest));
    assert.deepEqual(unrouted(s.parse(changed)),unrouted(s.parse(original)),'Routing altered native commands: '+dest);
    refs.push(...s.all(s.parse(changed),n=>['waypoint','target_waypoint'].includes(s.name(n))&&n.tokens.length===2).map(n=>n.tokens[1].value));
}
for(const m of reports.maps) {
    const rel='map/multi/'+m.map,original=read(path.join(baseline,rel,'campaign_capture_the_flag.mi'));
    const modified=read(path.join(g.resource,rel,'campaign_capture_the_flag.mi'));
    wp.collect(path.join(g.resource,rel,'campaign_capture_the_flag.mi'),g.resource);
    const zonesFixed=m.map==='dcg_karvola_winter'?staging.repairKarvolaZones(original,g.mapData(original)):original;
    const expectedOriginal=staging.repairAddedAnchors(zonesFixed,g.mapData(zonesFixed)).text;
    assert.equal(modified.replace('\r\n(include "ufb_garrison_layout.inc")\r\n','')
        .replace('"../ufb_garrison_functions.inc"','"../dcg_functions.inc"')
        .replace('"../ufb_garrison_script.inc"','"../dcg_script.inc"'),expectedOriginal,'Unrelated mission changes: '+m.map);
    const data=g.mapData(original), generated=s.parse(read(path.join(g.resource,rel,'ufb_garrison_layout.inc')));
    const ids=new Set(generated.children.map(s.name));assert.equal(ids.size,generated.children.length);
    for(const id of ids)assert(!data.points.has(id),'Collision with original ID');
    for(const ref of refs)assert(data.points.has(ref)||ids.has(ref),'Dangling shared target '+m.map+' '+ref);
    for(let spawn=1;spawn<=8;spawn++) {
        variants++;
        const entryName=(spawn<=4?'a':'b')+((spawn-1)%4+1),entry=data.entries[entryName];
        const side=spawn<=4?'b':'a',v=m.variants.find(v=>v.entry===entryName),found=new Set();
        const authored={infantry:[],vehicle:[]};
        for(const [id,n] of data.points){const group=data.groups.get(id);if(group.startsWith(side+'_f'))
            authored[group.endsWith('_inf')?'infantry':'vehicle'].push((s.child(n,'position')||s.child(n,'Position')).tokens.slice(1).map(t=>Number(t.value)));}
        const expected=[...data.points.keys()].filter(id=>data.groups.get(id).startsWith(side+'_')||/^[1-5]$/.test(id));
        for(const id of expected) {
            const alias=g.alias(spawn,id),n=generated.children.find(n=>s.name(n)===alias);assert(n,'Missing alias '+m.map+' '+alias);points++;
            const group=data.groups.get(id),kind=group.endsWith('_inf')||/^[1-5]$/.test(id)?'infantry':'vehicle';
            const originalNode=data.points.get(id), selected=s.parse(g.selectSide(original.slice(originalNode.start,originalNode.end),side==='a'?1:2)).children[0];
            const bodyShape=node=>tree(node,(value,owner)=>{
                if(['position','Position'].includes(s.name(owner)))return 'coordinate';
                const identifier=value===s.name(owner)&&(s.child(owner,'position')||s.child(owner,'Position'));
                const reference=['waypoint','transition','target_waypoint'].includes(s.name(owner))&&owner.tokens.length===2&&value===owner.tokens[1].value;
                return (identifier||reference)&&g.aliasParts(value)?g.aliasParts(value).id:value;
            });
            assert.deepEqual(bodyShape(n),bodyShape(selected),'Changed garrison command '+alias);
            const p=(s.child(n,'position')||s.child(n,'Position')).tokens.slice(1).map(t=>Number(t.value));
            const op=(s.child(originalNode,'position')||s.child(originalNode,'Position')).tokens.slice(1).map(t=>Number(t.value));
            assert(p.every(Number.isFinite));
            assert(JSON.stringify(p)===JSON.stringify(op)||authored[kind].some(c=>JSON.stringify(c)===JSON.stringify(p)),'Invented fallback coordinate');
            const spread=Number(s.child(n,'radius')?.tokens[1]?.value||0)/20;
            const random=Number(s.child(n,'RandomPosition')?.tokens[1]?.value||0)>0?g.config.randomScatterMetres:0;
            const required=g.config.weaponEnvelopeMetres[kind]*g.config.botRangeScale+g.config.startZoneMetres+g.config.marginMetres+spread+random;
            const d=Math.hypot(p[0]-entry[0],p[1]-entry[1])/20;
            if(d+1e-8<required){unsafe++;if(kind==='infantry')infantryUnsafe++;found.add(id);
                const issue=v.unsupported.find(x=>x.id===id);assert(issue,'Unreported shortfall');assert(Math.abs(issue.availableMetres-d)<1e-8);}
            for(const ref of s.all(n,r=>['waypoint','transition'].includes(s.name(r))&&r.tokens.length===2)) {
                assert(ids.has(ref.tokens[1].value),'Dangling chain target');
                assert.equal(g.aliasParts(ref.tokens[1].value).spawn,spawn,'Chain crosses entry layouts');
            }
        }
        assert.equal(found.size,v.unsupported.length,'Stale shortfall report');
        assert.equal(generated.children.filter(n=>g.aliasParts(s.name(n)).spawn===spawn).length,expected.length);
    }
}
assert.equal(variants,912);assert.equal(infantryUnsafe,0,'Infantry protection must hold on every supported entrance');
// Regression: no available position must cause a tank pile at one farthest waypoint.
const p=g.choose([8000,0],[{id:'x',point:[8000,0]},{id:'y',point:[7800,0]}],[0,0],600,[8000,0],new Map([[g.occupancyKey([8000,0]),10]]),false);
assert.equal(p.safe,false);assert.deepEqual(p.point,[7800,0]);
console.log(JSON.stringify({maps:reports.maps.length,entrances:variants,waypoints:points,reportedRangeShortfalls:unsafe,infantryRangeShortfalls:infantryUnsafe,nativeCommandsPreserved:true,unrelatedMissionContentPreserved:true}));
