#include <cmath>
#include <iostream>
#include <cstdio>
#define mod 1000000007
inline int read();
int dp[1000005][22][3];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int aa=((int)log2(int(n/3)))+1;
  int bb=log2(n);
  dp[1][bb][0]=1;
  if(aa==bb){
    dp[1][bb-1][1]=1;
  }
  for(int i=2;i<=n;i++){
    int cur=1;
    for(int j=0;j<=20;j++){
      int cur2=cur;
      for(int k=0;k<=1;k++){
        dp[i][j][k]+=(1ll*dp[i-1][j][k]*((n/cur2)-(i-1)))%mod;
        dp[i][j][k]+=(1ll*dp[i-1][j+1][k]*((n/(cur2))-(n/(cur2*2))))%mod;
        dp[i][j][k]%=mod;
        dp[i][j][k]+=(1ll*dp[i-1][j][k+1]*((n/(cur2))-(n/(cur2*3))))%mod;
        dp[i][j][k]%=mod;
        cur2*=3;
        if(cur2>n){
          continue;
        }
      }
      cur*=2;
    }
  }
  printf("%d\n",dp[n][0][0]);
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

