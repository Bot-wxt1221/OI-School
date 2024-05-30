#include <iostream>
#include <cstdio>
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen("rev.out","w",stdout);
  #endif
  int n=5000;
  int q=5000;
  srand(clock()+time(NULL));
  printf("%d %d\n",n,q);
  for(int i=1;i<=n;i++){
    printf("%d ",rand()%2);
  }
  printf("\n");
  for(int i=1;i<=q;i++){
    int t=rand()%2+1;
    int l=rand()%n+1;
    int r=rand()%(n-l+1)+l;
    printf("%d %d %d\n",t,l,r);
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

