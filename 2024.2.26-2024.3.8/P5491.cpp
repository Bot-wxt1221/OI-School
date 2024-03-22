#include <iostream>
#include <cstdio>
#include <random>
#define int long long
inline int read();
std::mt19937 ran;
class complex{
public:
  int real,imag;
  complex(int a=0,int b=0){
    real=a;
    imag=b;
    return ;
  }
};
int p;
int i2;
const complex operator * (const complex &a,const complex &b){
  complex ans(0,0);
  ans.real=a.real*b.real;
  ans.real%=p;
  ans.real+=((a.imag*b.imag)%p*i2)%p;
  ans.real%=p;
  ans.real+=p;
  ans.real%=p;
  ans.imag+=(a.imag*b.real)%p;
  ans.imag%=p;
  ans.imag+=(b.imag*a.real)%p;
  ans.imag%=p;
  return ans;
}
complex pow(complex a,int b,int mod){
  complex ans(1,0);
  complex cur=a;
  while(b){
    if(b%2==1){
      ans=ans*cur;
      ans.real=ans.real%mod;
      ans.imag=ans.imag%mod;
    }
    cur=cur*cur;
    cur.real=cur.real%mod;
    cur.imag=cur.imag%mod;
    b/=2;
  }
  return ans;
}
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
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    p=read();
    if(n==0){
      printf("0\n");
      continue;
    }
    if(pow(n,(p-1)/2,p)==p-1){
      printf("Hola!\n");
      continue;
    }
    int a;
    while(1){
      a=ran()%p;
      int b=(((a*a)%p-n)%p+p)%p;
      i2=b;
      if(pow(b,(p-1)/2,p)==p-1){
        break;
      }
    }
    complex base(a,1);
    int ans1=pow(base,(p+1)/2,p).real;
    int ans2=p-ans1;
    if(ans1>ans2){
      std::swap(ans1,ans2);
    }
    if(ans1==ans2){
      printf("%lld\n",ans1);
    }else{
      printf("%lld %lld\n",ans1,ans2);
    }
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


