#include <iostream>
#include <cstdio>
inline int read();
int x[9000005];
int y[9000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  for(int i=1;i<=300*300;i++){
    x[i]=read();
    y[i]=read();
    if(i%10000==0){
      std::cerr<<i<<std::endl;
    }
    for(int j=1;j<=i;j++){
      if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==5120){
        std::cerr<<"oops"<<i<<' '<<j<<std::endl;
        return 0;
      }
      if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==76928){
        std::cerr<<"oops"<<i<<' '<<j<<std::endl;
        return 0;
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
