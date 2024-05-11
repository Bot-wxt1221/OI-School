#include <iostream>
#include <cstdio>
inline int read();
char temp[255][255];
int sum[255][255];
int dp[105][105][105][105];
bool getsum(int x,int y,int nx,int ny){
  if(sum[nx][ny]-sum[nx][y-1]-sum[x-1][ny]+sum[x-1][y-1]==0){
    return 1;
  }
  if(sum[nx][ny]-sum[nx][y-1]-sum[x-1][ny]+sum[x-1][y-1]==(nx-x+1)*(ny-y+1)){
    return 1;
  }
  return 0;
}
int dp1[255];
int dp2[255];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("painting.in","r",stdin);
  freopen("painting.out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  if(n>100){
    dp1[1]=0;
    for(int i=2;i<=n;i++){
      dp1[i]=dp1[i/2+(i%2)]+1;
    }
    dp2[1]=dp1[n];
    for(int i=2;i<=m;i++){
      dp2[i]=dp2[i/2+(i%2)]+1;
    }
    printf("%d\n",dp2[m]);
    return 0;
  }
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(temp[i][j]=='.');
    }
  }
  for(int li=1;li<=n;li++){
    for(int lj=1;lj<=m;lj++){
      for(int i=1;i+li-1<=n;i++){
        for(int j=1;j+lj-1<=m;j++){
          int &cur=dp[i][j][i+li-1][j+lj-1];
          cur=0x3f3f3f3f;
          if(getsum(i,j,i+li-1,j+lj-1)){
            cur=0;
          }else{
            for(int ni=i;ni<i+li-1;ni++){
              cur=std::min(cur,std::max(dp[i][j][ni][j+lj-1],dp[ni+1][j][i+li-1][j+lj-1])+1);
            }
            for(int ni=j;ni<j+lj-1;ni++){
              cur=std::min(cur,std::max(dp[i][j][i+li-1][ni],dp[i][ni+1][i+li-1][j+lj-1])+1);
            }
          }
        }
      }
    }
  }
  printf("%d",dp[1][1][n][m]);
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

