#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
inline int read();
int s,t;
std::vector<int>edge[505];
int v[30005];
int now=1;
int can[30005];
int used[30005];
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
      for(int i=1;i<=501;i++){
        nfir[i]=0;
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};
int seq[505];
namespace ntree{
int fir[505];
int nxt[10005];
int v[10005];
int w[10005];
int now,ans;
int sta[10005];
int tp;
void dfs(int now,int fa,int to){
  if(to==now){
    for(int i=1;i<=tp;i++){
      ans=std::min(ans,w[sta[i]]);
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    sta[++tp]=i;
    dfs(v[i],now,to);
    tp--;
  }
  return ;
}
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
};
int t1[505];
int t2[505];
void build(int l,int r){
  if(l>=r){
    return ;
  }
  s=seq[l];
  t=seq[r];
  int cnt1=0,cnt2=0;
  memset(used,0,sizeof(used));
  int ret=Dinic::solve();
  ntree::add(s,t,ret);
  ntree::add(t,s,ret);
  for(int i=l;i<=r;i++){
    if(Dinic::dep[seq[i]]!=0){
      t1[++cnt1]=seq[i];
    }else{
      t2[++cnt2]=seq[i];
    }
  }
  for(int i=1;i<=cnt1;i++){
    seq[i+l-1]=t1[i];
  }
  for(int i=1;i<=cnt2;i++){
    seq[i+l+cnt1-1]=t2[i];
  }
  build(l,l+cnt1-1);
  build(l+cnt1,l+cnt1+cnt2-1);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read()+1;
  int m=read();
  for(int i=1;i<=n;i++){
    ntree::fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read()+1;
    int y=read()+1;
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  for(int i=1;i<=n;i++){
    seq[i]=i;
  }
  build(1,n);
  int q=read();
  for(int i=1;i<=q;i++){
    int x=read()+1;
    int y=read()+1;
    ntree::ans=0x3f3f3f3f;
    ntree::dfs(x,x,y);
    printf("%lld\n",ntree::ans);
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
