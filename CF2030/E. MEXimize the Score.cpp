#include <iostream>
#include <cstdio>
#include <vector>
#define int __int128
#define mod 998244353
inline int read();
int cnt[200005];
std::vector<int>sum[200005],num[200005];
int fac[200005*2];
int inv[200005*2];
int C(int n,int m){
  return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int pow(int n,int m){
  int ans=1;
  while(m){
    if(m&1){
      ans*=n;
      ans%=mod;
    }
    n*=n;
    n%=mod;
    m>>=1;
  }
  return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  fac[0]=1;
  for(int i=1;i<=400000;i++){
    fac[i]=fac[i-1]*i%mod;
  }
  inv[400000]=pow(fac[400000],mod-2);
  for(int i=399999;i>=0;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      cnt[i-1]=0;
    }
    for(int i=1;i<=n;i++){
      cnt[read()]++;
    }
    for(int i=0;i<n;i++){
      sum[i].clear();
      num[i].clear();
      sum[i].resize(cnt[i]+5);
      num[i].resize(cnt[i]+5);
    }
    int sufnum=0;
    int sufsum=0;
    for(int i=0;i<=cnt[0];i++){
      sum[0][i]=num[0][i]=C(cnt[0],i);
      sum[0][i]*=i;
      sum[0][i]%=mod;
      sufnum+=num[0][i];
      sufnum%=mod;
      sufsum+=sum[0][i];
      sufsum%=mod;
    }
    for(int i=1;i<n;i++){
      int curans=0;
      for(int j=0;j<=cnt[i];j++){
        curans+=C(cnt[i],j);
        curans%=mod;
      }
      for(int j=0;j<=std::min(cnt[i],cnt[i-1]);j++){
        sufnum-=num[i-1][j];
        sufnum%=mod;
        sufsum-=sum[i-1][j];
        sufsum%=mod;
        num[i][j]=sufnum*C(cnt[i],j)%mod;
        num[i][j]+=curans*num[i-1][j]%mod;
        num[i][j]%=mod;
        sum[i][j]=sufsum*C(cnt[i],j)%mod;
        sum[i][j]%=mod;
        sum[i][j]+=curans*sum[i-1][j]%mod;
        sum[i][j]%=mod;
        sum[i][j]+=num[i][j]*(j)%mod;
        sum[i][j]%=mod;
        curans-=C(cnt[i],j);
        curans%=mod;
      }
      sufnum=0;
      sufsum=0;
      for(int j=0;j<=cnt[i];j++){
        sufnum+=num[i][j];
        sufsum+=sum[i][j];
        sufnum%=mod;
        sufsum%=mod;
      }
    }
    int tt=0;
    for(int i=0;i<=cnt[n-1];i++){
      tt+=sum[n-1][i];
      tt%=mod;
    }
    tt+=mod;
    tt%=mod;
    printf("%lld\n",(long long)tt);
  }
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
