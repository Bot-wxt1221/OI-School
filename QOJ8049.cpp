#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int l[505];
int r[505];
int l2[505];
int r2[505];
int dp[505][505][1005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    l[i]=read();
    r[i]=read();
  }
  for(int i=1;i<=m;i++){
    l2[i]=read();
    r2[i]=read();
  }
  dp[0][0][500]=1;
  dp[0][0][501]=-1;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      for(int k=1;k<=1000;k++){
        dp[i][j][k]+=dp[i][j][k-1];
        dp[i][j][k]%=mod;
      }
      for(int k=0;k<=1000;k++){
        if(k>=500){
          dp[i][j+1][k-r2[j+1]]+=(dp[i][j][k])%mod;
          dp[i][j+1][k-r2[j+1]]%=mod;
          dp[i][j+1][k-l2[j+1]+1]-=(dp[i][j][k])%mod;
          dp[i][j+1][k-l2[j+1]+1]%=mod;
        }
        if(k<500){
          dp[i+1][j][k+l[i+1]]+=(dp[i][j][k])%mod;
          dp[i+1][j][k+l[i+1]]%=mod;
          dp[i+1][j][k+r[i+1]+1]-=(dp[i][j][k])%mod;
          dp[i+1][j][k+r[i+1]+1]%=mod;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      printf("%d ",(dp[i][j][500]+mod)%mod);
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
