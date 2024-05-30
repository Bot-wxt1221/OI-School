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
int fa[200005];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int s,t;
std::vector<int>edge[300005];
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
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  s=200000+1;
  t=200000+2;
  for(int i=1;i<=200000;i++){
    fa[i]=i;
  }
  for(int i=1;i<=n;i++){
    a[i]=read()+1;
    int fi=getfa(i);
    int fj=getfa(a[i]);
    fa[fi]=fj;
  }
  for(int i=1;i<=n;i++){
    b[i]=read()+1;
    int fi=getfa(i+100000);
    int fj=getfa(b[i]+100000);
    fa[fi]=fj; 
  }
  for(int i=1;i<=200000;i++){
    getfa(i);
  }
  int ans=n;
  for(int i=1;i<=n;i++){
    if(a[i]==b[i]&&b[i]==i){
      //wuwuwu
      ans--;
    }else if(a[i]==i&&b[i]!=i){
      add(fa[b[i]+100000],t,1);
      add(t,fa[b[i]+100000],0);
    }else if(b[i]==i&&a[i]!=i){
      add(s,fa[a[i]],1);
      add(fa[a[i]],s,0);
    }else if(a[i]!=b[i]&&a[i]!=i&&b[i]!=i){
      add(fa[b[i]+100000],fa[a[i]],1);
      add(fa[a[i]],fa[b[i]+100000],0);
    }else{
      add(fa[a[i]],fa[b[i]+100000],1);
      add(fa[b[i]+100000],fa[a[i]],1);
    }
  }
  printf("%d",ans-Dinic::solve());
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

