#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
int x[105];
int y[105];
int fir[505];
int nxt[5000005];
int v[5000005];
int now;
int s,t;
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
bool ignore[5000005];
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
        if(dep[v[i]]||can[i]==used[i]||ignore[i]){
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
      if(dep[v[i]]!=dep[now]+1||can[i]==used[i]||ignore[i]){
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
  int T=read();
  while(T--){
    int n=read();
    now=1;
    double d;
    int tot=0;
    scanf("%lf",&d);
    memset(ignore,0,sizeof(ignore));
    for(int i=1;i<=2*n+2;i++){
      fir[i]=-1;
    }
    s=2*n+1;
    t=2*n+2;
    for(int i=1;i<=n;i++){
      x[i]=read();
      y[i]=read();
      int cntt=read();
      tot+=cntt;
      add(s,i,cntt);
      add(i,s,0);
      add(i,i+n,read());
      add(i+n,i,0);
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=d*d&&i!=j){
          add(i+n,j,0x3f3f3f3f);
          add(j,i+n,0);
        }
      }
    }
    int lst=0;
    for(int i=1;i<=n;i++){
      memset(used,0,sizeof(used));
      add(i,t,0x3f3f3f3f);
      add(t,i,0);
      if(Dinic::solve()!=tot){
        ignore[now]=ignore[now-1]=1;
        continue;
      }
      ignore[now]=ignore[now-1]=1;
      if(lst){
        printf(" ");
      }
      lst=i;
      printf("%d",i-1);
    }
    if(lst==0){
      printf("-1");
    }
    printf("\n");
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


