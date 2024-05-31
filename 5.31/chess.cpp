#include <iostream>
#include <cstdio>
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int x1=read();
  int y1=read();
  int x2=read();
  int y2=read();
  if(std::abs(x1-x2)+std::abs(y1-y2)<=1){
    printf("-1");
    return 0;
  }
  if(n<=3&&m<=3&&(x2)<=2&&x2>=n-1&&y2<=2&&y2>=m-1){
    printf("1");
    return 0;
  }
  if(n==1||m==1){
    if(std::abs(x1-x2)+std::abs(y1-y2)<=2){
      printf("-1");
    }else{
      printf("2");
    }
    return 0;
  }
  if(n==2||m==2){
    if(std::abs(x1-x2)==1&&std::abs(y1-y2)==1){
      if(x1==1&&x2==2&&m==2){
        printf("2");
      }else if(x1==n-1&&x2==n&&m==2){
        printf("2");
      }else if(y1==1&&y2==2&&n==2){
        printf("2");
      }else if(y1==m-1&&y2==m&&n==2){
        printf("2");
      }else{
        printf("3");
      }
    }else{
      printf("2");
    }
    return 0;
  }
  if(n==3&&m==3&&x1==2&&y1==2&&(std::max(x2,y2)<=1||std::max(x2,m-y2+1)<=1||std::max(n-x2+1,y2)<=1||std::max(n-x2+1,m-y2+1)<=1)){
    printf("2");
    return 0;
  }
  if(std::max(x2-1,y2-1)<=1||std::max(x2-1,m-y2)<=1||std::max(n-x2,y2-1)<=1||std::max(n-x2,m-y2)<=1){
    if(std::abs(x1-x2)==1&&std::abs(y1-y2)==1){
      printf("3");
    }else{
      printf("2");
    }
    return 0;
  }
  printf("3");
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

