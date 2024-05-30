#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();
double mp[105][105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n+1;j++){
      scanf("%lf",&mp[i][j]);
    }
  }
  int r=1;
  for(int i=1;i<=n;i++){//变换
    int ni=r;
    for(int j=r+1;j<=n;j++){
      if(std::abs(mp[j][i])>std::abs(mp[ni][i])){
        ni=j;
      }
    }
    for(int j=1;j<=n+1;j++){
      std::swap(mp[ni][j],mp[r][j]);
    }
    if(mp[r][i]==0){
      continue;
    }
    double te=mp[r][i];
    for(int j=1;j<=n+1;j++){
      mp[r][j]/=te;
    }
    for(int j=r+1;j<=n;j++){
        double te2=mp[j][i];
        for(int k=1;k<=n+1;k++){
          mp[j][k]-=mp[r][k]*te2;
        }
    }
    r++;
  }
  if(r<=n){
    for(int i=r;i<=n;i++){
      if(std::abs(mp[i][n+1])>1e-6){
        printf("-1");
        return 0;
      }
    }
    printf("0");
    return 0;
  }

  for(int i=n-1;i>=1;i--){
    for(int j=i+1;j<=n;j++){
      mp[i][n+1]-=mp[j][n+1]*mp[i][j];
    }
  }
     for(int i=1;i<=n;i++){
    printf("x%lld=%.2lf\n",i,mp[i][n+1]);
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

