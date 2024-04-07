#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int long long
inline int read();
int dp[5005][5005];
int sum[5005];
int pre[5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int s=read();
  int b=read();
  b-=s;
  for(int i=1;i<=s;i++){
    for(int j=0;j<=b;j++){
      pre[j]+=sum[j];
      pre[j]%=mod;
      if(j==0){
        dp[i][j]=1;
      }else{
        dp[i][j]=pre[j];
      }
      sum[i+j]+=dp[i][j];
      sum[i+j]%=mod;
    }
  }
  printf("%lld\n",dp[s][b]);
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


