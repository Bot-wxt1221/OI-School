#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
long double dp[2005][2005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("doki.in","r",stdin);
	freopen("doki.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=0;i<=2000;i++){
    for(int j=0;j<=2000;j++){
      dp[i][j]=0x3f3f3f3f3f3f3f3f;
    }
  }
  dp[0][0]=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      dp[i+j][0]=std::min(dp[i+j][0],dp[i][j]+1);
      for(int k=1;k<m;k++){
        dp[i][j+k]+=dp[i][j]/(m-1);
      }
    }
  }
  printf("%.6Lf",dp[n][0]);
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
