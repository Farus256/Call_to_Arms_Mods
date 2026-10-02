// GEM actor_state/ai ratios use string/ident/integer accessors, unlike human.ext.
// Native reference: gamelogic.pak/map/multi/dcg_script.inc, advance_ratio "0.5".
// This is a targeted static check, not a replacement for the game loader.
const fs = require('fs');
const path = require('path');
const assert = require('assert/strict');
const sdl = require('./lib/sdl.cjs');

function inspect(text, file = '<input>') {
    const ast = sdl.parse(text), issues = [];
    for (const actor of sdl.all(ast, n => sdl.name(n) === 'actor_state')) {
        const ai = sdl.child(actor, 'ai');
        if (!ai) continue;
        for (const field of ai.children) {
            if (!['advance_ratio', 'retreat_ratio'].includes(sdl.name(field))) continue;
            const token = field.tokens[1];
            const raw = token ? text.slice(token.start, token.end) : '';
            // Identifiers may refer to mission variables; quoted decimals are native syntax.
            if (!raw || field.tokens.length !== 2 || field.children.length ||
                (!raw.startsWith('"') && Number.isFinite(Number(raw)) && !/^[+-]?\d+$/.test(raw))) {
                issues.push({file, line: text.slice(0, field.start).split('\n').length,
                    field: sdl.name(field), value: raw, error: 'Expected string, identifier or integer; quote fractional ratios.'});
            }
        }
    }
    return issues;
}

function walk(dir) {
    return fs.readdirSync(dir, {withFileTypes: true}).flatMap(entry =>
        entry.isDirectory() ? walk(path.join(dir, entry.name)) : [path.join(dir, entry.name)]);
}

function selfTest() {
    for (const value of ['0.5', '0.1', '-0.2', '1e-2'])
        assert.equal(inspect('{"actor_state" {ai {advance_ratio '+value+'}}}').length, 1);
    assert.equal(inspect('{"actor_state" {ai {retreat_ratio 2.5}}}').length, 1);
    for (const value of ['"0.5"', '"0.1"', '1', '2', 'ratio$'])
        assert.equal(inspect('{"actor_state" {ai {advance_ratio '+value+'}}}').length, 0);
    assert.equal(inspect('{"delay" {time 0.1}} {human {ai {advance_ratio 0.5}}}').length, 0);
    assert.equal(inspect('; {"actor_state" {ai {advance_ratio 0.5}}}\n').length, 0);
    assert.throws(() => inspect('{"actor_state"'));
    return 13;
}

if (require.main === module) {
    const root = path.resolve(__dirname, '..');
    const tests = selfTest(), issues = [];
    let files = 0;
    for (const file of walk(path.join(root, 'mods'))) {
        if (!/\.(inc|mi)$/i.test(file) || !file.replaceAll('\\','/').includes('/resource/map/')) continue;
        files++;
        try { issues.push(...inspect(fs.readFileSync(file, 'utf8'), path.relative(root, file).replaceAll('\\','/'))); }
        catch (e) { issues.push({file: path.relative(root, file), error: e.message}); }
    }
    console.log(JSON.stringify({files, regressionTests: tests, issues}, null, 2));
    if (issues.length) process.exitCode = 1;
}
module.exports = {inspect};
