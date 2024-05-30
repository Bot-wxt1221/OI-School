#include <queue>
#include <iostream>
#include <cstdio>
#define int long long 
inline int read();
int fir[1005];
int nxt[2000005];
int v[2000005];
int now=1;
int can[2000005];
bool cadd[2000005];
int used[2000005];
int cost[2000005];
int nowk[2000005];
int u[2000005];
int tt[2000005];
void add(int x,int y,int z,int a,bool caa=0,int caaa=0){
  v[++now]=y;
  u[now]=x;
  tt[now]=caaa;
  nxt[now]=fir[x];
  cadd[now]=caa;
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
    return ;
  }
  bool dij(){
    std::priority_queue<node>qu;
    for(int i=1;i<=t;i++){
      dis[i]=0x3f3f3f3f;
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
    return dis[t]!=0x3f3f3f3f;
  }
  int ans(){
  int ans=0;
  while(1){
    spfa();
    if(dij()==0) break;
      int minf=2147483647ll;
      for(int i=t;i!=s;i=pre[i]){
        minf=std::min(minf,can[usedge[i]]-used[usedge[i]]);
      }
      for(int i=t;i!=s;i=pre[i]){
        used[usedge[i]]+=minf;
        if(cadd[usedge[i]]&&minf!=0){
          add(u[usedge[i]],v[usedge[i]]+1,1,tt[usedge[i]]+cost[usedge[i]],1,tt[usedge[i]]);
          add(v[usedge[i]]+1,u[usedge[i]],0,-tt[usedge[i]]-cost[usedge[i]],1,tt[usedge[i]]);
        }
        used[usedge[i]^1]-=minf;
      }
     ans+=minf*h[t];
  }
    return ans;
  }
};

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("P2050_1.in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  s=n*m+n+1;
  t=n*m+n+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    add(s,i,read(),0);
    add(i,s,0,0);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      int t=read();
      nowk[j]=1;
      add(i,j*n+nowk[j],1,(nowk[j]*t),1,t);
      add(j*n+nowk[j],i,0,-(nowk[j]*t),1,t);
    }
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      add(i*n+j,t,1,0);
      add(t,i*n+j,0,0);
    }
  }
  printf("%lld",mcflow::ans());
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


