#include <iostream>
#include <cstdio>
inline int read();
char str[2005][2005];
int dp[105][105][105][105];
int sum[105][105][105][105];
int num[105][105][105][105];
int dp2[105][105][105][105];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",str[i]+1);
  }
  if(n<=100&&m<=100){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(str[i][j]=='*'){
          for(int i2=1;i2<=n;i++){
            for(int j2=1;j2<=n;j++){
              if(str[i2][j2]!='*'){
                continue;
              }
              if(i2==i&&j2==j){
                continue;
              }
              dp[]
            }
          }
        }else if(str[i][j]=='+'){

        }else{
          sum[i][j][i][j]=str[i][j]-'0';
          num[i][j][i][j]=1;
          for(int i2=1;i2<=n;i++){
            for(int j2=1;j2<=n;j++){
              if(str[i2][j2]>'9'||str[i2][j2]<'0'){
                continue;
              }
              if(i2==i&&j2==j){
                continue;
              }
              sum[i2][j2][i][j]=sum[i2][j2][i][j-1]*10+sum[i2][j2][i-1][j]*10+(num[i2][j2][i][j-1]+num[i2][j2][i-1][j])*(str[i][j]-'0');
              num[i2][j2][i][j]=num[i2][j2][i][j-1]+num[i2][j2][i-1][j];
            }
          }
        }
      }
    }
  }
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


