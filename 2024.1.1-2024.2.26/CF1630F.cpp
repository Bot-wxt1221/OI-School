#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
inline int read();
int fir[5000005];
int nxt[5000005];
int v[5000005];
int now;
int s,t;
int tot;
int can[5000005];
int used[5000005];
void add(int x,int y,int z){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  can[now]=z;
  used[now]=0;
  return ;
}
int a[5000005];
namespace Dinic{
  std::queue<int>qu;
  int nfir[1000005];
  int dep[1000005];
  bool bfs(int now){
    for(int i=1;i<=t;i++){
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
      for(int i=1;i<=t;i++){
        nfir[i]=fir[i];
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
};
std::map<int,int>mp;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    s=4*n+1;
    t=4*n+2;
    tot=t;
    now=1;
    mp.clear();
    int _max=0;
    for(int i=1;i<=n;i++){
      a[i]=read();
      _max=std::max(_max,a[i]);
    }
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
      mp[a[i]]=i;
    }
    for(int i=1;i<=tot;i++){
      fir[i]=-1;
    }
    for(int i=1;i<=n;i++){
      add(i,3*n+i,1);
      add(3*n+i,i,0);
      int cntt=a[i]*2;
      for(int j=mp[cntt];cntt<=_max;cntt+=a[i]){
          j=mp[cntt];
          if(j!=0){
            add(i,j+3*n,1);
            add(j+3*n,i,0);
            add(i,j+2*n,1);
            add(j+2*n,i,0);
            add(i+n,j+3*n,1);
            add(j+3*n,i+n,0);
        }
      }
    }
    for(int i=1;i<=2*n;i++){
      add(s,i,1);
      add(i,s,0);
      add(i+2*n,t,1);
      add(t,i+2*n,0);
    }
    printf("%d\n",Dinic::solve()-n);
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


