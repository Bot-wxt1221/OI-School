#include <iostream>
#include <cstdio>
inline int read();
int x[10005];
int y[10005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    x[i]=read();
    y[i]=read();
  }
  for(int i=1;i<=n;i++){
    int mxd=0,mxi=i;
    for(int j=1;j<=n;j++){
      if(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))>mxd){
        mxd=((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        mxi=j;
      }
    }
    printf("%d\n",mxi);
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

