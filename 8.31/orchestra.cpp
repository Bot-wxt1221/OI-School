#include <iostream>
#include <cstdio>
#define mod 1000000007
inline int read();
int l[55];
int r[55];
int dp[55][55][4005][2];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("orchestra.in","r",stdin);
  freopen("orchestra.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    l[i]=read();
    r[i]=read();
  }
  dp[0][n+1][0][0]=1;
  dp[0][n+1][1][0]=-1;
  dp[0][n+1][0][1]=1;
  dp[0][n+1][1][1]=-1;

  for(int i=0;i<=n;i++){
    for(int j=n+1;j>=i+1;j--){
      for(int k=1;k<=2000;k++){
        dp[i][j][k][0]+=dp[i][j][k-1][0];
        dp[i][j][k][0]%=mod;
        dp[i][j][k][1]+=dp[i][j][k-1][1];
        dp[i][j][k][1]%=mod;
      }
      for(int val=0;val<=2000;val++){
        if(l[j-1]<val){
          (dp[i][j-1][std::max(1,val-r[j-1])][0]+=dp[i][j][val][0])%=mod;
          (dp[i][j-1][val-l[j-1]+1][0]-=dp[i][j][val][0])%=mod;
        }
        if(val<r[j-1]){
          (dp[i][j-1][std::max(1,l[j-1]-val)][1]+=dp[i][j][val][0])%=mod;
          (dp[i][j-1][r[j-1]-val+1][1]-=dp[i][j][val][0])%=mod;
        }
        if(l[i+1]<val){
          (dp[i+1][j][std::max(1,val-r[i+1])][1]+=dp[i][j][val][1])%=mod;
          (dp[i+1][j][val-l[i+1]+1][1]-=dp[i][j][val][1])%=mod;
        }
        if(val<r[i+1]){
          (dp[i+1][j][std::max(1,l[i+1]-val)][0]+=dp[i][j][val][1])%=mod;
          (dp[i+1][j][r[i+1]-val+1][0]-=dp[i][j][val][1])%=mod;
        }
      }
    }
  }
  long long ret=0;
  for(int i=0;i<=n;++i){
    for(int val=1;val<=2000;++val){
      for(int op=0;op<2;++op){
        ret+=dp[i][i+1][val][op];
        ret%=mod;
      }
    }
  }
  ret+=mod;
  ret%=mod;
  ret*=(mod+1)/2;
  ret%=mod;
  printf("%lld",ret);
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
