#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int mnchu[10000005];
bool is_prime[10000005];
int prcnt[1000005];
int mu[10000005];
int ans2[10000005];
int pw[1000005];
int inv[1000005];
int getnum(int x,int y){
  int ans=1;
  while(x%y==0){
    ans*=y;
    x/=y;
  }
  return ans;
}
int pow(long long x,int y){
  if(y==mod-2&&x<=1e6){
    return inv[x];
  }
  long long ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    y>>=1;
    x*=x;
    x%=mod;
  }
  return ans;
}
int cnt;
signed main(){
  #ifndef ONLINE_JUDGE
	freopen("ntq.in","r",stdin);
	freopen("ntq.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  int k=read();
  mu[1]=1;
  for(int i=2;i<=n;i++){
    if(is_prime[i]==0){
      prcnt[++cnt]=i;
      mu[i]=-1;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*prcnt[j]*i>1e7){
        break;
      }
      is_prime[1ll*prcnt[j]*i]=1;
      mnchu[1ll*prcnt[j]*i]=prcnt[j];
      if(i%prcnt[j]==0){
        mu[1ll*prcnt[j]*i]=0;
        break;
      }
      mu[1ll*prcnt[j]*i]=-mu[i];
    }
  }
  pw[0]=1;
  for(int i=1;i<=1e6;i++){
    pw[i]=1ll*pw[i-1]*(i)%mod;
  }
  inv[1000000]=pow(pw[1000000],mod-2);
  for(int i=1e6-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  for(int i=1;i<=1e6;i++){
    inv[i]=1ll*inv[i]*pw[i-1]%mod;
  }
  for(int i=1;i<=n;i++){
    mu[i]+=mu[i-1];
  }
  int tans=0;
  int ans=0;
  for(int i=1;i<=n;i++){
    if(i==1||(n/i)!=(n/(i-1))||(m/i)!=(m/(i-1))){
      ans=0;
      int ni=n/i;
      int mi=m/i;
      int up=std::min(ni,mi);
      for(int j=1;j<=up;j++){
        int mx=std::min((ni)/((ni)/j),(mi)/((mi)/j));
        ans+=1ll*(mu[mx]-mu[j-1])*(ni/(j))%mod*(mi/(j))%mod;
        ans%=mod;
        j=mx;
      }
    }
    if(mnchu[i]==0){
      int chu=i;
      if(i!=1){
        chu+=1;
      }
      ans2[i]=chu;
      tans+=1ll*ans*pow(chu,k)%mod;
      tans%=mod;
    }else{
      int ret=getnum(i,mnchu[i]);
      long long ret2=(1ll*ret-1)%mod;
      ret2=pow(ret2,mod-2);
      ans2[i]=1ll*ans2[i/mnchu[i]]*ret2%mod;
      ret2=(1ll*ret*mnchu[i]-1)%mod;
      ans2[i]=1ll*ans2[i]*ret2%mod;
      tans+=1ll*ans*pow(ans2[i],k)%mod;
      tans%=mod;
    }
  }
  printf("%d",tans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
