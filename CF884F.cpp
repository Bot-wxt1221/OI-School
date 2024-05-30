#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[800005];
int nxt[5000005];
int v[5000005];
int now=1;
int can[5000005];
int used[5000005];
int cost[5000005];
void add(int x,int y,int z,int a){
  v[++now]=y;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int s,t;
namespace mcflow{
  bool vis[5000005];
  long long h[5000005];
  long long dis[5000005];
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
      h[i]=0x3f3f3f3f3f3f3f3f;
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
      dis[i]=0x3f3f3f3f3f3f3f3f;
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
        long long edge=std::min(cost[i]+h[temp.id]+0ll-h[v[i]],0x7f7f7f7f7f7f7f7fll);
        if(can[i]!=used[i]&&0ll+dis[v[i]]>0ll+dis[temp.id]+edge){
          dis[v[i]]=dis[temp.id]+edge;
          usedge[v[i]]=i;
          pre[v[i]]=temp.id;
          if(vis[v[i]]==0){
            qu.push(node(v[i],dis[v[i]]));
          }
        }
      }
    }
    return dis[t]!=0x3f3f3f3f3f3f3f3f;
  }
  long long ans(){
    spfa();
    long long ans=0;
    while(dij()){
      for(int i=1;i<=t;i++){
        h[i]=std::min(dis[i]+0ll+h[i],0x3f3f3f3f3f3f3f3fll);
      }
      long long minf=0x3f3f3f3f3f3f3f3f;
      for(int i=t;i!=s;i=pre[i]){
        minf=std::min(minf,(long long)(can[usedge[i]]-used[usedge[i]]));
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
char a[105];
int app[55];
int co[105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  now=1;
  scanf("%s",a+1);
  for(int i=1;i<=n;i++){
    app[a[i]-'a']++;
    co[i]=read();
  }
  s=26+26*n/2+n+1;
  t=s+1;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    add(i+26*n/2+26,t,1,0);
    add(t,i+26*n/2+26,0,0);
  }
  for(int i=0;i<26;i++){
    add(s,i+1,app[i],0);
    add(i+1,s,0,0);
    for(int j=1;j<=n/2;j++){
      add(i+1,26+j+(i*n/2),1,0);
      add(26+j+(i*n/2),i+1,0,0);
      add(26+j+(i*n/2),26+26*n/2+j,1,-co[j]*(a[j]==i+'a'));
      add(26+26*n/2+j,26+j+(i*n/2),0,co[j]*(a[j]==i+'a'));
      add(26+j+(i*n/2),26+26*n/2+(n-j+1),1,-co[(n-j+1)]*(a[(n-j+1)]==i+'a'));
      add(26+26*n/2+(n-j+1),26+j+(i*n/2),0,co[(n-j+1)]*(a[(n-j+1)]==i+'a'));
    }
  }
  printf("%lld",-mcflow::ans());
  return 0;
}
inline signed read(){
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

