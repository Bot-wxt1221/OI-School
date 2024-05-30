#include <iostream>
#include <cstdio>
inline int read();
class Matrix{
  public:
    int map[205][205];
};
Matrix operator * (const Matrix &a,const Matrix &b){
  Matrix ans;
  for(int i=1;i<=200;i++){
    for(int j=1;j<=200;j++){
      ans.map[i][j]=0;
      for(int k=1;k<=200;k++){
        ans.map[i][j]+=(a.map[i][k]*b.map[k][j]);
      }
    }
  }
  return ans;
}
Matrix a,b;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("matrix.in","r",stdin);
  freopen("matrix.out","w",stdout);
  #endif
  a.map[1][2]=a.map[1][4]=1;
  a.map[3][1]=a.map[3][2]=a.map[3][4]=1;
  a.map[5][1]=a.map[5][2]=a.map[5][4]=1;
  b=a*a;
  int n=read(),k;
  k=read();
  if(k==1){
    printf("0\n");
    return 0;
  }
  if(k==2){
    if(n%2==0){
      printf("%lld\n",1ll*(n/2)*(n/2));
      return 0;
    }else{
      printf("%lld\n",1ll*((n-1)/2)*((n+1)/2));
      return 0;
    }
  }
  if(n==3){
    if(k>=3){
      printf("3\n");
      return 0;
    }
  }
  if(n==2){
    printf("1\n");
    return 0;
  }
  if(n==1){
    printf("0\n");
    return 0;
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

