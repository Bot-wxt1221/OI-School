#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int w1[6005];
int w2[6005];
int dp[6005][6005];
int cnt[6005][6005];
int dp2[6005][6005];
int fac[300005];
int ans2[6005];
int inv[300005];
int pow(int x,int y){
  int ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    x*=x;
    x%=mod;
    y>>=1;
  }
  return ans;
}
int C(int n,int m){
  if(n<m){
    return 0;
  }
  return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  fac[0]=1;
  for(int i=1;i<=300000;i++){
    fac[i]=fac[i-1]*i%mod;
  }
  inv[300000]=pow(fac[300000],mod-2);
  for(int i=299999;i>=0;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  while(T--){
    int n=read();
    for(int i=0;i<=2*n;i++){
      for(int j=0;j<=2*n;j++){
        dp[i][j]=cnt[i][j]=0;
        dp2[i][j]=0;
      }
    }
    int m=read();
    int k=read();
    ans2[0]=0;
    for(int i=1;i<=n;i++){
      w2[i]=read();
      ans2[i]=0;
    }
    for(int i=1;i<=n;i++){
      ans2[i+n]=0;
      w1[i]=read();
    }
    std::sort(w1+1,w1+n+1);
    std::reverse(w1+1,w1+n+1);
    std::sort(w2+1,w2+n+1);
    std::reverse(w2+1,w2+n+1);
    dp[0][0]=0;
    cnt[0][0]=1;
    for(int i=1;i<=n;i++){
      cnt[i][0]=1;
      for(int j=1;j<=i;j++){
        dp[i][j]+=dp[i-1][j-1]+cnt[i-1][j-1]*(w1[i])%mod;
        dp[i][j]%=mod;
        cnt[i][j]+=cnt[i-1][j-1];
        cnt[i][j]%=mod;
        dp[i][j]+=dp[i-1][j];
        dp[i][j]%=mod;
        cnt[i][j]+=cnt[i-1][j];
        cnt[i][j]%=mod;
      }
    }
    dp2[0][0]=1;
    for(int i=1;i<=n;i++){
      dp2[i][0]=1;
      for(int j=1;j<=i;j++){
        dp2[i][j]+=dp2[i-1][j-1]*w2[i]%mod;
        dp2[i][j]%=mod;
        dp2[i][j]+=dp2[i-1][j];
        dp2[i][j]%=mod;
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        ans2[j]+=(dp[i][1]-dp[i-1][1])*C(n-i,j-1)%mod;
        ans2[j]%=mod;
      }
    }
    int ans=0;
    for(int i=2;i<=k;i++){
      for(int j=i;j<=n;j++){
        int sum=(dp[j][i]-dp[j-1][i])*C(n-j,m-k)%mod;
        int sum2=dp2[n][k-i];
        ans+=sum*sum2%mod;
        ans%=mod;
      }
    }
    for(int i=k-1;i<m;i++){
      for(int j=k-1;j<=n;j++){
        int sum=(dp2[j][k-1]-(j-1>=0?dp2[j-1][k-1]:0))*C(n-j,i-(k-1))%mod;
        int sum2=ans2[(m-i)];
        ans+=sum*sum2%mod;
        ans%=mod;
      }
    }
    ans+=mod;
    ans%=mod;
    printf("%lld\n",ans);
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
