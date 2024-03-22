#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
std::deque<int>qu;
int dp[2005][2005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read(),mxp,w;
  mxp=read();
  w=read();
  memset(dp,128,sizeof(dp));
  for(int i=1;i<=T;i++){
    int ap=read();
    int bp=read();
    int as=read();
    int bs=read();
    for(int j=0;j<=as;j++){
      dp[i][j]=-(j*ap);
    }
    for(int j=0;j<=mxp;j++){
      dp[i][j]=std::max(dp[i][j],dp[i-1][j]);
    }
    if(i<=w){
      continue;
    }
    qu=std::deque<int>();
    for(int j=0;j<=mxp;j++){
      while(qu.size()>0&&j-qu.front()>as){
        qu.pop_front();
      }
      while(qu.size()>0&&dp[i-w-1][qu.back()]+qu.back()*ap<=dp[i-w-1][j]+j*ap){
        qu.pop_back();
      }
      qu.push_back(j);
      dp[i][j]=std::max(dp[i][j],dp[i-w-1][qu.front()]+qu.front()*ap-j*ap);
    }
    qu=std::deque<int>();
    for(int j=mxp;j>=0;j--){
      while(qu.size()>0&&qu.front()-j>bs){
        qu.pop_front();
      }
      while(qu.size()>0&&dp[i-w-1][qu.back()]+qu.back()*bp<=dp[i-w-1][j]+j*bp){
        qu.pop_back();
      }
      qu.push_back(j);
      dp[i][j]=std::max(dp[i][j],dp[i-w-1][qu.front()]+qu.front()*bp-j*bp);
    }
  }
  int ans=-0x3f3f3f3f;
  for(int i=0;i<=mxp;i++){
    ans=std::max(ans,dp[T][i]);
  }
  printf("%d",ans);
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


