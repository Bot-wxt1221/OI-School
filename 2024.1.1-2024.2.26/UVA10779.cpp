#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
int s,t;
int fir[105];
int nxt[5005];
int v[5005];
int now;
int can[5005];
int used[5005];
int cnt[55];
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
  int T=read();
  int TT=0;
  while(T--){
    now=1;
    int n=read(),m;
    m=read();
    s=n+m+1;
    t=n+m+2;
    for(int i=1;i<=t;i++){
      fir[i]=-1;
    }
    int k1=read();
    for(int i=1;i<=k1;i++){
      int aj=read();
      add(s,aj+n,1);
      add(aj+n,s,0);
    }
    for(int i=2;i<=n;i++){
      int ki=read();
      memset(cnt,0,sizeof(cnt));
      for(int j=1;j<=ki;j++){
        int aj=read();
        cnt[aj]++;
      }
      for(int j=1;j<=m;j++){
        if(cnt[j]==0){
          add(j+n,i,1);
          add(i,j+n,0);
          continue;
        }
        add(i,j+n,cnt[j]-1);
        add(j+n,i,0);
      }
    }
    for(int i=1;i<=m;i++){
      add(i+n,t,1);
      add(t,i+n,0);
    }
    printf("Case #%d: %d\n",++TT,Dinic::solve());
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


