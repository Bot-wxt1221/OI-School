#include <cinttypes>
#include <cmath>
#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int a[1005],b[1005];
int sz[1000005];
int fa[1000005];
int dp[1000005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
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
    b[i]=read();
  }
  for(int i=0;i<(1<<n);i++){
    int pop=0;
    for(int j=1;j<=n;j++){
      if((1<<(j-1))&i){
        fa[j]=j;
        pop++;
      }
    }
    for(int j=1;j<=m;j++){
      if(((1<<(a[j]-1))&i)&&((1<<(b[j]-1))&i)){
        fa[getfa(a[j])]=fa[getfa(b[j])];
      }
    }
    int cnt=0;
    for(int j=1;j<=n;j++){
      if(getfa(j)==j&&((1<<(j-1))&i)){
        cnt++;
      }
    }
    sz[i]=cnt;
  }
  dp[0]=1;
  for(int i=1;i<(1<<n);i++){
    for(int j=(i);j;j=(j-1)&i){
      dp[i]+=dp[i^j]*(((sz[j]+1)%2)?-1:1);
      dp[i]%=mod;
      dp[i]+=mod;
      dp[i]%=mod;
    }
  }
  printf("%d",dp[(1<<n)-1]);
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

