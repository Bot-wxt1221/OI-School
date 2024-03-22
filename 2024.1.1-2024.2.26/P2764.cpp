#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int s,t;
int fir[305];
int nxt[600005];
int v[600005];
int now=1;
int can[600005];
int used[600005];
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
  int nfir[1005];
  int dep[1005];
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
bool out[305];
bool begin[305];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  s=n*2+1;
  t=n*2+2;
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x+n,y,1);
    add(y,x+n,0);
  }
  for(int i=1;i<=n;i++){
    add(s,i+n,1);
    add(i+n,s,0);
    add(i,t,1);
    add(t,i,0);
  }
  int ans=n-Dinic::solve();
  for(int i=1;i<=n;i++){
    for(int j=fir[i+n];j!=-1;j=nxt[j]){
      if(can[j]!=used[j]||can[j]==0){
        continue;
      }
      begin[v[j]]=1;
    }
  }
  for(int i=1;i<=ans;i++){
    int rj=0;
    for(int j=1;j<=n;j++){
      if(out[j]||begin[j]){
        continue;
      }
      rj=j;
      break;
    }
    while(1){
      printf("%d ",rj);
      out[rj]=1;
      bool end=1;
      for(int i=fir[rj+n];i!=-1;i=nxt[i]){
        if(can[i]!=used[i]||can[i]==0||out[v[i]]){
          continue;
        }
        rj=v[i];
        end=0;
        break;
      }
      if(end){
        break;
      }
    }
    printf("\n");
  }
  printf("%d",ans);
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


