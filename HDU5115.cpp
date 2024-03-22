#include <iostream>
#include <cstdio>
inline int read();
int dp[205][205];
int a[205];
int b[205];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int TT=0;
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      for(int j=1;j<=n;j++){
        dp[i][j]=0;
      }
    }
    for(int i=1;i<=n;i++){
      b[i]=read();
    }
    for(int i=1;i<=n;i++){
      dp[i][i]=a[i]+b[i-1]+b[i+1];
    }
    for(int siz=2;siz<=n;siz++){
      for(int i=1;i+siz-1<=n;i++){
        int j=i+siz-1;
        dp[i][j]=0x3f3f3f3f;
        for(int k=i;k<=j;k++){//[i,k],(k,j]
          dp[i][j]=std::min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
        }
      }
    }
    printf("Case #%d: %d\n",++TT,dp[1][n]);
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


