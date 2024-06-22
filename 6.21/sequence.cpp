#include <iostream>
#include <cstdio>
#include <vector>
#define mod 998244353
inline int read();
std::vector<int> dp[45][45][255];
int ans[255];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
  #endif
  int n=read();
  int k=read();
  dp[1][0][0].resize(5);
  dp[1][0][0][0]=2;
  for(int ans1=0;ans1<=k;ans1++){
    dp[1][0][ans1].resize(k-ans1+5);
  }
  for(int i=2;i<=n+1;i++){
    for(int j=0;j<i-1;j++){
      for(int ans1=0;ans1<=k;ans1++){
        dp[i][j][ans1].resize(k-ans1+5);
        for(int ans2=0;ans1+ans2<=k;ans2++){
          if(j==i-2&&ans1-ans2-1>=0){
            for(int pre=0;pre<=std::max(0,i-3);pre++){
              dp[i][j][ans1][ans2]+=dp[i-1][pre][ans2][ans1-ans2-1];
              dp[i][j][ans1][ans2]%=mod;
            }
          }else if(ans1-ans2-1>=0){
            dp[i][j][ans1][ans2]+=dp[i-1][j][ans1-ans2-1][ans2];
            dp[i][j][ans1][ans2]%=mod;
          }
          if(i==n+1&&ans1+ans2>=0){
            ans[ans1+ans2]+=dp[i][j][ans1][ans2];
            ans[ans1+ans2]%=mod;
          }
        }
      }
    }
  }
  for(int i=1;i<=k;i++){
    printf("%d ",ans[i]);
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
