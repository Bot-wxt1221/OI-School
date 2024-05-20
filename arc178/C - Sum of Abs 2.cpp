#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
inline int read();
int dp[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int l=read();
  memset(dp,0x3f,sizeof(dp));
  int inf=dp[0];
  dp[0]=0;
  for(int k=1;k*(l-k)<=2e5&&k*2<=l;k++){
    int w=k*(l-k);
    for(int i=w;i<=2e5;i++){
      dp[i]=std::min(dp[i],dp[i-w]+1);
    }
  }
  for(int i=1;i<=n;i++){
    int tt=read();
    if(dp[tt]==inf){
      printf("-1\n");
    }else{
      printf("%lld\n",dp[tt]);
    }
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

