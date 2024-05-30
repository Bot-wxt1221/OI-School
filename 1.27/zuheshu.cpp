#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int C[105][105];
signed main(){
//	#ifdef ONLINE_JUDGE
//	#else
	freopen(".in","r",stdin);
  	freopen(".out","w",stdout);
	#endif
  for(int i=1;i<=50;i++){
    printf("1 ");
    C[i][i]=1;
    for(int j=i+1;j<=50;j++){
      C[i][j]=C[i][j-1]+C[i-1][j-1];
      printf("%5lld ",C[i][j]);
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


