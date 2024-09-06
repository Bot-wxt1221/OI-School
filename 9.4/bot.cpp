#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int p[500005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("bot.in","r",stdin);
  freopen("bot.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      p[i]=read();
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
