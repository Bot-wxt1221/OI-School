#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();
int pow(__int128 n,int k){
	__int128 ans=1;
	while(k){
		if(k&1){
			ans*=n;
			ans=std::min(ans,(__int128)1e18+1);
		}
		n=n*n;
		n=std::min(n,(__int128)1e18+1);
		k>>=1;
	}
	return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	#endif
	int n=read();
	int k=read();
	if(k==1){
		printf("%lld",n);
		return 0;
	}
	if(k==2){
		int ans=1;
		for(int i=2;i<=1e5;i++){
			while(n%(i*i)==0){
				n/=(i*i);
				ans*=i;
			}
			if(n%i==0){
				n/=i;
			}
		}
		int tt=std::sqrt(n);
		if(tt*tt==n){
			ans*=tt;
		}
		printf("%lld",ans);
	}else{
		int ans=1;
		for(int i=2;i<=1e6;i++){
			int tt=pow(i,k);
			if(tt>n){
				break;
			}
			if(n%tt==0){
				ans=i;
			}
		}
		printf("%lld",ans);
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
