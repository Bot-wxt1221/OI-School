#include <iostream>
#include <cstdio>
inline int read();
signed main(){
//  #ifdef ONLINE_JUDGE
//  #else
  freopen("party.in","w",stdout);
//  freopen(".out","w",stdout);
//  #endif
  srand(time(NULL)+clock());
  int n=5000;
  printf("%d\n",n);
  for(int i=1;i<=n;i++){
    int tt1=rand()%100000+1;
    int tt2=rand()%(100001-tt1)+tt1;
    int tt3=rand()%100000+1;
    printf("%d %d %d\n",tt1,tt2,tt3);
  }
  for(int i=1;i<=n;i++){
    int tt1=rand()%100000+1;
    int tt2=rand()%(100001-tt1)+tt1;
    int tt3=rand()%100000+1;
    printf("%d %d %d\n",tt1,tt2,tt3);
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

