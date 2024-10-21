#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
int fac[100005];
int inv[100005];
int C(int n,int m){
  return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int pow(long long a,long long n){
  n%=(mod-1);
  if(n<0){
    return 0;
  }
  long long res=1;
	while(n)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  fac[0]=1;
  for(int i=1;i<=100000;i++){
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  inv[100000]=pow(fac[100000],mod-2);
  for(int i=99999;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  while(T--){
    int n=read();
    int V=read();
    int ans=0;
    for(int i=1;i<V;i++){
      int curans=1;
      int curans2=pow(V-i,n);
      int tt=pow(V-i,mod-2);
      for(int c00=0;c00<=n;c00++){
        int c0=c00;
        int c1=n-c00;
        if(n%2==1){
          if(c0>=n/2+1){
            c0--;
          }else{
            c1--;
          }
        }
        ans+=curans*curans2%mod*C(n,c00)%mod*std::min(c0,c1)%mod;
        curans*=i;
        curans%=mod;
        curans2*=tt;
        curans2%=mod;
        ans%=mod;
      }
    }
    ans*=2;
    ans%=mod;
    printf("%lld\n",ans);
  }
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
