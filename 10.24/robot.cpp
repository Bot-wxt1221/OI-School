#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int p[65];
int dp[105][105];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	#endif
	int n=read();
	int tt=0;
	for(int i=1;i<=2*n;i++){
		p[i]=read();
		if(p[i]!=i){
			tt=1;
		}
	}
	if(tt==0){
		dp[0][0]=1;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(i){
					dp[i][j]+=dp[i-1][j];
				}
				if(j){
					dp[i][j]+=dp[i][j-1];
				}
			}
		}
		printf("%lld",dp[n][n]);
		return 0;
	}
	int ans=0;
	for(int i=0;i<(1<<(2*n));i++){
		int curx=0,cury=0;
		for(int j=1;j<=2*n;j++){
			if(((i&(1<<(j-1)))>0)!=((i&(1<<(p[j]-1)))>0)){
				goto end;
			}
			curx+=((i&(1<<(j-1)))>0);
			cury+=!((i&(1<<(j-1))));
			if(curx>cury){
				goto end;
			}
			if(curx>n||cury>n){
				goto end;
			}
		}
		ans++;
		end:{}
	}
	printf("%lld",ans);
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
