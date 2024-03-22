#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int pow(int a,int b){
  long long ans=1;
  long long cur=a;
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
int invv[5005];
int C(int x,int y){
  int ans=1;
  for(int i=1;i<=y;i++){
    ans*=(x-i+1);
    ans%=mod;
    ans*=invv[i];
    ans%=mod;
  }
  return ans;
}
int string[5005][5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m,k;
  m=read();
  k=read();
  int ans=0;
  string[0][0]=1;
  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++){
      string[i][j]=string[i-1][j-1]+(string[i-1][j]*j%mod);
      string[i][j]%=mod;
    }
  }
  for(int i=1;i<=k;i++){
    invv[i]=pow(i,mod-2);
  }
  int inv=1;
  for(int i=1;i<=k;i++){
    inv*=i;
    inv%=mod;
    ans+=1ll*string[k][i]*inv%mod*C(n,i)%mod*pow(m,n-i)%mod;
    ans%=mod;
  }
  printf("%lld",1ll*ans*pow(pow(m,n),mod-2)%mod);
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


