#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#define int long long
inline int read();
int fir[105];
int nxt[200005];
int v[200005];
int now=1;
int can[200005];
int used[200005];
int cost[200005];
void add(int x,int y,int z,int a){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  return ;
}
std::string str[105];
std::map<std::string,int>mp;
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
    for(int i=1;i<=t*2;i++){
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
    for(int i=1;i<=t*2;i++){
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
  int ans(int &ans1){
    spfa();
    ans1=0;
    int ans=0;
    while(dij()){
    for(int i=1;i<=t*2;i++){
        h[i]+=dis[i];   
      }
      int minf=2147483647ll;
      for(int i=t;i!=s;i=pre[i]){
        minf=std::min(minf,can[usedge[i]]-used[usedge[i]]);
      }
      for(int i=t;i!=s;i=pre[i]){
        used[usedge[i]]+=minf;
        used[usedge[i]^1]-=minf;
      }
      ans+=minf*h[t];
      ans1+=minf;
    }
    return ans;
  }
};
int cnt=0,n;
int seq[1005];
bool vised[1005];
bool find;
void dfs(int now){
  if(find){
    return ;
  }
  if(vised[now]){
    return ;
  }
  if(now==n+n){
    find=1;
    vised[n]=1;
    seq[++cnt]=n;
    return ;
  }
  vised[now]=1;
  seq[++cnt]=now-n;
  for(int i=fir[now-n];i!=-1;i=nxt[i]){
    if(can[i]!=used[i]||can[i]==0||vised[v[i]]||cost[i]!=0){
      continue;
    }
    dfs(v[i]);
    break;
  }
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    std::cin>>str[i];
    mp[str[i]]=i;
  }
  s=1+n;
  t=n;
  for(int i=1;i<=2*t;i++){
    fir[i]=-1;
  }
  bool yes=0;
  for(int i=1;i<=m;i++){
    std::string a;
    std::string b;
    std::cin>>a>>b;
    if(mp[a]>mp[b]){
      std::swap(a,b);
    }
    if(mp[a]==1&&mp[b]==n){
      yes=1;
    }
    if(mp[a]==n&&mp[b]==1){
      yes=1;
    }
    add(mp[a],mp[b]+n,1,0);
    add(mp[b]+n,mp[a],0,0);
  }
  add(1,1+n,0,1);
  add(n+1,1,2,-1);
  add(n,n*2,0,1);
  add(n*2,n,2,-1);
  for(int i=2;i<n;i++){
    add(i+n,i,1,-1);
    add(i,i+n,0,1);
  } 
  int cntt=0;
  int ans=mcflow::ans(cntt);
  if(yes&&cntt==1){
    printf("%lld\n%s\n%s\n%s",2ll,str[1].c_str(),str[n].c_str(),str[1].c_str());
    return 0;
  }
  if(cntt!=2){
    printf("No Solution!");
    return 0;
  }
  printf("%lld\n",-ans-2);
  find=0;
  cnt=0;
  dfs(1+n);
  for(int i=1;i<=cnt;i++){
    printf("%s\n",str[seq[i]].c_str());
  }
  find=0; 
  cnt=0;
  vised[1+n]=0;
  dfs(1+n);
  for(int i=cnt-1;i>=1;i--){
    printf("%s\n",str[seq[i]].c_str());
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


