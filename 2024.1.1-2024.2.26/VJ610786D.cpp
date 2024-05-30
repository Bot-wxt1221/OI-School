#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
inline int read();
int st[350];
int ed[350];
int mp[350][350];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int t=read();
  while(t--){
    int n=read();
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=n;i++){
      st[i]=read();
    }
    for(int i=1;i<=n;i++){
      ed[i]=read();
      mp[i][i]=1;
    }
    int ni=read(),nj;
    nj=read();
    while(1){
      if(ni==0&&nj==0){
        break;
      }
      mp[nj][ni]=1;
      ni=read();
      nj=read();
    }
    for(int i=1;i<=n;i++){
      mp[i][n+1]=st[i]^ed[i];
    }
    int r=1;
    for(int i=1;i<=n;i++){
      int ni=r;
      for(int j=r+1;j<=n;j++){
        if(mp[ni][i]<mp[j][i]){
          ni=j;
        }
      }
      for(int j=1;j<=n+1;j++){
        std::swap(mp[r][j],mp[ni][j]);
      }
      if(mp[r][i]==0){
        continue;
      }
      for(int j=r+1;j<=n;j++){
        if(mp[j][i]){
          for(int k=i;k<=n+1;k++){
            mp[j][k]^=mp[r][k];
          }
        }
      }
      r++;
    }
   for(int i=r;i<=n;i++){
      if(mp[i][n+1]){
        printf("Oh,it's impossible~!!\n");
        goto end;
      }
    }
    printf("%d\n",1<<(n-r+1));
    end:{}
  }
  return 0;
}
inline int read(){
  int x=0;
  scanf("%d",&x);
  return x;
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


