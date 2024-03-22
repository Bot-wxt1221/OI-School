#include <iostream>
#include <cstdio>
inline int read();
long double matrix[605][605];
void swap(int x,int y){
  for(int i=1;i<=105;i++){
    std::swap(matrix[x][i],matrix[y][i]);
  }
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  long double ans=1,v=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j){
        scanf("%Lf",&matrix[i][j]);
      }else{
        long double tt;
        scanf("%Lf",&tt);
        continue;
      }
      matrix[i][j]+=1e-8;
      if(i<j){
        ans*=(1-matrix[i][j]);
      }
      matrix[i][j]=matrix[i][j]/(1-matrix[i][j]);
      matrix[i][i]+=matrix[i][j];
      matrix[i][j]*=-1;
    }
  }
  n--;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      while(std::abs(matrix[i][i])>1e-4){
        long double x=matrix[j][i]/matrix[i][i];
        for(int k=i;k<=n;k++){
          matrix[j][k]-=x*matrix[i][k];
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
  }
  printf("%.10Lf",ans*v);
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


