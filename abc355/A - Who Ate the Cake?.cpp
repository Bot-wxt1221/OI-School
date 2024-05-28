#include <iostream>
#include <cstdio>
inline int read();
bool yes[5];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int a=read();
  int b=read();
  if(a==b){
    printf("-1");
    return 0;
  }
  yes[a]=yes[b]=1;
  for(int i=1;i<=3;i++){
    if(yes[i]==0){
      printf("%d",i);
      return 0;
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

