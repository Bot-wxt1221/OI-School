#include <csignal>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <queue>
inline int read();
int fir[205];
int nxt[50005];
int v[50005];
int now=1;
int can[50005];
int used[50005];
int cost[50005];
int n,s,t;
int h[50005];
bool vis[50005];
int dis[50005];
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
void add(int x,int y,int z,int a){
  v[++now]=y;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void spfa(){
  std::queue<int>qu;
  qu.push(s);
  for(int i=1;i<=t;i++){
    vis[i]=0;
    h[i]=0x3f3f3f3f;
  }
  h[s]=0;
  vis[s]=1;
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
int pre[50005];
int uedge[50005];
bool dij(){
  std::priority_queue<node>qu;
  for(int i=1;i<=t;i++){
    vis[i]=0;
    dis[i]=0x3f3f3f3f;
  }
  dis[s]=0;
  qu.push(node(s,0));
  while(qu.size()>0){
    node tt=qu.top();
    qu.pop();
    if(vis[tt.id]){
      continue;
    }
    vis[tt.id]=1;
    for(int i=fir[tt.id];i!=-1;i=nxt[i]){
      int edge=cost[i]+h[tt.id]-h[v[i]];
      if(can[i]!=used[i]&&dis[v[i]]>dis[tt.id]+edge){
        dis[v[i]]=dis[tt.id]+edge;
        pre[v[i]]=tt.id;
        uedge[v[i]]=i;
        if(vis[v[i]]==0){
          qu.push(node(v[i],dis[v[i]]));
        }
      }
    }
  }
  return dis[t]!=0x3f3f3f3f;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  s=n*2+1;
  t=n*2+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int cij=read();
      add(i,j+n,1,cij);
      add(j+n,i,0,-cij);
    }
    add(s,i,1,0);
    add(i,s,0,0);
    add(i+n,t,1,0);
    add(t,i+n,0,0);
  }
  spfa();
  int ans1=0;
  while(dij()){
    for(int i=1;i<=t;i++){
      h[i]+=dis[i];
    }
    int minf=0x3f3f3f3f;
    for(int i=t;i!=s;i=pre[i]){
      minf=std::min(minf,can[uedge[i]]-used[uedge[i]]);
    }
    for(int i=t;i!=s;i=pre[i]){
      used[uedge[i]]+=minf;
      used[uedge[i]^1]-=minf;
    }
    ans1+=minf*h[t];
  }
  printf("%d\n",ans1);
  for(int i=2;i<=now;i++){
    cost[i]=-cost[i];
    used[i]=0;
  }
  ans1=0;
  spfa();
  while(dij()){
    for(int i=1;i<=t;i++){
      h[i]+=dis[i];
    }
    int minf=0x3f3f3f3f;
    for(int i=t;i!=s;i=pre[i]){
      minf=std::min(minf,can[uedge[i]]-used[uedge[i]]);
    }
    for(int i=t;i!=s;i=pre[i]){
      used[uedge[i]]+=minf;
      used[uedge[i]^1]-=minf;
    }
    ans1+=minf*h[t];
  }
  printf("%d",-ans1);
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


