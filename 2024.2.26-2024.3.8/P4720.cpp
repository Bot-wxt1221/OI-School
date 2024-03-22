#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();
int p;
int pow(int a,int b,int mod){
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
int exgcd(int a,int b,int &x,int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int ret=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ret;
}

int inv(int a,int p){
  int x1,x2;
  int ret=exgcd(a,p,x1,x2);
  if(ret!=1){
    return -1;
  }
  return (x1+p)%p;
}
int calc(int n,int p,int pk){
  if(n==0){
    return 1;
  }
  int ans=1;
  for(int i=1;i<=pk;i++){
    if(i%p){
      ans*=i;
      ans%=pk;
    }
  }
  ans=pow(ans,n/pk,pk);
  for(int i=1;i<=n%pk;i++){
    if(i%p){
      ans*=i;
      ans%=pk;
    }
  }
  return ans*calc(n/p,p,pk)%pk;
}
int C(int n,int m,int p,int pk){
  if(n==0||m==0||m==n){
    return 1;
  }
  if(n<m){
    return 0;
  }
  int cnt=0;
  int tt=n;
  while(tt){
    tt/=p;
    cnt+=tt;
  }
  tt=m;
  while(tt){
    tt/=p;
    cnt-=tt;
  }
  tt=n-m;
  while(tt){
    tt/=p;
    cnt-=tt;
  }
  return ((((calc(n,p,pk)*inv(calc(m,p,pk),pk))%pk)*(inv(calc(n-m,p,pk),pk)%pk)%pk)*pow(p,cnt,pk))%pk;
}
int b[1000005];
int c[1000005];
int d[1000005];
int te[1000005];
int CRT(int tot){
  int M=1;
  int ans=0;
  for(int i=1;i<=tot;i++){
    M*=c[i];
  }
  for(int i=1;i<=tot;i++){
    d[i]=inv(M/c[i],c[i]);
  }
  for(int i=1;i<=tot;i++){
    ans+=(b[i])*(M/c[i])*d[i];
  }
  return ((ans%M)+M)%M;
}
int exlucas(int n,int m,int p){
  if(n==m){
    return 1%p;
  }
  int sq=std::sqrt((long long)(p));
  int tot=0;
  for(int i=2;i<=sq;i++){
    int pk=1;
    while(p%i==0){
      p/=i;
      pk*=i;
    }
    if(pk>1){
      b[++tot]=C(n,m,i,pk);
      c[tot]=pk;
    }
  }
  if(p>1){
    b[++tot]=C(n,m,p,p);
    c[tot]=p;
  }
  return CRT(tot);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  p=read();
  printf("%lld",exlucas(n,m,p));
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


