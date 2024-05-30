#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int temp[205][205];
int n,m;
int to[8][2]={{-1,0},{1,0},{0,-1},{0,1}};
int two(int x,int y){
  return (m)*(x-1)+y;
}
int fir[400005];
int nxt[3200005];
int v[3200005];
int can[3200005];
int used[3200005];
int now=1;
void add(int x,int y,int z){
  v[++now]=y;
  can[now]=z;
  used[now]=0;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int s,t;
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
  n=read();
  m=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      temp[i][j]=read();
    }
  }
  for(int i=1;i<=n*m+2;i++){
    fir[i]=-1;
  }
  s=n*m+1;
  int cntt=0;
  t=n*m+2;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cntt+=temp[i][j];
      if((i+j)%2==0){
        add(two(i,j),t,temp[i][j]);
        add(t,two(i,j),0);
        continue;
      }
      add(s,two(i,j),temp[i][j]);
      add(two(i,j),s,0);
      for(int k=0;k<4;k++){
        int nx=i+to[k][0];
        int ny=j+to[k][1];
        if(nx<=0||ny<=0||nx>n||ny>m){
          continue;
        }
        add(two(i,j),two(nx,ny),0x3f3f3f3f);
        add(two(nx,ny),two(i,j),0);
      }
    }
  }
  printf("%lld",cntt-Dinic::solve());
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

