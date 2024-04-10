#include <iostream>
#include <cstdio>
#include <map>
#define int __int128
inline int read();
int dp[155];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  long long n;
  dp[0]=1;
  for(int i=1;i<=125;i++){
    for(int j=i;j<=125;j++){
      dp[j]+=dp[j-i];
    }
  }
  while(scanf("%lld",&n)!=EOF){
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

