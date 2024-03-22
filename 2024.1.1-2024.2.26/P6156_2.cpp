#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int qpow(int a,int n)
{
  int res=1;
  while(n)
  {
    if(n&1)
      res=1ll*res*a%mod;
    a=1ll*a*a%mod;
    n>>=1;
  }
  return res;
}
int n;
long long k;
const int max_n=5e6+5;
bool mark_p[max_n<<1];
const int max_cnt=664579+5;
int prime[max_cnt],cnt,Pow[max_n<<1],sum_Pow[max_n<<1],F[max_n],G[max_n],sum[max_n],expo[max_n];
inline void init()
{
  int m=n<<1;
  for(int i=2;i<=m;++i)
    mark_p[i]=true;
  Pow[1]=sum_Pow[1]=1;
  for(int i=2;i<=m;++i)
  {
    if(mark_p[i])
    {
      prime[++cnt]=i;
      Pow[i]=qpow(i,k);
    }
    for(int j=1;j<=cnt&&i*prime[j]<=m;++j)
    {
      mark_p[i*prime[j]]=false;
      Pow[i*prime[j]]=1ll*Pow[i]*Pow[prime[j]]%mod;
      if(i%prime[j]==0)
        break;
    }
    sum_Pow[i]=sum_Pow[i-1]+Pow[i];
    sum_Pow[i]-=sum_Pow[i]>=mod?mod:0;
  }
  cnt=0;
  G[1]=1;
  for(int i=2;i<=n;++i)
  {
    if(mark_p[i])
    {
      prime[++cnt]=i;
      G[i]=i-1;
      expo[i]=1;
    }
    for(int j=1;j<=cnt&&i*prime[j]<=n;++j)
    {
      mark_p[i*prime[j]]=false;
      if(i%prime[j]==0)
      {
        if(expo[i]==1)
          G[i*prime[j]]=1ll*G[i/prime[j]]*(mod-prime[j])%mod;
        else
          G[i*prime[j]]=0;
        expo[i*prime[j]]=expo[i]+1;
        break;
      }
      G[i*prime[j]]=1ll*G[i]*G[prime[j]]%mod;
      expo[i*prime[j]]=1;
    }
  }
  for(int i=1;i<=n;++i)
  {
    F[i]=(1ll*F[i-1]+sum_Pow[i<<1]+sum_Pow[(i<<1)-1]-(sum_Pow[i]<<1)+(mod<<1))%mod;
    sum[i]=(sum[i-1]+1ll*G[i]*Pow[i])%mod;
  }
}
int main()
{
  scanf("%d%lld",&n,&k);
  k%=mod-1;
  init();
  int ans=0;
  for(int i=1,j;i<=n;i=j+1)
  {
    int v=n/i;
    j=n/v;
    ans=(ans+1ll*F[v]*(sum[j]-sum[i-1]+mod))%mod;
  }
  printf("%d\n",ans); 
  return 0;
}
