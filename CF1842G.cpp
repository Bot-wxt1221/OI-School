#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int dp[5005][5005];
int a[5005];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (1ll*tt*tt)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int v=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=std::min(n,m);j++){
      dp[i][j]=dp[i-1][j]*a[i]%mod;
      if(j>0){
        dp[i][j]+=dp[i-1][j-1]*(i)%mod*(m-j+1)%mod*v%mod;
        dp[i][j]%=mod;
      }
      dp[i][j]+=dp[i-1][j]*j%mod*v%mod;
      dp[i][j]%=mod;
    }
  }
  int tt=1;
  int tans=0;
  for(int j=0;j<=std::min(n,m);j++){
    tans+=dp[n][j]*tt;
    tans%=mod;
    tt*=pow(n,mod-2);
    tt%=mod;
  }
  printf("%lld",tans);
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

