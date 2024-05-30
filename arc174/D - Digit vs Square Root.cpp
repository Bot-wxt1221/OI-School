#include <iostream>
#include <cstdio>
#define int __int128
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int ans=1;
    int tt=1;
    int tt2=1;
    for(int i=1;i<=9;i++){
      tt*=10;
      tt2*=100;
      if(n>=(tt-2)*tt){
        ans++;
      }
      if(n>=(tt-1)*tt){
        ans+=(std::min(n,(tt2)+(tt-1))-((tt-1)*tt)+1);
      }
    }
    printf("%lld\n",ans);
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


