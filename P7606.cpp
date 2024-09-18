#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
int a1[105][15];
std::bitset<105> dp[35][35][105][105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int p=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=12;j++){
      a1[i][j]=read();
    }
  }
  dp[15][15][0][0][0]=1;
  for(int i=1;i<=n;i++){
    for(int i=0;i<=30;i++){
      for(int j=0;j<=30;j++){
        
      }
    }
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
