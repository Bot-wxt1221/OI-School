#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
std::bitset<100005>dp[20005],sum;
int a[100005];
int cnt[1000005];
int C(int n,int m){
	int tt=cnt[n]-cnt[m]-cnt[n-m];
	if(tt==0){
		return 1;
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	#endif
	cnt[2]=1;
	for(int i=3;i<=1e6;i++){
		if(i%2==0){
			cnt[i]=cnt[i/2]+1;
		}
	}
	for(int i=2;i<=1e6;i++){
		cnt[i]+=cnt[i-1];
	}
	int T=read();
	while(T--){
		int n=read();
		int m=read();
		sum=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			dp[a[i]]=0;
		}
		for(int i=1;i<=n;i++){
			sum^=dp[a[i]];
			dp[a[i]]=(sum<<1);
			sum^=dp[a[i]];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(sum[i]){
				ans+=C(n-1,i-1);
				ans&=1;
			}
		}
		printf("%d",ans);
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
