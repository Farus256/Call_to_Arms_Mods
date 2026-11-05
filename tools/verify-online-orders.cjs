const fs = require('fs'), path = require('path'), assert = require('assert/strict');
const s = require('./lib/sdl.cjs');
const {coverSelectors, patchCover, patchCrew, unsafeStates, walk} = require('./fix-online-orders.cjs');
const resource = path.resolve(process.argv[2] || path.join(__dirname, '../mods/ultimate_frontline_bundle/resource'));
const packageRoot = process.argv[3] && path.resolve(process.argv[3]);
let selectors = 0, checks = 0;
function facet(n, actor) {
    if (n.children.length) return n.children.some(c => facet(c, actor));
    const type = s.name(n), value = n.tokens[1]?.value;
    if (type === 'state') return actor.states.has(value);
    if (type === 'tag') return actor.tags.has(value);
    if (type === 'prop') return actor.props.has(value);
    throw Error('Unsupported facet: ' + type);
}
function eligible(group, actor) {
    const selected = s.child(group, 'select'), include = s.child(group, 'include'), exclude = s.child(group, 'exclude');
    return (!selected || selected.children.some(c => facet(c, actor))) &&
        (!include || include.children.every(c => facet(c, actor))) &&
        (!exclude || !exclude.children.some(c => facet(c, actor)));
}
function selectorGroup(selector) {
    return s.child(selector, 'group') || s.parse('{group {select {tag {tag unhold_iq}}} {include {state {state operatable}}}}').children[0];
}
function verifyCover(text, baseline, file) {
    const nodes = coverSelectors(text), previous = baseline && coverSelectors(baseline);
    if (baseline) assert.equal(nodes.length, previous.length);
    assert(patchCover(text) === text, 'Fix is missing: ' + file);
    nodes.forEach((selector, index) => {
        selectors++;
        const group = s.child(selector, 'group');
        const actor = {states: new Set(['operatable']), tags: new Set(['unhold_iq']), props: new Set(['human'])};
        assert(eligible(group, actor), 'Healthy infantry excluded: ' + file); checks++;
        for (const state of [...unsafeStates, 'user_control']) {
            actor.states.add(state); assert(!eligible(group, actor), state + ' receives cover order: ' + file);
            if (baseline && unsafeStates.includes(state))
                assert(eligible(selectorGroup(previous[index]), actor), 'Old failure not reproduced');
            actor.states.delete(state); checks++;
        }
    });
    if (baseline) assert(patchCover(baseline) === text, 'Unrelated mission edits: ' + file);
}
for (const file of walk(path.join(resource, 'map/multi'))) {
    if (!file.endsWith('.mi') || path.basename(file) === 'campaign_capture_the_flag.mi') continue;
    const text = fs.readFileSync(file, 'utf8'); if (!text.includes('unhold_iq')) continue;
    const before = packageRoot && path.join(packageRoot, 'source-before', path.relative(resource, file));
    verifyCover(text, before && fs.existsSync(before) ? fs.readFileSync(before, 'utf8') : null, file);
}
assert(selectors > 0, 'No multiplayer cover selectors tested');
const crewFile = 'map/multi/ufb_crew_skirmish.inc', crewText = fs.readFileSync(path.join(resource, crewFile), 'utf8');
assert.equal(patchCrew(crewText), crewText, 'Bot ownership restriction missing');
const group = s.child(s.parse(crewText).children.find(n => n.tokens[1]?.value === 'ufb_bot_crew_candidates'), 'group');
const include = s.child(group, 'include');
const actor = {states: new Set(['operatable']), tags: new Set(['_ufb_crew_profile']), props: new Set(['human', 'crew'])};
assert(!include.children.every(c => facet(c, actor)), 'Human crew receives automatic cover'); checks++;
actor.tags.add('_bot'); assert(include.children.every(c => facet(c, actor)), 'Bot crew no longer protected'); checks++;
if (packageRoot) {
    const before = fs.readFileSync(path.join(packageRoot, 'source-before', crewFile), 'utf8');
    const old = s.child(s.parse(before).children.find(n => n.tokens[1]?.value === 'ufb_bot_crew_candidates'), 'group');
    actor.tags.delete('_bot'); assert(s.child(old, 'include').children.every(c => facet(c, actor)), 'Old human-crew failure not reproduced');
    assert.equal(patchCrew(before), crewText, 'Unrelated crew edits'); checks += 2;
}
console.log(`Online cover: ${selectors} mission selectors, ${checks} assertions; SDL selector model, no live network match.`);
