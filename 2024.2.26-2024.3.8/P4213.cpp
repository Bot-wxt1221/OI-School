#include <iostream>
#include <cstdio>
#include <unordered_map>
#define int long long
inline int read();
int shai=1000000;
int pri[1000005];
bool is[1000005];
int phi[1000005];
int mu[1000005];
int cnt;
std::unordered_map<int,int>mu_2;
std::unordered_map<int,int>phi_2;
int getphi(int n){
  if(n<=1000000){
    return phi[n];
  }
  if(phi_2[n]){
    return phi_2[n];
  }
  int ans=0;
  for(int i=2,j;i<=n;i=j+1){
    j=(n/(n/i));
    ans+=getphi(n/i)*(j-i+1);
  }
  return phi_2[n]=((n)*(n+1)/2)-ans;
}
int getmu(int n){
    if(n<=1000000){
    return mu[n];
  }
  if(mu_2[n]){
    return mu_2[n];
  }
  int ans=0;
  for(int i=2,j;i<=n;i=j+1){
    j=(n/(n/i));
    ans+=getmu(n/i)*(j-i+1);
  }
  return mu_2[n]=(1-ans);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  mu[1]=phi[1]=1;
  for(int i=2;i<=shai;i++){
    if(!is[i]){
      pri[++cnt]=i;
      phi[i]=i-1;
      mu[i]=-1;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*i*pri[j]>shai){
        break;
      }
      is[i*pri[j]]=1;
      if(i%pri[j]==0){
        phi[i*pri[j]]=phi[i]*pri[j];
        mu[i*pri[j]]=0;
        break;
      }
      phi[i*pri[j]]=phi[pri[j]]*phi[i];
      mu[i*pri[j]]=-mu[i];
    }
  }
  for(int i=2;i<=shai;i++){
    mu[i]+=mu[i-1];
    phi[i]+=phi[i-1];
  }
  while(T--){
    int n=read();
    printf("%lld %lld\n",getphi(n),getmu(n));
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


