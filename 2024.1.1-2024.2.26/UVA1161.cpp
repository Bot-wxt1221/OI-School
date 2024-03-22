#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
inline int read();
std::map<std::string,int>mp;
int fir[516005];
int nxt[5000005];
int v[5000005];
int now;
int s,t;
int tot;
int can[5000005];
int used[5000005];
std::string st;
std::string en;
int two(int x,int m){
  return (x-1)*1440+m;
}
void add(int x,int y,int z){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  return ;
}
namespace Dinic{
  std::queue<int>qu;
  int nfir[1000005];
  int dep[1000005];
  bool bfs(int now){
    for(int i=1;i<=tot;i++){
      dep[i]=0;
    }
    dep[now]=1;
    qu.push(now);
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      for(int i=fir[tt];i!=-1;i=nxt[i]){
        if(dep[v[i]]||can[i]==used[i]){
          continue;
        }
        dep[v[i]]=dep[tt]+1;
        qu.push(v[i]);
      }
    }
    return dep[t];
  }
  int dfs(int now,int flow){
    if(flow==0||now==t){
      return flow;
    }
    int nflow=0;
    for(int &i=nfir[now];i!=-1;i=nxt[i]){
      if(dep[v[i]]!=dep[now]+1||can[i]==used[i]){
        continue;
      }
      int tt=dfs(v[i],std::min(flow-nflow,can[i]-used[i]));
      if(tt==0){
        continue;
      }
      nflow+=tt;
      used[i]+=tt;
      used[i^1]-=tt;
      if(nflow==flow){
        return nflow;
      }
    }
    return nflow;
  }
  int solve(int ans=0){
  while(bfs(s)){
      for(int i=1;i<=tot;i++){
        nfir[i]=fir[i];
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};

int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n;
  while(scanf("%d",&n)!=EOF){
    mp.clear();
    now=1;
    std::cin>>st;
    std::cin>>en;
    int cnt=0;
    tot=1440*(n+2);
    for(int i=1;i<=tot;i++){
      fir[i]=-1;
    }
    s=1;
    mp[st]=++cnt;
    if(mp[en]==0){
      mp[en]=++cnt;
    }
    int lst=read();
    lst=(lst/100)*60+(lst%100+1);
    t=two(mp[en],lst);
    for(int i=1;i<=n;i++){
      for(int j=2;j<=1440;j++){
        add(two(i,j-1),two(i,j),0x3f3f3f3f);
        add(two(i,j),two(i,j-1),0);
      }
    }
    int m=read();
    for(int i=1;i<=m;i++){
      std::string u,v;
      std::cin>>u>>v;
      int c=read();
      int d=read();
      d=(d/100)*60+(d%100+1);
      int a=read();
      a=(a/100)*60+(a%100+1)+30;
      if(v==en){
        a-=30;
      }
      if(a>1440){
        continue;
      }
      if(mp[u]==0){
        mp[u]=++cnt;
      }
      if(mp[v]==0){
        mp[v]=++cnt;
      }
      add(two(mp[u],d),two(mp[v],a),c);
      add(two(mp[v],a),two(mp[u],d),0);
    }
    printf("%d\n",Dinic::solve());
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


