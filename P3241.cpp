#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
inline int read();
int fir[150005];
int nxt[400005];
int v[400005];
int w[400005];
int now;
void add(int x,int y,int z){
  w[++now]=z;
  v[now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int age[400005];
class node{
  public:
    int age,leng;
    node(int a=0,int b=0){
      age=a;
      leng=b;
      return ;
    }
};
const bool operator < (const node &a,const node &b){
  return a.age<b.age;
}
const bool operator == (const node &a,const node &b){
  return a.age==b.age;
}
std::vector<node>vec[400005];
std::vector<node>vec2[400005];
int siz[400005];
int maxx[400005];
int rt;
int sum;
bool vised[400005];
void calcsiz(int now,int fa){
  siz[now]=1;
  maxx[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcsiz(v[i],now);
    siz[now]+=siz[v[i]];
    maxx[now]=std::max(maxx[now],siz[v[i]]);
  }
  maxx[now]=std::max(maxx[now],sum-siz[now]);
  if(maxx[now]<maxx[rt]||rt==0){
    rt=now;
  }
  return ;
}
int tp;
int dep[150005];
int fa[150005];
void calcdis(int now,int fa,int dis){
  vec[tp].push_back(node(age[now],dis));
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcdis(v[i],now,dis+w[i]);
  }
  return ;
}
void calcdis2(int now,int fa,int dis){
  vec2[tp].push_back(node(age[now],dis));
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcdis2(v[i],now,dis+w[i]);
  }
  return ;
}
void dfs(int now,int fa){
  tp=now;
  vised[now]=1;
  calcdis(now,fa,0);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    rt=0;
    sum=siz[v[i]];
    calcsiz(v[i],now);
    calcsiz(rt,-1);
    dep[rt]=dep[now]+1;
    ::fa[rt]=now;
    tp=rt;
    calcdis2(v[i],now,w[i]);
    dfs(rt,-1);
  }
  return ;
}
int dd[150005][30];
namespace LCA{
int dep[150005];
int to[150005][30];
int dis[150005][30];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  if(now==fa){
    dis[now][0]=0;
  }
  for(int i=1;i<30;i++){
    to[now][i]=to[to[now][i-1]][i-1];
    dis[now][i]=dis[now][i-1]+dis[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dis[v[i]][0]=w[i];
    dfs(v[i],now);
  }
  return ;
}
int gdis(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  int ret=0;
  while(dep[x]>dep[y]){
    int i=29;
    for(i=29;i>0;i--){
      if(dep[to[x][i]]>dep[y]){
        break;
      }
    }
    ret+=dis[x][i];
    x=to[x][i];
  }
  while(x!=y){
    int i=29;
    for(i=29;i>0;i--){
      if(to[x][i]!=to[y][i]){
        break;
      }
    }
    ret+=dis[y][i];
    ret+=dis[x][i];
    x=to[x][i];
    y=to[y][i];
  }
  return ret;
}
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),q,A;
  q=read();
  A=read();
  for(int i=1;i<=n;i++){
    vec[i].push_back(node(-1,0));
    vec2[i].push_back(node(-1,0));
    fir[i]=-1;
    age[i]=read();
  }
  for(int i=1;i<n;i++){
    int u=read();
    int v=read();
    int w=read();
    add(u,v,w);
    add(v,u,w);
  }
  sum=n;
  calcsiz(1,1);
  calcsiz(rt,-1);
  int rtt=rt;
  dfs(rt,-1);
  LCA::dfs(1,1);
  for(int i=1;i<=n;i++){
    std::sort(vec[i].begin(),vec[i].end());
    std::sort(vec2[i].begin(),vec2[i].end());
    for(int j=1;j<vec[i].size();j++){
      vec[i][j].leng+=vec[i][j-1].leng;
    }
    for(int j=1;j<vec2[i].size();j++){
      vec2[i][j].leng+=vec2[i][j-1].leng;
    }
  }
  for(int i=1;i<=n;i++){
    int j=i;
    while(j!=rtt){
      dd[i][dep[i]-dep[j]]=LCA::gdis(i,j);
      j=fa[j];
    }
    dd[i][dep[i]-dep[j]]=LCA::gdis(i,j);
    j=fa[j];
  }
  int preans=0;
  for(int i=1;i<=q;i++){
    int u=read();
    int a=read();
    int b=read();
    int l=std::min((a+preans)%A,(b+preans)%A);
    int r=std::max((a+preans)%A,(b+preans)%A);
    auto ql=--(std::lower_bound(vec[u].begin(),vec[u].end(),node(l,0)));
    auto qr=--(std::lower_bound(vec[u].begin(),vec[u].end(),node(r+1,0)));
    preans=(qr->leng)-(ql->leng);
    int tu=u;
    while(u!=rtt){
      auto ql=--(std::lower_bound(vec2[u].begin(),vec2[u].end(),node(l,0)));
      auto qr=--(std::lower_bound(vec2[u].begin(),vec2[u].end(),node(r+1,0))); 
      preans-=(qr->leng)-(ql->leng)+dd[tu][dep[tu]-dep[fa[u]]]*(qr-ql);
      u=fa[u];
      ql=--(std::lower_bound(vec[u].begin(),vec[u].end(),node(l,0)));
      qr=--(std::lower_bound(vec[u].begin(),vec[u].end(),node(r+1,0)));
      preans+=(qr->leng)-(ql->leng)+dd[tu][dep[tu]-dep[u]]*(qr-ql);
    }
    ql=--(std::lower_bound(vec2[u].begin(),vec2[u].end(),node(l,0)));
    qr=--(std::lower_bound(vec2[u].begin(),vec2[u].end(),node(r+1,0))); 
    preans-=(qr->leng)-(ql->leng)+dd[tu][dep[tu]-dep[fa[u]]]*(qr-ql);
    u=fa[u];
    printf("%lld\n",preans);
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


