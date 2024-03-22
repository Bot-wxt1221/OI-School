#include <iostream>
#include <cstdio>
#define mod 1000000009
#define int long long
inline int read();
int fa[100005];
int siz[100005];
int fac[100005];
int inv[100005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2){
    return (pow(x,y-1)*x)%mod;
  }
  int tt=pow(x,y/2);
  return (tt*tt)%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  fac[0]=1;
  for(int i=1;i<=100000;i++){
    fac[i]=fac[i-1]*(i)%mod;
  }
  inv[100000]=pow(fac[100000],mod-2);
  for(int i=99999;i>=0;i--){
    inv[i]=(inv[i+1])*(i+1)%mod;
  }
  while(T--){
    int n=read();
    int ans=1;
    for(int i=1;i<=n;i++){
      fa[i]=i;
      siz[i]=0;
    }
    for(int i=1;i<=n;i++){
      fa[getfa(read())]=getfa(i);
    }
    for(int i=1;i<=n;i++){
      siz[getfa(i)]++;
    }
    int kk=0;
    for(int i=1;i<=n;i++){
      if(siz[i]==0){
        continue;
      }
      kk++;
      ans*=inv[siz[i]-1];
      ans%=mod;
      if(siz[i]>=2){
        ans*=pow(siz[i],siz[i]-2);
        ans%=mod;
      }
    }
    ans*=fac[n-kk];
    ans%=mod;
    printf("%lld\n",(ans+mod)%mod);
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


