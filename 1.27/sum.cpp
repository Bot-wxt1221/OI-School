#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[200005];
int sum[200005];
int ans[200005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	#endif
  int n=read();
  int _min=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    ans[i]=a[i];
    sum[i]=sum[i-1]+a[i];
    ans[i]+=sum[i-1]-_min;
    _min=std::min(_min,sum[i]);
  }
  _min=0;
  for(int i=n;i>=1;i--){
    sum[i]=sum[i+1]+a[i];
    ans[i]+=sum[i+1]-_min;
    _min=std::min(_min,sum[i]);
  }
  for(int i=1;i<=n;i++){
    printf("%lld ",ans[i]);
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


