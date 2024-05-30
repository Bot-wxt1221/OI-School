#include <iostream>
#include <cstdio>
inline int read();
int c[50005];
int f[50005];
int h[50005];
int dp[5005][5005];
int cnt[300005];
int cnt2[300005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  #endif
  int n=read(),k;
  k=read();
  for(int i=1;i<=n*k;i++){
    c[i]=read();
    cnt2[c[i]]++;
  }
  for(int i=1;i<=n;i++){
    f[i]=read();
    cnt[f[i]]++;
  }
  for(int i=1;i<=k;i++){
    h[i]=read();
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n*k;j++){
      for(int k2=0;k2<=std::min(j,k);k2++){
        dp[i][j]=std::max(dp[i][j],dp[i-1][j-k2]+h[k2]);
      }
    }
  }
  int ans=0;
  for(int i=1;i<=300000;i++){
    ans+=dp[cnt[i]][cnt2[i]];
  }
  printf("%d",ans);
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

