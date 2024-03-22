#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int p,q,n;
int s,t;
int fir[100005];
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
bool fang[105][105];
bool del[105][105];
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
  n=read();
  p=read();
  q=read();
  s=n*2+p+q+1;
  t=n*2+p+q+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=p;j++){
      fang[i][j]=read();
      if(fang[i][j]){
        add(j+n*2,i,1);
        add(i,j+n*2,0);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=q;j++){
      del[i][j]=read();
      if(del[i][j]){
        add(i+n,j+n*2+p,1);
        add(j+n*2+p,i+n,0);
      }
    }
  }
  for(int i=1;i<=n;i++){
    add(i,i+n,1);
    add(i+n,i,0);
  }
  for(int i=1;i<=p;i++){
    add(s,i+n*2,1);
    add(i+n*2,s,0);
  }
  for(int i=1;i<=q;i++){
    add(i+n*2+p,t,1);
    add(t,i+n*2+p,0);
  }
  printf("%d",Dinic::solve());
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


