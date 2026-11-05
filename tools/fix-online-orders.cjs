// Repair the shared skirmish cover template without rebuilding whole missions.
// --apply <new-package-dir> saves source baselines and a reviewed install package.
const fs = require('fs'), path = require('path'), crypto = require('crypto');
const s = require('./lib/sdl.cjs');
const resource = path.resolve(__dirname, '../mods/ultimate_frontline_bundle/resource');
const installed = 'D:/Programs/Steam/steamapps/common/Call to Arms - Gates of Hell/mods/ultimate_frontline_bundle/resource';
const unsafeStates = ['linked', 'inactive', 'dead'];
function coverSelectors(text) {
    return s.all(s.parse(text), n => s.name(n) === 'actor_to_cover')
        .map(n => s.child(n, 'selector')).filter(n => n &&
            s.all(n, x => s.name(x) === 'tag' && x.tokens[1]?.value === 'unhold_iq').length);
}
function patchCover(text) {
    const edits = [];
    for (const selector of coverSelectors(text)) {
        const group = s.child(selector, 'group');
        if (!group) {
            if (selector.children.length !== 2 || !s.child(selector, 'tag') || !s.child(selector, 'state') ||
                s.child(selector, 'tag').tokens[1]?.value !== 'unhold_iq' ||
                s.child(selector, 'state').tokens[1]?.value !== 'operatable')
                throw Error('Unexpected basic unhold_iq selector');
            edits.push({at: selector.start, end: selector.end, value:
                '{selector {source advanced} {group {select {tag {tag unhold_iq}}} ' +
                '{include {state {state operatable}}} {exclude ' +
                [...unsafeStates, 'user_control'].map(state => `{state {state ${state}}}`).join(' ') + '}}}'});
            continue;
        }
        const exclude = s.child(group, 'exclude');
        if (!exclude) throw Error('Unexpected unhold_iq cover selector');
        const missing = unsafeStates.filter(state => !s.all(exclude,
            n => s.name(n) === 'state' && n.tokens[1]?.value === state).length);
        if (missing.length) {
            const lineStart = text.lastIndexOf('\n', exclude.end - 1) + 1;
            const indent = text.slice(lineStart, exclude.end - 1);
            const newline = text.includes('\r\n') ? '\r\n' : '\n';
            if (!/^[\t ]*$/.test(indent)) throw Error('Unexpected inline exclusion block');
            edits.push({at: lineStart, value: missing.map(state =>
                indent + '\t' + `{state {state ${state}}}` + newline).join('')});
        }
    }
    for (const edit of edits.sort((a, b) => b.at - a.at))
        text = text.slice(0, edit.at) + edit.value + text.slice(edit.end ?? edit.at);
    return text;
}
function patchCrew(text) {
    const def = s.parse(text).children.find(n => s.name(n) === 'define' && n.tokens[1]?.value === 'ufb_bot_crew_candidates');
    if (!def) throw Error('Missing bot crew selector');
    const include = s.child(s.child(def, 'group'), 'include');
    if (s.all(include, n => s.name(n) === 'tag' && n.tokens[1]?.value === '_bot').length) return text;
    return text.slice(0, include.end - 1) + ' {tag {tag _bot}}' + text.slice(include.end - 1);
}
function walk(dir) {
    return fs.readdirSync(dir, {withFileTypes: true}).flatMap(e =>
        e.isDirectory() ? walk(path.join(dir, e.name)) : [path.join(dir, e.name)]);
}
const hash = data => crypto.createHash('sha256').update(data).digest('hex');
function main() {
    const apply = process.argv[2] === '--apply', packageRoot = process.argv[3] && path.resolve(process.argv[3]);
    if (apply && !packageRoot) throw Error('Specify a new package directory');
    if (apply && fs.existsSync(packageRoot)) throw Error('Package already exists; refusing to replace baselines');
    const changes = []; let missions = 0;
    for (const file of walk(path.join(resource, 'map/multi'))) {
        if (!file.endsWith('.mi') || path.basename(file) === 'campaign_capture_the_flag.mi') continue;
        const before = fs.readFileSync(file, 'utf8');
        if (!before.includes('unhold_iq')) continue;
        missions += coverSelectors(before).length;
        const after = patchCover(before);
        if (after !== before) changes.push({file: path.relative(resource, file), before, after});
    }
    const crew = 'map/multi/ufb_crew_skirmish.inc';
    const before = fs.readFileSync(path.join(resource, crew), 'utf8'), after = patchCrew(before);
    if (after !== before) changes.push({file: crew, before, after});
    // A previously reviewed phase-2 Frontlines fix exists in source but was not installed.
    const frontline = 'script/multiplayer/modes/frontlines.lua';
    const frontSource = fs.readFileSync(path.join(resource, frontline), 'utf8');
    if (!fs.readFileSync(path.join(installed, frontline)).equals(Buffer.from(frontSource)))
        changes.push({file: frontline, before: frontSource, after: frontSource});
    const entries = changes.map(change => {
        const current = fs.readFileSync(path.join(installed, change.file));
        if (change.file !== frontline && !current.equals(Buffer.from(change.before)))
            throw Error('Installed file differs; merge first: ' + change.file);
        return {file: change.file.replaceAll('\\', '/'), beforeSHA256: hash(current), afterSHA256: hash(change.after)};
    });
    if (apply) {
        for (const change of changes) {
            for (const [folder, bytes] of [['source-before', change.before], ['baseline', fs.readFileSync(path.join(installed, change.file))], ['resource', change.after]]) {
                const target = path.join(packageRoot, folder, change.file);
                fs.mkdirSync(path.dirname(target), {recursive: true}); fs.writeFileSync(target, bytes);
            }
        }
        fs.writeFileSync(path.join(packageRoot, 'manifest.json'), JSON.stringify({createdAt: new Date().toISOString(), files: entries}, null, 2));
        for (const change of changes) fs.writeFileSync(path.join(resource, change.file), change.after);
    }
    console.log(JSON.stringify({coverSelectors: missions, files: entries.length, appliedToSource: apply, package: apply ? packageRoot : null}));
}
if (require.main === module) main();
module.exports = {coverSelectors, patchCover, patchCrew, unsafeStates, walk};
