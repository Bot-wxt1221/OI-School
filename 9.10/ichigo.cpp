#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int fac[1000005];
int inv[1000005];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2){
    return (pow(x,y-1)*x)%mod;
  }
  int tt=pow(x,y/2);
  return (tt*tt)%mod;
}
int C(int n,int m){
  return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;  
}
int calc(int n,int m){
  int tt=1;
  int ans=0;
  for(int i=0;i<=m;i++){
    ans+=tt*1ll*C(m,i)*pow(m-i,n)%mod;
    ans%=mod;
    tt*=-1;
  }
  ans+=mod;
  ans%=mod;
  return 1ll*ans*inv[m]%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int k=read();
  int sum=0;
  fac[0]=1;
  for(int i=1;i<=n;i++){
    sum+=read();
    sum%=mod;
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  if(n==k){
    printf("%lld",sum);
    return 0;
  }
  inv[n]=pow(fac[n],mod-2);
  for(int i=n-1;i>=0;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  int ret=calc(n,k)+(n-1)*calc(n-1,k)%mod;
  ret%=mod;
  ret+=mod;
  ret%=mod;
  sum=1ll*ret*sum%mod;
  printf("%lld",sum);
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
