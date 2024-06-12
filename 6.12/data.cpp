#include <algorithm>
#include <ctime>
#include <iostream>
#include <cstdio>
inline int read();
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  srand(time(NULL)+clock());
  int n=11;
  int m=rand()%2+3;
  printf("%d %d\n",n,m);
  for(int i=1;i<=m;i++){
    printf("%d %d\n",rand()%n+1,rand()%n+1);
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

