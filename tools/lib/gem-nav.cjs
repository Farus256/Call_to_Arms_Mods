// Read the installed GEM v2 terrain navigation grid; do not modify it.
const assert=require('assert/strict');
class NavGrid {
    constructor(buffer) {
        this.b=buffer;this.step=buffer[0];assert.equal(buffer[1],2,'Unsupported navigation version');
        assert([5,10].includes(this.step),'Unsupported navigation cell size');
        this.w=buffer.readUInt16LE(2);this.h=buffer.readUInt16LE(4);
        this.x=buffer.readFloatLE(6);this.y=buffer.readFloatLE(10);
        let offset=14;this.layers=[];
        for(const marker of ['MAP0','MAP1']) {
            assert.equal(buffer.toString('ascii',offset,offset+4),marker);offset+=4;
            const layer=new Map(),count=buffer[offset++];
            for(let i=0;i<count;i++){const id=buffer[offset++],length=buffer[offset++];layer.set(id,buffer.toString('ascii',offset,offset+length));offset+=length;}
            this.layers.push(layer);
        }
        assert.equal(buffer.toString('ascii',offset,offset+4),'GRID');this.offset=offset+4;
        assert.equal(buffer.length-this.offset,this.w*this.h*4,'Grid length does not match header');
    }
    cell(x,y) {
        const i=Math.floor((x+this.x)/this.step),j=Math.floor((y+this.y)/this.step);
        if(i<0||j<0||i>=this.w||j>=this.h)return null;
        const p=this.offset+4*(j*this.w+i);
        return {height:this.b.readInt16LE(p),base:this.layers[0].get(this.b[p+2]),surface:this.layers[1].get(this.b[p+3])};
    }
    dry(x,y) {
        const c=this.cell(x,y);
        return !!c&&['ground','road','snow','slope'].includes(c.base)&&['ground','road','country_road','grass','snow','mud'].includes(c.surface);
    }
    suitable(x,y) {
        if(!this.dry(x,y))return false;
        const heights=[];
        for(const dx of [-this.step,0,this.step])for(const dy of [-this.step,0,this.step]){
            if(!this.dry(x+dx,y+dy))return false;heights.push(this.cell(x+dx,y+dy).height);
        }
        return Math.max(...heights)-Math.min(...heights)<=this.step;
    }
    nearest(point,bounds,maxRadius=2000) {
        const inside=(x,y)=>x>=bounds[0]&&y>=bounds[1]&&x<=bounds[2]&&y<=bounds[3];
        const x=Math.max(bounds[0],Math.min(bounds[2],point[0])),y=Math.max(bounds[1],Math.min(bounds[3],point[1]));
        if(inside(x,y)&&this.suitable(x,y))return [x,y,this.cell(x,y).height];
        for(let r=this.step;r<=maxRadius;r+=this.step*2) {
            for(let i=0;i<24;i++) {
                const a=i*Math.PI/12,xx=x+Math.cos(a)*r,yy=y+Math.sin(a)*r;
                if(inside(xx,yy)&&this.suitable(xx,yy))return [xx,yy,this.cell(xx,yy).height];
            }
        }
        throw Error('No dry navigation position near '+point.slice(0,2).join(','));
    }
}
module.exports=NavGrid;
