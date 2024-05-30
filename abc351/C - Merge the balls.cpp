#include <iostream>
#include <cstdio>

inline int read();
int a[200005];
int pre[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    pre[i]=i-1;
  }
  int del=0;
  for(int i=2;i<=n;i++){
    int ti=i;
    while(a[ti]==a[pre[ti]]&&ti!=1){
      a[pre[ti]]++;
      pre[i+1]=pre[ti];
      del++;
      ti=pre[ti];
    }
  }
  printf("%d",n-del);
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

