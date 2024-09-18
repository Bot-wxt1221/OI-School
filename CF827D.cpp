#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
bool choose[200005];
int ans[200005];
int out[200005];
int fir[200005];
int nxt[400005];
int v[400005];
int w[400005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
class edge{
public:
  int u,v,w;
  int i;
  edge(int a=0,int b=0,int c=0,int d=0){
    u=a;
    v=b;
    w=c;
    i=d;
    return ;
  }
}seq[200005];
bool operator < (const edge &a,const edge &b){
  return a.w<b.w;
}
int bson[200005];
int fa[200005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int to[200005][20];
int dfn[200005];
int cnt;
int siz[200005];
int edge2p[200005];
int dep[200005];
int seqq[200005];
void dfs(int now,int fa,int too){
  to[now][0]=fa;
  dep[now]=dep[fa]+1;
  for(int i=1;i<20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  edge2p[now]=too;
  bson[now]=0;
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,w[i]);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
  }
  return ;
}
int getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  if(dep[x]>dep[y]){
    for(int i=19;i>=0;i--){
      if(dep[to[x][i]]>dep[y]){
        x=to[x][i];
      }
    }
    x=to[x][0];
  }
  if(x!=y){
    for(int i=19;i>=0;i--){
      if(to[x][i]!=to[y][i]){
        x=to[x][i];
        y=to[y][i];
      }
    }
    x=to[x][0];
    y=to[y][0];
  }
  return x;
}
int tp[200005];
void dfs2(int now,int fa,int top){
  dfn[now]=++cnt;
  tp[now]=top;
  if(bson[now]){
    dfs2(bson[now],now,top);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
}
int tree[800005];
int tree2[800005];
int lazy[800005];
void pushdown(int now){
  tree[now*2]=std::min(tree[now*2],lazy[now]);
  tree[now*2+1]=std::min(tree[now*2+1],lazy[now]);
  lazy[now*2]=std::min(lazy[now*2],lazy[now]);
  lazy[now*2+1]=std::min(lazy[now*2+1],lazy[now]);

  lazy[now]=0x3f3f3f3f;
  return ;
}
void build(int now,int l,int r){
  if(l==r){
    tree[now]=0x3f3f3f3f;
    lazy[now]=0x3f3f3f3f;
    tree2[now]=seqq[l];
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=0x3f3f3f3f;
  lazy[now]=0x3f3f3f3f;
  tree2[now]=std::max(tree2[now*2+1],tree2[now*2]);
}
int ql,qr,op;
void mod(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now]=std::min(tree[now],op);
    lazy[now]=std::min(lazy[now],op);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  return ;
}
void query(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    op=std::min(op,tree[now]);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
}
void query2(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    op=std::max(op,tree2[now]);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query2(now*2,l,mid);
  query2(now*2+1,mid+1,r);
}
int n;
void mod2(int x,int y,int z){
  int tfa=getlca(x,y);
  while(x!=tfa){
    if(dep[tp[x]]>dep[tfa]){
      ql=dfn[tp[x]];
      qr=dfn[x];
      op=z;
      mod(1,1,n);
      x=to[tp[x]][0];
    }else{
      ql=dfn[tfa]+1;
      qr=dfn[x];
      op=z;
      if(ql<=qr){
        mod(1,1,n);
      }
      break;
    }
  }
  x=y;
  while(x!=tfa){
    if(dep[tp[x]]>dep[tfa]){
      ql=dfn[tp[x]];
      qr=dfn[x];
      op=z;
      mod(1,1,n);
      x=to[tp[x]][0];
    }else{
      ql=dfn[tfa]+1;
      qr=dfn[x];
      op=z;
      if(ql<=qr){
        mod(1,1,n);
      }
      break;
    }
  }
  return ;
}
int query3(int x,int y){
  int tfa=getlca(x,y);
  op=0;
  while(x!=tfa){
    if(dep[tp[x]]>dep[tfa]){
      ql=dfn[tp[x]];
      qr=dfn[x];
      query2(1,1,n);
      x=to[tp[x]][0];
    }else{
      ql=dfn[tfa]+1;
      qr=dfn[x];
      if(ql<=qr){
        query2(1,1,n);
      }
      break;
    }
  }
  x=y;
  while(x!=tfa){
    if(dep[tp[x]]>dep[tfa]){
      ql=dfn[tp[x]];
      qr=dfn[x];
      query2(1,1,n);
      x=to[tp[x]][0];
    }else{
      ql=dfn[tfa]+1;
      qr=dfn[x];
      if(ql<=qr){
        query2(1,1,n);
      }
      break;
    }
  }
  return op;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    fa[i]=i;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int z=read();
    seq[i]=edge(x,y,z,i);
  }
  std::sort(seq+1,seq+m+1);
  for(int i=1;i<=m;i++){
    int fu=getfa(seq[i].u);
    int fv=getfa(seq[i].v);
    if(fu==fv){
      continue;
    }
    fa[fu]=fv;
    add(seq[i].u,seq[i].v,i);
    add(seq[i].v,seq[i].u,i);
    choose[i]=1;
  }
  dfs(1,1,0);
  dfs2(1,1,1);
  for(int i=2;i<=n;i++){
    seqq[dfn[i]]=seq[edge2p[i]].w;
  }
  build(1,1,n);
  for(int i=1;i<=m;i++){
    if(choose[i]==0){
      mod2(seq[i].u,seq[i].v,seq[i].w);
    }
  }
  for(int i=2;i<=n;i++){
    op=0x3f3f3f3f;
    ql=dfn[i];
    qr=dfn[i];
    query(1,1,n);
    ans[edge2p[i]]=op;
  }
  for(int i=1;i<=m;i++){
    if(choose[i]==0){
      ans[i]=query3(seq[i].u,seq[i].v);
    }
  }
  for(int i=1;i<=m;i++){
    if(ans[i]==0x3f3f3f3f){
      ans[i]=0;
    }
    out[seq[i].i]=ans[i]-1;
  }
  for(int i=1;i<=m;i++){
    printf("%d ",out[i]);
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
