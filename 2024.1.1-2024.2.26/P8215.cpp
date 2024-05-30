#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int s,t;
int fir[35005];
int nxt[5000005];
int v[5000005];
int now=1;
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
namespace Dinic{
  std::queue<int>qu;
  int nfir[550015];
  int dep[550015];
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


signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  s=3*n+1;
  t=3*n+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=2*n;i++){
    int c=read();
    int d=read();
    int e=read();
    add(i,t,c);
    add(t,i,0);
    add(s,i,d);
    add(i,s,0);
    add(i,i+((i%2)?1:-1),e);
    add(i+((i%2)?1:-1),i,0);
    add((i+1)/2+2*n,i,0x3f3f3f3f);
    add(i,(i+1)/2+2*n,0);
  }
  for(int i=1;i<=m;i++){
    int a=read();
    int b=read();
    add(b,(a+1)/2+n*2,read());
    add((a+1)/2+n*2,b,0);
    add((b+1)/2+n*2,a,read());
    add(a,(b+1)/2+n*2,0);
  }
  printf("%lld",Dinic::solve());
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


