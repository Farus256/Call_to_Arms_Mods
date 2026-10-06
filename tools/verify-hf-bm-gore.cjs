// UFB gore must follow workshop/HF_BM_Patch (dismemberment, stock blood, pools) while keeping
// UFB persistence (no body-part delete timers) and UFB stress hooks. Usage: node tools/verify-hf-bm-gore.cjs
const fs = require('fs'), path = require('path'), assert = require('assert/strict');
const s = require('./lib/sdl.cjs');
const repo = path.resolve(__dirname, '..');
const ufb = path.join(repo, 'mods/ultimate_frontline_bundle/resource');
const bmp = path.join(repo, 'workshop/HF_BM_Patch/resource');
const text = (root, rel) => fs.readFileSync(path.join(root, rel), 'utf8').replace(/\r/g, '');
const strip = n => JSON.stringify(n, (k, v) => ['line', 'pos', 'start', 'end'].includes(k) ? undefined : v);
const parse = (root, rel) => s.parse(text(root, rel));
const handler = (ast, name) => strip(ast.children[0].children.find(n => s.name(n) === 'on' && n.tokens[1]?.value === name));
const entity = (ast, name) => strip(ast.children.find(n => n.tokens[0]?.value === name));
let checks = 0; const ok = (c, m) => { assert(c, m); checks++; };

const hU = parse(ufb, 'set/interaction_entity/human.inc'), hB = parse(bmp, 'set/interaction_entity/human.inc');
// Normalize the reviewed pool scheduler only; compare all remaining gore actions.
const dieU=hU.children[0].children.find(n=>s.name(n)==='on'&&n.tokens[1]?.value==='die_with_blood');
const dieB=hB.children[0].children.find(n=>s.name(n)==='on'&&n.tokens[1]?.value==='die_with_blood');
const oldPool=s.all(dieB,n=>s.name(n)==='delay'&&s.all(n,c=>s.name(c)==='spawn'&&c.tokens[1]?.value==='bloodstain').length)[0];
const newPool=s.all(dieU,n=>s.name(n)==='call'&&n.tokens[1]?.value==='ufb_schedule_corpse_pool')[0];
ok(!!oldPool&&!!newPool,'pool scheduling replaces the original corpse pool');
const deathSplash=s.all(dieU,n=>s.name(n)==='spawn'&&n.tokens[1]?.value==='ground_blood_small')[0];
ok(!!deathSplash,'death leaves a small splatter, never the independent large blood splash');
deathSplash.tokens[1].value='blood';
const parent=s.all(dieU,n=>n.children.includes(newPool))[0];
parent.children=parent.children.map(n=>n===newPool?oldPool:n);
for (const name of ['explosion', 'crush', 'bm_explosion', 'hit-light', 'hit-heavy', 'die_with_blood', 'ground_hit'])
  ok(handler(hU, name) === handler(hB, name), 'human.inc handler matches HF_BM_Patch: ' + name);
const human = text(ufb, 'set/interaction_entity/human.inc');
ok(human.includes('(include "ufb_stress.inc")') && (human.match(/call_synced "ufb_stress"/g) || []).length === 2, 'UFB stress hooks kept');
ok(human.includes('{if not dead {call "die_scream"}}'), 'corpses do not scream');

const dU = parse(ufb, 'set/interaction_entity/dummy.inc'), dB = parse(bmp, 'set/interaction_entity/dummy.inc');
// Only the reviewed landing trace changes; all BM body-part physics remain equal.
const limb=dU.children.find(n=>s.name(n)==='bm_limb_a');
const landing=s.all(limb,n=>s.name(n)==='on'&&n.tokens[1]?.value==='blood_stain')[0];
const paint=s.child(landing,'spawn');
ok(paint.tokens[1]?.value==='ground_blood_small','body part landing makes a small trace, never an immediate corpse pool');
paint.tokens[1].value='bloodstain';
for (const name of ['bm_limb_a', 'bm_limb_b', 'bm_limb_c', 'part'])
  ok(entity(dU, name) === entity(dB, name), 'dummy.inc entity matches HF_BM_Patch: ' + name);
const dummy = text(ufb, 'set/interaction_entity/dummy.inc');
ok(!/\{delay 180 90/.test(dummy) && !/\{delay 300 240 \{hide 1\}/.test(dummy), 'persistence: no body-part delete timers');
ok(dummy.includes('{"stamp_hybrid_with_x"') && dummy.includes('{"map_point_conquest"'), 'former hortens_frontline_patch entities kept');
ok(text(ufb, 'set/interaction_entity/generic.inc') === text(bmp, 'set/interaction_entity/generic.inc'), 'generic.inc is stock HF like HF_BM_Patch');

for (const f of ['blood_medium.def', 'blood_small.def', 'blood_tiny.def']){
  const fx=parse(ufb,'entity/fx/hit/'+f);
  fx.children[0].children=fx.children[0].children.filter(n=>!(s.name(n)==='decalview'&&n.tokens[1]?.value==='ufb_hit_ground'));
  ok(strip(fx)===strip(parse(bmp,'entity/fx/hit/'+f)), 'stock airborne blood retained, with a small ground trace: ' + f);
}
const pool = text(ufb, 'entity/fx/hit/bloodstain.def');
ok(/\{min 0\.0575\}/.test(pool) && /\{max 0\.23\}/.test(pool) && /\{lifetime 240\}/.test(pool), 'pool: stock size +15%, finite particle growth');
ok(/\{particleview/.test(pool) && /\{flags ground\}/.test(pool) && !/\{spriteview/.test(pool), 'pool uses native ground particles');

const all = fs.readdirSync(path.join(ufb, 'set/interaction_entity')).filter(f => f.endsWith('.inc')).map(f => text(ufb, 'set/interaction_entity/' + f)).join('\n');
ok(!/ufb_blood_spot|ufb_bloodstain|blood_(small|medium)_air/.test(all), 'no references to removed UFB blood fx');
console.log(`HF_BM gore in UFB: ${checks} checks passed (static; in-game look untested).`);
