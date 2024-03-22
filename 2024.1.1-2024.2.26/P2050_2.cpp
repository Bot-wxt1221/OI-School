#include <queue>
#include <iostream>
#include <cstdio>
inline int read();
int fir[400005];
int nxt[5000005];
int v[5000005];
int now=1; 
int n,m;
int can[5000005];
int used[5000005];
int cost[5000005];
int top[400005];
int p[400005];
void add(int x,int y,int z,int a){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  return ;
}
int s,t;
namespace mcflow{
  bool vis[5000005];
  int h[5000005];
  int dis[5000005];
  int pre[5000005];
  int usedge[5000005];
  class node{
    public:
      int id,data;
      node(int x,int y){
        id=x;
        data=y;
        return ;
      }
  };
  bool operator < (node a,node b){
    return a.data>b.data;
  }
  bool spfa(){
    std::queue<int>qu;
    for(int i=1;i<=t;i++){
      h[i]=2147483647ll;
    }
    h[s]=0;
    vis[s]=1;
    qu.push(s);
    while(qu.size()>0){
      int tp=qu.front();
      qu.pop();
      vis[tp]=0;
      for(int i=fir[tp];i!=-1;i=nxt[i]){
        if(can[i]!=used[i]&&h[v[i]]>h[tp]+cost[i]){
          h[v[i]]=h[tp]+cost[i];
          if(vis[v[i]]==0){
            vis[v[i]]=1;
            qu.push(v[i]);
          }
        }
      }
    }
    return h[t]!=2147483647ll;
  }
  int viss[400005];
  int nxxt[400005];
int nfir[400005];
  int c[45][105];
  int mincost=0;
  int dfs(int now,int flow){
    if(now==t||flow==0){
      return flow;
    }
    int nflow=0;
    viss[now]=1;
    for(int &i=nfir[now];i!=-1;i=nxt[i]){
      if(can[i]==used[i]||viss[v[i]]||h[v[i]]!=h[now]+cost[i]){
        continue;
      }
      int d=dfs(v[i],std::min(flow-nflow,can[i]-used[i]));
      if(d>0){
        used[i]+=d;
        used[i^1]-=d;
        nflow+=d;
        mincost+=d*cost[i];
        nxxt[now]=v[i];
        if(nflow==flow){
        viss[now]=0;
        return flow;
      }
      }
    }
    if(nflow==0){
      dis[now]=0x3f3f3f3f;
    }
    viss[now]=0;
    return nflow;
  }
  int ans(){
    int maxflow=0;
    while(spfa()){
      for(int i=1;i<=t;i++){
      nfir[i]=fir[i];
    }
      maxflow+=dfs(s,0x3f3f3f3f);
      for(int i=1;i<=m;i++){
        if(nxxt[(i-1)*(p[n])+top[i]+n]&&top[i]<p[n]){
          top[i]++;
          int now=(i-1)*(p[n])+top[i]+n;
          for(int j=1;j<=n;j++){
            add(j,now,1,c[j][i]*top[i]);
            add(now,j,0,-c[j][i]*top[i]);
          }
          add(now,t,1,0);
          add(t,now,0,0);
        }
      }
    }
  return maxflow;
  }
};
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  m=read();
  
  int sum=0;
  for(int i=1;i<=n;i++){
    p[i]=read();
    p[i]+=p[i-1];
  }
  s=p[n]*m+n+1;
  t=p[n]*m+n+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    add(s,i,p[i]-p[i-1],0);
    add(i,s,0,0);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      int t=read();
      mcflow::c[i][j]=t;
      add(i,(j-1)*p[n]+1+n,1,(t));
      add((j-1)*p[n]+1+n,i,0,-(t));
    }
  }
  for(int i=1;i<=m;i++){
    top[i]=1;
      add((i-1)*p[n]+1+n,t,1,0);
      add(t,(i-1)*p[n]+1+n,0,0);
  }
  mcflow::ans();
  printf("%d",((mcflow::mincost)));
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


