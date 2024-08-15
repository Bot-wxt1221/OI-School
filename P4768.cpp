#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
inline int read();
int fir[800005];
int nxt[3200005];
int v[3200005];
int w[3200005];
int dis[800005];
int now;
std::priority_queue<std::pair<int,int> >qu;
void add(int x,int y,int z){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  w[now]=z;
  return ;
}
bool vised[800005];
class node{
public:
  void Union(int x,int y){
    int fx=getfa(x);
    int fy=getfa(y);
    if(fx==fy){
      return ;
    }
    if(siz[fx]>siz[fy]){
      std::swap(fx,fy);
    }
    fa[fx]=fy;
    siz[fy]+=siz[fx];
    return ;
  }
  bool query(int x,int y){
    return getfa(x)==getfa(y);
  }
  node(int n=800001){
    for(int i=1;i<=n;i++){
      fa[i]=i;
      siz[i]=1;
    }
  }
  void init(int n=800001){
    for(int i=1;i<=n;i++){
      fa[i]=i;
      siz[i]=1;
    }
    return ;
  }
  int getfa(int x){
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
  }
  int fa[800005];
  int siz[800005];
}Un;

class bian{
  public:
    int u,v,l,a;
    bian(int aa=0,int bb=0,int cc=0,int dd=0){
      u=aa;
      v=bb;
      l=cc;
      a=dd;
      return ;
    }
}quan[800005];
bool operator < (const bian &a,const bian &b){
  return a.a>b.a;
}
namespace tree{
int fir[800005];
int nxt[3200005];
int v[3200005];
int w[800005];
int mn[800005][30];
int fa[800005][30];
int now=0;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  tree::fa[now][0]=fa;
  tree::mn[now][0]=w[fa];
  for(int i=1;i<29;i++){
    tree::fa[now][i]=tree::fa[tree::fa[now][i-1]][i-1];
    mn[now][i]=std::min(mn[now][i-1],mn[tree::fa[now][i-1]][i-1]);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    dis[now]=std::min(dis[now],dis[v[i]]);
  }
  return ;
}
int getans(int x,int p){
  for(int i=28;i>=0;i--){
    if(mn[x][i]>p){
      x=fa[x][i];
    }
  }
  return dis[x];
}

};
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("/home/wxt/Downloads/return3.in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int m=read();
    now=0;
    tree::now=0;
    Un.init();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      tree::w[i]=0x3f3f3f3f;
    }
    memset(dis,0x3f,sizeof(dis));
    memset(tree::fir,-1,sizeof(tree::fir));
    memset(vised,0,sizeof(vised));
    for(int i=1;i<=m;i++){
      quan[i].u=read();
      quan[i].v=read();
      quan[i].l=read();
      quan[i].a=read();
      add(quan[i].u,quan[i].v,quan[i].l);
      add(quan[i].v,quan[i].u,quan[i].l);
    }
    std::sort(quan+1,quan+m+1);
    dis[1]=0;
    qu.push(std::make_pair(0,1));
    while(qu.size()>0){
      auto tp=qu.top().second;
      qu.pop();
      if(vised[tp]){
        continue;
      }
      vised[tp]=1;
      for(int i=fir[tp];i!=-1;i=nxt[i]){
        int nw=dis[tp]+w[i];
        if(nw<dis[v[i]]){
          dis[v[i]]=nw;
          qu.push(std::make_pair(-dis[v[i]],v[i]));
        }
      }
    }
    for(int i=1;i<=m;i++){
      if(Un.query(quan[i].u,quan[i].v)){
        continue;
      }
      tree::add(i+n,Un.getfa(quan[i].u));
      tree::add(i+n,Un.getfa(quan[i].v));
      tree::add(Un.getfa(quan[i].u),i+n);
      tree::add(Un.getfa(quan[i].v),i+n);
      Un.fa[Un.getfa(quan[i].u)]=i+n;
      Un.fa[Un.getfa(quan[i].v)]=i+n;
      tree::w[i+n]=quan[i].a;
    }
    tree::dfs(1,1);
    int q=read(),k,s;
    k=read();
    s=read();
    int lstans=0;
    for(int i=1;i<=q;i++){
      int v=(read()+1ll*k*lstans-1)%n+1;
      int p=(read()+1ll*k*lstans)%(s+1);
      printf("%d\n",(lstans=tree::getans(v,p)));
    }
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
