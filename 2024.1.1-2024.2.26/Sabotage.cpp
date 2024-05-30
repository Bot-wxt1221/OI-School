#include <queue>
#include <iostream>
#include <cstdio>
inline int read();
int s,t;
int fir[55];
int nxt[5005];
int v[5005];
int now=1;
int can[5005];
int u[5005];
int used[5005];
void add(int x,int y,int z){
  v[++now]=y;
  u[now]=x;
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

bool vised[55];
void dfs(int now){
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(can[i]==0||used[i]==can[i]||vised[v[i]]){
      continue;
    }
    dfs(v[i]);
  }
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  do{
    now=1;
    s=n+1;
    t=n+2;
    for(int i=1;i<=t;i++){
      vised[i]=0;
      fir[i]=-1;
    }
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      int z=read();
      add(x,y,z);
      add(y,x,z);
    }
    add(s,1,0x3f3f3f3f);
    add(1,s,0);
    add(2,t,0x3f3f3f3f);
    add(t,2,0);
    int ans=Dinic::solve();
    dfs(s);
    for(int i=2;i<=now;i+=2){
      if(can[i]==0||u[i]==s||v[i]==t||vised[u[i]]==vised[v[i]]){
        continue;
      }
      printf("%d %d\n",u[i],v[i]);
    }
    printf("\n");
    n=read();
    m=read();
  }while(n!=0||m!=0);
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


