#include <iostream>
#include <cstdio>
#define int long long 
inline int read();
int dp[100005];
int sum[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int l=read();
    int r=read();
    for(int i=1;i<=n;i++){
      sum[i]=read()+sum[i-1];
    }
    for(int i=1,j=0;i<=n;i++){
      dp[i]=dp[i-1];
      while(j<i&&sum[i]-sum[j+1]>=l){
        j++;
      }
      if(j!=i&&l<=sum[i]-sum[j]&&sum[i]-sum[j]<=r){
        dp[i]=dp[j]+1;
      }
    }
    printf("%lld\n",dp[n]);
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
