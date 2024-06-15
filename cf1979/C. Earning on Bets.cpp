#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int k[55];
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
      k[i]=read();
    }
    for(int i=1e9;i<=1e9;i++){
      int cnt=0;
      for(int j=1;j<=n;j++){
        cnt+=(i/k[j])+1;
      }
      if(cnt<=i){
        for(int j=1;j<=n;j++){
          printf("%lld ",(i/k[j])+1);
        }
        printf("\n");
        goto end;
      }
    }
    printf("-1\n");
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
