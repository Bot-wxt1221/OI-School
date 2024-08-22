#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline long long read();
long long dp[3005][3005];
long long h[3005];
class node{
  public:
    int a,b;
}a[3005];
bool operator < (node a,node b){
  return (a.a+a.b)>(b.a+b.b);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("hunter.in","r",stdin);
  freopen("hunter.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int d=read();
  for(int i=1;i<=n;i++){
    a[i].a=read();
  }
  for(int i=1;i<=n;i++){
    a[i].b=read();
    dp[0][i]=0x3f3f3f3f3f3f3f3f;
  }
  std::sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
    dp[i][i+1]=0x3f3f3f3f3f3f3f3f;
    for(int j=1;j<=i;j++){
      dp[i][j]=dp[i-1][j];
      dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]+(a[i].a+(j-1)*d)*(a[i].b+(j-1)*d));
    }
  }
  for(int i=1;i<=m;i++){
    h[i]=read();
    int ret=std::lower_bound(dp[n]+0,dp[n]+n+1,h[i])-dp[n]-1;
    printf("%lld ",ret);
  }
  return 0;
}
inline long long read(){
  long long x=0,f=1;char c=getchar();
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
