#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int matrix[605][605];
void swap(int x,int y){
  for(int i=1;i<=600;i++){
    std::swap(matrix[x][i],matrix[y][i]);
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),mod;
  mod=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      matrix[i][j]=read();
    }
  }
  int ans=1,v=1;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      while(matrix[i][i]){
        int x=matrix[j][i]/matrix[i][i];
        for(int k=i;k<=n;k++){
          matrix[j][k]-=x*matrix[i][k]%mod;
          matrix[j][k]%=mod;
        }
        swap(i,j);
        v=-v;
      }
      swap(i,j);
      v=-v;
    }
  }
  for(int i=1;i<=n;i++){
    ans*=matrix[i][i];
    ans%=mod;
  }
  printf("%lld",(ans*v+mod)%mod);
  end:{}
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


