#include <iostream>
#include <cstdio>
inline int read();
int dp[5005][5005];
int a[5005];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int siz=2;siz<=n;siz++){
    for(int i=1;i+siz-1<=n;i++){
      if(a[i]==a[i+siz-1]){
        dp[i][i+siz-1]=dp[i+1][i+siz-2];
      }else{
        dp[i][i+siz-1]=std::min(std::min(dp[i+1][i+siz-1],dp[i+1][i+siz-2]),dp[i][i+siz-2])+1;
      }
    }
  }
  printf("%d",dp[1][n]);
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


