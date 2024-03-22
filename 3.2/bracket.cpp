#include <iostream>
#include <cstdio>
using namespace std;
int read();
char str[2005];
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
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  #endif
 
  int n=read();
  int m=read();
  scanf("%s",str+1);
  printf("\n");
  for(int i=1;i<=m;i++){
    int op=read();
    read();
    read();
    if(op==2){
      return 0;
    }
  }
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
