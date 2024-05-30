#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int a[25][25];
char temp[25][25];
int t[25][50],t2[25][50];
int dp[(1<<20)+5];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      a[i][j]=read();
    }
  }
  for(int i=1;i<=n;i++){
    for(int k=1;k<=m;k++){
      for(int j=1;j<=n;j++){
        if(i==j){
          continue;
        }
        if(temp[j][k]==temp[i][k]){
          t[i][k]|=(1<<(j-1));
          t2[i][k]+=a[j][k];
        }
      }
    }
  }
  memset(dp,0x3f,sizeof(dp));
  dp[0]=0;
  for(int i=1;i<=m;i++){
    for(int j=0;j<(1<<n);j++){
      for(int k=1;k<=n;k++){
        if(((1<<(k-1))&j)==0){
          dp[j|(1<<(k-1))]=std::min(dp[j|(1<<(k-1))],dp[j]+a[k][i]);
        }
        dp[j|t[k][i]|(1<<(k-1))]=std::min(dp[j|t[k][i]|(1<<(k-1))],dp[j]+t2[k][i]);
      }
    }
  }
  printf("%d",dp[(1<<n)-1]);
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

