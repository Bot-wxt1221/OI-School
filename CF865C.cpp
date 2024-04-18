#include <iostream>
#include <cstdio>
inline int read();
int a[55],b[55],p[55];
long double dp[55][5505];
int m,n;
bool check(double mid){
  dp[n][0]=0;
  for(int i=n-1;i>=0;i--){
    for(int j=m+1;j<=5500;j++){
      dp[i+1][j]=mid;
      
    }
    for(int j=0;j<=m;j++){
      dp[i][j]=std::min((long double)mid,(((dp[i+1][j+a[i+1]]+a[i+1])*(long double)p[i+1]/100.0)+(dp[i+1][j+b[i+1]]+b[i+1])*(long double)(100-p[i+1])/100.0));
    }
  }
  return dp[0][0]<mid;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
    p[i]=read();
  }
  long double l=0,r=1e9;
  for(int i=1;i<=100;i++){
    long double mid=(l+r)/2;
    if(check(mid)){
      r=mid;
    }else{
      l=mid;
    }
  }
  int n=read();
  printf("%.15Lf",l);
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

