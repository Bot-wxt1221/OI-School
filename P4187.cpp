#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int dp[1000005];
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
  int k=read();
  int sum=1;
  dp[0]=1;
  int ans=pow(m,n-k)*(m)%mod;
  for(int i=1;i<=n-k;i++){
    if(i-k>=0){
      sum+=mod-dp[i-k];
      sum%=mod;
    }
    dp[i]=(1ll*sum*(m-1))%mod;
    dp[i]%=mod;
    if(i<k){
      dp[i]++;
      dp[i]%=mod;
    }
    sum+=dp[i];
    sum%=mod;
    ans+=(pow(m,(n-k-i))*dp[i]%mod*(m-1)%mod);
    ans%=mod;
  }
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

