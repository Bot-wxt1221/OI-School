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
    int big=0;
    int big2=0;
    for(int i=62;i>=0;i--){
      if((1ll<<i)&(n)){
        if(big==0){
          big=(1ll<<i);
        }else if(big2==0){
          big2=(1ll<<i);
        }
      }
    }
    if(big2==0){
      printf("-1\n");
      continue;
    }
    if((!(m&big))&&(m>=big2*2)){
      printf("-1\n");
      continue;
    }
    if((big2&m)||(big&m)){
      printf("%lld\n%lld %lld\n",1ll,n,m);
    }else{
      printf("2\n%lld %lld %lld\n",n,big2^m,m);
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


