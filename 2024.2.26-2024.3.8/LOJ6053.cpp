#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int pow(int a,int b){
  int ans=1;
  int cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=mod;
    }
    cur*=cur;
    cur%=mod;
    b/=2;
  }
  return ans;
}
int prime[5000005];
int nprime[5000005];
int cnt=0;
bool is[5000005];
int sum1[5000005];
int sum2[5000005];
int g1[5000005];
int g2[5000005];
int to1[5000005],to2[5000005];
int n;
int ans(int x,int y){
  if(x<=1){
    return 0;
  }
  if(prime[y]>=x){
    return 0;
  }
  int k;
  if(x>100000){
    k=to2[n/x];
  }else{
    k=to1[x];
  }
  int ret=((((g2[k]-g1[k])%mod+mod)%mod)-(((sum2[y]-sum1[y])%mod)+mod))%mod;
  if(k==1){
    ret+=2;
  }
  ret+=mod;
  ret%=mod;
  for(int i=y+1;i<=cnt&&prime[i]*prime[i]<=x;i++){
    int cp=prime[i];
    for(int e=1;cp<=x;e++){
      int tx=(cp)%mod;
      ret+=(((prime[i])^(e))%mod)*(ans(x/cp,i)+(e!=1))%mod;
      ret%=mod;
      ret+=mod;
      ret%=mod;
      cp*=prime[i];
    }
  }
  return ret;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  for(int i=2;i<=200000+1000;i++){
    if(is[i]==0){
      prime[++cnt]=i;
      sum1[cnt]=sum1[cnt-1]+1;
      sum1[cnt]%=mod;
      sum2[cnt]=sum2[cnt-1]+((i%mod));
      sum2[cnt]%=mod;
    }
    for(int j=1;j<=cnt;j++){
      if(((__int128)(prime[j]))*i>201000){
        break;
      }
      is[prime[j]*i]=1;
      if(i%prime[j]==0){
        break;
      }
    }
  }
  int tot=0;
  for(int l=1,r;l<=n;l=r+1){
    r=(n)/(n/l);
    nprime[++tot]=n/l;
    g1[tot]=nprime[tot]%mod;
    g2[tot]=((g1[tot])*(g1[tot]+1)/2)%mod;
    g2[tot]+=mod-1;
    g2[tot]%=mod;
    g1[tot]--;
    g1[tot]+=mod;
    g1[tot]%=mod;
    if(nprime[tot]<=100000){
      to1[nprime[tot]]=tot;
    }else{
      to2[n/nprime[tot]]=tot;
    }
  }
  for(int i=1;i<=cnt;i++){
    for(int j=1;j<=tot&&prime[i]*prime[i]<=nprime[j];j++){
      int k=nprime[j]/prime[i];
      if(k>100000){
        k=to2[n/k];
      }else{
        k=to1[k];
      }
      g1[j]-=(g1[k]-sum1[i-1]+mod)%mod;
      g1[j]%=mod;
      g1[j]+=mod;
      g1[j]%=mod;
      g2[j]-=(prime[i])%mod*(g2[k]-sum2[i-1]+mod)%mod;
      g2[j]%=mod;
      g2[j]+=mod;
      g2[j]%=mod;
    }
  }
  printf("%lld",(ans(n,0)+1)%mod);
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


