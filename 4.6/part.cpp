#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int long long
inline int read();
int dp[(1<<20)+5];
int h[(1<<20)+5];
int a[55];
int tans[(1<<20)+5];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("partition.in","r",stdin);
  freopen("partition.out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=0;i<(1ll<<n);i++){
    for(int j=1;j<=n;j++){
      if((1ll<<(j-1))&i){
        tans[i]=tans[i]^a[j];
      }
    }
    tans[i]++;
  }
  for(int i=0;i<(1<<n);i++){
    h[i]=tans[i];
    int lwb=(i)&(-i);
    for(int j=lwb;j<(i);j+=lwb){
      if((i|j)!=i){
        continue;
      }
      if((j&lwb)==0){
        continue;
      }
      h[i]-=(h[j]*tans[i^j])%mod;
      h[i]%=mod;
      h[i]+=mod;
      h[i]%=mod;
    }
  }
  dp[0]=1;
  for(int i=1;i<(1<<n);i++){
    int lwb=(i)&(-i);
    dp[i]=m*h[i]%mod*dp[0]%mod;
    for(int j=lwb;j<i;j+=lwb){
      if((i|j)!=i){
        continue;
      }
      if((j&lwb)==0){
        continue;
      }
      dp[i]+=((m*h[j])%mod*dp[i^j])%mod;
      dp[i]%=mod;
    }
  }
  int fans=dp[(1ll<<n)-1];
  printf("%lld",fans);
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

