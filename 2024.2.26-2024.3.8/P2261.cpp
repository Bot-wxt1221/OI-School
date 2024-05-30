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
  int k=read();
  int ans=n*k;
  for(int l=1,r;l<=n;l=r+1){
    if(k/l!=0){
      r=(k)/(k/l);
      if(r>n){
        r=n;
      }
    }else{
      r=n;
    }
    ans-=(l+r)*(r-l+1)/2*(k/l);
  }
  printf("%lld",ans);
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


