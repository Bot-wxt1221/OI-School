#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[205];
int nxt[50005];
int v[50005];
int now=1,n,m,s,t;
int can[50005];
int used[50005];
int cost[50005];
bool vis[50005];
int h[50005];
int dis[50005];
int pre[50005];
int usedge[50005];
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
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  return ;
}
void spfa(){
  std::queue<int>qu;
  for(int i=1;i<=t;i++){
    vis[i]=0;
    h[i]=0x3f3f3f3f;
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
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  m=read();
  n=read();
  s=n+m+1;
  t=n+m+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    add(s,i,read(),0);
    add(i,s,0,0);
  }
  for(int i=1;i<=n;i++){
    add(i+m,t,read(),0);
    add(t,i+m,0,0);
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      int tt=read();
      add(i,j+m,0x3f3f3f3f,tt);
      add(j+m,i,0,-tt);
    }
  }
  spfa();
  int ans=0;
  while(dij()){
    for(int i=1;i<=t;i++){
      h[i]+=dis[i];
    }
    int minf=0x3f3f3f3f;
    for(int i=t;i!=s;i=pre[i]){
      minf=std::min(minf,can[usedge[i]]-used[usedge[i]]);
    }
    for(int i=t;i!=s;i=pre[i]){
      used[usedge[i]]+=minf;
      used[usedge[i]^1]-=minf;
    }
    ans+=minf*h[t];
  }
  printf("%d\n",ans);
  for(int i=2;i<=now;i++){
    used[i]=0;
    cost[i]=-cost[i];
  }
  spfa();
  ans=0;
  while(dij()){
    for(int i=1;i<=t;i++){
      h[i]+=dis[i];
    }
    int minf=0x3f3f3f3f;
    for(int i=t;i!=s;i=pre[i]){
      minf=std::min(minf,can[usedge[i]]-used[usedge[i]]);
    }
    for(int i=t;i!=s;i=pre[i]){
      used[usedge[i]]+=minf;
      used[usedge[i]^1]-=minf;
    }
    ans+=minf*h[t];
  }
  printf("%d\n",-ans);
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


