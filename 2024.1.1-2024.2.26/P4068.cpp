#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#define int long long
inline int read();
int a[205];
int b[205];
int s,t;
int c[205];
int cnt[205];
int fir[1005];
int nxt[2000005];
int v[2000005];
int now=1;
int can[2000005];
int used[2000005];
int cost[2000005];
void add(int x,int y,int z,int a){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  return ;
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
    int ans2=0;
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
      if(ans+minf*h[t]>0){
      ans2+=(-ans)/h[t];
      break;
    }
    ans2+=minf;
      ans+=minf*h[t];
    }
    return ans2;
  }
};


signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    int a1=a[i];
    int sq=std::sqrt(a[i]);
    for(int j=2;j<=sq;j++){
      while(a1%j==0){
        a1/=j;
        cnt[i]++;
      }
    }
    if(a1!=1){
      cnt[i]++;
    }
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
  }
  for(int i=1;i<=n;i++){
    c[i]=read();
  }
  s=n+1;
  t=n+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  now=1;
  for(int i=1;i<=n;i++){
    if(cnt[i]&1){
      add(s,i,b[i],0);
      add(i,s,0,0);
    }else{
      add(i,t,b[i],0);
      add(t,i,0,0);
      continue;
    }
    for(int j=1;j<=n;j++){
      if(a[i]%a[j]==0&&cnt[i]==cnt[j]+1){
        add(i,j,0x3f3f3f3f3f3f3f3f,-c[i]*c[j]);
        add(j,i,0,c[i]*c[j]);
      }
      if(a[j]%a[i]==0&&cnt[j]==cnt[i]+1){
        add(i,j,0x3f3f3f3f3f3f3f3f,-c[i]*c[j]);
        add(j,i,0,c[i]*c[j]);
      }
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


