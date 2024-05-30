#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("relax.in","r",stdin);
	freopen("relax.out","w",stdout);
	#endif
  int h=read(),m;
  m=read();
  int xiang=std::min(m,h);
  int lst=(m-xiang+1);
  int a=((m+lst)*xiang);
  int b=2*h*m;
  int gg=std::__gcd(a,b);
  a/=gg;
  b/=gg;
  printf("%lld/%lld",a,b);
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


