#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
inline int read();
int dp[305][3005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("Func.in","r",stdin);
	freopen("Func.out","w",stdout);
	#endif
  int T=read();
  memset(dp,0x3f,sizeof(dp));
  for(int i=0;i<=3000;i++){
    dp[0][i]=0;
  }
  for(int i=1;i<=80;i++){
    for(int j=1;j<=80-i;j++){
      if(i*j>300){
        break;
      }
      if(std::__gcd(i,j)==1){
        for(int kk=300;kk;kk--){
          for(int kkk=i;kkk<=3000;kkk++){
            dp[kk][kkk]=std::min(dp[kk][kkk],dp[kk-1][kkk-i]+j);
          }
        }
      }
    }
  }
  while(T--){
    int n=read();
    int m=read();
    for(int i=300;i>=0;i--){
      if(dp[i][n]<=m){
        printf("%d\n",i+1);
        break;
      }
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
