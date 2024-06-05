#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int mx[2005];
char map[2005];
int dp[2005][2005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",map+1);
    for(int j=1;j<=m;j++){
      if(map[j]=='#'){
        mx[j]=std::max(mx[j],n-i+1);
      }
    }
  }
  dp[0][0]=1;
  for(int i=1;i<=m;i++){
    int sum=dp[i-1][0];
    for(int j=0;j<=n;j++){
      sum+=dp[i-1][j+1];
      sum%=mod;
      if(j>=mx[i]){
        dp[i][j]=sum;
      }
    }
  }
  int sum=0;
  for(int i=0;i<=n;i++){
    sum+=dp[m][i];
    sum%=mod;
  }
  printf("%d",sum);
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

