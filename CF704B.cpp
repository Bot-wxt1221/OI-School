#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int x[5005];
int a[5005];
int b[5005];
int c[5005];
int d[5005];
int dp[5005][5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int s=read();
  int e=read();
  for(int i=1;i<=n;i++){
    x[i]=read();
  }
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
  }
  for(int i=1;i<=n;i++){
    c[i]=read();
  }
  for(int i=1;i<=n;i++){
    d[i]=read();
  }
  memset(dp,0x3f,sizeof(dp));
  dp[0][0]=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      if(i==s){
        dp[i][j]=std::min(dp[i][j],dp[i-1][j]+x[i]+c[i]);
        dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]-x[i]+d[i]);
      }else if(i==e){
        dp[i][j]=std::min(dp[i][j],dp[i-1][j]+x[i]+a[i]);
        dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]-x[i]+b[i]);
      }else{
        if(j>1||(i<s&&j>0)){
          dp[i][j]=std::min(dp[i][j],dp[i-1][j]+c[i]+b[i]);
        }
        if(j>1||(i<e&&j>0)){
          dp[i][j]=std::min(dp[i][j],dp[i-1][j]+a[i]+d[i]);
        }
        dp[i][j]=std::min(dp[i][j],dp[i-1][j+1]+2*x[i]+a[i]+c[i]);
        if(j>(i>s)+(i>e)){
          dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]-2*x[i]+b[i]+d[i]);
        }
      }
    }
  }
  printf("%lld",dp[n][1]);
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


