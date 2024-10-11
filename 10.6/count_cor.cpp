#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
int fac[500005];
int fac2[500005];
int fac3[500005];
int inv3[100005];
int pow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1){
			ans*=x;
			ans%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return ans;
}
int C(int n,int m){
	return ((1ll*fac3[n]*inv3[m]%mod)*(inv3[n-m]))%mod;
}
int ans[10005];
int C2(int n,int m){
	long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=(1ll*inv3[i]*fac3[i-1]%mod);
		ans%=mod;
		ans*=(n-i+1);
		ans%=mod;
	}
	return ans;
}
int ttt[10005];
int xxx[10005];
int yyy[10005];
int dp[5005][5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int x=read();
  int y=read();
  int q=read();
  fac[0]=fac2[0]=1;
  fac3[0]=1;
  for(int i=1;i<=100000;i++){
    fac[i]=1ll*fac[i-1]*x%mod;
    fac2[i]=1ll*fac2[i-1]*y%mod;
    fac3[i]=1ll*fac3[i-1]*i%mod;
  }
  inv3[100000]=pow(fac3[100000],mod-2);
  for(int i=100000-1;i>=0;i--){
    inv3[i]=(1ll*inv3[i+1])*(i+1)%mod;
  }
	if(x==y){
		for(int i=1;i<=q;i++){
			int a=read();
			int b=read();
			if(::ans[a+b]){
				printf("%lld\n",::ans[a+b]);
				continue;
			}
			int ans=C2(n+1,a+b+1);
			ans=(1ll*ans*pow(x,n-a-b))%mod;
			::ans[a+b]=ans;
			printf("%lld\n",ans);
		}
		return 0;
	}
  ttt[0]=1;
  for(int i=1;i<=std::min(n+1,10000ll);i++){
    ttt[i]=ttt[i-1]*pow(i,mod-2)%mod*(n-i+2)%mod;
    xxx[i]=pow(x,n-i+1);
    yyy[i]=pow(y,n-i+1);
  }
  xxx[0]=pow(x,n+1);
  yyy[0]=pow(y,n+1);
  int invk=pow(y-x,mod-2);
  for(int i=0;i<=std::min(n,5000ll);i++){
    int tt=ttt[i];
    for(int j=0;i+j<=n&&j<=5000;j++){
      int k=y-x;
      int more=0;
      if(i!=0){
        more+=dp[i-1][j];
        more%=mod;
      }else{
        more+=ttt[j]*yyy[j]%mod;
        more%=mod;
      }
      if(j!=0){
        more-=dp[i][j-1];
        more%=mod;
      }else{
        more-=tt*xxx[i]%mod;
        more%=mod;
      }
      dp[i][j]=more*invk%mod;
    }
  }
  for(int i=1;i<=q;i++){
    int a=read();
    int b=read();
    printf("%lld\n",(dp[a][b]+mod)%mod);
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
