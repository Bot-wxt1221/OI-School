#include <iostream>
#include <cstdio>
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int fa[500005];
int dep[500005];
int down[500005];
void dfs(int now,int fa){
  ::fa[now]=fa;
  dep[now]=dep[fa]+1;
  down[now]=dep[now];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    down[now]=std::max(down[now],down[v[i]]);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int x=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  int dis=0;
  int ans=0;
  while(x!=1){
    if(dep[x]>dis){
      ans=std::max(ans,std::max((down[x]-dep[x]+dis),(down[x]-1))*2);
    }
    dis++;
    x=fa[x];
  }
  ans=std::max(ans,dis);
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

