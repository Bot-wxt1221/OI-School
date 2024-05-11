#include <iostream>
#include <cstdio>
inline int read();
char a[105][105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      a[i][j]=read();
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(read()!=a[i][j]){
        printf("%d %d",i,j);
        return 0;
      }
    }
  }
  return 0;
}
inline int read(){
  int x=0,f=1;char c=getchar();
  while(c<'a'||c>'z'){
    c=='-'?f=-1:1;
    c=getchar();
  }
  x=c;
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

