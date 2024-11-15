#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define mod 32767
inline int read();
int a[1000005];
int b[1000005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
  int n=read();
  a[1]=read();
  a[2]=read();
  int x=read();
  int y=read();
  int z=read();
  for(int i=3;i<=n;i++){
    a[i]=((1ll*a[i-1]*x)%mod+(1ll*a[i-2]*y)%mod+z)%mod;
  }
  b[1]=read();
  b[2]=read();
  x=read();
  y=read();
  z=read();
  for(int i=3;i<=n;i++){
    b[i]=((1ll*b[i-1]*x)%mod+(1ll*b[i-2]*y)%mod+z)%mod;
  }
  std::sort(a+1,a+1+n);
  std::sort(b+1,b+n+1);
  int ans=0;
  for(int i=1;i<=n;i++){
    ans=std::max(a[i]*a[i]-b[i]*b[i],ans);
  }
  printf("%d",ans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
