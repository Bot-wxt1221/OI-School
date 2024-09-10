#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
long double x[2005];
long double y[2005];
long double dp[2005][2005][2];
int pre[2005][2005][2];
int n;
int presta[2005][2005][2];
long double dis(int a,int b){
  return std::sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
void getans(int i,int j,int sta){
  if(i==j){
    printf("%d ",(i-1)%n+1);
    return ;
  }
  if(pre[i][j][sta]){
    getans(i,j-1,presta[i][j][sta]);
    printf("%d ",(j-1)%n+1);
  }else{
    getans(i+1,j,presta[i][j][sta]);
    printf("%d ",(i-1)%n+1);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int k=1;
  scanf("%Lf%Lf",&x[1],&y[1]);
  x[n+1]=x[1];
  y[n+1]=y[1];
  for(int i=2;i<=n;i++){
    scanf("%Lf%Lf",&x[i],&y[i]);
    if(y[i]>y[k]){
      k=i;
    }
    x[i+n]=x[i];
    y[i+n]=y[i];
  }
  for(int siz=1;siz<=n+n;siz++){
    for(int i=1;i+siz-1<=n+n;i++){
      int j=i+siz-1;
      dp[i][j][0]=dp[i][j][1]=0x3f3f3f3f3f3f3f3f;
    }
  }
  dp[k][k][0]=0;
  dp[k][k][1]=0;
  dp[k+n][k+n][0]=0;
  dp[k+n][k+n][1]=0;
  for(int siz=1;siz<=2*n;siz++){
    for(int i=1;i+siz-1<=2*n;i++){
      int j=i+siz-1;
      if(j<=2*n){
        dp[i][j+1][1]=std::min(dp[i][j+1][1],dp[i][j][0]+dis(j+1,i));
        if(dp[i][j+1][1]==dp[i][j][0]+dis(j+1,i)){
          pre[i][j+1][1]=1;
          presta[i][j+1][1]=0;
        }
        dp[i][j+1][1]=std::min(dp[i][j+1][1],dp[i][j][1]+dis(j+1,j));
        if(dp[i][j+1][1]==dp[i][j][1]+dis(j+1,j)){
          pre[i][j+1][1]=1;
          presta[i][j+1][1]=1;
        }
      }
      if(i){
        dp[i-1][j][0]=std::min(dp[i-1][j][0],dp[i][j][1]+dis(i-1,j));
        if(dp[i-1][j][0]==dp[i][j][1]+dis(j,i-1)){
          pre[i-1][j][0]=0;
          presta[i-1][j][0]=1;
        }
        dp[i-1][j][0]=std::min(dp[i-1][j][0],dp[i][j][0]+dis(i-1,i));
        if(dp[i-1][j][0]==dp[i][j][0]+dis(i,i-1)){
          pre[i-1][j][0]=0;
          presta[i-1][j][0]=0;
        }
      }
    }
  }
  long double ans=0x3f3f3f3f3f3f3f3f;
  int l,r,sta;
  for(int i=1;i<=n;i++){
    if(dp[i][i+n-1][0]<ans){
      ans=dp[i][i+n-1][0];
      l=i;
      r=i+n-1;
      sta=0;
    }
    if(dp[i][i+n-1][1]<ans){
      ans=dp[i][i+n-1][1];
      l=i;
      r=i+n-1;
      sta=1;
    }
  }
  getans(l,r,sta);
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
