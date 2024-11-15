#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int dp[105][105][2];
int calc(int tt,int k){
  dp[0][0][1]=1;
  for(int i=1;i<=65;i++){
    for(int k=0;k<=65;k++){
      dp[i][k][0]=dp[i][k][1]=0;
    }
    int cur=tt&((__int128)1<<(64-(i-1)));
    cur=cur>0;
    for(int k=0;k<=65;k++){
      dp[i][k][0]+=dp[i-1][k][0];
      if(k){
        dp[i][k][0]+=dp[i-1][k-1][0];
      }
    }
    for(int now=0;now<cur;now++){
      for(int k=0;k<=65;k++){
        dp[i][k][0]+=dp[i-1][k][1];//always 0
      }
    }
    dp[i][k][1]+=dp[i-1][k-cur][1];
  }
  return dp[65][k][0]+dp[65][k][1];
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  printf("%lld",(long long)calc(10,2));
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
