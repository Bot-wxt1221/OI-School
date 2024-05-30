#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define int long long
inline int read();
int s,t;
std::vector<int>edge[500005];
int v[3000005];
int now=1;
int can[3000005];
int used[3000005];
void add(int x,int y,int z){
  v[++now]=y;
  edge[x].push_back(now);
  can[now]=z;
  used[now]=0;
  return ;
}
bool vised[3000005];
int ttans=0;
void tans(int now){
  if(vised[now]){
    return ;
  }
  ttans++;
  vised[now]=1;
  for(auto i:edge[now]){
    if(can[i]!=used[i]){
      tans(v[i]);
    }
  }
  return ;
}
namespace Dinic{
  std::queue<int>qu;
  int nfir[500005];
  int dep[500005];
  bool bfs(int now){
    memset(dep,0,sizeof(dep));
    dep[now]=1;
    qu.push(now);
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      for(auto i:edge[tt]){
        if(dep[v[i]]||can[i]==used[i]){
          continue;
        }
        dep[v[i]]=dep[tt]+1;
        qu.push(v[i]);
      }
    }
    return dep[t];
  }
  int dfs(int now,int flow){
    if(flow==0||now==t){
      return flow;
    }
    int nflow=0;
    for(int &ii=nfir[now];ii<edge[now].size();ii++){
      int i=edge[now][ii];
      if(dep[v[i]]!=dep[now]+1||can[i]==used[i]){
        continue;
      }
      int tt=dfs(v[i],std::min(flow-nflow,can[i]-used[i]));
      if(tt==0){
        continue;
      }
      nflow+=tt;
      used[i]+=tt;
      used[i^1]-=tt;
      if(nflow==flow){
        return nflow;
      }
    }
    return nflow;
  }
  int solve(int ans=0){
    while(bfs(s)){
      for(int i=1;i<=t;i++){
        nfir[i]=0;
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};
int map[505][505];
int a[505];
int ans[505];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read(),m;
    m=read();
    memset(map,0,sizeof(map));
    for(int i=1;i<=n;i++){
      a[i]=-1;
      ans[i]=0;
    }
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      map[x][y]++;
      map[y][x]++;
    }
    int k=read();
    for(int i=1;i<=k;i++){
      int a=read();
      int b=read();
      ::a[a]=b;
    }
    int ans=0;
    for(int tt=0;tt<=60;tt++){
      now=1;
      s=n+1;
      t=n+2;
      for(int i=1;i<=n+2;i++){
        edge[i].clear();
        vised[i]=0;
      }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          if(map[i][j]){
            add(i,j,map[i][j]);
            add(j,i,0);
          }
        }
      }
      for(int i=1;i<=n;i++){
        if(a[i]>=0){
          if(a[i]&(1ll<<(tt))){
            add(s,i,0x3f3f3f3f);
            add(i,s,0);
          }else{
            add(i,t,0x3f3f3f3f);
            add(t,i,0);
          }
        }
      }
      int ret=Dinic::solve();
      ans+=ret*(1ll<<(tt));
      ttans=0;
      tans(s);
      for(int i=1;i<=n;i++){
        if(vised[i]){
          ::ans[i]+=(1<<tt);
        }
      }
    }
    for(int i=1;i<=n;i++){
      printf("%lld\n",::ans[i]);
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

