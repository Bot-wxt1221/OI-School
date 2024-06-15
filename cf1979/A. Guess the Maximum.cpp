#include <iostream>
#include <cstdio>
inline int read();
int a[500005];
int solve(){
  int n=read();
  int mx=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(i>1){
      mx=std::min(mx,std::max(a[i],a[i-1]));
    }
  }
  printf("%d\n",mx-1);
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    solve();
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
