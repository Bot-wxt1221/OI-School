#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int seq[20000005];
int dp[20000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("dwn.in","r",stdin);
	freopen("dwn.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  if(n%2==1&&m%2==1){
    printf("0");
    return 0;
  }
  if(n>m){
    std::swap(n,m);
  }
  if(n==1){
    printf("1");
    return 0;
  }
  if(n==2){
    for(int i=0;i<=n;i++){
      seq[i]=(n+1)/2;
    }
    seq[n]=2;
    for(int i=n+1;i<2*n;i++){
      seq[i]=3;
    }
    for(int i=2*n;i<=n+m;i++){
      seq[i]=seq[i-n+1]+seq[i-2*n+1];
      seq[i]%=mod;
    }
    if(n%2){
      printf("%lld",seq[m]);
    }else{
      printf("%lld",seq[m]);
    }
    return 0;
  }
  if(n%2==1){
    dp[0]=dp[n-1]=1;
    for(int i=n+1;i<=m;i++){
      dp[i]+=dp[i-n+1];
      dp[i]%=mod;
      dp[i]+=dp[i-n-1];
      dp[i]%=mod;
    }
    dp[m]*=2;
    dp[m]%=mod;
    printf("%lld",dp[m]);
  }else{
    dp[0]=1;
    dp[n-1]=dp[1]=1;
    dp[n]=1;
    for(int i=n+1;i<=m+1;i++){
      dp[i]+=dp[i-n-1];
      dp[i]%=mod;
      dp[i]+=dp[i-n+1];
      dp[i]%=mod;
    }
    printf("%lld",((dp[m]+dp[m+1]))%mod);
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


