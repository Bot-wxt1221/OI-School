#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int fir[10005];
int nxt[400005];
int u[400005];
int v[400005];
int now=1;
int can[400005];
int used[400005];
int cost[400005];
void add(int x,int y,int z,int a){
  v[++now]=y;
  u[now]=x;
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
  void spfa(){
    std::queue<int>qu;
    for(int i=1;i<=t;i++){
      vis[i]=0;
      h[i]=0x3f3f3f3f3f3f3f;
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
    return ;
  }
  bool dij(){
    std::priority_queue<node>qu;
    for(int i=1;i<=t;i++){
      dis[i]=0x3f3f3f3f3f3f3f;
      vis[i]=0;
      pre[i]=0;
    }
    dis[s]=0;
    qu.push(node(s,0));
    while(qu.size()>0){
      node temp=qu.top();
      qu.pop();
      if(vis[temp.id]){
        continue;
      }
      vis[temp.id]=1;
      for(int i=fir[temp.id];i!=-1;i=nxt[i]){
        int edge=cost[i]+h[temp.id]-h[v[i]];
        if(can[i]!=used[i]&&dis[v[i]]>dis[temp.id]+edge){
          dis[v[i]]=dis[temp.id]+edge;
          usedge[v[i]]=i;
          pre[v[i]]=temp.id;
          if(vis[v[i]]==0){
            qu.push(node(v[i],dis[v[i]]));
          }
        }
      }
    }
    return dis[t]!=0x3f3f3f3f3f3f3f;
  }
  int ans(){
    spfa();
    int ans=0;
    while(dij()){
    for(int i=1;i<=t;i++){
        h[i]+=dis[i];   
      }
      int minf=0x3f3f3f3f3f3f3f;
      for(int i=t;i!=s;i=pre[i]){
        minf=std::min(minf,can[usedge[i]]-used[usedge[i]]);
      }
      for(int i=t;i!=s;i=pre[i]){
        used[usedge[i]]+=minf;
        used[usedge[i]^1]-=minf;
      }
      ans+=minf*h[t];
    }
    return ans;
  }
};
int a[5005];
int b[5005];
int c[5005];
int d[5005];
int cnt[5005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  s=n+m+1;
  t=n+m+2;
  now=1;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
    c[i]=read();
    d[i]=read();
  }
  for(int i=1;i<=m;i++){
    int ss=read();
    int tt=read();
    add(s,i+n,1,0);
    add(i+n,s,0,0);
    add(i+n,ss,1,0);
    add(ss,i+n,0,0);
    add(i+n,tt,1,0);
    add(tt,i+n,0,0);
    cnt[ss]++;
    cnt[tt]++;
    b[ss]++;
    b[tt]++;
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=a[i]*a[i]*c[i]+b[i]*b[i]*d[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=cnt[i];j++){
      add(i,t,1,(c[i])*(2*(a[i])+1)-d[i]*(2*(b[i])-1));
      add(t,i,0,-(c[i])*(2*(a[i])+1)+d[i]*(2*(b[i])-1));
      b[i]--;
      a[i]++;
    }
  }
  ans+=mcflow::ans();
  printf("%lld",ans);
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


