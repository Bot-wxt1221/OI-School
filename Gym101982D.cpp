#include <iostream>
#include <cstdio>
#define mod 1000000009
#define int long long
inline int read();
int dp[130][1005];
int cnt[130][1005];
int pre[1005];
int pre2[1005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int k=read(),b;
  b=read();
  dp[0][0]=0;
  cnt[0][0]=1;
  for(int i=0;i<k;i++){
    pre[i]=pre2[i]=k;
  }
  for(int i=0;i<k;i++){
    pre2[(i*2)%k]=i;
    pre[(i*2+1)%k]=i;
  }
  for(int i=1;i<=b;i++){
    for(int j=0;j<k;j++){
      dp[i][(j*2)%k]+=(dp[i-1][j]);
      dp[i][(j*2)%k]%=mod;
      cnt[i][(j*2)%k]+=cnt[i-1][j];
      cnt[i][(j*2)%k]%=mod;
      dp[i][(j*2+1)%k]+=dp[i-1][j]+cnt[i-1][j];
      dp[i][(j*2+1)%k]%=mod;
      cnt[i][(j*2+1)%k]+=cnt[i-1][j];
      cnt[i][(j*2+1)%k]%=mod;
    }
  }
  printf("%lld",dp[b][0]);
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


