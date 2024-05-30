#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int dp[5005];
int tt[5005];
int fac[5005];
int getans(int x){
  return fac[x];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("record.in","r",stdin);
  freopen("record.out","w",stdout);
  #endif
  int n=read();
  int cnt=0;
  fac[0]=1;
  for(int i=1;i<=n;i++){
    fac[i]=(1ll*fac[i-1]*i)%mod;
  }
  for(int i=1;i<=n;){
    tt[++cnt]=read();
    for(int j=i+1;j<=i+tt[cnt]-1;j++){
      if(read()!=tt[cnt]){
        printf("0");
        return 0;
      }
    }
    i+=tt[cnt];
  }
//  int tans=0;
//  for(int sta=0;sta<(1<<cnt);sta++){
//    if((sta&(1<<(cnt-1)))==0){
//      continue;
//    }
//    int sum=0;
//    int ans=1;
//    int tt=0;
//    int tt2=0;
//    for(int i=1;i<=cnt;i++){
//      sum+=::tt[i];
//      if(sta&(1ll<<(i-1))){
//        tt++;
//        if(sum>1){
//          tt2++;
//        }
//        sum=0;
//      }
//    }
//    ans=getans(tt);
//    if((cnt-tt)%2){
//      ans=mod-ans;
//    }
//    ans=(1ll*ans*(1ll<<(tt2)))%mod;
//    tans+=ans;
//    tans%=mod;
//  }
  dp[0]=1;
  for(int i=1;i<=cnt;i++){
    for(int j=0;j<i;j++){
      if(tt[i]==1&&j==i-1){
        dp[i]+=(-dp[j]*fac[(i-j)])%mod;
      }else{
        dp[i]+=((-dp[j]*fac[(i-j)])%mod)*2%mod;
      }
    }
  }
  printf("%lld",dp[cnt]);
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

