#include <iostream>
#include <cstdio>
inline int read();
int a[65];
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
    for(int i=1;i<=n;i++){
      bool ans=1;
      for(int j=2;j<=n;j++){
        if(a[(i+j-1-1)%n+1]>a[(i+j-1)%n+1]){
          ans=0;
          break;
        }
      }
      if(ans){
        printf("Yes\n");
        goto end;
      }
    }
    printf("No\n");
    end:{};
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
