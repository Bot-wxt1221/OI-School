#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int a[1000005];
int dp[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int r1=read();
  int r2=read();
  int r3=read();
  int d=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int ret=0;
  memset(dp,0x3f,sizeof(dp));
  dp[1]=0;
  for(int i=1;i<=n;i++){
    dp[i+1]=std::min(dp[i+1],dp[i]+a[i]*r1+r3+d);
    dp[i+2]=std::min(dp[i+2],dp[i]+std::min((a[i]+1)*r1,r2)+std::min((a[i+1]+1)*r1,r2)+4*d+2*r1);
    dp[i+1]=std::min(dp[i+1],dp[i]+std::min((a[i]+1)*r1,r2)+r1+d*3);
  }
  printf("%lld",std::min(dp[n+1]-d,dp[n-1]+std::min((a[n-1]+1)*r1,r2)+r1*(a[n]+1)+r3+2*d));
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
