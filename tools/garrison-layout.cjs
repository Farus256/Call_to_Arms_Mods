// Offline Conquest garrison relocation. No new runtime API or periodic scene scan.
const fs = require('fs'), path = require('path'), assert = require('assert/strict');
const s = require('./lib/sdl.cjs');
const wp = require('./lib/gem-waypoints.cjs');
const staging = require('./lib/garrison-staging.cjs');
const root = path.resolve(__dirname, '..');
const resource = path.join(root, 'mods/ultimate_frontline_bundle/resource');
const configFile = path.join(__dirname, 'garrison-layout.json');
const config = JSON.parse(fs.readFileSync(configFile));
assert.equal(config.unitsPerMetre,20,'GEM coordinates use 20 units per metre');
for(const value of Object.values(config.weaponEnvelopeMetres))assert(Number.isFinite(value)&&value>0);
for(const key of ['startZoneMetres','marginMetres','randomScatterMetres','coverMatchMetres','coverPreferenceMetres','reusePenaltyMetres','fallbackSpreadMetres','spacingCellMetres'])
    assert(Number.isFinite(config[key])&&config[key]>0,'Invalid layout setting '+key);
assert(Number.isFinite(config.botRangeScale)&&config.botRangeScale>=1);
const dir = path.join(resource, 'map/multi');
const val = (n, key) => s.child(n, key)?.tokens[1]?.value;
const pos = n => s.child(n, 'position') || s.child(n, 'Position');
const xyz = n => pos(n)?.tokens.slice(1).map(t => Number(t.value));
const distance = (a, b) => Math.hypot(a[0]-b[0], a[1]-b[1])/config.unitsPerMetre;
function edit(text, edits) {
    for (const e of edits.sort((a,b)=>b.start-a.start)) text = text.slice(0,e.start)+e.text+text.slice(e.end);
    return text;
}
// Numeric IDs must fit GoH's 8192-slot allocator. Keep all eight layouts
// above native/HF IDs (0..1090), with room for the authored IDs (0..736).
const aliasBase=1200,aliasStride=850;
function alias(spawn, id) {
    assert(Number.isInteger(spawn)&&spawn>=1&&spawn<=8,'Unsupported player entrance');
    assert(/^\d+$/.test(id)&&Number(id)<aliasStride,'Unsupported original waypoint ID '+id);
    const result=String(aliasBase+(spawn-1)*aliasStride+Number(id));wp.checkID(result);return result;
}
function aliasParts(id) {
    if(!/^\d+$/.test(id)||Number(id)<aliasBase||Number(id)>=aliasBase+8*aliasStride)return null;
    return {spawn:Math.floor((Number(id)-aliasBase)/aliasStride)+1,id:String((Number(id)-aliasBase)%aliasStride)};
}
const occupancyKey = p => p.slice(0,2).map(v=>Math.round(v/(config.unitsPerMetre*config.spacingCellMetres))).join(',');
function references(ast) {
    return s.all(ast, n => ['transition','waypoint','target_waypoint'].includes(s.name(n)) && n.tokens.length===2);
}
// The only side-dependent dispatch in waypoint bodies is the native bots_spawnside switch.
function selectSide(text, side) {
    const ast = s.parse(text), edits = [];
    for (const n of s.all(ast, n => s.name(n)==='switch')) {
        const branch = n.children.find(c => s.name(c)==='case' && val(s.child(c,'condition')||{children:[]},'var')==='bots_spawnside$');
        if (!branch) continue;
        const condition = s.child(branch,'condition');
        assert.equal(val(condition,'op'), '==');
        const selected = Number(val(condition,'value'))===side ? branch : s.child(n,'default');
        assert(selected, 'Missing native side default');
        edits.push({start:n.start,end:n.end,text:selected.children.filter(c=>s.name(c)!=='condition').map(c=>text.slice(c.start,c.end)).join('\r\n')});
    }
    // No nested side switch exists in the supplied missions. Refuse unsupported input.
    for (let i=0;i<edits.length;i++) for(let j=i+1;j<edits.length;j++)
        assert(edits[i].end<=edits[j].start || edits[j].end<=edits[i].start, 'Nested side switch');
    return edit(text, edits);
}
function choose(original, candidates, entry, required, objective, usage, cover) {
    if (distance(original,entry)>=required) return {point:original, changed:false, safe:true};
    let safe = candidates.filter(c=>distance(c.point,entry)>=required);
    let guaranteed = true;
    // If geometry cannot satisfy range, choose the farthest valid authored point and report it.
    // This is explicitly not a range guarantee and does not change firing/health/spawn timers.
    if (!safe.length) {
        assert(candidates.length, 'No authored fallback');
        const farthest = Math.max(...candidates.map(c=>distance(c.point,entry)));
        safe=candidates.filter(c=>distance(c.point,entry)>=farthest-config.fallbackSpreadMetres);
        guaranteed=false;
    }
    const score = c => distance(c.point,original)+distance(c.point,objective)*0.35 +
        (usage.get(occupancyKey(c.point))||0)*config.reusePenaltyMetres - (cover && c.cover ? config.coverPreferenceMetres : 0);
    safe.sort((a,b)=>score(a)-score(b) || a.id.localeCompare(b.id));
    const c = safe[0], key=occupancyKey(c.point); usage.set(key,(usage.get(key)||0)+1);
    return {point:c.point,changed:true,safe:guaranteed};
}
function mapData(text) {
    const mission = s.parse(text).children[0];
    const entities = new Map(mission.children.filter(n=>['Entity','Human'].includes(s.name(n))).map(n=>[n.tokens.at(-1).value,n]));
    const entries = {}, flags = {};
    for (const t of mission.children.filter(n=>s.name(n)==='Tags')) {
        const e = entities.get(t.tokens.at(-1).value); if (!e) continue;
        for (const token of t.tokens) {
            if (/^[ab][1-4]$/.test(token.value) && t.tokens.some(x=>/^spawn_[ab]$/.test(x.value))) entries[token.value]=xyz(e);
            if (/^fpc[1-5]$/.test(token.value)) flags[token.value.slice(-1)]=xyz(e);
        }
    }
    assert.equal(Object.keys(entries).length,8,'Expected all player entrances');
    assert.equal(Object.keys(flags).length,5,'Expected all objectives');
    const points = new Map(), groups = new Map();
    const script = mission.children.find(n=>s.child(n,'functions'));
    assert(script, 'Missing mission script');
    for (const group of script.children.filter(n=>s.name(n)==='waypoints')) {
        for(const n of group.children.filter(n=>pos(n))) {
            const id = s.name(n); wp.checkID(id); assert(!points.has(id),'Duplicate original waypoint '+id);
            points.set(id,n); groups.set(id,group.tokens[1]?.value||'common');
        }
    }
    const covers = [...entities.values()].filter(n=>s.child(n,'Cover')).map(xyz).filter(Boolean);
    return {entries, flags, points, groups, covers, script};
}
function layout(text) {
    const data = mapData(text), output = [], report = {variants:[], changed:0, unresolved:0};
    for (let spawn=1;spawn<=8;spawn++) {
        const entryName = (spawn<=4?'a':'b')+((spawn-1)%4+1), entry=data.entries[entryName];
        const side=spawn<=4?'b':'a', sideValue=side==='a'?1:2;
        const selected=new Map(), kinds=new Map(), flagOf=new Map();
        for (const [id,n] of data.points) {
            const group=data.groups.get(id);
            if (group.startsWith(side+'_') || /^[1-5]$/.test(id)) {
                assert(/^(?:[ab]_(?:def_spawns|f[1-5]_def_(?:inf|vehicle))|common)$/.test(group),'Unexpected group '+group);
                selected.set(id,selectSide(text.slice(n.start,n.end),sideValue));
                kinds.set(id,group.endsWith('_inf')||/^[1-5]$/.test(id)?'infantry':'vehicle');
                flagOf.set(id,group.match(/_f([1-5])_/)?.[1] || (/^[1-5]$/.test(id)?id: String(Number(id)-(side==='a'?14:19))));
            }
        }
        for (const [id,body] of selected) for (const ref of references(s.parse(body)))
            assert(selected.has(ref.tokens[1].value), 'Waypoint escapes garrison: '+id+' -> '+ref.tokens[1].value);
        const candidates={infantry:[],vehicle:[]};
        for (const [id] of selected) {
            // Dispatch hubs are not candidate cover or firing positions.
            const group=data.groups.get(id); if(!group.includes('_def_inf')&&!group.includes('_def_vehicle'))continue;
            const point=xyz(data.points.get(id)), kind=kinds.get(id);
            candidates[kind].push({id,point,cover:kind==='infantry' && data.covers.some(c=>distance(c,point)<=config.coverMatchMetres)});
        }
        // Only authored three-dimensional garrison waypoints are relocation candidates.
        // Spawn markers often omit height; inventing their Z risks underground placements.
        for(const kind of ['infantry','vehicle'])
            candidates[kind]=candidates[kind].filter(c=>c.point.length===3&&c.point.every(Number.isFinite));
        const usage=new Map(), variant={entry:entryName, relocated:0, unsupported:[], minClearanceMetres:Infinity};
        for(const kind of ['infantry','vehicle']) for(const c of candidates[kind])
            usage.set(occupancyKey(c.point),1); // Count physical places, including duplicate authored IDs.
        const records=[];
        for (const [id,body] of selected) {
            const ast=s.parse(body), n=ast.children[0], original=xyz(n), kind=kinds.get(id);
            const spread=Number(val(n,'radius')||0)/config.unitsPerMetre;
            // RandomPosition uses native placement, with a configured buffer for its unexposed scatter.
            const random=Number(val(n,'RandomPosition')||0)>0?config.randomScatterMetres:0;
            const required=config.weaponEnvelopeMetres[kind]*config.botRangeScale+config.startZoneMetres+config.marginMetres+spread+random;
            const objective=data.flags[flagOf.get(id)]; assert(objective,'Missing objective for '+id);
            const result=choose(original,candidates[kind],entry,required,objective,usage,kind==='infantry');
            assert(!data.points.has(alias(spawn,id)),'Garrison alias collides with original ID');
            const edits=[{start:n.tokens[0].start,end:n.tokens[0].end,text:'"'+alias(spawn,id)+'"'}];
            for (const r of references(ast)) edits.push({start:r.tokens[1].start,end:r.tokens[1].end,text:'"'+alias(spawn,r.tokens[1].value)+'"'});
            if(result.changed){ const p=pos(n); edits.push({start:p.start,end:p.end,text:'{position '+result.point.join(' ')+'}'}); variant.relocated++;report.changed++; }
            if(!result.safe){variant.unsupported.push({id,kind,requiredMetres:required,availableMetres:distance(result.point,entry)});report.unresolved++;}
            variant.minClearanceMetres=Math.min(variant.minClearanceMetres,distance(result.point,entry)-required);
            records.push({id:alias(spawn,id),body:edit(body,edits),point:result.point,required,safe:result.safe});
        }
        output.push('; player entry '+entryName+'\r\n'+records.map(x=>x.body).join('\r\n'));
        report.variants.push(variant);
    }
    return {text:'; Generated by tools/garrison-layout.cjs. Do not edit by hand.\r\n'+output.join('\r\n'),report};
}
function routeActions(text, predicate, command, key) {
    const ast=s.parse(text), edits=[];let count=0;
    function visit(n,side) {
        if(s.name(n)==='switch') {
            const branch=n.children.find(c=>s.name(c)==='case'&&val(s.child(c,'condition')||{children:[]},'var')==='bots_spawnside$');
            if(branch) {
                assert.equal(Number(val(s.child(branch,'condition'),'value')),1);
                for(const c of n.children) visit(c,s.name(c)==='case'?1:2);
                return;
            }
        }
        const ref=s.name(n)===command?s.all(n,x=>s.name(x)===key && x.tokens.length===2)[0]:null;
        if(!ref){for(const c of n.children)visit(c,side);return;}
        assert(side===1||side===2,'Missing defender side for action');
        const original=text.slice(n.start,n.end), token=ref.tokens[1];
        const cases=Array.from({length:4},(_,i)=>{
            const spawn=i+1+(side===1?4:0);
            const changed=edit(original,[{start:token.start-n.start,end:token.end-n.start,text:'"'+alias(spawn,token.value)+'"'}]);
            return '{"case" {condition {type cmp_i}{var "player_spawn_name$"}{op "=="}{value '+spawn+'}}\r\n'+changed+'}';
        });
        edits.push({start:n.start,end:n.end,text:'{"switch"\r\n'+cases.join('\r\n')+'\r\n{"default"\r\n'+original+'}}'});count++;
    }
    for(const owner of s.all(ast,predicate))visit(owner,null);
    assert(count>0,'No garrison routing actions');
    return {text:edit(text,edits),count};
}
function run(baselineDir, apply=false) {
    const functions=fs.readFileSync(path.join(baselineDir,'dcg_functions.inc'),'latin1');
    const missionScript=fs.readFileSync(path.join(baselineDir,'dcg_script.inc'),'latin1');
    const funcs=routeActions(functions,n=>/^flag[1-5]_bots_d$/.test(s.name(n)),'waypoint','waypoint');
    // Native forwardN selectors discover bought defenders at the staging
    // anchors 15..24. Only their subsequent combat destinations are relocated.
    const generated=new Map([['map/multi/ufb_garrison_functions.inc',funcs.text],['map/multi/ufb_garrison_script.inc',missionScript]]),report={maps:[],functionActions:funcs.count,spawnPlacements:0};
    for(const folder of fs.readdirSync(dir,{withFileTypes:true}).filter(x=>x.isDirectory()&&x.name.startsWith('dcg_'))) {
        const rel='map/multi/'+folder.name+'/campaign_capture_the_flag.mi', file=path.join(baselineDir,rel);
        if(!fs.existsSync(file))continue;
        const nativeText=fs.readFileSync(file,'latin1');
        const zonesFixed=folder.name==='dcg_karvola_winter'?staging.repairKarvolaZones(nativeText,mapData(nativeText)):nativeText;
        const text=staging.repairAddedAnchors(zonesFixed,mapData(zonesFixed)).text;
        const built=layout(text), data=mapData(text);
        const group=data.script.children.find(n=>s.name(n)==='waypoints');
        // Includes are local to their named waypoint group, just like the native HF include.
        let modified=text.slice(0,group.end-1)+'\r\n(include "ufb_garrison_layout.inc")\r\n'+text.slice(group.end-1);
        assert(text.includes('"../dcg_functions.inc"')&&text.includes('"../dcg_script.inc"'),'Map did not reference native scripts');
        modified=modified.replace('"../dcg_functions.inc"','"../ufb_garrison_functions.inc"').replace('"../dcg_script.inc"','"../ufb_garrison_script.inc"');
        generated.set(rel,modified);generated.set('map/multi/'+folder.name+'/ufb_garrison_layout.inc',built.text);
        report.maps.push({map:folder.name,...built.report});
    }
    assert.equal(report.maps.length,114,'Unexpected supported map count');
    if(apply) for(const [rel,text] of generated) fs.writeFileSync(path.join(resource,rel),text,'latin1');
    return {generated,report};
}
if(require.main===module){
    const baseline=process.argv[2];assert(baseline,'Pass backed-up baseline directory');
    const {report}=run(path.resolve(baseline),process.argv.includes('--apply'));
    const reportFile=path.join(root,'docs/realism/GARRISON_LAYOUT_REPORT.json');
    fs.writeFileSync(reportFile,JSON.stringify(report,null,2)+'\n');
    console.log(JSON.stringify({maps:report.maps.length,relocated:report.maps.reduce((a,m)=>a+m.changed,0),unresolved:report.maps.reduce((a,m)=>a+m.unresolved,0),functionActions:report.functionActions,spawnPlacements:report.spawnPlacements}));
}
module.exports={run,layout,mapData,selectSide,routeActions,choose,alias,aliasParts,distance,occupancyKey,config,resource};
