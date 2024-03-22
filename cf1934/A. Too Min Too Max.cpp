#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[100005];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    std::sort(a+1,a+n+1);
    printf("%d\n",std::max(a[n]-a[1]+a[n-1]-a[1]+a[n-1]-a[2]+a[n]-a[2],a[n]-a[1]+a[n]-a[2]+a[n-1]-a[2]+a[n-1]-a[1]));
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


