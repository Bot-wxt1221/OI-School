#include <cmath>
#include <iostream>
#include <cstdio>
inline int read();
double mp[1005][1005];
int guass(int n){
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
        return -1;
      }
    }
    return -2;
  }
  for(int i=n-1;i>=1;i--){
    for(int j=i+1;j<=n;j++){
      mp[i][n+1]-=mp[j][n+1]*mp[i][j];
    }
  }
  int mx=0;
  for(int i=1;i<=n;i++){
    if(std::abs(std::round(mp[i][n+1])-mp[i][n+1])>1e-3||int(mp[i][n+1])<=0){
      return -1;
    }
    mx=std::max(mx,int(mp[i][n+1]));
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(mx==(int(mp[i][n+1]))){
      cnt++;
    }
  }
  if(cnt>1){
    return -1;
  }
  return 0;
}
int yuan[105][105];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n+1;i++){
    int m=read();
    for(int j=1;j<=m;j++){
      yuan[i][read()]=1;
    }
    yuan[i][n+1]=read();
  }
  int ans=0;
  for(int i=1;i<=n+1;i++){
    int ntt=0;
    for(int j=1;j<=n+1;j++){
      if(i==j){
        continue;
      }
      ntt++;
      for(int k=1;k<=n+1;k++){
        mp[ntt][k]=yuan[j][k];
      }
    }
    int ret=guass(n);
    if(ret==-2){
      printf("illegal");
      return 0;
    }
    if(ret==0){
      if(ans!=0){
        printf("illegal");
        return 0;
      }
      for(int ij=1;ij<=n;ij++){
        ans=std::max(ans,int(mp[ij][n+1]));
      }
      for(int ij=1;ij<=n;ij++){
        if(ans==int(mp[ij][n+1])){
          ans=ij;
          break;
        }
      }
    }
  }
  if(ans==0){
    printf("illegal");
    return 0;
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


