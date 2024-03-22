#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
int s,t,n;
int fir[5005];
int nxt[200005];
int v[200005];
int can[200005];
int used[200005];
int cost[200005];
int now=1;
int dis[5005];
int h[5005];
bool inque[5005];
int pre[5005];
int edg[5005];
void add(int x,int y,int z,int a){
  v[++now]=y;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
class node{
  public:
    int id,data;
    node(int x=0,int y=0){
      id=x;
      data=y;
      return ;
    }
};
bool operator < (node a,node b){
  return a.data>b.data;
}
void spfa(int now){
  std::queue<int>qu;
  memset(h,0x3f,sizeof(h));
  h[now]=0;
  inque[s]=1;
  qu.push(s);
  while(qu.size()>0){
    int tp=qu.front();
    qu.pop();
    inque[tp]=0;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(can[i]!=used[i]&&h[v[i]]>h[tp]+cost[i]){
        h[v[i]]=h[tp]+cost[i];
        if(inque[v[i]]==0){
          qu.push(v[i]);
          inque[v[i]]=1;
        }
      }
    }
  }
  return ;
}
bool dij(int now){
  std::priority_queue<node>qu;
  for(int i=1;i<=n;i++){
    dis[i]=0x3f3f3f3f;
    inque[i]=0;
  }
  dis[s]=0;
  qu.push(node(s,0));
  while(qu.size()>0){
    node tp=qu.top();
    qu.pop();
    if(inque[tp.id]){
      continue;
    }
    inque[tp.id]=1;
    for(int i=fir[tp.id];i!=-1;i=nxt[i]){
      int edge=cost[i]+h[tp.id]-h[v[i]];
      if(can[i]!=used[i]&&dis[v[i]]>dis[tp.id]+edge){
        dis[v[i]]=dis[tp.id]+edge;
        pre[v[i]]=tp.id;
        edg[v[i]]=i;
        if(inque[v[i]]==0){
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
  int m=read();
  s=read();
  t=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int u=read();
    int v=read();
    int w=read();
    int c=read();
    add(u,v,w,c);
    add(v,u,0,-c);
  }
  spfa(s);
  int ans1=0;
  int ans2=0;
  while(dij(s)){
    for(int i=1;i<=n;i++){
      h[i]+=dis[i];
    }
    int minf=0x3f3f3f3f;
    for(int i=t;i!=s;i=pre[i]){
      minf=std::min(minf,can[edg[i]]-used[edg[i]]);
    }
    for(int i=t;i!=s;i=pre[i]){
      used[edg[i]]+=minf;
      used[edg[i]^1]-=minf;
    }
    ans1+=minf;
    ans2+=minf*h[t];
  }
  printf("%d %d",ans1,ans2);
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


