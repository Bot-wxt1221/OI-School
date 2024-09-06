#include <iostream>
#include <cstdio>
inline int read();
double dp[2005][2005][2];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  dp[1][0][1]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=i;j++){
      dp[i+1][j+1][0]+=dp[i][j][0]/2;
      dp[i+1][j+1][1]+=dp[i][j][1]/2;
      if(j){
        dp[i+1][j-1][0]+=dp[i][j][0]/2+dp[i][j][1];
        dp[i+1][j-1][1]+=dp[i][j][1]/2;     
      }else{
        dp[i+1][j][0]+=dp[i][j][0]/2;
        dp[i+1][j][1]+=dp[i][j][1]/2;
      }
    }
  }
  long double ans=n;
  for(int i=0;i<=n;i++){
    ans-=dp[n+1][i][0];
  }
  printf("%.3Lf",ans);
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
