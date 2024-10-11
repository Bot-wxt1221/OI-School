#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int a[1000005];
int dp[2][1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int cur=0;
  int cut=0;
  int ncut=0;
  dp[cur][0]=1;
  for(int i=1;i<=n;i++){
    cur^=1;
    for(int j=0;j<=m;j++){
      dp[cur][j]=0;
    }
    dp[cur][0]=dp[cur^1][0]+dp[cur^1][m];
    dp[cur][0]%=mod;
    if(a[i-1]==m){
      dp[cur][0]-=cut;
      dp[cur][0]%=mod;
    }
    int sum=0;
    for(int j=0;j<=m;j++){
      sum+=dp[cur^1][j];
      sum%=mod;
    }
    for(int j=std::max(1,m-(n-i));j<=m;j++){
      if(j==1){
        dp[cur][j]=sum-cut;
      }else{
        dp[cur][j]=dp[cur^1][j-1]+dp[cur^1][m];
      }
      dp[cur][j]%=mod;
    }
    if(std::max(1,(m-(n-i)))>a[i]){
      ncut=0;
    }else if(a[i]==1){
      ncut=dp[cur][0];
    }else if(a[i-1]==a[i]-1){
      ncut=cut+dp[cur^1][m];
    }else{
      ncut=dp[cur^1][m];
    }
    ncut%=mod;
    cut=ncut;
  }
  int ans=0;
  for(int i=0;i<=m;i++){
    ans+=dp[cur][i];
    ans%=mod;
  }
  ans-=cut;
  ans+=mod;
  ans%=mod;
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
