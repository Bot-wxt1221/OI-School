#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int a[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("math.in","r",stdin);
  freopen("math.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  std::sort(a+1,a+n+1);
  long double mn=0x3f3f3f3f;
  long double aa=0,bb=0;
  for(int i=1;i<=m;i++){
    aa+=1ll*a[i]*a[i];
    bb+=a[i];
  }
  mn=(aa+bb*bb/m+-2*bb*bb/m);
  for(int i=m+1;i<=n;i++){
    aa-=1ll*a[i-m]*a[i-m];
    bb-=a[i-m];
    aa+=1ll*a[i]*a[i];
    bb+=a[i];
    mn=std::min(mn,aa+bb*bb/m+-2*bb*bb/m);
  }
  printf("%.4Lf",mn/m);
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

