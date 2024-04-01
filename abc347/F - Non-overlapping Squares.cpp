#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int map[1505][1505],n,m,mm;
int sum1[1505][1505];
int dp[1505][1505][3];
int k;
int sum(int x1,int y1,int x2,int y2){
  return sum1[x2][y2]-sum1[x2][y1-1]-sum1[x1-1][y2]+sum1[x1-1][y1-1];
}
int solve(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+map[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      dp[i][j][0]=std::max(dp[i-1][j][0],dp[i][j-1][0]);
      if(i>=m&&j>=m){
        dp[i][j][0]=std::max(dp[i][j][0],sum(i-m+1,j-m+1,i,j));
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      dp[i][j][1]=std::max(dp[i-1][j][1],dp[i][j-1][1]);
      if(i>=m&&j>=m){
        dp[i][j][1]=std::max(dp[i][j][1],std::max(dp[i][j-m][0],dp[i-m][j][0])+sum(i-m+1,j-m+1,i,j));
      }
    }
  }
  for(int i=n;i>=1;i--){
    for(int j=mm;j>=1;j--){
      dp[i][j][2]=std::max(dp[i+1][j][2],dp[i][j+1][2]);
      if(i+m-1<=n&&j+m-1<=mm){
        dp[i][j][2]=std::max(dp[i][j][2],sum(i,j,i+m-1,j+m-1));
      }
    }
  }
  int res=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      res=std::max(res,dp[i][j][1]+std::max(dp[i+1][1][2],dp[1][j+1][2]));
    }
  }
  return res;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  mm=read();
  m=read();
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      map[i][j]=read();
    }
  }
  int ans=solve();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      int tj=mm-j+1;
      if(j<tj){
        std::swap(map[i][j],map[i][tj]);
      }
    }
  }
  ans=std::max(ans,solve());
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      int ti=n-i+1;
      if(i<ti){
        std::swap(map[i][j],map[ti][j]);
      }
    }
  }
  ans=std::max(ans,solve());
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mm;j++){
      int tj=mm-j+1;
      if(j<tj){
        std::swap(map[i][j],map[i][tj]);
      }
    }
  }
  ans=std::max(ans,solve());
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

