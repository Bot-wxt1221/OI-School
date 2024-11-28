#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int a[1000005];
int b[1000005];
std::queue<int>qu,qu2;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("pop.in","r",stdin);
	freopen("pop.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(a[i]<=n/2){
      qu.push(i);
    }
    if(n-a[i]+1<=n/2){
      qu2.push(i);
    }
  }
  long long ans=0;
  long long ans2=0;
  for(int i=1;i<=n;i++){
    b[i]=read();
    if(n-b[i]+1<=n/2){
      ans+=std::abs(i-qu.front());
      qu.pop();
    }
    if(b[i]<=n/2){
      ans2+=std::abs(i-qu2.front());
      qu2.pop();
    }
  }
  ans=std::min(ans,ans2);
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
