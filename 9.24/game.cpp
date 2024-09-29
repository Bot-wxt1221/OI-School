#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int inv[2000006];
int fac[2000005];

int pow(int x,int y){
	long long ans=1;
	while(y){
		if(y&1){
			ans=(1ll*ans*x)%mod;
		}
		y>>=1;
		x=(1ll*x*x)%mod;
	}
	return ans;
}
int C(int n,int m){
	return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int S(int n,int m){
	return C(n+m-1,n);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	#endif
	int n=read();
	int k=read();
	int ans=0;
	fac[0]=1;
	inv[0]=1;
	for(int i=1;i<=2000000;i++){
		fac[i]=1ll*fac[i-1]*i%mod;
	}
	inv[2000000]=pow(fac[2000000],mod-2);
	for(int i=2000000-1;i>=0;i--){
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	}
  for(int p=0;p<=k;p++){
    if(2*p<n){
      
    }
  }
	printf("%d",ans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?f=-1:0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
