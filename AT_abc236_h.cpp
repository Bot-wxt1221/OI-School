#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353ll
inline int read();
int d[35];
int f[(1<<16)+5];
int lbit(int x){
  return x&(-x);
}
__int128 lcm[(1<<16)+5];
int to[(1<<16)+5];
int pop[(1<<16)+5];
int fac[(1<<16)+5];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  fac[0]=1;
  for(int i=1;i<=n;i++){
    d[i]=read();
    to[(1<<(i-1))]=d[i];
    lcm[(1<<(i-1))]=d[i];
    pop[(1<<(i-1))]=1;
    fac[i]=fac[i-1]*i%mod;
  }
  for(int i=1;i<(1<<n);i++){
    if(lcm[i]){
      continue;
    }
    lcm[i]=((__int128)lcm[i^lbit(i)])*to[lbit(i)]/std::__gcd(lcm[i^lbit(i)],(__int128)to[lbit(i)]);    
    if(lcm[i]>m){
      lcm[i]=m+1;
    }
    pop[i]=pop[i^lbit(i)]+1;
  }
  f[0]=1;
  for(int i=1;i<(1<<n);i++){
    f[i]=0;
    for(int j=i;j;j=(j-1)&i){
      if((lbit(i)&j)!=lbit(i)){
        continue;
      }
      f[i]+=((f[i^j]*(m/lcm[j])%mod)*fac[(pop[j]-1)]%mod)*((pop[j]%2==0)?-1:1);
      f[i]%=mod;
      f[i]+=mod;
      f[i]%=mod;
    }
  }
  printf("%lld",f[(1<<n)-1]);
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

