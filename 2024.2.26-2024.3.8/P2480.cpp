#include <cinttypes>
#include <iostream>
#include <cstdio>
#define int long long
#define mod 999911658
inline int read();
int a[1000005];
int p[10]={0,2,3,4679,35617};
int frac[1000005];
int inv[1000005];
int CRT(int );
int pow(int ,int ,int );
int C(int ,int );
int Lucas(int ,int ,int );
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),g;
  g=read();
  if(g==mod+1){
    printf("0");
    return 0;
  }
  for(int k=1;k<=4;k++){
    frac[1]=1;
    frac[0]=1;
    for(int i=2;i<p[k];i++){
      frac[i]=(frac[i-1]*i)%p[k];
    }
    inv[0]=1;
    inv[p[k]-1]=pow(p[k]-1,p[k]-2,p[k]);
    for(int i=p[k]-2;i>=1;i--){
      inv[i]=(inv[i+1]*(i+1))%p[k];
    }
    for(int i=1;i*i<=n;i++){
      if(n%i==0){
        a[k]+=(Lucas(n,i,p[k]));
        a[k]%=p[k];
        if(n/i!=i){
          a[k]+=(Lucas(n,n/i,p[k]));
          a[k]%=p[k];
        }
      }
    }
  }
  printf("%lld",pow(g,CRT(4),mod+1));
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
int CRT(int n){
  int val=0;
  for(int i=1;i<=n;i++){
    val+=(((a[i]*(mod/p[i]))%mod)*pow(mod/p[i],p[i]-2,p[i]))%mod;
    val%=mod;
  }
  return val;
}
int pow(int a,int b,int p){
  int ans=1;
  int cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=p;
    }
    cur*=cur;
    cur%=p;
    b/=2;
  }
  return ans;
}
int C(int n,int m,int p){
  if(n<m){
    return 0;
  }
  return (((frac[n])*inv[m])%p*inv[n-m])%p;
}
int Lucas(int n,int m,int p){
  if(n<=m){
    return 1;
  }
  return Lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
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


