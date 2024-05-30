#include <iostream>
#include <cstdio>
inline int read();
long double dp[105][105][105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=0;k<=n;k++){
        long double p1=(long double)1*i/(i+j);
        dp[i][j][k]+=dp[i-1][j][std::max(0,k-1)]*p1+dp[i][j-1][k+1]*(1-p1);
        if(k==0){
          dp[i][j][k]+=p1*i;
        }
      }
    }
  }
  printf("%.6Lf",dp[n][n][0]);
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

