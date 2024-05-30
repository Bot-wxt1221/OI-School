#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int n=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    int tt=std::sqrt((long long)(2*i+1));
    if(tt*tt<2*i+1){
      tt++;
    }
    tt*=tt;
    if(tt-i>n){
      cnt+=i;
    }
  }
  printf("%lld",(long long)cnt);
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

