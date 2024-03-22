#include <iostream>
#include <cstdio>
using namespace std;
int read();
char str[2005][2005];
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    long long tt=pow(x,y/2);
    return (tt*tt)%1000000007;
  }
  return (((1ll)*(x))*pow(x,y-1))%1000000007;
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
  #endif
 
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",str[i]+1);
  }
  int ans=(n*m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      for(int k=0;k<4;k++){
        int xi=i+to[k][0];
        int xj=j+to[k][1];
        if(xi<=0||xj<=0||xi>n||xj>m){
          continue;
        }
        if(str[xi][xj]!=str[i][j]){
          ans--;
          break;
        }
      }
    }
  }
  printf("%d\n",pow(2,ans));
  return 0;
}

int read(){
  int x=0,f=1;
  char tt=getchar();
  while(tt>'9'||tt<'0'){
    (tt=='-')?f=-1:0;
    tt=getchar();
  }
  while('0'<=tt&&tt<='9'){
    x=(x*10)+(tt-'0');
    tt=getchar();
  }
  return f*x;
}
