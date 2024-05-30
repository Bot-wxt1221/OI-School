#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
inline int read();
class edge{
  public:
    int v,w;
    edge(int vv=0,int ww=0){
      v=vv;
      w=ww;
      return ;
    }
};
bool operator < (edge a,edge b){
  return a.v<b.v;
}
std::vector<edge>gra[500005];
class node{
  public:
    int x,y,i;
    node(int xx=0,int yy=0,int ii=0){
      x=xx;
      y=yy;
      i=ii;
      return ;
    }
};
std::vector<node>ans[500005];
int tree[4000005];
int out[500005];
int siz[4000005];
int lazy[4000005];
void pushdown(int now){
  tree[now*2]+=lazy[now];
  tree[now*2+1]+=lazy[now];
  lazy[now*2]+=lazy[now];
  lazy[now*2+1]+=lazy[now];
  lazy[now]=0;
  return ;
}
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  siz[now]=r-l+1;
  if(l==r){
    tree[now]=0x3f3f3f3f3f3f3f3f;
    lazy[now]=0;
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  return ;
}
int ql,qr;
int query(int now,int l,int r){
  if(l>r){
    return 0x3f3f3f3f3f3f3f3f;
  }
  pushdown(now);
  if(r<ql||qr<l){
    return 0x3f3f3f3f3f3f3f3f;
  }
  if(ql<=l&&r<=qr){
    return tree[now];
  }
  int mid=(l+r)/2;
  return std::min(query(now*2,l,mid),query(now*2+1,mid+1,r));
}
int op,n;
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  pushdown(now);
  if(r<ql||qr<l){
    return ;
  }
  if(l==r){
    tree[now]=op;
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  return ;
}
void mod2(int now,int l,int r){
  if(ql>qr){
    return ;
  }
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  pushdown(now);
  if(ql<=l&&r<=qr){
    tree[now]+=op;
    lazy[now]+=op;
    return ;
  }
  int mid=(l+r)/2;
  mod2(now*2,l,mid);
  mod2(now*2+1,mid+1,r);
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  return ;
}
int cnt=0;
int be[500005],end[500005];
void dfs(int now,int fa,int dep){
  be[now]=++cnt;
  bool anss=0;
  for(int i=0;i<gra[now].size();i++){
    if(gra[now][i].v==fa){
      continue;
    }
    anss=1;
    dfs(gra[now][i].v,now,dep+gra[now][i].w);
  }
  if(!anss){
    ql=qr=now;
    op=dep;
    mod(1,1,n);
  }
  end[now]=cnt;
  return ;
}
void dfs1(int now,int fa,int dep){
  for(int i=0;i<gra[now].size();i++){
    if(gra[now][i].v==fa){
      continue;
    }
    ql=1;
    qr=be[gra[now][i].v]-1;
    op=gra[now][i].w;
    mod2(1,1,n);
    ql=end[gra[now][i].v]+1;
    qr=n;
    op=gra[now][i].w;
    mod2(1,1,n);
    ql=be[gra[now][i].v];
    qr=end[gra[now][i].v];
    op=-gra[now][i].w;
    mod2(1,1,n);
    dfs1(gra[now][i].v,now,dep+gra[now][i].w);
    ql=be[gra[now][i].v];
    qr=end[gra[now][i].v];
    op=gra[now][i].w;
    mod2(1,1,n);
    ql=end[gra[now][i].v]+1;
    qr=n;
    op=-gra[now][i].w;
    mod2(1,1,n);
    ql=1;
    qr=be[gra[now][i].v]-1;
    op=-gra[now][i].w;
    mod2(1,1,n);
  }
  for(int i=0;i<ans[now].size();i++){
    ql=ans[now][i].x;
    qr=ans[now][i].y;
    out[ans[now][i].i]=query(1,1,n);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int q=read();
  build(1,1,n);
  for(int i=2;i<=n;i++){
    int x=read();
    int y=read();
    gra[i].push_back(edge(x,y));
    gra[x].push_back(edge(i,y));
  }
  for(int i=1;i<=n;i++){
    std::sort(gra[i].begin(),gra[i].end());
  }
  for(int i=1;i<=q;i++){
    int x=read();
    int l=read();
    int r=read();
    ans[x].push_back(node(l,r,i));
  }
  dfs(1,1,0);
  dfs1(1,1,0);
  for(int i=1;i<=q;i++){
    printf("%lld\n",out[i]);
  }
  return 0;
}
inline int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){
    c=='-'?f=-1:1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+(c^48);
    c=getchar();
  }
  return f*x;
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


