#include <iostream>
#include <cstdio>
#define int long long
inline int read();
bool fre[105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int a,b,c,x=0,y=0;
  a=read();
  b=read();
  c=read();
  for(int i=0;i<60;i++){
    if((c&(1ll<<i))==0){
      fre[i]=1;
    }else{
      if(a>=b&&a>0){
        x|=(1ll<<i);
        a--;
      }else if(b>a&&b>0){
        y|=(1ll<<i);
        b--;
      }else{
        printf("-1");

        return 0;
      }
    }
  }
  if(a!=b){
    printf("-1");
    return 0;
  }
  for(int i=0;i<60;i++){
    if(fre[i]&&a>0){
      a--;
      b--;
      x|=(1ll<<i);
      y|=(1ll<<i);
    }
  }
  if(a>0){
    printf("-1");
    return 0;
  }
  printf("%lld %lld",x,y);
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

