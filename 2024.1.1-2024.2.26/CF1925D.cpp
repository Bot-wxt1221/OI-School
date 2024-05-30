#include <clocale>
#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007ll
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int temp=pow(x,y/2);
    return (temp*temp)%mod;
  }
  return (pow(x,y-1)*x)%mod;
}
int fra[5000005];
int inv[5000005];
int C(int x,int y){
  return (((fra[x]*inv[y])%mod)*inv[x-y])%mod;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  fra[0]=inv[0]=1;
  for(int i=1;i<=5000000;i++){
    fra[i]=(fra[i-1]*i)%mod;
  }
  inv[5000000]=pow(fra[5000000],mod-2);
  for(int i=5000000-1;i>=1;i--){
    inv[i]=(inv[i+1]*(i+1))%mod;
  }
  while(T--){
    int n=read(),m,k;
    m=read();
    k=read();
    int sum=0;
    for(int i=1;i<=m;i++){
      int a=read(),b,f;
      b=read();
      f=read();
      sum+=f;
      sum%=mod;
    }
    int den=((n)*(n-1)/2)%mod;
    int invden=pow(den,mod-2);
    int base=((sum*k)%mod)*invden;
    base%=mod;
    int ans=0;
    for(int i=1;i<=k;i++){
      int sum=((i)*(i-1)/2)%mod;
      int a,b;
      a=(C(k,i)*pow(invden,i))%mod;
      b=((den-1)*(invden))%mod;
      ans+=(sum*((a*(pow(b,k-i)))%mod))%mod;
      ans%=mod;
    }
    printf("%lld\n",(base+(ans*m)%mod)%mod);
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


