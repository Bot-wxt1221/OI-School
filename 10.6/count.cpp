#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int fac[500005];
int fac2[500005];
int fac3[500005];
int inv3[100005];
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
	return ((1ll*fac3[n]*inv3[m]%mod)*(inv3[n-m]))%mod;
}
int ans[10005];
int C2(int n,int m){
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=(1ll*inv3[i]*fac3[i-1]%mod);
		ans%=mod;
		ans*=(n-i+1);
		ans%=mod;
	}
	return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	#endif
	int n=read();
	int x=read();
	int y=read();
	int q=read();
	if(x==y){
		fac[0]=fac2[0]=1;
		fac3[0]=1;
		for(int i=1;i<=100000;i++){
			fac[i]=1ll*fac[i-1]*x%mod;
			fac2[i]=1ll*fac2[i-1]*y%mod;
			fac3[i]=1ll*fac3[i-1]*i%mod;
		}
		inv3[100000]=pow(fac3[100000],mod-2);
		for(int i=100000-1;i>=0;i--){
			inv3[i]=(1ll*inv3[i+1])*(i+1)%mod;
		}
		for(int i=1;i<=q;i++){
			int a=read();
			int b=read();
			if(::ans[a+b]){
				printf("%d\n",::ans[a+b]);
				continue;
			}
			int ans=C2(n+1,a+b+1);
			ans=(1ll*ans*pow(x,n-a-b))%mod;
			::ans[a+b]=ans;
			printf("%d\n",ans);
		}
		return 0;
	}
	fac[0]=fac2[0]=1;
	fac3[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*x%mod;
		fac2[i]=1ll*fac2[i-1]*y%mod;
		fac3[i]=1ll*fac3[i-1]*i%mod;
	}
	inv3[n]=pow(fac3[n],mod-2);
	for(int i=n-1;i>=0;i--){
		inv3[i]=(1ll*inv3[i+1])*(i+1)%mod;
	}
	for(int i=1;i<=q;i++){
		int a=read();
		int b=read();
		int ans=0;
		int ttx=1;
		int tty=pow(y,n-a-b);
		int invy=pow(y,mod-2);
		for(int j=a;j<=n-b;j++){
			ans+=((((1ll*C(j,a)*ttx%mod)*(C(n-j,b)))%mod)*tty)%mod;
			ttx=(1ll*ttx*x)%mod;
			tty=(1ll*tty*invy)%mod;
			tty%=mod;
			ans%=mod;
		}
		printf("%d\n",ans);
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
