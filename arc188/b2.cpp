#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
inline int read();
bool vised[505];
int color[505];
int calc(int n,int k){
  memset(vised,0,sizeof(vised));
  int rett=0;
  int a[2]={k,0};
  for(int i=1;i<=n;i++){
    rett^=1;
    for(int j=0;j<n;j++){
      if(vised[j]){
        continue;
      }
      vised[j]=1;
      for(int k=0;k<n;k++){
        int ret=2*a[rett]-k;
        ret%=n;
        ret+=n;
        ret%=n;
        if(vised[k]!=vised[ret]){
          goto end;
        }
      }
      goto end2;
      end:{}
      vised[j]=0;
    }
    return 0;
    end2:{}
  }
  return 1;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    int k=read();
        if(std::__gcd(n,2*k)==1){
          printf("Yes\n");
        }else if(std::__gcd(n,2*k)==2&&n%4!=0){
          printf("Yes\n");
        }else{
          printf("No\n");
        }
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
