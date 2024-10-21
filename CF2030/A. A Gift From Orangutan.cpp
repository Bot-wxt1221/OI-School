#include <iostream>
#include <cstdio>
inline int read();
int a[1005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    int mx=0;
    int mn=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
      a[i]=read();
      mx=std::max(mx,a[i]);
      mn=std::min(mn,a[i]);
    }
    printf("%d\n",(mx-mn)*(n-1));
  }
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
