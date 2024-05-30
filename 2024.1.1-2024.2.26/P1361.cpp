#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int s,t;
int fir[100005];
int nxt[2000005];
int v[2000005];
int now=1;
int can[2000005];
int used[2000005];
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
  int n=read();
  s=n+2000+1;
  t=s+1;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    int ai=read();
    cnt+=ai;
    add(s,i,ai);
    add(i,s,0);
  }
  for(int i=1;i<=n;i++){
    int bi=read();
    cnt+=bi;
    add(i,t,bi);
    add(t,i,0);
  }
  int m=read();
  for(int i=1;i<=m;i++){
    int ki=read();
    int c1=read();
    int c2=read();
    cnt+=c1;
    cnt+=c2;
    add(s,n+i,c1);
    add(n+i,s,0);
    add(n+i+m,t,c2);
    add(t,n+i+m,0);
    for(int j=1;j<=ki;j++){
      int num=read();
      add(n+i,num,0x3f3f3f3f);
      add(num,n+i,0);
      add(num,n+i+m,0x3f3f3f3f);
      add(n+i+m,num,0);
    }
  }
  printf("%d",cnt-Dinic::solve());
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


