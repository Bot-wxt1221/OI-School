#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int h[1000005];
int p[1000005];
int a[1000005];
int b[1000005];
int c[1000005];
int pp[1000005];
bool learn[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    h[i]=read();
  }
  for(int i=1;i<=m;i++){
    p[i]=read();
    a[i]=read();
    b[i]=read();
    c[i]=read();
  }
  for(int ii=1;ii<=m;ii++){
    int st=p[ii];
    for(int i=0;i<(1<<(m));i++){
      if(i&(1<<(st-1))){
        pp[1]=ii;
        for(int i=1;i<=n;i++){
          if(i==ii){
            continue;
          }
          if(i<ii){
            pp[i+1]=i;
          }else{
            pp[i]=i;
          }
        }
        do{
          for(int i=1;i<=n;i++){

          }
        }while(std::next_permutation(pp+2,pp+n+1));
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

