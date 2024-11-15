#include <csignal>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[100005];
int dis[1000005];
int m;
int pre(int x){
  return (x)*(x-1)/2;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	#endif
  int n=read();
  m=read()*3;
  int bkm=m;
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      m+=pre(dis[a[i]^a[j]]);
      dis[a[i]^a[j]]++;
      m-=pre(dis[a[i]^a[j]]);
      if(m<=0){
        goto end;
      }
    }
  }
  end:{}
  m=std::max(m,0ll);
  printf("%lld",(bkm-m)/3);
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
