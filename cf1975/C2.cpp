#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
inline int read();
int a[100005];
int b[100005];
signed main(){
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
    int mx=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        b[j]=a[j];
      }
      for(int j=i+1;j<=n;j++){
        std::sort(b+i,b+j+1);
        mx=std::max(mx,b[(j-i+2)/2+i-1]);
      }
    }
    printf("%d\n",mx);
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
