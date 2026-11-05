// SDL contract proof; this does not emulate the game's movement or combat engine.
// Usage: node tools/verify-hf-retreat.cjs [resource-dir] [before-HF-dcg_script.inc]
const fs = require('fs'), path = require('path'), assert = require('assert/strict');
const s = require('./lib/sdl.cjs');
const resource = path.resolve(process.argv[2] || path.join(__dirname, '../mods/ultimate_frontline_bundle/resource'));
const file = path.join(resource, 'map/multi/HF-dcg_script.inc');
const text = fs.readFileSync(file, 'latin1');
const names = ['1', '1.1', '1.2', '2', '2.1', '2.2', '3', '4', '5'].map(x => 'hf arty ai/part ' + x);
const vars = ['attacker_retreat_requested$', 'defender_retreat_requested$', 'bot_retreat_active$', 'winner_decided$'];
const trees = t => new Map(s.all(s.parse(t), n => s.child(n, 'condition') && s.child(n, 'actions')).map(n => [s.name(n), n]));
const current = trees(text);
const beforeText = process.argv[3] ? fs.readFileSync(process.argv[3], 'latin1') : null;
const before = beforeText ? trees(beforeText) : null;
const signature = (n, t) => JSON.stringify({kind: n.kind, tokens: n.tokens.map(x => t.slice(x.start, x.end)), children: n.children.map(x => JSON.parse(signature(x, t)))});
const value = (n, key) => s.child(n, key)?.tokens[1]?.value;
function expression(expr, terms) {
  const tokens = expr.match(/\d+|[!&|()]/g) || []; let i = 0;
  function atom() {
    const t = tokens[i++];
    if (t === '!') return !atom();
    if (t === '(') { const v = or(); assert.equal(tokens[i++], ')'); return v; }
    assert(/^\d+$/.test(t), 'invalid condition expression'); assert(t in terms, 'missing term ' + t); return terms[t];
  }
  function and() { let v = atom(); while (tokens[i] === '&') { i++; const r = atom(); v = v && r; } return v; }
  function or() { let v = and(); while (tokens[i] === '|') { i++; const r = and(); v = v || r; } return v; }
  const result = or(); assert.equal(i, tokens.length); return result;
}
function condition(n, state, predicates = {}) {
  if (s.child(n, 'type')) {
    assert.equal(value(n, 'type'), 'cmp_i'); assert.equal(value(n, 'op'), '=='); assert.equal(value(n, 'value'), '0');
    const variable = value(n, 'var'); assert(vars.includes(variable), 'unexpected guard variable'); return state[variable] === 0;
  }
  const terms = s.child(n, 'terms').children, values = {};
  for (const term of terms) {
    const [id, type] = s.name(term).split('.');
    if (type === 'cmp_i' && vars.includes(value(term, 'var'))) {
      assert.equal(value(term, 'op'), '=='); assert.equal(value(term, 'value'), '0'); values[id] = state[value(term, 'var')] === 0;
    } else { assert(id in predicates, 'missing original predicate ' + id); values[id] = predicates[id]; }
  }
  const expr = value(n, 'expression') || terms.map(x => s.name(x).split('.')[0]).join(' & ');
  return expression(expr, values);
}
function commands(nodes, state) {
  return nodes.flatMap(n => {
    if (s.name(n) === 'delay') return [];
    if (s.name(n) !== 'switch') return [n];
    assert.equal(n.children.length, 1, 'only one guarded branch expected'); const branch = n.children[0]; assert.equal(s.name(branch), 'case');
    return condition(s.child(branch, 'condition'), state) ? commands(branch.children.filter(x => s.name(x) !== 'condition'), state) : [];
  });
}
const normal = Object.fromEntries(vars.map(v => [v, 0]));
let totalCommands = 0, lateRetreatChecks = 0, normalConditionChecks = 0;
for (const name of names) {
  const now = current.get(name); assert(now, 'missing artillery trigger: ' + name);
  const actions = s.child(now, 'actions').children, cond = s.child(now, 'condition');
  const normalCommands = commands(actions, normal); assert(normalCommands.length > 0);
  totalCommands += normalCommands.length;
  const originalTerms = s.child(cond, 'terms').children.filter(n => !vars.includes(value(n, 'var')));
  const guardTerms = s.child(cond, 'terms').children.filter(n => vars.includes(value(n, 'var')));
  assert.deepEqual(guardTerms.map(n => value(n, 'var')).sort(), [...vars].sort(), name + ': all retreat/result guards required');
  for (let mask = 0; mask < 1 << originalTerms.length; mask++) {
    const predicates = Object.fromEntries(originalTerms.map((n, i) => [s.name(n).split('.')[0], !!(mask & (1 << i))]));
    if (before) { assert.equal(condition(cond, normal, predicates), condition(s.child(before.get(name), 'condition'), normal, predicates), name + ': normal condition changed'); normalConditionChecks++; }
    for (let stopped = 1; stopped < 1 << vars.length; stopped++) {
      const state = Object.fromEntries(vars.map((v, i) => [v, (stopped >> i) & 1]));
      assert.equal(condition(cond, state, predicates), false, name + ': starts during retreat/end');
      assert.equal(commands(actions, state).length, 0, name + ': queued commands survive retreat/end');
    }
  }
  for (let i = 0; i < actions.length; i++) if (s.name(actions[i]) === 'delay') {
    for (const variable of vars) {
      const state = {...normal, [variable]: 1};
      assert.equal(commands(actions.slice(i + 1), state).length, 0, name + ': delayed command overrides retreat'); lateRetreatChecks++;
    }
  }
  if (before) {
    const original = before.get(name); assert(original);
    const originalActions = s.child(original, 'actions').children;
    assert.deepEqual(normalCommands.map(n => signature(n, text)), originalActions.filter(n => s.name(n) !== 'delay').map(n => signature(n, beforeText)), name + ': normal commands/selectors changed');
    assert.deepEqual(actions.filter(n => s.name(n) === 'delay').map(n => signature(n, text)), originalActions.filter(n => s.name(n) === 'delay').map(n => signature(n, beforeText)), name + ': delays changed');
    assert.deepEqual(originalTerms.map(n => signature(n, text)), s.child(s.child(original, 'condition'), 'terms').children.map(n => signature(n, beforeText)), name + ': original predicates changed');
  }
}
if (before) {
  assert.deepEqual([...current.keys()], [...before.keys()], 'trigger list changed');
  for (const [name, n] of current) if (!names.includes(name)) assert.equal(signature(n, text), signature(before.get(name), beforeText), 'unrelated trigger changed: ' + name);
}
console.log(JSON.stringify({ok: true,artilleryTriggers: names.length,guardedCommands: totalCommands,lateRetreatChecks,normalConditionChecks,baselineCompared: !!before,gameEngineEmulated: false}, null, 2));
