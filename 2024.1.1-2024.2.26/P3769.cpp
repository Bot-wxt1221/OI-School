#include <iostream>
#include <cstdio>
inline int read();
class node{
public:
  int a,b,c,d;
  node(int x=0,int y=0,int z=0,int aa=0){
    x=a;
    b=y;
    c=z;
    d=aa;
    return ;
  }
}no[50005];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    no[i].a=read();
    no[i].b=read();
    no[i].c=read();
    no[i].d=read();
  }
  for(int i=1;i<=n;i++){
    
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


