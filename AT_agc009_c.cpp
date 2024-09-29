#include <cmath>
#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int long long
inline int read();
int seq[100005];
int dp[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int a=read();
  int b=read();
  if(a>b){
    std::swap(a,b);
  }
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  for(int i=3;i<=n;i++){
    if(seq[i]-seq[i-2]<a){
      printf("0");
      return 0;
    }
  }
  seq[0]=-0x3f3f3f3f3f3f3f3f;
  seq[n+1]=0x3f3f3f3f3f3f3f3f;
  dp[0]=1;
  int cur=0;
  int sum=0;
  for(int i=1;i<=n+1;i++){
    while(cur<=n){
      if(seq[i]-seq[cur]<b){
        break;
      }
      sum+=dp[cur];
      sum%=mod;
      cur++;
    }
    dp[i]=sum;
    if(seq[i]-seq[i-1]<a){
      sum=0;
      cur=i-1;
    }
  }
  printf("%lld",dp[n+1]);
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

