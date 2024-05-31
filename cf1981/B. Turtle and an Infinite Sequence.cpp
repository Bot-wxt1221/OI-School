#include <iostream>
#include <cstdio>
#define int long long
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
    int m=read();
    int mx=n+m;
    n-=m;
    n=std::max(n,0ll);
    int ans=0;
    int sta=0;
    int cur=0;
    for(int i=63;i>=1;i--){
      if(n&(1ll<<(i-1))){
        cur|=(1ll<<(i-1));
        ans|=(1ll<<(i-1));
        continue;
      }
      if(((cur|(1ll<<(i-1))))<=mx){
        ans|=(1ll<<(i-1));
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

