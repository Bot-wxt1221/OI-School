#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
int fac[10000005];
int inv[10000005];
int C(int m,int n){
  if(m>n||n<0||m<0){
    return 0;
  }
  return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int pow(int a,int b){
  int ans=1;
  int cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=mod;
    }
    cur*=cur;
    cur%=mod;
    b/=2;
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  fac[0]=1;
  for(int i=1;i<=10000000;i++){
    fac[i]=fac[i-1]*i%mod;
  }
  inv[10000000]=pow(fac[10000000],mod-2);
  inv[0]=1;
  for(int i=9999999;i>=1;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  int T=read();
  while(T--){
    int l=read(),n;
    n=read();
    int ans=0;
    for(int i=0;i<=l;i+=2){
      ans+=2*C(n,l-i-n)%mod*C(n-1,i/2+n-1);
      ans%=mod;
    }
    printf("%lld\n",((2*C(2*n,l))%mod-ans+mod)%mod);
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

