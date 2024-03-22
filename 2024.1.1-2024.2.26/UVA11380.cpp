#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
char temp[35][35];
int s,t;
int fir[4005];
bool ignore[50005];
int nxt[50005];
int v[50005];
int now;
int y;
int u[50005];
int can[50005];
int used[50005];
int two(int a,int b){
  return (a-1)*y+b;
}
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

int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int x;
  while(scanf("%d",&x)!=EOF){
    y=read();
    int p=read();
    for(int i=1;i<=x;i++){
      scanf("%s",temp[i]+1);
    }
    s=x*y*2+1;
    t=x*y*2+2;
    for(int i=1;i<=t;i++){
      fir[i]=-1;
    }
    now=1;
    for(int i=1;i<=x;i++){
      for(int j=1;j<=y;j++){
        if(temp[i][j]=='*'){
          add(s,two(i,j),1);
          add(two(i,j),s,0);
          add(two(i,j),two(i,j)+x*y,1);
          add(two(i,j)+x*y,two(i,j),0);
        }
        if(temp[i][j]=='.'){
          add(two(i,j),two(i,j)+x*y,1);
          add(two(i,j)+x*y,two(i,j),0);
        }
        if(temp[i][j]=='@'){
          add(two(i,j),two(i,j)+x*y,0x3f3f3f3f);
          add(two(i,j)+x*y,two(i,j),0);
        }
        if(temp[i][j]=='#'){
          add(two(i,j),two(i,j)+x*y,0x3f3f3f3f);
          add(two(i,j)+x*y,two(i,j),0);
          add(two(i,j)+x*y,t,p);
          add(t,two(i,j)+x*y,0);
        }
        for(int k=0;k<4;k++){
          int nx=i+to[k][0];
          int ny=j+to[k][1];
          if(nx<=0||ny<=0||nx>x||ny>y){
            continue;
          }
          add(two(i,j)+x*y,two(nx,ny),0x3f3f3f3f);
          add(two(nx,ny),two(i,j)+x*y,0);
        }
      }
    }
    printf("%d\n",Dinic::solve());
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


