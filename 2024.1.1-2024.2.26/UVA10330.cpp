#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int s,t;
int fir[505];
int nxt[5000005];
int v[5000005];
int now;
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
  int nfir[100005];
  int dep[100005];
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


int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n;
  while(scanf("%d",&n)!=EOF){
    now=1;
    s=n*2+1;
    t=n*2+2;
    for(int i=1;i<=t;i++){
      fir[i]=-1;
    }
    for(int i=1;i<=n;i++){
      int ai=read();
      add(i,i+n,ai);
      add(i+n,i,0);
    }
    int m=read();
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      add(x+n,y,read());
      add(y,x+n,0);
    }
    int b=read();
    int d=read();
    for(int i=1;i<=b;i++){
      int tt=read();
      add(s,tt,0x3f3f3f3f);
      add(tt,s,0);
    }
    for(int i=1;i<=d;i++){
      int tt=read();
      add(tt+n,t,0x3f3f3f3f);
      add(t,tt+n,0);
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


