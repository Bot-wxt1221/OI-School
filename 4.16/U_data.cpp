#include <iostream>
#include <cstdio>
#include <random>
inline int read();
std::mt19937_64 ran;
int map[805][805];
signed main(){
  #ifdef ONLINE_JUDGE
//  #else
  freopen(".in","r",stdin);
  freopen("U.in","w",stdout);
  #endif
  int h=777;
  int w=777;
  printf("%d %d\n",h,w);
  int cnt=0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(ran()%100==0&&cnt<7777){
        map[i][j]='#';
        cnt++;
      }else{
        map[i][j]='.';
      }
    }
  }
  int aa=ran()%h+1;
  int bb=ran()%w+1;
  map[aa][bb]='G';
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      printf("%c",map[i][j]);
    }
    printf("\n");
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


