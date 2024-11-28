#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
inline int read();
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int x=read();
  int y=read();
  int ans=0;
  while(y){
    int cur=std::__gcd(x,y);
    int tx=x/cur;
    int ty=y/cur;
    if(tx==1){
      ans+=ty;
      break;
    }
    int tt=std::sqrt(tx);
    int mn=ty%tx;
    for(int i=2;i<=tt;i++){
      if(tx%i){
        continue;
      }
      mn=std::min(mn,ty%(i));
      mn=std::min(mn,ty%((tx/i)));
    }
    y-=mn*cur;
    ans+=mn;
  }
  printf("%lld",ans);
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
