#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
inline int read();
int a[50005];
class Poly{
  public:
    int ci,xi[50005];
};
Poly operator * (Poly a,Poly b){
  Poly ans;
  memset(ans.xi,0,sizeof(ans.xi));
  ans.ci=a.ci+b.ci;
  for(int i=0;i<=a.ci;i++){
    for(int j=0;j<=b.ci;j++){
      ans.xi[i+j]+=(a.xi[i]*b.xi[j])%mod;
      ans.xi[i+j]%=mod;
    }
  }
  return ans;
}
Poly aa;
Poly bb;
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

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),k;
  k=read();
  aa.ci=0;
  aa.xi[0]=1;
  int ans=1;
  for(int i=1;i<=n;i++){
    a[i]=read();
    ans*=a[i];
    ans%=mod;
    bb.ci=1;
    bb.xi[0]=a[i];
    bb.xi[1]=-1;
    aa=aa*bb;
  }
  int tt=1;
  for(int j=0;j<=std::min(k,n+5);j++){
    ans-=pow(pow(n,j),mod-2)*tt%mod*aa.xi[j]%mod;
    ans%=mod;
    tt*=(k-j);
    tt%=mod;
  }
  printf("%lld",(ans+mod)%mod);
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

