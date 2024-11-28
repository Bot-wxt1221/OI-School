#include <iostream>
#include <cstdio>
#define mod 1000000007
inline int read();
int fac(int n){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans*=i;
    ans%=mod;
  }
  return ans;
}
int dp[2][105][24005];//i->to j->used k->cursum
int getans(int n,int K){
  dp[0][0][12001]=1;
  int op=0;
  int kk=(n)*(n+1);
  for(int i=1;i<=n;i++){
    op^=1;
    for(int j=0;j<=i;j++){
      for(int k=-kk;k<=kk;k++){
        dp[op][j][k+12001]=0;
        if(k+12001<=24003){
          dp[op][j][k+12001]+=1ll*dp[op^1][j][k+12001]*(2*j+1)%mod;
          dp[op][j][k+12001]%=mod;
        }
        if(k-2*i+12001>=0){
          dp[op][j][k+12001]+=1ll*dp[op^1][j+1][k-2*i+12001]*(j+1)%mod*(j+1)%mod;
          dp[op][j][k+12001]%=mod;
        }
        if(j&&k+12001+2*i<=24003){
          dp[op][j][k+12001]+=dp[op^1][j-1][k+12001+2*i];
          dp[op][j][k+12001]%=mod;
        }
      }
    }
  }
  return dp[op][0][K+12001];
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("cargo.in","r",stdin);
	freopen("cargo.out","w",stdout);
	#endif
  int n=read();
  int K=read();
  printf("%lld",(1ll*getans(n,K))%mod);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
