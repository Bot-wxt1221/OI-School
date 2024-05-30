#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
int f[400005];
int g[400005];
int k;
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m,p;
  m=read();
  p=read();
  k=n+m;
  k=(1<<(int(std::log2(k)+1)));
  for(int i=0;i<=n;i++){
    f[i]=read();
  }
  for(int i=0;i<=m;i++){
    g[i]=read();
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


