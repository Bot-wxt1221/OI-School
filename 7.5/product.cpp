#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("product.in","r",stdin);
  freopen("product.out","w",stdout);
  #endif
  int n=read();
  int out=1;
  int tt=1;
  for(int i=n;i>=1;i--){
    tt*=i;
    tt%=mod;
    out*=tt;
    out%=mod;
  }
  printf("%lld",out);
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
