#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 998244353
#define int __int128
inline int read();
int a[5005];
int po[5005];
int inv[5005];
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
int C(int x,int y){
  if(x<y){
    return 0;
  }
  return (((po[x]*inv[y])%mod)*inv[x-y])%mod;
}
int f[5005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),k;
  k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  std::sort(a+1,a+n+1);
  inv[0]=po[0]=1;
  for(int i=1;i<=5000;i++){
    po[i]=po[i-1]*i;
    po[i]%=mod;
  }
  inv[5000]=pow(po[5000],mod-2);
  for(int i=4999;i>=1;i--){
    inv[i]=inv[i+1]*(i+1);
    inv[i]%=mod;
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    f[i]=(i-1)*po[i];
    f[i]%=mod;
    f[i]*=po[n-i];
    f[i]%=mod;
    int sum=0;
    for(int j=1;j<=k;j++){
      sum+=C(n-j,i-1);
      sum%=mod;
    }
    sum%=mod;
    f[i]*=sum;
    f[i]%=mod;
    ans+=(((f[i]-f[i-1])%mod+mod)%mod)*a[i];
    ans%=mod;
  }
  printf("%lld",(long long)(ans));
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

