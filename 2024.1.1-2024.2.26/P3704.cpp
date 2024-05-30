#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
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
int f[1000005],g[1000005],F[1000005];
bool pr[1000005];
int prl[1000005];
int mu[1000005];
void init(){
  f[1]=g[1]=F[0]=F[1]=1;
  mu[1]=1;
  int cnt=0;
  for(int i=2;i<=1000000;i++){
    f[i]=(f[i-1]+f[i-2])%mod;
    g[i]=pow(f[i],mod-2);
    F[i]=1;
    if(pr[i]==0){
      prl[++cnt]=i;
      mu[i]=-1;
    }
    for(int j=1;j<=cnt;j++){
      if(i*prl[j]>1000000){
        break;
      }
      pr[i*prl[j]]=1;
      if(i%prl[j]==0){
        mu[i*prl[j]]=0;
        break;
      }else{
        mu[i*prl[j]]=-mu[i];
      }
    }
  }
  for(int i=1;i<=1000000;i++){
    if(mu[i]==0){
      continue;
    }
    for(int j=1;i*j<=1000000;j++){
      if(mu[i]==1){
        F[i*j]=((long long)(F[i*j]))*(f[j]);
        F[i*j]%=mod;
      }else{
        F[i*j]=((long long)(F[i*j]))*(g[j]);
        F[i*j]%=mod;
      }
    }
  }
  for(int i=2;i<=1000000;i++){
    F[i]*=F[i-1];
    F[i]%=mod;
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  init();
  while(T--){
    int n=read(),m;
    m=read();
    int ans=1;
    for(int i=1,j;i<=std::min(n,m);i=j+1){
      j=std::min(n/(n/i),m/(m/i));
      int tt=(F[j]*pow(F[i-1],mod-2))%mod;
      ans*=(pow(tt,((n/i)*(m/i))));
      ans%=mod;
    } 
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


