#include <algorithm>
#include <iostream>
#include <cstdio>
inline int read();
int a[15];
int x[15];
int y[15];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
  for(int i=1;i<=m;i++){
    x[i]=read();
    y[i]=read();
  }
  int ans=0;
  do{
    ans++;
    for(int i=1;i<=m;i++){
      if(a[x[i]]!=y[i]&&a[y[i]]!=x[i]){
        ans--;
        break;
      }
    }
  }while(std::next_permutation(a+1,a+n+1));
  ans%=998244353;
  printf("%d",ans);
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

