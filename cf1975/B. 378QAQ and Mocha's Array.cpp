#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[100005];
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
    std::sort(a+1,a+n+1);
    n=std::unique(a+1,a+n+1)-a-1;
    int nxt=0;
    for(int i=2;i<=n;i++){
      if(a[i]%a[1]==0){
        continue;
      }else{
        nxt=i;
        break;
      }
    }
    for(int i=nxt+1;i<=n;i++){
      if(a[i]%a[1]==0||a[i]%a[nxt]==0){
      }else{
        printf("No\n");
        goto end;
      }
    }
    printf("Yes\n");
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
