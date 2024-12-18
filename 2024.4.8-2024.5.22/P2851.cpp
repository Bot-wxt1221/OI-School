#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int v[105];
int c[105];
int dp[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int T=read();
  for(int i=1;i<=n;i++){
    v[i]=read();
  }
  for(int i=1;i<=n;i++){
    c[i]=read();
  }
  memset(dp,0x3f,sizeof(dp));
  dp[0]=0;
  for(int i=1;i<=n;i++){
    int cnt=0;
    for(int j=1;j+cnt<=c[i];j*=2){
      cnt+=j;
      for(int k=1000000;k>=v[i]*j;k--){
        dp[k]=std::min(dp[k],dp[k-v[i]*j]+j);
      }
    }
    int j=c[i]-cnt;
    for(int k=1000000;k>=v[i]*j;k--){
      dp[k]=std::min(dp[k],dp[k-v[i]*j]+j);
    }
  }
  for(int i=1;i<=n;i++){
    for(int k=1000000-v[i];k>=0;k--){
      dp[k]=std::min(dp[k],dp[k+v[i]]+1);
    }
  }
  if(dp[T]==0x3f3f3f3f){
    printf("-1");
  }else{
    printf("%d",dp[T]);
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

