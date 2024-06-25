#include <iostream>
#include <cstdio>
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int x1=read();
    int y1=read();
    int x2=read();
    int y2=read();
    if(x1>y1){
      std::swap(x1,y1);
      std::swap(x2,y2);
    }
    int ad=std::min(x2-x1,y2-y1);
    x1+=ad;
    y1+=ad;
    if(y1==y2){
      if(x1<=y1&&y1<=x2){
        printf("NO\n");
        goto end;
      }
    }else if(y1<=x1&&x1<=y2){
      printf("NO\n");
      goto end;
    }
    printf("YES\n");
    end:{}
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
