#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
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
  int T=read();
  while(T--){
    int n=read(),m;
    m=read();
    s=n+m+1;
    t=n+m+2;
    tot=n+m+2;
    for(int i=1;i<=t;i++){
      fir[i]=-1;
    }
    now=1;
    for(int i=1;i<=n;i++){
      add(i,t,2);
      add(t,i,0);
    }
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      add(s,i+n,1);
      add(i+n,s,0);
      add(i+n,x,0x3f3f3f3f);
      add(x,i+n,0);
      add(i+n,y,0x3f3f3f3f);
      add(y,i+n,0);
    }
    bool ans=0;
    int nowflow=Dinic::solve();
    for(int i=1;i<=n;i++){
      s=i;
      t=n+1+m;
      nowflow-=Dinic::solve();
      can[i*2]=used[i*2]=0;
      s=n+m+1;
      t=n+m+2;
      nowflow+=Dinic::solve();
      if(m-nowflow>0){
        printf("No\n");
        ans=1;
        ignore[i]=0;
        break;
      }
      can[i*2]=2;
   }
    if(!ans){
      printf("Yes\n");
    }
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


