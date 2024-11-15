#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
inline int read();
int dp[2][30005];
int seq[5005];
int fac[500005];
int inv[500005];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int temp=pow(x,y/2);
    return (1ll*temp*temp)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
int C(int n,int m){
  if(n<0||m<0||n<m){
    return 0;
  }
  return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  fac[0]=1;
  for(int i=1;i<=500000;i++){
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  inv[500000]=pow(fac[500000],mod-2);
  for(int i=500000-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  int tt=0;
  for(int i=1;i<=n;i++){
    seq[i]=read();
    tt+=seq[i];
  }
  if(tt%2==1){
    printf("%d\n",0);
    return 0;
  }
  tt/=2;
  dp[0][0]=1;
  int op=0;
  int pre=0;
  for(int i=0;i<n;i++){
    op^=1;
    memset(dp[op],0,sizeof(dp[op]));
    for(int j=0;j<=pre/2;j++){
      if(dp[op^1][j]){
        for(int k=0;k<=seq[i+1];k++){
          int m2=j;
          int m1=pre-2*m2;
          int m0=tt-m1-m2;
          dp[op][j+k]+=1ll*dp[op^1][j]*C(m1,k)%mod*C(m0,seq[i+1]-k)%mod;
          dp[op][j+k]%=mod;
        }
      }else{
      }
    }
    pre+=seq[i+1];
  }
  printf("%d\n",dp[op][tt]);
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
