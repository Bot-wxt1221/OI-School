#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
int a[2005][2005];
std::bitset<2005>bit[2005][1005],ans;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      a[i][j]=read();
      bit[j][a[i][j]][i]=1;
    }
  }
  int tot=0;
  for(int i=1;i<=n;i++){
    ans=0;
    for(int j=1;j<=m;j++){
      ans^=(bit[j][a[i][j]]);
    }
    ans[i]=0;
    tot+=ans.count();
  }
  printf("%d\n",tot/2);
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

