#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int dp[4005][4005];
int dp2[4005][4005];
int a[12005];
std::vector<int>tt;
int mx[4005];
int mx2[4005];
int totmx;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	#endif
	int n=read();
	for(int i=1;i<=3*n;i++){
		a[i]=read();
	}
	int plus=0;
	dp[a[3*n]][a[3*n]]=1;
	dp2[a[3*n]][a[3*n]]=1;
	for(int i=n-1;i>=1;i--){
		if(a[i*3]==a[i*3+1]&&a[i*3+1]==a[i*3+2]){
			plus++;
			continue;
		}
		for(int fir=3*i;fir<=std::min(3*i+2,3*n);fir++){
			int ta,tb;
			int precnt=1;
			for(int tt=3*i;tt<=std::min(3*i+2,3*n);tt++){
				if(a[tt]==a[fir]){
					precnt++;
				}
			}
			for(int sec=1;sec<=n;sec++){
				if(fir==3*i){
					ta=a[fir+1];
					tb=a[fir+2];
				}else if(fir==3*i+1){
					ta=a[fir-1];
					tb=a[fir+1];
				}else{
					ta=a[fir-1];
					tb=a[fir-2];
				}
				int cnt=precnt;
				if(sec==a[fir]){
					cnt++;
				}
				if(ta==a[fir]){
					ta=sec;
				}else if(tb==a[fir]){
					tb=sec;
				}
				mx2[sec]=std::max(mx2[sec],std::max(dp[a[fir]][sec],std::max(totmx,std::max(mx[a[fir]],mx[sec]))));
				if(cnt<=2){
					dp2[a[fir]][sec]=std::max(dp2[a[fir]][sec],std::max(dp[a[fir]][a[fir]],std::max(totmx,mx[a[fir]])));
					dp2[sec][a[fir]]=dp2[a[fir]][sec];
					continue;
				}
				dp2[a[fir]][sec]=std::max(dp2[a[fir]][sec],std::max(dp[ta][tb],std::max(totmx,std::max(mx[ta],mx[tb])))+1);
				dp2[a[fir]][sec]=std::max(dp2[a[fir]][sec],std::max(dp[a[fir]][a[fir]],std::max(totmx,mx[a[fir]])));
				dp2[sec][a[fir]]=dp2[a[fir]][sec];
			}
		}
		for(int sec=1;sec<=n;sec++){
			mx[sec]=std::max(mx[sec],mx2[sec]);
		}
		totmx=std::max(totmx,dp[a[i*3]][a[i*3+1]]);
		totmx=std::max(totmx,dp[a[i*3]][a[i*3+2]]);
		totmx=std::max(totmx,dp[a[i*3+1]][a[i*3+2]]);
		for(int fir=3*i;fir<=std::min(3*i+2,3*n);fir++){
			for(int sec=1;sec<=n;sec++){
				dp[a[fir]][sec]=std::max(dp[a[fir]][sec],std::max(dp2[a[fir]][sec],std::max(totmx,std::max(mx[a[fir]],mx[sec]))));
				dp[sec][a[fir]]=std::max(dp[a[fir]][sec],std::max(dp2[a[fir]][sec],std::max(totmx,std::max(mx[a[fir]],mx[sec]))));
			}
		}
	}
	printf("%d",std::max(dp[a[1]][a[2]],std::max(mx[a[1]],std::max(mx[a[2]],totmx)))+plus);
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
