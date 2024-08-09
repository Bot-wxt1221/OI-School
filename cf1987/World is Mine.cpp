#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int long long
inline int read();
int cnt[5005];
int dp[5005][5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
      cnt[read()]++;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
      dp[0][i]=-0x3f3f3f3f3f3f3f3f;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
      for(int j=0;j<=n;j++){
        dp[i][j]=-0x3f3f3f3f3f3f3f3f;
        if(j>0&&cnt[i]!=0){
          dp[i][j]=std::max(dp[i][j],dp[i-1][j-1]);
        }
        if(j+cnt[i]<=n){
          dp[i][j]=std::max(dp[i][j],dp[i-1][j+cnt[i]]+1);
        }
        if(i==n){
          ans=std::max(ans,dp[n][j]);
        }
      }
    }
    printf("%lld\n",n-ans);
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
