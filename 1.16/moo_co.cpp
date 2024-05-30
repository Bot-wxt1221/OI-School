#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int a[100005];
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
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    a[i]/=2;
  }
  fra[0]=1;
  for(int i=1;i<=1000000;i++){
    fra[i]=fra[i-1]*i;
    fra[i]%=mod;
  }
  inv[1000000]=pow(fra[1000000],mod-2);
  for(int i=1000000-1;i>=1;i--){
    inv[i]=(inv[i+1]*(i+1))%mod;
  }
  inv[0]=1;

  int ans=1;
  for(int i=1;i<n;i++){
    if(a[i]>a[i+1]){
      ans*=C(a[i],a[i+1]);
    }else{
      ans*=C(a[i+1]-1,a[i]-1);
    }
    ans%=mod;
  }
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


