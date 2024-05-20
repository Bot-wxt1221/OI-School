#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[200005];
bool yes[200005];
int b[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    a[i]=read();
    if(a[i]==n){
      printf("-1");
      return 0;
    }
    if(a[i]==1){
      printf("-1");
      return 0;
    }
    yes[a[i]]=1;
  }
  std::sort(a+1,a+m+1);
  m=std::unique(a+1,a+m+1)-a-1;
  b[1]=1;
  for(int i=1;i<=n;i++){
    b[i]=i;
  }
  for(int i=1;i<=n;i++){
    if(yes[i]){
      std::swap(b[i],b[i+1]);
    }
  }
  for(int i=1;i<=n;i++){
    printf("%d " ,b[i]);
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

