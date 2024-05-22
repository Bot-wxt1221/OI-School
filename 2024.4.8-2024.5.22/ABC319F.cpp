#include <iostream>
#include <cstdio>
inline int read();
int p[505];
int t[505];
int s[505];
int g[505];
int fir[505];
int nxt[1005];
int v[1005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=2;i<=n;i++){
    int fa=read();
    add(fa,i);
    add(i,fa);
    t[i]=read();
    s[i]=read();
    g[i]=read();
  }
  for(int i=)
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

