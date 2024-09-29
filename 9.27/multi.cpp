#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int n,m;
int a[200005];
bool check(int mid){
	if(mid==n){
		return 1;
	}
	for(int i=mid+1;i<=n;i++){
		if(i!=n-(i-mid)+1){
			if(a[i]+a[n-(i-mid)+1]>m){
				return 0;
			}
		}
	}
	return 1;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout);
	#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		int cnt=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			cnt+=a[i];
		}
		std::sort(a+1,a+n+1);
		std::reverse(a+1,a+n+1);
		int l=0,r=n;
		while(r-l>3){
			int mid=(l+r)/2;
			if(check(mid)){
				r=mid;
			}else{
				l=mid;
			}
		}
		for(int i=l;i<=r;i++){
			if(check(i)==0){
				continue;
			}
			printf("%lld\n",i+cnt+1);
			break;
		}
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
