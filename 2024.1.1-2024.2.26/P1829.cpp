#include <iostream>
#include <cstdio>
#define mod 20101009
#define int __int128
inline int read();
int mu[10000005];
bool fin[10000005];
int p[10000005];
int f[10000005];
void init(){
  int tot=0;
  mu[1]=1;
  for(int i=2;i<=10000000;i++){
    if(fin[i]==0){
      p[++tot]=i;
      mu[i]=-1;
    }
    for(int j=1;j<=tot;j++){
      if(i*p[j]>10000000){
        break;
      }
      fin[i*p[j]]=1;
      if(i%p[j]==0){
        mu[i*p[j]]=0;
        break;
      }
      mu[i*p[j]]=-mu[i];
    }
  }
  for(int i=1;i<=10000000;i++){
    mu[i]=(mu[i]*i)%mod*i;
    mu[i]%=mod;
    mu[i]+=mu[i-1];
    mu[i]%=mod;
  }
  return ;
}
int solve2(int n,int m){
  int ans=0;
  for(int i=1,j;i<=std::min(n,m);i=j+1){
    j=std::min(n/(n/i),m/(m/i));
    ans+=((((mu[j]-mu[i-1]+mod)%mod)*((n/i)*(n/i+1)/2))%mod*((m/i)*(m/i+1)/2))%mod;
    ans%=mod;
  }
  return ans;
}
int solve(int n,int m){
  int ans=0;
  for(int i=1,j;i<=std::min(n,m);i=j+1){
    j=std::min((n/(n/i)),(m/(m/i)));
    ans+=((j-i+1)*(i+j)/2*solve2((n/i),(m/i)))%mod;
    ans%=mod;
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=1;
  init();
  for(int i=1;i<=n;i++){
    int a=read();
    int b=read();
    printf("%lld\n",(long long)solve(a,b));
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


