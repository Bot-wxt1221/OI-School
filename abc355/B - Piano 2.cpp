#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int a[105];
int b[105];
int c[205];
bool ape[205];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    c[++cnt]=a[i];
    ape[a[i]]=1;
  }
  for(int i=1;i<=m;i++){
    b[i]=read();
    c[++cnt]=b[i];
  }
  std::sort(c+1,c+cnt+1);
  for(int i=1;i<cnt;i++){
    if(ape[c[i]]&&ape[c[i+1]]){
      printf("Yes");
      return 0;
    }
  }
  printf("No");
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

