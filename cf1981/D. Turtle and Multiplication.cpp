#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int zhi[300005];
int lst[300005];
int ans[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int cnt=0;
  lst[++cnt]=1;
  for(int i=2;i<=300000;i++){
    if(zhi[i]){
      continue;
    }
    lst[++cnt]=i;
    for(int j=2;j*i<=300000;j++){
      zhi[i*j]=1;
    }
  }
  ans[1]=1;
  ans[2]=1;
  ans[3]=2;
  ans[4]=2;
  int cur=4;
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      printf("%lld ",ans[i]);
    }
    printf("\n");
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

