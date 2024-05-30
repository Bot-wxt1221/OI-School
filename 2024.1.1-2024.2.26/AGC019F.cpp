#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
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
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  fra[0]=1;
  for(int i=1;i<=n+m;i++){
    fra[i]=fra[i-1]*i;
    fra[i]%=mod;
  }
  inv[n+m]=pow(fra[n+m],mod-2);
  for(int i=n+m-1;i>=1;i--){
    inv[i]=(inv[i+1]*(i+1))%mod;
  }
  inv[0]=1;
  int ans=0;
  for(int i=1;i<=std::min(n,m);i++){
    ans+=C(2*i,i)*C(n+m-2*i,n-i);
    ans%=mod;
  }
  ans*=pow(C(n+m,m),mod-2);
  ans%=mod;
  ans*=inv[2];
  ans%=mod;
  ans+=std::max(n,m);
  ans%=mod;
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


