#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
inline int read();
int a[100005];
int b[100005];
int p[100005];
int q[100005];
int s,t;
std::vector<int>edge[300005];
std::vector<std::pair<int,int> >aa;
int v[900005];
int now=1;
int can[900005];
int used[900005];
void add(int x,int y,int z){
  v[++now]=y;
  edge[x].push_back(now);
  can[now]=z;
  used[now]=0;
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
      for(int i=1;i<=300002;i++){
        nfir[i]=0;
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};
int du[200005];
int du2[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  s=200000+1;
  t=200000+2;
  int m=read();
  for(int i=1;i<=m;i++){
    int u=read();
    int v=read();
    int d=read();
    du[u]++;
    du[v]++;
    if(d==1){
      du2[v]++;
    }else{
      aa.push_back({u,v});
    }
  }
  for(int i=1;i<=n;i++){
    if(du[i]&1||du2[i]>du[i]/2){
      printf("NO\n");
      return 0;
    }
  }
  for(int i=0;i<aa.size();i++){
    add(n+i+1,aa[i].first,1);
    add(aa[i].first,n+i+1,0);
    add(n+i+1,aa[i].second,1);
    add(aa[i].second,n+i+1,0);
  }
  int sum=0;
  for(int i=1;i<=n;i++){
    add(i,t,du[i]/2-du2[i]);
    add(t,i,0);
    sum+=du[i]/2-du2[i];
  }
  for(int i=0;i<aa.size();i++){
    add(s,n+i+1,1);
    add(n+i+1,s,0);
  }
  if(Dinic::solve()==sum){
    printf("YES\n");
  }else{
    printf("NO\n");
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

