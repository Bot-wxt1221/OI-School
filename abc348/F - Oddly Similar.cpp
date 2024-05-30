#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
std::bitset<2005>bit[2005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      int tt=read();
      for(int i = 1;i <= n;i++)
      {
        for(int j = 1;j <= m;j++)
        {
        
        }
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

