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
  int n=read();
  int c=read();
  int min=0;
  int max=0;
  int sum=0;
  int mn=0x3f3f3f3f;
  int mx=0;
  for(int i=1;i<=n;i++){
    sum+=read();
    min=std::min(min,sum);
    max=std::max(max,sum);
    mx=std::max(mx,sum-min);
    mn=std::min(mn,sum-max);
  }
  printf("%lld",std::max(sum+mx*(c-1),sum+mn*(c-1)));
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


