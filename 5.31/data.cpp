#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int tt[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=100;
  int m=100;
  srand(time(NULL));
  printf("%d %d\n",n,m);
  for(int i=1;i<=n*m;i++){
    tt[i]=i;
  }
  while(rand()%1000000!=0&&std::next_permutation(tt+1,tt+n*m+1));
  int cnt=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      printf("%d ",tt[++cnt]);
    }
    printf("\n");
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

