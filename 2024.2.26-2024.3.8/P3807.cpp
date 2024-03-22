#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[1000005];
int inv[1000005];
int mod;
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
int C2(int a,int b){
  if(a<b){
    return 0;
  }
  return ((::a[a]*pow(::a[b],mod-2))%mod*pow(::a[a-b],mod-2))%mod;
}
int C(int a,int b){
  if(a<=b){
    return 1;
  }
  return (C2(a%mod,b%mod)*C(a/mod,b/mod))%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read(),m,p;
    m=read();
    p=read();
    mod=p;
    a[0]=1;
    for(int i=1;i<=p-1;i++){
      a[i]=(a[i-1]*i)%mod;
    }
    inv[p-1]=pow(a[p-1],mod-2);
    for(int i=p-2;i>=1;i--){
      inv[i]=(inv[i+1]*(i+1))%mod;
    }
    inv[0]=1;
    printf("%lld\n",C(n+m,n));
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


