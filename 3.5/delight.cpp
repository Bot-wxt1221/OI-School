#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int dp[1005][5005];
int s[1005];
int e[1005];
int popcount(int now){
  int ret=0;
  while(now){
    ret+=(now&1);
    now>>=1;
  }
  return ret;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("delight.in","r",stdin);
  freopen("delight.out","w",stdout);
  #endif
  int n=read(),k,S,E;
  k=read();
  S=read();
  E=read();
  for(int i=1;i<=n;i++){
    s[i]=read();
  }
  for(int i=1;i<=n;i++){
    e[i]=read();
  }
  if(k>10){
    int ans=0;
    for(int i=1;i<=n;i++){
      ans+=std::max(s[i],e[i]);
    }
    printf("%lld\n",ans);
    return 0;
  }
  for(int i=1;i<k;i++){
    for(int j=0;j<=((1<<(k))-1);j++){
      if(j&(1)){
        dp[i][j]=dp[i-1][j>>1]+e[i];
      }else{
        dp[i][j]=dp[i-1][j>>1]+s[i];
      }
    }
  }
  for(int i=k;i<=n;i++){
    for(int j=0;j<=((1<<(k))-1);j++){
      int pp=popcount(j);
      if(pp>=E&&k-pp>=S){
        dp[i][j]=std::max(dp[i-1][(j>>1)|(1<<(k-1))],dp[i-1][j>>1]);
        if(j&(1)){
          dp[i][j]+=e[i];
        }else{
          dp[i][j]+=s[i];
        }
      }else{
        dp[i][j]=-0x3f3f3f3f3f3f3f3f;
      }
    }
  }
  int ans=-0x3f3f3f3f3f3f3f3f;
  for(int i=0;i<((1<<k)-1);i++){
    ans=std::max(ans,dp[n][i]);
  }
  printf("%lld",ans);
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


