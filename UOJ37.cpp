#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <bitset>
#define int long long
#define mod 1000000007ll
inline int read();
int dp[50005];
int d[50005];
int s[50005];
int a[1005];
int b[1005];
int eg[1005];
int pop[50005];
int pw[50005];
std::bitset<305>cnt[50005],cnt2[50005];
std::vector<int>vec[25],vec2[25];
int calc(int i,int j){
  return (cnt[i]&cnt2[j]).count();
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  pw[0]=1;
  for(int i=1;i<=m;i++){
    a[i]=read();
    b[i]=read();
    pw[i]=pw[i-1]*2%mod;
  }
  for(int i=0;i<(1<<n);i++){
    for(int j=1;j<=m;j++){
      if(i&(1<<(a[j]-1))){
        cnt[i][j]=1;
      }
      if(i&(1<<(b[j]-1))){
        cnt2[i][j]=1;
      }
    }
  }
  s[0]=1;
  for(int i=1;i<(1<<n);i++){
    dp[i]=pw[calc(i,i)];
    for(int s=(i);s;s=(s-1)&i){
      if(i==s){
        continue;
      }
      dp[i]-=1ll*(d[s]-::s[s])*pw[calc(s,i-s)+calc(i-s,i-s)]%mod;
      dp[i]%=mod;
      if(s&((i&(-i)))){
        d[i]+=dp[s]*::s[i-s]%mod;
        d[i]%=mod;
        ::s[i]+=dp[s]*d[i-s]%mod;
        ::s[i]%=mod;
      }
    }
    dp[i]-=d[i]-s[i];
    dp[i]%=mod;
    d[i]+=dp[i];
    d[i]%=mod;
  }
  printf("%lld",(dp[(1<<n)-1]+mod)%mod);
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

