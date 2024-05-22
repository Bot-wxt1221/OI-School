#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int f[505][505];
int g[505][505];
int f2[505][505];
int g2[505][505];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (tt*tt)%mod;
  }
  return (pow(x,y-1)*x)%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int p=read();
  p*=pow(10000,mod-2);
  p%=mod;
  f[0][0]=1;
  int pre=1;
  for(int i=1;i<=n;i++){
    pre*=pow(2*i-1,mod-2);
    pre%=mod;
    pre*=i;
    pre%=mod;
    for(int j=0;j<i;j++){
      g[i][std::max(j-1,0ll)]+=p*f[i-1][j]%mod*pow(i,mod-2)%mod;
      g[i][std::max(j-1,0ll)]%=mod;
      g[i][j+1]+=(1-p+mod)%mod*f[i-1][j]%mod*pow(i,mod-2)%mod;
      g[i][j+1]%=mod;
    }
    for(int j=0;j<=i;j++){
      for(int k=0;k<=i;k++){
        g2[j][k]=g[j][k];
        f2[j][k]=f[j][k];
        if(k>0){
          g2[j][k]+=g2[j][k-1];
          g2[j][k]%=mod;
          f2[j][k]+=f2[j][k-1];
          f2[j][k]%=mod;
        }
      }
    }
    for(int j=0;j<i;j++){
      for(int k=0;k<=i;k++){
        f[i][k]+=(f2[j][k]*g[i-j][k])%mod;
        f[i][k]%=mod;
        if(k>0){
          f[i][k]+=(g2[i-j][k-1]*f[j][k])%mod;
          f[i][k]%=mod;
        }
      }
    }
  }
  int res=f[n][0];
  res*=pre;
  res%=mod;
  printf("%lld\n",res);
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

