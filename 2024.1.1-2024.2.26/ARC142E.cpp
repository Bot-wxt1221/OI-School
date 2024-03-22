#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int a[105];
int b[105];
int x[105];
int y[105];
int fir[5005];
int nxt[5000005];
int u[5000005];
int v[5000005];
int now;
int tot;
int s,t;
int can[5000005];
int used[5000005];
int ncan[5000005];
void add(int x,int y,int z){
  v[++now]=y;
  u[now]=x;
  nxt[now]=fir[x];
  fir[x]=now;
  ncan[now]=z;
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
    for(int i=1;i<=tot;i++){
      dep[i]=0;
    }
    dep[now]=1;
    qu.push(now);
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      for(int i=fir[tt];i!=-1;i=nxt[i]){
        if(dep[v[i]]||can[i]==used[i]||ignore[v[i]]){
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
      if(dep[v[i]]!=dep[now]+1||can[i]==used[i]||ignore[v[i]]){
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
  if(s==t){
    return 0;
  }
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
  int n=read();
  now=1;
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
  }
  s=101*n+1;
  t=101*n+2;
  tot=101*n+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  int m=read();
  int ans=0;
  for(int i=1;i<=m;i++){
    x[i]=read();
    y[i]=read();
    if(b[x[i]]<b[y[i]]){
      std::swap(x[i],y[i]);
    }
    if(a[y[i]]<b[y[i]]){
      ans+=b[y[i]]-a[y[i]];
      a[y[i]]=b[y[i]];
    }
    if(a[x[i]]<b[y[i]]){
      ans+=b[y[i]]-a[x[i]];
      a[x[i]]=b[y[i]];
    }
  }
  for(int i=1;i<=n;i++){
    if(a[i]<b[i]){
      add(s,i,b[i]-a[i]);
      add(i,s,0);
    }
  }
  for(int i=1;i<=m;i++){
    if(a[y[i]]<b[x[i]]){
      add(x[i],(b[x[i]]-a[y[i]])*n+y[i],0x3f3f3f3f);
      add((b[x[i]]-a[y[i]])*n+y[i],x[i],0);
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=100-a[i];j++){
      add(j*n+i,t,1);
      add(t,j*n+1,0);
      if(j!=1){
        add(j*n+i,(j-1)*n+i,0x3f3f3f3f);
        add((j-1)*n+i,j*n+i,0);
      }
    }
  }
  printf("%d",ans+Dinic::solve());
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


