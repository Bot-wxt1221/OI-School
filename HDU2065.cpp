#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    long long tt=pow(x,y/2);
    return (tt*tt)%100;
  }
  return (((1ll)*(x))*pow(x,y-1))%100;
}

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  signed T;
  while(scanf("%d",&T)!=EOF){
    long long TT=0;
    while(T--){
      int n=read();
      printf("Case %lld: %lld\n",++TT,(pow(2,n-1)+pow(4,n-1)+0ll)%100);
    }
    printf("\n");
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

