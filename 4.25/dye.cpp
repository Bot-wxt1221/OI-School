#include <iostream>
#include <cstdio>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dep[100005];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("dye.in","r",stdin);
  freopen("dye.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  int x=read();
  int y=read();
  for(int i=1;i<n;i++){
    int a=read();
    int b=read();
    add(a,b);
    add(b,a);
  }
  dfs(1,1);
  if(dep[x]>=dep[y]){
    printf("Cuber QQ");
  }else{
    printf("Little Fang");
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

