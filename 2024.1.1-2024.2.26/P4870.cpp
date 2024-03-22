#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
inline int read();
int dp[305][305][2];
int x[305];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  int start=0;
  bool cut=0;
  for(int i=1;i<=n;i++){
    x[i]=read();
    if(x[i]==0){
      start=1;
    }
  }
  if(!start){
    cut=1;
    x[++n]=0;
  }
  std::sort(x+1,x+n+1);
  for(int i=1;i<=n;i++){
    if(x[i]==0){
      start=i;
    }
  }
  int ans=0;
  for(int l=1;l<=n;l++){
    memset(dp,0x3f,sizeof(dp));
    dp[start][start][0]=dp[start][start][1]=0;
    for(int len=1;len<=l;len++){
      for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        dp[i-1][j][0]=std::min(dp[i-1][j][0],std::min(dp[i][j][0]+(l-len)*(x[i]-x[i-1]),dp[i][j][1]+(l-len)*(x[j]-x[i-1])));
        dp[i][j+1][1]=std::min(dp[i][j+1][1],std::min(dp[i][j][0]+(l-len)*(x[j+1]-x[i]),dp[i][j][1]+(l-len)*(x[j+1]-x[j])));
      }
    }
    int minn=0x3f3f3f3f;
    for(int i=1;i<=n-l+1;i++){
      int j=i+l-1;
      minn=std::min(minn,std::min(dp[i][j][0],dp[i][j][1]));
    }
    ans=std::max(ans,m*l-minn);
  }
  printf("%d",ans-cut*m);
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


