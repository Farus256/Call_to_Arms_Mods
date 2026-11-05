// Anti-glare check for UFB pbr/light.hlsl + phong2pbr.hlsl: JS port of the lighting math (green channel).
// Run: node tools/verify-pbr-glare.cjs  (asserts fail if a change re-introduces the glare).
const assert=require('assert');const PI=3.1415926,sat=x=>Math.min(1,Math.max(0,x)),lerp=(a,b,t)=>a+(b-a)*t;
const dot=(a,b)=>a[0]*b[0]+a[1]*b[1]+a[2]*b[2],norm=a=>{const l=Math.hypot(...a);return a.map(x=>x/l)};
const SH=[2.7186,0.7325,0.1927,-0.5035,-0.3031,0.1614,0.0063,-0.2415,0.4663],SHL=[2.9474,0.1987,0.2419,0.0879,-0.0032,0.0101,0.0086,-0.0002,0.0193];
const shEval=(C,n)=>{const x=n[0],y=n[2],z=n[1];return C[0]*.282095+C[1]*.488603*y+C[2]*.488603*z+C[3]*.488603*x+C[4]*1.092548*x*y+C[5]*1.092548*y*z+C[6]*.315392*(3*z*z-1)+C[7]*1.092548*x*z+C[8]*.546274*(x*x-y*y)};
const baseRoughT=(s,c,th,re,st)=>{s=lerp(.5,s,1+c);return sat(1-(s>=th?s*st:s+re))};
function conv(kind,s){ // returns [metallic, roughness]
 const p={ground:[.1,1],flora:[.3,.9],universal:[.4,.9],water:[.4,.9]}[kind];
 return {orig:[kind==='ground'?sat(2*s-1):kind==='flora'?sat(1.5*s-1):sat(2*s-1),baseRoughT(s,.2,.5,p[0],p[1])]};
}
function shade(fix,kind,spec,base,sun,amb,L,V){
 const N=[0,0,1];let [metal,rough]=conv(kind,spec).orig;
 if(fix&&kind!=='universal')metal=0;
 const mix=fix?0.15:0.4,env=lerp(amb,sun,mix);
 rough=lerp(fix?0.3:0.1,1,rough);
 const f0=lerp(.04,base,metal),H=norm(L.map((x,i)=>x+V[i])),NdV=sat(dot(N,V)),HdV=sat(dot(H,V)),NdL=sat(dot(N,L)),NdH=sat(dot(N,H)),LdH=sat(dot(L,H));
 const F=f0+(1-f0)*Math.pow(1-HdV,5),kD=(1-F)*(1-metal);
 const a2=rough**4,D=a2/(PI*(NdH*NdH*(a2-1)+1)**2),k=(rough+1)**2/8,g=d=>d/(d*(1-k)+k),G=g(NdV)*g(NdL);
 let sp=F*D*G;if(fix)sp/=Math.max(4*NdL*NdV,1);
 const Fd90=.5+2*rough*LdH*LdH,dif=kD*base/PI*(1+(Fd90-1)*(1-NdL)**5)*(1+(Fd90-1)*(1-NdV)**5);
 const direct=(dif+sp)*PI*sun*NdL;
 const R=[-V[0],-V[1],V[2]],fake=lerp(shEval(SH,R),shEval(SHL,R),rough)*env,gi=shEval(SH,N)*env;
 const ind=gi*base*kD+1/(rough*rough+1)*lerp(f0,sat(1-rough+(1-kD)),(1-NdV)**5)*fake;
 return {total:direct+ind,glint:sp*PI*sun*NdL,metal,rough};
}
const deg=d=>d*PI/180,dir=(el,az)=>[Math.cos(deg(el))*Math.cos(deg(az)),Math.cos(deg(el))*Math.sin(deg(az)),Math.sin(deg(el))];
const sun=1.4,amb=0.55,L=dir(40,0);
const views={'blik (zerkalo)':dir(40,180),'v storonu':dir(55,90)};
const cases=[['Sneg, zemlya',  'ground',1.0,.85],['Mokraya gryaz','ground',.8,.35],['Bruschatka',   'ground',.6,.45],['Matovaya zemlya','ground',.2,.4],['Voda',        'water',1.0,.25],['Dekal/trava','flora',.9,.5],['Krysha/okno (universal)','universal',.9,.5]];
const vanilla=(base,spec,V)=>{const N=[0,0,1],NdL=sat(dot(N,L)),H=norm(L.map((x,i)=>x+V[i]));return base*(sun*NdL+amb)+spec*sun*NdL*Math.pow(sat(dot(N,H)),20)};
console.log('poverkhnost'.padEnd(26),'vid'.padEnd(15),'vanilla','PBR-orig','PBR-UFB','  metal o->u');
for(const [name,kind,s,b] of cases)for(const [vn,V] of Object.entries(views)){
 const o=shade(false,kind,s,b,sun,amb,L,V),f=shade(true,kind,s,b,sun,amb,L,V);
 console.log(name.padEnd(26),vn.padEnd(15),vanilla(b,s,V).toFixed(2).padStart(7),o.total.toFixed(2).padStart(8),f.total.toFixed(2).padStart(8),`  ${o.metal.toFixed(2)}->${f.metal.toFixed(2)}`);
}
// checks: glint never brighter than original PBR; non-metal surfaces stay near vanilla
const G=views["blik (zerkalo)"],O=views["v storonu"];
for(const [n,kind,s,b] of cases){
 assert(shade(true,kind,s,b,sun,amb,L,G).total<=shade(false,kind,s,b,sun,amb,L,G).total+1e-9,n);
 if(kind!=="universal"){
  const r=shade(true,kind,s,b,sun,amb,L,O).total/vanilla(b,s,O);assert(r>0.75&&r<1.25,n+" off-glint "+r);
  assert(shade(true,kind,s,b,sun,amb,L,G).total<3*vanilla(b,s,G),n+" glint");
 }
}
console.log("checks OK");
