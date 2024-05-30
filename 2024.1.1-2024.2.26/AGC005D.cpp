#include <iostream>
#include <cstdio>
#define mod 924844033
#define int long long
inline int read();
int fac[2005];
int dp[4005][2005][2];
bool top[4005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int k=read();
  fac[0]=1;
  for(int i=1;i<=n;i++){
    fac[i]=(fac[i-1]*i)%mod;
  }
  int tot=0;
  for(int i=1;i<=k;i++){
    for(int kk=0;kk<=1;kk++){
      for(int j=i;j<=n;j+=k){
        tot++;
        if(i!=j){
          top[tot]=1;
        }
      }
    }
  }
  dp[0][0][0]=1;
  for(int i=1;i<=n*2;i++){
    for(int j=0;j<=n;j++){
      dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%mod;
      if(top[i]){
        dp[i][j][1]=dp[i-1][j-1][0];
      }
    }
  }
  int ans=0;
  for(int i=0;i<=n;i++){
    if(i%2){
      ans-=(((dp[n*2][i][0]+dp[n*2][i][1])%mod)*fac[n-i])%mod;
      ans%=mod;
    }else{
      ans+=(((dp[n*2][i][0]+dp[n*2][i][1])%mod)*fac[n-i])%mod;
      ans%=mod;
    }
  }
  ans+=mod;
  ans%=mod;
  printf("%lld",ans);
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


