#include <iostream>
#include <cstdio>
#include <vector>
#define mod 998244353
inline int read();
int a[2005];
std::vector<int> dp[2005][2005],sum[2005][2005];
int mx[2005];
int cnt[2005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    cnt[a[i]]++;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      mx[i]+=std::min(i,cnt[j]);
    }
    mx[i]=std::min(mx[i],n);
  }
  int sum2=0;
  for(int j=0;j<=mx[1];j++){
    dp[1][j].resize(n+1);
    sum[1][j].resize(n+1);
    for(int lst=0;lst<=n;lst++){
      if(lst==j){
        dp[1][j][lst]=(1);
        sum[1][j][lst]=(((lst!=0?sum[1][j][lst-1]:0)+1)%mod);
      }else{
        dp[1][j][lst]=(0);
        sum[1][j][lst]=(((lst!=0?sum[1][j][lst-1]:0))%mod);
      }
      if(j==n&&lst!=0){
        sum2+=dp[1][j][lst];
        sum2%=mod;
      }
    }
  }
  for(int i=2;i<=n;i++){
    for(int j=0;j<=mx[i];j++){
      dp[i][j].resize(n/i+2);
      sum[i][j].resize(n/i+2);
      for(int lst=0;lst<=n/i+1;lst++){
        if(j-lst<=0){
          dp[i][j][lst]=(0);
          sum[i][j][lst]=(((lst!=0?sum[i][j][lst-1]:0)+dp[i][j][lst])%mod);
          continue;
        }
        if(j-lst>mx[i-1]){
          dp[i][j][lst]=(0);
          sum[i][j][lst]=(((lst!=0?sum[i][j][lst-1]:0)+dp[i][j][lst])%mod);
          continue;
        }
        if(lst*i>n){
          dp[i][j][lst]=(0);
          sum[i][j][lst]=(((lst!=0?sum[i][j][lst-1]:0)+dp[i][j][lst])%mod);
        }
        dp[i][j][lst]=((*(--sum[i-1][j-lst].end())-(lst!=0?sum[i-1][j-lst][lst-1]:0))%mod);
        sum[i][j][lst]=(((lst!=0?sum[i][j][lst-1]:0)+dp[i][j][lst])%mod);
        if(j==n&&lst!=0){
          sum2+=dp[i][j][lst];
          sum2%=mod;
        }
      }
    }
  }
  printf("%d",(sum2+mod)%mod);
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

