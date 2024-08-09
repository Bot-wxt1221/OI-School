#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[100005];
int ad[100005];
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
    int mx=-0x3f3f3f3f;
    int ans=0;
    int mxad=0;
    for(int i=1;i<=n;i++){
      if(a[i]>=mx){
        mx=a[i];
        ad[i]=0;
      }else{
        ad[i]=mx-a[i];
        mxad=std::max(mxad,ad[i]);
        ans+=mx-a[i];
        a[i]=mx;
      }
    }
    printf("%lld\n",ans+mxad);
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
