#include <queue>
#include <iostream>
#include <cstdio>
#define int long long
inline int read();
char temp[25][25];
int fir[5005];
int nxt[50005];
int v[50005];
int now=1;
int cost[50005];
int used[50005];
int can[50005];
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
int r,c;
int two(int x,int y){
  if(y==0){
    y=c;
  }
  if(y==c+1){
    y=1;
  }
  if(x==0){
    x=r;
  }
  if(x==r+1){
    x=1;
  }
  return (x-1)*c+y;
}
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



signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  r=read();
  c=read();
  for(int i=1;i<=r;i++){
    scanf("%s",temp[i]+1);
  }
  s=2*r*c+1;
  t=2*r*c+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  now=1;
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      add(two(i,j),two(i,j+1)+r*c,1,(temp[i][j]!='R'));
      add(r*c+two(i,j+1),two(i,j),0,-(temp[i][j]!='R'));
      add(two(i,j),two(i,j-1)+r*c,1,(temp[i][j]!='L'));
      add(r*c+two(i,j-1),two(i,j),0,-(temp[i][j]!='L'));
      add(two(i,j),two(i-1,j)+r*c,1,(temp[i][j]!='U'));
      add(r*c+two(i-1,j),two(i,j),0,-(temp[i][j]!='U'));
      add(two(i,j),two(i+1,j)+r*c,1,(temp[i][j]!='D'));
      add(r*c+two(i+1,j),two(i,j),0,-(temp[i][j]!='D'));
    }
  }
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      add(s,two(i,j),1,0);
      add(two(i,j),s,0,0);
      add(two(i,j)+r*c,t,1,0);
      add(t,two(i,j)+r*c,0,0);
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


