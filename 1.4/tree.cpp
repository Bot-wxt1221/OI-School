#include <iostream>
#include <cstdio>
#define int long long
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
int big[200005];
int ans=0,m;
int depth[200005];
int maxdep=0;
void dfs(int now){
  maxdep=std::max(maxdep,depth[now]);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    depth[v[i]]=depth[now]+1;
    dfs(v[i]);
  }
  return ;
}
void dfs2(int now){
  big[now]=0;
  int big2=0;
  bool ye=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    ye=0;
    dfs2(v[i]);
    if(big[v[i]]+1>=big[now]){
      big2=big[now];
      big[now]=big[v[i]]+1;
    }else if(big[v[i]]+1>big2){
      big2=big[v[i]]+1;
    }
  }
  if(ye){
    big[now]=maxdep*(m-1);
  }
  ans=std::max(ans,big[now]+big2+1);
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
  int n=read();
  m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=2;i<=n;i++){
    add(read(),i);
  }
  dfs(1);
  maxdep++;
  dfs2(1);
  printf("%lld",ans);
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


