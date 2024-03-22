#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int s,t,r,c;
int fir[2005];
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
bool vised[2005];
bool mention[2005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  r=read();
  c=read();
  int n=read();
  do{
    memset(vised,0,sizeof(vised));
    memset(mention,0,sizeof(mention));
    s=r+c+1;
    t=r+c+2;
    now=1;
    for(int i=1;i<=t;i++){
      fir[i]=-1;
    }
    for(int i=1;i<=n;i++){
      int x=read();
      int y=read();
      mention[x]=mention[y+r]=1;
      add(x,y+r,1);
      add(y+r,x,0);
    }
    for(int i=1;i<=r;i++){
      add(s,i,1);
      add(i,s,0);
    }
    for(int i=1;i<=c;i++){
      add(i+r,t,1);
      add(t,i+r,0);
    }
    printf("%d ",Dinic::solve());
    for(int i=1;i<=r;i++){
      if(mention[i]&&Dinic::dep[i]==0){
        printf("r%d ",i);
      }
    }
    for(int i=1;i<=c;i++){
      if(mention[i+r]&&Dinic::dep[i+r]){
        printf("c%d ",i);
      }
    }
    printf("\n");
    r=read();
    c=read();
    n=read();
  }while(r!=0||c!=0||n!=0);
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


