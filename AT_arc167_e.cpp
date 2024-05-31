#include <iostream>
#include <cstdio>
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
    if(n%2==0){
      if(n>=4){
        printf("Yes\n0 0 2 0 %d %d\n",n/2,n/2);
      }else{
        printf("No\n");
      }
    }else{
      if(n>=9){
        printf("Yes\n0 0 3 1 %d %d\n",(n-3)/2,(n-1)/2);
      }else{
        printf("No\n");
      }
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

