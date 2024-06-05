#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int x[2505];
int y[2505];
int map[2505][2505];
int s,t;
int fir[35005];
int nxt[2000005];
int v[2000005];
int now=1;
int can[2000005];
int used[2000005];
void add(int x,int y,int z){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  return ;
}
namespace Dinic{
  std::queue<int>qu;
  int nfir[550015];
  int dep[550015];
  bool bfs(int now){
    for(int i=1;i<=t;i++){
      dep[i]=0;
    }
    dep[now]=1;
    qu.push(now);
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      for(int i=fir[tt];i!=-1;i=nxt[i]){
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
    for(int &i=nfir[now];i!=-1;i=nxt[i]){
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
        nfir[i]=fir[i];
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};
std::vector<int>vec[1000005],vec2[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("rain.in","r",stdin);
  freopen("rain.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int k=read();
  int ans=0;
  for(int i=1;i<=n;i++){
    x[i]=read();
    ans+=x[i];
    vec[x[i]].push_back(i);
  }
  for(int i=1;i<=n;i++){
    y[i]=read();
    ans+=y[i];
    vec2[y[i]].push_back(i);
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    map[x][y]=1;
  }
  now=1;
  s=2*n+1;
  t=2*n*2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int k2=k;k2>=1;k2--){
    for(int i=0;i<vec[k2].size();i++){
      add(s,vec[k2][i],k2);
      add(vec[k2][i],s,0);
      for(int j=0;j<vec2[k2].size();j++){
        if(i==0){
          add(vec2[k2][j]+n,t,k2);
          add(t,vec2[k2][j]+n,0);
        }
        if(map[vec[k2][i]][vec2[k2][j]]){
          add(vec[k2][i],vec2[k2][j]+n,k2);
          add(vec2[k2][j]+n,vec[k2][i],0);
        }
      }
    }
  }
  printf("%lld",ans-Dinic::solve());
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

