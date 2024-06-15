#include <cinttypes>
#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int a[200005];
int sum[200005];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (1ll*tt*tt)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    sum[n+1]=0;
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    for(int i=n;i>=1;i--){
      sum[i]=sum[i+1]+a[i];
    }
    a[n+1]=0;
    int ans=0;
    int pre=0;
    for(int i=1;i<=n+1;i++){
      ans=std::max(ans,std::abs(pre)+sum[i]);
      pre+=a[i];
    }
    pre=0;
    int cnt=0;
    int ad2=0;
    int ad=0;
    int ad3=0;
    int ad4=0;
    for(int i=1;i<=n+1;i++){
      bool yes=0;
      if(ans==std::abs(pre)+sum[i]){
        yes=1;
        cnt+=(pow(2,ad2-ad)-(ad==1?1:0))*pow(2,ad4-ad2-ad3+ad)%mod*pow(2,(std::max(n-i+1,0ll)))%mod;
        cnt%=mod;
        cnt%=mod;
      }
      if(i==1&&yes){
        break;
      }
      if(pre>=0&&i!=1&&yes&&ad!=1){
        ad++;
      }
      if(pre>=0&&i!=1&&ad!=1){
        ad2++;
      }
      if(pre>=0&&i!=1&&yes){
        ad3++;
      }
      if(pre>=0&&i!=1){
        ad4++;
      }
      pre+=a[i];
    }
    printf("%lld\n",cnt);
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
