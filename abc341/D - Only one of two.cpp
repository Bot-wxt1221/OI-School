#include <iostream>
#include <cstdio>
#include <algorithm>
#define int __int128
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  int lc=n*m/std::__gcd(n,m);
  int l=0;
  int r=2e18;
  r*=1e18;
  int k=read();
  int res=0;
  while(l<=r){
    int mid=(l+r)/2;
    if(mid/n+mid/m-2*(mid/lc)>=k){
      res=mid;
      r=mid-1;
    }else{
      l=mid+1;
    }
  }
      printf("%lld",res);
      return 0;
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


