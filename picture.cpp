#include <iostream>
#include <cstdio>
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
	if(n!=300){
    printf("%d\n",n*3+4);
		for(int i=1;i<=n+1;i++){
      printf("%d %d\n",i,i);
      printf("%d %d\n",i+1,i);
      printf("%d %d\n",i,i+1);
		}
    printf("%d %d\n",(n+2),(n+2));
	}else{
    printf("%d\n",512);
    printf("%d %d\n",1,1);
    printf("%d %d\n",1,2);
    printf("%d %d\n",1,3);
    printf("%d %d\n",1,4);
    printf("%d %d\n",2,1);
    printf("%d %d\n",3,1);
    printf("%d %d\n",4,1);
    printf("%d %d\n",4,2);
    printf("%d %d\n",3,3);
    printf("%d %d\n",2,4);
		for(int i=1;i<=50;i++){
			int x=i*2+1,y=i*2+1;
      printf("%d %d\n",x+1,y);
      printf("%d %d\n",x+2,y);
      printf("%d %d\n",x,y+1);
      printf("%d %d\n",x,y+2);
      printf("%d %d\n",x+1,y+1);
      printf("%d %d\n",x+1,y+2);
      printf("%d %d\n",x+1,y+3);
      printf("%d %d\n",x+2,y+1);
      printf("%d %d\n",x+2,y+2);
      printf("%d %d\n",x+3,y+1);
			if(i==50){
        printf("%d %d\n",x+2,y+3);
        printf("%d %d\n",x+3,y+2);
			}
		}
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
