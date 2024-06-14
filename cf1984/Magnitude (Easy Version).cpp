#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[200005];
int sum[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    sum[n+1]=0;
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    for(int i=n;i>=1;i--){
      sum[i]=sum[i+1]+a[i];
    }
    a[n+1]=0;
    int ans=0;
    int pre=0;
    for(int i=1;i<=n+1;i++){
      ans=std::max(ans,std::abs(pre)+sum[i]);
      pre+=a[i];
    }
    printf("%lld\n",ans);
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
