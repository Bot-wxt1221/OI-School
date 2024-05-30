#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[1000005];
int sum[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("num.in","r",stdin);
  freopen("num.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  std::sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
    sum[i]=a[i]+sum[i-1];
  }
  int j=0;
  int sum1=0,sum2=0;
  int ans=0;
  for(int i=1;i<=n;i++){
    sum2-=a[i];
    while(j+1<=n&&(((sum1+sum2+a[j+1]+a[i])<a[i]*(j+1))||(j<i))){
      j++;
      sum2+=a[j];
    }
    if(sum1+sum2+a[i]<a[i]*(j)){
      ans=std::max(ans,j-i+1);
    }
    sum1+=a[i];
  }
  printf("%lld",ans);
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


