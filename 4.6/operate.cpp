#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
namespace IO{
	const int S=(1<<20);
	int flag,num[50];char c;
  long long x;
	char ibuf[S],*iS=ibuf,*iT=ibuf;
	char obuf[S],*oS=obuf,*oT=obuf+S;
	char getc(){
//		return getchar();
		if (iS==iT)iS=ibuf,iT=ibuf+fread(ibuf,1,S,stdin);
		return (iS==iT ? EOF : *iS++);
	}
	void flush(){
		fwrite(obuf,1,oS-obuf,stdout),oS=obuf;
	}
	void putc(char c){
		*oS++=c;
		if (oS==oT)flush();
	}
	int read(){
		x=flag=0,c=getc();
		while ((c<'0')||(c>'9'))flag|=(c=='-'),c=getc();
		while ((c>='0')&&(c<='9'))x=x*10+c-'0',c=getc();
		return (flag ? -x : x);
	}
	char read_char(){
		c=getc();
		while (1)c=getc();
		return c;
	}
	void write(long long x,char c='\n'){
		if (x<0)putc('-'),x=-x;
		while (x)num[++num[0]]=x%10,x/=10;
		if (!num[0])putc('0');
		while (num[0])putc(num[num[0]--]+'0');
		putc(c);
	}
};
using IO::read;
using IO::write;
namespace BIT{
  long long tree[2000005];
  int lowbit(int x){
    return x&(-x);
  }
  long long query(int now){
    long long ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=2000000){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
}
class node{
  public:
    int x,y;
    node(int xx=0,int yy=0){
      x=xx;
      y=yy;
      return ;
    }
};
long long fans[2000005];
class pos{
  public:
    int l,r,ps,i;
    pos(int ll=0,int rr=0,int pp=0,int ii=0){
      l=ll;
      r=rr;
      ps=pp;
      i=ii;
      return ;
    }
}ls[4000005];
bool operator < (const pos &a,const pos &b){
  if(a.l!=b.l){
    return a.l>b.l;
  }
  if(a.r!=b.r){
    return a.r<b.r;
  }
  return a.ps>b.ps;
}
node tree[8000005];
node lazy[8000005];
void build(int now,int l,int r){
  if(l==r){
    tree[now]=0;
    lazy[now].x=-1;
    return ;
  }
  int mid=(l+r)/2;
  tree[now]=0;
  lazy[now].x=-1;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  return ;
}
int ql,qr;
node op;
inline void pushdown(int now){
  if(lazy[now].x==-1){
    return ;
  }
  tree[now*2]=tree[now*2+1]=lazy[now*2]=lazy[now*2+1]=lazy[now];
  lazy[now].x=-1;
  return ;
}
void mod(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    lazy[now]=op;
    tree[now]=op;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  if(mid>=ql&&qr>=l){
    mod(now*2,l,mid);
  }
  if(r>=ql&&qr>=mid+1){
    mod(now*2+1,mid+1,r);
  }
  return ;
}
int qpos;
node ans;
void query(int now,int l,int r){
  if(r<qpos||qpos<l){
    return ;
  }
  if(l==r){
    ans=tree[now];
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  if(l<=qpos&&qpos<=mid){
    query(now*2,l,mid);
  }else{
    query(now*2+1,mid+1,r);
  }
  return ;
}
int pre[2000005];
int rans[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("operate.in","r",stdin);
  freopen("operate.out","w",stdout);
  #endif
  int n=read(),m,q;
  m=read();
  q=read();
  build(1,1,n);
  int cnt=0;
  for(int i=1;i<=m;i++){
    int op=read();
    switch(op){
      case 1:{
        int x=read();
        int y=read();
        qpos=x;
        query(1,1,n);
        node fx=ans;
        qpos=y;
        query(1,1,n);
        node fy=ans;
        ql=qr=x;
        ::op=fy;
        mod(1,1,n);
        ql=qr=y;
        ::op=fx;
        mod(1,1,n);
        break;
      }
      case 2:{
        ql=read();
        qr=read();
        ::op=node(i,read());
        mod(1,1,n);
        break;
      }
      case 3:{
        qpos=read();
        query(1,1,n);
        node fx=ans;
        pre[i]=fx.x;
        rans[i]=fx.y;
        ls[++cnt]=pos(pre[i],i,rans[i],0);
        break;
      }
    }
  }
  for(int i=1;i<=q;i++){
    int l=read();
    int r=read();
    ls[++cnt]=pos(l,r,0,i);
  }
  std::sort(ls+1,ls+cnt+1);
  for(int i=1;i<=cnt;i++){
    BIT::mod(ls[i].r,ls[i].ps);
    fans[ls[i].i]+=BIT::query(ls[i].r);
  }
  for(int i=1;i<=q;i++){
    write(fans[i]);
  }
  IO::flush();
  return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/

