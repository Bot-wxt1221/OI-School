#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
int tt[100005];
int dp[5005][5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int a=read();
  int b=read();
  int cnt=0;
  int tt3=0;
  for(int i=1;i<=a+b;i++){
    int tt2=read();
    if(tt2==1){
      tt[++tt3]=++cnt;
    }else{
      tt3--;
    }
  }
  for(int i=0;i<=5000;i++){
    dp[0][i]=1;
  }
  for(int i=1;i<=a-b;i++){
    for(int j=1;j<=tt[i];j++){
      dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
    }
    for(int j=tt[i]+1;j<=a;j++){
      dp[i][j]=dp[i][tt[i]];
    }
  }
  printf("%lld",dp[a-b][tt[a-b]]);
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

