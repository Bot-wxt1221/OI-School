#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#define int long long
#define mod 1000000007
inline int read();
int a[305];
int dp[305][305];
int cnt[305];
int fra[1000005];
int inv[1000005];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==1){
    return (pow(x,y-1)*x)%mod;
  }
  int temp=pow(x,y/2);
  return (temp*temp)%mod;
}
int C(int x,int y){
  return (((fra[x]*inv[y])%mod)*(inv[x-y]))%mod;
}
std::map<int,int>mp;
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  fra[0]=1;
  for(int i=1;i<=n;i++){
    fra[i]=fra[i-1]*i;
    fra[i]%=mod;
  }
  inv[n]=pow(fra[n],mod-2);
  for(int i=n-1;i>=1;i--){
    inv[i]=(inv[i+1]*(i+1))%mod;
  }
  inv[0]=1;
  int to=0;
  for(int i=1;i<=n;i++){
    int sq=std::sqrt(a[i]);
    for(int j=2;j<=sq;j++){
      while(a[i]%(j*j)==0){
        a[i]/=(j*j);
      }
    }
    if(mp[a[i]]==0){
      mp[a[i]]=++to;
    }
    cnt[mp[a[i]]]++;
  }
  dp[0][0]=1;
  for(int i=1;i<=to;i++){
    for(int j=0;j<=n;j++){
      for(int k=0;k<=std::min(j,cnt[i]-1);k++){
          dp[i][j]+=((((dp[i-1][j-k]*C(cnt[i],k))%mod*fra[cnt[i]-1])%mod*inv[cnt[i]-k-1]))%mod;
          dp[i][j]%=mod;
      }
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    ans+=((pow(-1,i)*fra[n-i])%mod*dp[to][i])%mod;
    ans%=mod;
    ans+=mod;
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


