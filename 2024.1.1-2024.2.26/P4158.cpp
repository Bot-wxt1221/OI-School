#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[105];
int dp[55][2505][2];
int ans[2505];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m,t;
  m=read();
  t=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp+1);
    memset(dp,0,sizeof(dp));
    for(int j=1;j<=m;j++){
      for(int k=1;k<=j;k++){
        dp[j][k][temp[j]-'0']=dp[j-1][k][temp[j]-'0']+1;
        dp[j][k][!(temp[j]-'0')]=dp[j-1][k][!(temp[j]-'0')];
        dp[j][k][temp[j]-'0']=std::max(dp[j][k][temp[j]-'0'],std::max(dp[j-1][k-1][0],dp[j-1][k-1][1])+1);
        dp[j][k][!(temp[j]-'0')]=std::max(dp[j][k][!(temp[j]-'0')],std::max(dp[j-1][k-1][0],dp[j-1][k-1][1]));
      }
    }
    for(int j=t;j>=1;j--){
      for(int k=0;k<=m;k++){
        if(j-k<0){
          continue;
        }
        ans[j]=std::max(ans[j],ans[j-k]+std::max(dp[m][k][0],dp[m][k][1]));
      }
    }
  }
  printf("%d",ans[t]);
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


