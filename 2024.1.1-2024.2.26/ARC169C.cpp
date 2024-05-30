#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353 
inline int read();
int a[5005];
int dp[5005][5005];
int sum[5005];
int pos[5005];
int s[5005][5005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  sum[0]=1;
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    if(a[i]!=-1){
      pos[a[i]]=i;
    }
    int _max1=0,_max2=0;
    for(int j=1;j<=n;j++){
      if(pos[j]>_max1){
        _max2=_max1;
        _max1=pos[j];
      }else if(pos[j]>_max2){
        _max2=pos[j];
      }
    }
    for(int j=1;j<=n;j++){
      int lst=std::max(i-j,(a[_max1]==j)?_max2:_max1);
      dp[i][j]=(sum[i-1]-s[i-1][j])%mod;
      if(lst){
        dp[i][j]-=sum[lst-1];
        dp[i][j]+=mod;
        dp[i][j]%=mod;
        dp[i][j]+=s[lst-1][j];
        dp[i][j]+=mod;
        dp[i][j]%=mod;
      }
      s[i][j]=s[i-1][j]+dp[i][j];
      s[i][j]%=mod;
      sum[i]+=dp[i][j];
      sum[i]%=mod;
    }
    sum[i]+=sum[i-1];
    sum[i]%=mod;
  }
  printf("%lld",(((sum[n]-sum[n-1])%mod)+mod)%mod);
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


