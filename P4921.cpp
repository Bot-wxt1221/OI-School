#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int g[1005];
int fac[1005];
int inv[1005];
int pow(long long x,int y){
  long long ans=1;
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
  return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int A(int n,int m){
  return fac[n]*inv[n-m]%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  g[0]=1;
  g[1]=0;
  fac[0]=fac[1]=1;
  for(int i=2;i<=1000;i++){
    fac[i]=1ll*fac[i-1]*i%mod;
    g[i]=(4ll*i)*(i-1)%mod*((g[i-1]+(2ll*(i-1)*g[i-2]%mod)))%mod%mod;
  }
  inv[1000]=pow(fac[1000],mod-2);
  for(int i=999;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  while(T--){
    int n=read();
    for(int i=0;i<=n;i++){
      int ans=pow(2,i)*A(n,i)%mod*C(n,i)%mod*g[n-i]%mod;
      printf("%lld\n",ans);
    }
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
