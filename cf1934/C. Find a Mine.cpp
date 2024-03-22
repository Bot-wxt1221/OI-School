#include <iostream>
#include <cstdio>
inline int read();
int query(int n,int m){
  printf("? %d %d\n",n,m);
  fflush(stdout);
  return read();
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int m=read();
    int sum1=query(1,1)+2;
    int sum2=m+n-query(n,m);
    int jan=query(1,m)-m+1;
    int x1=(sum1+jan)/2;
    x1=std::max(x1,1);
    x1=std::min(x1,n);
    int y1=(sum1-jan)/2;
    y1=std::max(y1,1);
    y1=std::min(y1,m);
    int x2=(sum2+jan)/2;
    x2=std::max(x2,1);
    x2=std::min(x2,n);
    int y2=(sum2-jan)/2;
    y2=std::max(y2,1);
    y2=std::min(y2,m);
    if(query(x1,y1)){
      printf("! %d %d\n",x2,y2);
    }else{
      printf("! %d %d\n",x1,y1);
    }
    fflush(stdout);
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


