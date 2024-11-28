#include <cmath>
#include <iostream>
#include <cstdio>
#define int long long
inline int read();

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("expert.in","r",stdin);
	freopen("expert.out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    int k=read();
    int tt=n-k;
    int st=std::sqrt(tt);
    for(int i=1;i<=1e6;i++){
      if(tt%i==0){
        int y=tt/i;
        if((n-y)%y==k){
          printf("%lld %lld\n",n-y,y);
          goto end;
        }
        i=tt/i;
        y=tt/i;
        if((n-y)%y==k){
          printf("%lld %lld\n",n-y,y);
          goto end;
        }
        i=tt/i;
      }
    }
    printf("-1\n");
    end:{}
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
