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
    int a1=read();
    int b1=read();
    int c1=read();
    if((a1+b1+c1)%2==0){
      int tt=b1-a1;
      c1-=(b1-a1);
      b1=a1;
      int ans=(a1+b1+c1)/2+tt;
      if(a1+b1>c1){
      }else{
        ans-=(c1-(a1+b1))/2;
      }
      printf("%d\n",ans);
      continue;
    }
    printf("-1\n");
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
