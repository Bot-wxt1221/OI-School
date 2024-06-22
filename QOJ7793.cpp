#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
inline int read();
int w[500005];
int dp[500005][2];
int n;
int lowbit(int x){
  return x&(-x);
}
int cnt=0;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    for(int i=1;i<=n;i++){
      w[i]=read();
      dp[i][0]=0x3f3f3f3f3f3f3f;
    }
    dp[0][0]=0x3f3f3f3f3f3f3f;
    std::sort(w+1,w+n+1);
    std::reverse(w+1,w+n+1);
    for(int i=n-1;i>=1;i--){
      w[i]+=w[i+1];
    }
    int op=0;
    dp[1][op]=0;
    for(int i=2;i<=n;i*=2){
      dp[i][op]=dp[i/2][op]+w[1];
    }
    for(int i=1;i<=n;i++){
      op^=1;
      for(int j=0;j<=n;j++){
        dp[j][op]=0x3f3f3f3f3f3f3f;
        if(j%2==0){
          dp[j][op]=std::min(dp[j/2][op]+w[i+1],dp[j][op]);
        }
        dp[j][op]=std::min(dp[j][op],dp[j+1][op^1]+lowbit(j));
      }
    }
    printf("%lld\n",dp[0][op]-(n-1));
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
