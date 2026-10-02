// Small span-preserving reader for the installed GEM SDL sources.
function parse(text) {
  const root = { children: [], tokens: [], start: 0, end: text.length };
  const stack = [root];
  let i = 0;
  while (i < text.length) {
    const c = text[i];
    if (/\s/.test(c)) { i++; continue; }
    if (c === ';' || text.slice(i,i+2) === '//') {
      const end = text.indexOf('\n',i); i = end < 0 ? text.length : end+1; continue;
    }
    if (c === '{' || c === '(') {
      const n = {start:i++, kind:c, children:[], tokens:[]};
      stack.at(-1).children.push(n); stack.push(n); continue;
    }
    if (c === '}' || c === ')') {
      const n = stack.pop();
      if (!n || n === root || (n.kind === '{' ? '}' : ')') !== c) throw Error('Unbalanced SDL at '+i);
      n.end=++i; continue;
    }
    const start=i;
    if (c === '"') {
      i++; while(i<text.length && text[i] !== '"') { if(text[i] === '\\') i++; i++; }
      if(i===text.length) throw Error('Unclosed string');
      i++;
    } else { while(i<text.length && !/[\s{}();"]/.test(text[i])) i++; }
    if(i===start) throw Error('Unexpected character at '+i);
    const raw=text.slice(start,i);
    stack.at(-1).tokens.push({value:raw[0]==='"'?raw.slice(1,-1):raw,start,end:i});
  }
  if(stack.length !== 1) throw Error('Unclosed SDL block');
  return root;
}
const name=n=>n.tokens[0]?.value;
const child=(n,key)=>n.children.find(c=>name(c)===key);
function all(n,pred) { return n.children.flatMap(c=>[...(pred(c)?[c]:[]),...all(c,pred)]); }
module.exports={parse,name,child,all};
