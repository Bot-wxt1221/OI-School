#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[5005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int tans=0;
  int mn=0;
  for(int i=1;i<=n;i++){
    mn=0;
    int ans=-0x3f3f3f3f3f3f3f3f;
    int sum=0;
    for(int j=i;j<=n;j++){
      sum+=a[j];
      ans=std::max(ans,sum-mn);
      mn=std::min(mn,sum);
      tans+=ans;
    }
  }
  printf("%lld",tans);
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
