#include <cassert>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#define int unsigned long long
inline int read();
int a[250005];
int b[250005];
int ans[250005];
std::vector<std::pair<int,int> >vec[250005];
class node{
public:
  int sumx,sumy,sumxy,sumS,siz;
  node(int a=0,int b=0,int c=0,int d=0,int e=0){
    sumx=a;
    sumy=b;
    sumxy=c;
    sumS=d;
    siz=e;
    return ;
  }
}tree[250005*8];
class tag{
public:
  int tarx,tary;
  int ax,ay,axy,a;
  tag(int a1=0,int b1=0,int c1=0,int d1=0,int e1=0,int f1=0){
    tarx=a1;
    tary=b1;
    ax=c1;
    ay=d1;
    axy=e1;
    a=f1;
    return ;
  }
}lazy[250005*8];
tag operator * (tag a,tag b){
  tag ret=a;
  if(a.tarx){
    ret.a+=b.ax*a.tarx;
    if(a.tary){
      ret.a+=b.axy*a.tarx*a.tary;
    }else{
      ret.ay+=b.axy*a.tarx;
    }
  }else{
    ret.ax+=b.ax;
    if(a.tary){
      ret.ax+=b.axy*a.tary;
    }else{
      ret.axy+=b.axy;
    }
  }
  if(a.tary){
    ret.a+=a.tary*b.ay;
  }else{
    ret.ay+=b.ay;
  }
  ret.a+=b.a;
  if(b.tarx){
    ret.tarx=b.tarx;
  }
  if(b.tary){
    ret.tary=b.tary;
  }
  return ret;
}
node apply(node old,tag a){
  int len=old.siz;
  return {a.tarx?a.tarx*len:old.sumx,a.tary?a.tary*len:old.sumy,a.tarx?(a.tary?a.tarx*a.tary*len:a.tarx*old.sumy):(a.tary?old.sumx*a.tary:old.sumxy),old.sumS+a.a*len+a.ax*old.sumx+a.ay*old.sumy+a.axy*old.sumxy,len};
}
void pushup(int now){
  tree[now]=node({tree[now*2].sumx+tree[now*2+1].sumx,tree[now*2].sumy+tree[now*2+1].sumy,tree[now*2].sumxy+tree[now*2+1].sumxy,tree[now*2].sumS+tree[now*2+1].sumS,tree[now*2].siz+tree[now*2+1].siz});
  tree[now]=apply(tree[now],lazy[now]);
  return ;
}
void pushdown(int now){
  lazy[now*2]=lazy[now*2]*lazy[now];
  lazy[now*2+1]=lazy[now*2+1]*lazy[now];
  tree[now*2]=apply(tree[now*2],lazy[now]);
  tree[now*2+1]=apply(tree[now*2+1],lazy[now]);
  lazy[now]=tag(0,0,0,0,0,0);
  return ;
}
tag op;
int ql,qr;
void init(int now,int l,int r){
  tree[now].siz=r-l+1;
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  return ;
}
void mod(int now,int l,int r){
  if(ql<=l&&r<=qr){
    lazy[now]=lazy[now]*op;
    tree[now]=apply(tree[now],op);
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
int anss=0;
void query(int now,int l,int r){
  if(ql<=l&&r<=qr){
    anss+=tree[now].sumS;
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
std::stack<int>sta,stb;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  read();
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int l=read();
    int r=read();
    vec[r].push_back({l,i});
  }
  init(1,1,n);
  sta.push(0);
  stb.push(0);
  for(int r=1;r<=n;r++){
    while(sta.size()>1&&a[sta.top()]<a[r]){
      sta.pop();
    }
    ql=sta.top()+1;
    qr=r;
    op=tag(a[r],0,0,0,0,0);
    mod(1,1,n);
    sta.push(r);

    while(stb.size()>1&&b[stb.top()]<b[r]){
      stb.pop();
    }
    ql=stb.top()+1;
    qr=r;
    op=tag(0,b[r],0,0,0,0);
    mod(1,1,n);
    stb.push(r);

    ql=1;
    qr=n;
    op=tag(0,0,0,0,1,0);
    mod(1,1,n);

    for(int k=0;k<vec[r].size();k++){
      anss=0;
      ql=vec[r][k].first;
      qr=r;
      query(1,1,n);
      ans[vec[r][k].second]=anss;
    }
  }
  for(int i=1;i<=q;i++){
    printf("%llu\n",ans[i]);
  }
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
