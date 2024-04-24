#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (tt*tt)%10;
  }
  return (pow(x,y-1)*x)%10;
}
int last(int x){
  return pow(2,x);
}
int dfs(int n,int m,int k){
  if(n<=m-1){
    if(m-k==1&&n==k){
      return 0;
    }
    return last(n);
  }
  int tt=(n-(m-1));
  tt/=(m-k);
  if(tt==0){
    return dfs(n-m+k,m,k);
  }
  return dfs(n-tt*(m-k),m,k);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int m=read();
    int k=read();
    printf("%lld\n",dfs(n,m,k));
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

