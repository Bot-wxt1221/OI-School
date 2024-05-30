#include <iostream>
#include <cstdio>
inline int read();
int hang[4005];
int li[4005];
int h2[4005];
int h3[4005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int T=read();
  for(int i=1;i<=T;i++){
    int tt=read()-1;
    int jj=tt%n+1;
    int ii=tt/n+1;
    hang[ii]++;
    if(hang[ii]==n){
      printf("%d",i);
      return 0;
    }
    li[jj]++;
    if(li[jj]==n){
      printf("%d",i);
      return 0;
    }
    h2[ii+jj]++;
    if(h2[ii+jj]==n){
      printf("%d",i);
      return 0;
    }
    h3[ii-jj+2000]++;
    if(h3[ii-jj+2000]==n){
      printf("%d",i);
      return 0;
    }
  }
  printf("-1");
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

