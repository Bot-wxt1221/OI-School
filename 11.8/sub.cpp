#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int dp[505][505];
int ans[505];
int fac[505];
int inv[505];
char temp[505];
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
  return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read()+1;
  temp[1]='2';
  scanf("%s",temp+2);
  fac[0]=1;
  for(int i=1;i<=n;i++){
    dp[i][i]=1;
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  inv[n]=pow(fac[n],mod-2);
  for(int i=n-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  for(int siz=2;siz<=n;siz++){
    for(int i=1;siz+i-1<=n;i++){
      int j=siz+i-1;
      for(int k=i+1;k<=j;k++){
        if(temp[k]!=temp[i]){
          dp[i][j]+=(1ll*dp[i][k-1]*dp[k][j]%mod*C(siz-2,k-i-1))%mod;
          dp[i][j]%=mod;
        }
      }
    }
  }
  printf("%d",dp[1][n]);
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
