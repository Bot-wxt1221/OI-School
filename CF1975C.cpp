#include <cstddef>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <complex>
#include <random>
#include <cassert>
#define CONFIG_POLY_DATA int
//#define CONFIG_FFT is not set
#define mod 998244353
bool escape;
#define g 3
#define invg 332748118
#define CONFIG_NTT y
inline int pow(int a,int k){
  long long res=1;
  while(k){
    if(k&1){
      #ifdef mod
      res=1ll*res*a%mod;
      #else
      res*=a;
      #endif
    }
    #ifdef mod
    a=1ll*a*a%mod;
    #else
    a*=a;
    #endif
    k>>=1;
  }
  return res;
}
namespace Poly{
class Poly{
  public:
    CONFIG_POLY_DATA xi[2500005];
    int ci;
    Poly(int n){
      ci=n;
      return ;
    }
    Poly(){
      ci=0;
      xi[0]=0;
      return ;
    }
    Poly & operator = (const Poly &a){
      ci=std::min(a.ci,2500000);
      for(int i=0;i<=ci;i++){
        xi[i]=a.xi[i];
      }
      return *this;
    }
};
double PI;
namespace warn{
  #ifdef CONFIG_FFT
  static void fft(std::complex <double> *f,int lim,int type,int *r){
    for(int i=0;i<=lim;i++){
      if(i<r[i]){
        std::swap(f[i],f[r[i]]);
      }
    }
    for(int len=2;len<=lim;len<<=1){
      std::complex <double> omega(std::cos(PI*2/len),std::sin(type*PI*2/len));
      for(int i=0;i<=lim;i+=len){
        std::complex<double>wn1(1,0);
        for(int k=i;k<len/2+i;k++,wn1*=omega){
          std::complex<double>x=f[k],y=f[k+len/2]*wn1;
          f[k]=x+y;
          f[k+len/2]=x-y;
        }
      }
    }
    return ;
  }
  #endif
  #ifdef CONFIG_NTT
int cntttt=0;
  static void ntt(int *a,int lim,int type,int *r){
    for(int i=0;i<=lim;i++){
      if(i<r[i]){
        std::swap(a[i],a[r[i]]);
      }
    }
    for(int i=1;i<lim;i<<=1){
      int omega=pow(type?g:invg,(mod-1)/(i<<1));
      for(int j=0;j<lim;j+=(i<<1)){
        int g0=1;
        for(int k=0;k<i;k++){
          int x=a[j+k];
          int y=1ll*a[i+j+k]*g0%mod;
          a[j+k]=(x+y)%mod;
          a[i+j+k]=(((x-y)%mod)+mod)%mod;
          g0=(1ll*g0*omega)%mod;
        }
      }
    }
    return ;
  }
  #endif
  #ifdef CONFIG_NTT
  static void fwt_or(int *a,int lim,int type){
    for(int x=2;x<=lim;x<<=1){
      int k=x>>1;
      for(int i=0;i<lim;i+=x){
        for(int j=0;j<k;j++){
          a[i+j+k]+=((1ll*a[i+j])*type)%mod;
          a[i+j+k]%=mod;
        }
      }
    }
    return ;
  }
  static void fwt_and(int *a,int lim,int type){
    for(int x=2;x<=lim;x<<=1){
      int k=x>>1;
      for(int i=0;i<lim;i+=x){
        for(int j=0;j<k;j++){
          a[i+j]+=(a[i+j+k]*type)%mod;
          a[i+j]%=mod;
        }
      }
    }
    return ;
  }
  static void fwt_xor(int *a,int lim,int type){
    for(int x=2;x<=lim;x<<=1){
      int k=x>>1;
      for(int i=0;i<lim;i+=x){
        for(int j=0;j<k;j++){
          a[i+j]+=a[i+j+k];
          a[i+j]%=mod;
          a[i+j+k]=(a[i+j]-a[i+j+k]*2)%mod;
          a[i+j+k]%=mod;
          a[i+j]=(1ll*a[i+j]*type)%mod;
          a[i+j+k]=(1ll*a[i+j+k]*type)%mod;
        }
      }
    }
    return ;
  }
  #endif
  #ifdef CONFIG_FFT
  static void fwt_or(double *a,int lim,int type){
    for(int x=2;x<=lim;x<<=1){
      int k=x>>1;
      for(int i=0;i<lim;i+=x){
        for(int j=0;j<k;j++){
          a[i+j+k]+=(a[i+j]*type);
        }
      }
    }
    return ;
  }
  static void fwt_and(double *a,int lim,int type){
    for(int x=2;x<=lim;x<<=1){
      int k=x>>1;
      for(int i=0;i<lim;i+=x){
        for(int j=0;j<k;j++){
          a[i+j]+=(a[i+j+k]*type);
        }
      }
    }
    return ;
  }
  static void fwt_xor(double *a,int lim,double type){
    for(int x=2;x<=lim;x<<=1){
      int k=x>>1;
      for(int i=0;i<lim;i+=x){
        for(int j=0;j<k;j++){
          a[i+j]+=a[i+j+k];
          a[i+j+k]=(a[i+j]-a[i+j+k]*2);
          a[i+j]*=type;
          a[i+j+k]*=type;
        }
      }
    }
    return ;
  }
  #endif
}
#ifdef CONFIG_FFT
Poly operator - (Poly a,const Poly &b){
  for(int i=a.ci+1;i<=b.ci;i++){
    a.xi[i]=0;
  }
  a.ci=std::max(a.ci,b.ci);
  for(int i=0;i<=a.ci;i++){
    a.xi[i]-=b.xi[i];
  }
  return a;
}
Poly operator + (Poly a,const Poly &b){
  for(int i=a.ci+1;i<=b.ci;i++){
    a.xi[i]=0;
  }
  a.ci=std::max(a.ci,b.ci);
  for(int i=0;i<=a.ci;i++){
    a.xi[i]+=b.xi[i];
  }
  return a;
}
Poly xor_cheng(Poly &a,Poly &b){
  int cnt=std::max(a.ci,b.ci);
  int ncnt=1;
  while(ncnt<cnt){
    ncnt*=2;
  }
  cnt=ncnt;
  CONFIG_POLY_DATA *aa=new CONFIG_POLY_DATA [cnt+5];
  CONFIG_POLY_DATA *bb=new CONFIG_POLY_DATA [cnt+5];
  for(int i=1;i<=a.ci;i++){
    aa[i-1]=a.xi[i];
  }
  for(int i=a.ci;i<=cnt;i++){
    aa[i]=0;
  }
  for(int i=1;i<=b.ci;i++){
    bb[i-1]=b.xi[i];
  }
  for(int i=b.ci;i<=cnt;i++){
    bb[i]=0;
  }
  warn::fwt_xor(aa,cnt,1);
  warn::fwt_xor(bb,cnt,1);
  for(int i=0;i<cnt;i++){
    aa[i]*=bb[i];
  }
  warn::fwt_xor(aa,cnt,(mod+1)/2);
  Poly ans;
  ans.ci=cnt;
  for(int i=1;i<=cnt;i++){
    ans.xi[i]=aa[i-1];
  }
  delete[] aa;
  delete[] bb;
  return ans;
}
Poly or_cheng(Poly &a,Poly &b){
  int cnt=std::max(a.ci,b.ci);
  int ncnt=1;
  while(ncnt<cnt){
    ncnt*=2;
  }
  cnt=ncnt;
  CONFIG_POLY_DATA *aa=new CONFIG_POLY_DATA [cnt+5];
  CONFIG_POLY_DATA *bb=new CONFIG_POLY_DATA [cnt+5];
  for(int i=1;i<=a.ci;i++){
    aa[i-1]=a.xi[i];
  }
  for(int i=a.ci;i<=cnt;i++){
    aa[i]=0;
  }
  for(int i=1;i<=b.ci;i++){
    bb[i-1]=b.xi[i];
  }
  for(int i=b.ci;i<=cnt;i++){
    bb[i]=0;
  }
  warn::fwt_or(aa,cnt,1);
  warn::fwt_or(bb,cnt,1);
  for(int i=0;i<cnt;i++){
    aa[i]=(bb[i]*aa[i]);
  }
  warn::fwt_or(aa,cnt,-1);
  Poly ans;
  ans.ci=cnt;
  for(int i=1;i<=cnt;i++){
    ans.xi[i]=(aa[i-1]);
  }
  delete[] aa;
  delete[] bb;
  return ans;
}
Poly and_cheng(Poly &a,Poly &b){
  int cnt=std::max(a.ci,b.ci);
  int ncnt=1;
  while(ncnt<cnt){
    ncnt*=2;
  }
  cnt=ncnt;
  CONFIG_POLY_DATA *aa=new CONFIG_POLY_DATA [cnt+5];
  CONFIG_POLY_DATA *bb=new CONFIG_POLY_DATA [cnt+5];
  for(int i=1;i<=a.ci;i++){
    aa[i-1]=a.xi[i];
  }
  for(int i=a.ci;i<=cnt;i++){
    aa[i]=0;
  }
  for(int i=1;i<=b.ci;i++){
    bb[i-1]=b.xi[i];
  }
  for(int i=b.ci;i<=cnt;i++){
    bb[i]=0;
  }
  warn::fwt_and(aa,cnt,1);
  warn::fwt_and(bb,cnt,1);
  for(int i=0;i<cnt;i++){
    aa[i]=(bb[i]*aa[i]);
  }
  warn::fwt_and(aa,cnt,-1);
  Poly ans;
  ans.ci=cnt;
  for(int i=1;i<=cnt;i++){
    ans.xi[i]=(aa[i-1]);
  }
  delete[] aa;
  delete[] bb;
  return ans;
}
Poly FFT(const Poly &a,const Poly &b){
  PI=acos(-1);
  int tol=1;
  int k=0;
  while(tol<std::min(a.ci+b.ci+2,1000002)){
    tol<<=1;
    k++;
  }
  int *r=new int[2*tol+5];
  r[0]=0;
  std::complex <double> *aa=new std::complex<double> [2*tol+5],*bb=new std::complex<double> [2*tol+5];
  for(int i=0;i<=a.ci;i++){
    aa[i]=a.xi[i];
  }
  for(int i=0;i<=b.ci;i++){
    bb[i]=b.xi[i];
  }
  Poly ans(tol+5);
  ans.ci=0;
  for(int i=0;i<=tol;i++){
    r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
  }
  warn::fft(aa,tol,1,r);
  warn::fft(bb,tol,1,r);
  for(int i=0;i<=tol;i++){
    aa[i]*=bb[i];
  }
  warn::fft(aa,tol,-1,r);
  for(int i=0;i<=a.ci+b.ci;i++){
    ans.xi[i]=(aa[i].real()/tol+0.5);
  }
  ans.ci=a.ci+b.ci;
  delete[] r;
  delete[] aa;
  delete[] bb;
  return ans;
}
#endif
#ifdef CONFIG_NTT
Poly operator - (Poly a,const Poly &b){
  for(int i=a.ci+1;i<=b.ci;i++){
    a.xi[i]=0;
  }
  a.ci=std::max(a.ci,b.ci);
  for(int i=0;i<=a.ci;i++){
    a.xi[i]-=b.xi[i];
    a.xi[i]%=mod;
    a.xi[i]+=mod;
    a.xi[i]%=mod;
  }
  return a;
}
Poly operator + (Poly a,const Poly &b){
  for(int i=a.ci+1;i<=b.ci;i++){
    a.xi[i]=0;
  }
  a.ci=std::max(a.ci,b.ci);
  for(int i=0;i<=a.ci;i++){
    a.xi[i]+=b.xi[i];
    a.xi[i]%=mod;
  }
  return a;
}
CONFIG_POLY_DATA aa[4500005],bb[4500005],r[4500005];
Poly ans;
int cntt=0;
Poly& NTT(const Poly &a,const Poly &b){
  cntt+=a.ci;
  int tol=1;
  cntt+=a.ci;
  int k=0;
  while(tol<std::min(a.ci+2,2000002)){
    tol<<=1;
    k++;
  } 
  ans.ci=0;
  r[0]=0;
  for(int i=0;i<=a.ci;i++){
    aa[i]=a.xi[i];
  }
  for(int i=a.ci+1;i<=tol*2;i++){
    aa[i]=0;
  }
  for(int i=0;i<=b.ci;i++){
    bb[i]=b.xi[i];
  }
  for(int i=b.ci+1;i<=tol*2;i++){
    bb[i]=0;
  }
  for(int i=0;i<=tol;i++){
    r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
  }
  warn::ntt(aa,tol,1,r);
  warn::ntt(bb,tol,1,r);
  for(int i=0;i<=tol;i++){
    aa[i]=1ll*aa[i]*bb[i]%mod;
  }
  warn::ntt(aa,tol,0,r);
  int inv=pow(tol,mod-2);
  ans.ci=std::min(a.ci+b.ci,2500000);
  for(int i=0;i<=std::min(a.ci+b.ci,2500000);i++){
    ans.xi[i]=1ll*aa[i]*inv%mod;
  }
  return ans;
}
#endif
Poly aaa;
const Poly& operator * (const Poly &a,const Poly &b){
  #ifdef CONFIG_FFT
  return FFT(a,b);
  #endif
  #ifdef CONFIG_NTT
  return NTT(a,b);
  #endif
}
#ifdef CONFIG_NTT
namespace modd{
  std::mt19937 ran;
  class complex{
  public:
    long long real,imag;
    complex(int a=0,int b=0){
      real=a;
      imag=b;
      return ;
    }
  };
  inline int pow(int a,int k){
    long long res=1;
    while(k){
      if(k&1){
        #ifdef mod
        res=1ll*res*a%mod;
        #else
        res*=a;
        #endif
      }
      #ifdef mod
      a=1ll*a*a%mod;
      #else
      a*=a;
      #endif
      k>>=1;
    }
    return res;
  }
  int i2;
  const complex operator * (const complex &a,const complex &b){
    complex ans(0,0);
    ans.real=a.real*b.real;
    ans.real%=mod;
    ans.real+=((a.imag*b.imag)%mod*i2)%mod;
    ans.real%=mod;
    ans.real+=mod;
    ans.real%=mod;
    ans.imag+=(a.imag*b.real)%mod;
    ans.imag%=mod;
    ans.imag+=(b.imag*a.real)%mod;
    ans.imag%=mod;
    return ans;
  }
  complex pow(complex a,int b){
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
  int sqrtt(long long n){
    if(n==0){
      return 0;
    }
    if(pow(n,(mod-1)/2)==mod-1){
      return -1;
    }
    long long a;
    while(1){
      a=ran()%mod;
      long long b=(((a*a)%mod-n)%mod+mod)%mod;
      i2=b;
      if(pow(b,(mod-1)/2)==mod-1){
        break;
      }
    }
    complex base(a,1);
    long long ans1=pow(base,(mod+1)/2).real;
    long long ans2=mod-ans1;
    return std::min(ans1,ans2);
  }
};
static void inv_work(Poly &b,Poly &a,int len){
  if(len==1){
    b.xi[0]=pow(a.xi[0],mod-2);
    b.ci=0;
    return ;
  }
  inv_work(b,a,((len+1)>>1));
  int tt=a.ci;
  a.ci=len-1;
  int tol=1;
  int k=0;
  while(tol<(len*2)){
    tol<<=1;
    k++;
  }
  ans.ci=0;
  int *r=new int[2*tol+5];
  r[0]=0;
  int *aa=new CONFIG_POLY_DATA [2*tol+5],*bb=new CONFIG_POLY_DATA[2*tol+5];
  for(int i=0;i<=a.ci;i++){
    aa[i]=a.xi[i];
  }
  for(int i=a.ci+1;i<=tol*2;i++){
    aa[i]=0;
  }
  for(int i=0;i<=b.ci;i++){
    bb[i]=b.xi[i];
  }
  for(int i=b.ci+1;i<=tol*2;i++){
    bb[i]=0;
  }
  for(int i=0;i<=tol;i++){
    r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
  }
  warn::ntt(aa,tol,1,r);
  warn::ntt(bb,tol,1,r);
  for(int i=0;i<=tol;i++){
    aa[i]=1ll*((((2-1ll*aa[i]*bb[i])%mod)+mod)%mod)*bb[i]%mod;
  }
  warn::ntt(aa,tol,0,r);
  int inv=pow(tol,mod-2);
  ans.ci=len-1;
  for(int i=0;i<len;i++){
    ans.xi[i]=1ll*aa[i]*inv%mod;
  }
  delete [] aa;
  delete [] bb;
  delete [] r;
  b=ans;
  a.ci=tt;
  return ;
}
Poly inv(Poly &a){
  Poly ans(a.ci);
  inv_work(ans,a,a.ci+1);
  return ans;
}
void Dao(Poly &b){
  if(b.ci==0){
    b.xi[0]=0;
    b.ci=0;
    return ;
  }
  for(int i=1;i<=b.ci;i++){
    b.xi[i-1]=(1ll*(i)*b.xi[i])%mod;
  }
  b.ci--;
  return ;
}
void Ji(Poly &b){
  b.ci++;
  for(int i=b.ci;i>=0;i--){
    b.xi[i+1]=(1ll*(pow(i+1,mod-2))*b.xi[i])%mod;
  }
  b.xi[0]=0;
  return ;
}
Poly ln(Poly a){
  Poly b=inv(a);
  Dao(a);
  b=b*a;
  for(int i=a.ci+2;i<=b.ci;i++){
    b.xi[i]=0;
  }
  b.ci=std::min(b.ci,a.ci+1);
  Ji(b);
  return b;
}
Poly a,temp,temp2;
void exp_work(Poly &ans,Poly &b,int len){
  if(len==1){
    ans.ci=0;
    ans.xi[0]=1;
    return ;
  }
  exp_work(ans,b,(len+1)>>1);
  for(int i=ans.ci+1;i<=(len)*2;i++){
    ans.xi[i]=0;
  }
  ans.ci=len*2;
  a=ln(ans);
  temp=Poly(len-1);
  temp.xi[0]=1;
  for(int i=0;i<len;i++){
    temp.xi[i]+=b.xi[i];
    temp.xi[i]%=mod;
  }
  for(int i=0;i<len;i++){
    temp.xi[i]+=mod-a.xi[i];
    temp.xi[i]%=mod;
  }
  ans=temp*ans;
  for(int i=len;i<=ans.ci;i++){
    ans.xi[i]=0;
  }
  ans.ci=len-1;
  return ;
}
Poly exp(Poly &a){
  Poly ans(a.ci);
  exp_work(ans,a,a.ci+1);
  return ans;
}
void sqrt_work(Poly &ans,Poly &a,int len){
  if(len==1){
    ans.ci=0;
    ans.xi[0]=modd::sqrtt(a.xi[0]);
    return ;
  }
  sqrt_work(ans,a,(len+1)/2);
  temp2=ans*ans;
  for(int i=0;i<=ans.ci;i++){
    ans.xi[i]*=2;
    ans.xi[i]%=mod;
  }
  for(int i=ans.ci+1;i<=len;i++){
    ans.xi[i]=0;
  }
  ans.ci=len-1;
  temp=inv(ans);
  for(int i=0;i<=temp.ci;i++){
    temp.xi[i]=(1ll*temp.xi[i])%mod;
    temp2.xi[i]+=a.xi[i];
    temp2.xi[i]%=mod; 
  }
  temp2.ci=len-1;
  ans=temp*temp2;
  for(int i=len;i<=ans.ci;i++){
    ans.xi[i]=0;
  }
  ans.ci=len-1;
  return ;
}
Poly sqrt(Poly &a){
  Poly ans(a.ci);
  sqrt_work(ans,a,a.ci+1);
  return ans;
}
Poly chu(Poly &F,Poly G,Poly &Lf){
  for(int i=0;i<=F.ci;i++){
    if(F.ci-i>i){
      std::swap(F.xi[i],F.xi[F.ci-i]);
    }
  }
  a=G;
  for(int i=0;i<=G.ci;i++){
    if(G.ci-i>i){
      std::swap(G.xi[i],G.xi[G.ci-i]);
    }
  }
  int bk=G.ci;
  for(int i=F.ci-G.ci+1;i<=G.ci;i++){
    G.xi[i]=0;
  }
  G.ci=F.ci-G.ci;
  G=inv(G);
  temp=F*G;
  for(int i=F.ci-bk+1;i<=a.ci;i++){
    temp.xi[i]=0;
  }
  temp.ci=std::min(temp.ci,F.ci-bk);
  for(int i=0;i<=temp.ci;i++){
    if(temp.ci-i>i){
      std::swap(temp.xi[i],temp.xi[temp.ci-i]);
    }
  }
  for(int i=0;i<=F.ci;i++){
    if(F.ci-i>i){
      std::swap(F.xi[i],F.xi[F.ci-i]);
    }
  }
  for(int i=0;i<=G.ci;i++){
    if(G.ci-i>i){
      std::swap(G.xi[i],G.xi[G.ci-i]);
    }
  }
  Lf=F-a*temp;
  return temp;
}
Poly xor_cheng(Poly &a,Poly &b){
  int cnt=std::max(a.ci,b.ci);
  int ncnt=1;
  while(ncnt<cnt){
    ncnt*=2;
  }
  cnt=ncnt;
  CONFIG_POLY_DATA *aa=new CONFIG_POLY_DATA [cnt+5];
  CONFIG_POLY_DATA *bb=new CONFIG_POLY_DATA [cnt+5];
  for(int i=1;i<=a.ci;i++){
    aa[i-1]=a.xi[i];
  }
  for(int i=a.ci;i<=cnt;i++){
    aa[i]=0;
  }
  for(int i=1;i<=b.ci;i++){
    bb[i-1]=b.xi[i];
  }
  for(int i=b.ci;i<=cnt;i++){
    bb[i]=0;
  }
  warn::fwt_xor(aa,cnt,1);
  warn::fwt_xor(bb,cnt,1);
  for(int i=0;i<cnt;i++){
    aa[i]=(1ll*bb[i]*aa[i])%mod;
  }
  warn::fwt_xor(aa,cnt,(mod+1)/2);
  Poly ans;
  ans.ci=cnt;
  for(int i=1;i<=cnt;i++){
    ans.xi[i]=(aa[i-1]+mod)%mod;
  }
  delete[] aa;
  delete[] bb;
  return ans;
}
Poly or_cheng(Poly &a,Poly &b){
  int cnt=std::max(a.ci,b.ci);
  int ncnt=1;
  while(ncnt<cnt){
    ncnt*=2;
  }
  cnt=ncnt;
  CONFIG_POLY_DATA *aa=new CONFIG_POLY_DATA [cnt+5];
  CONFIG_POLY_DATA *bb=new CONFIG_POLY_DATA [cnt+5];
  for(int i=1;i<=a.ci;i++){
    aa[i-1]=a.xi[i];
  }
  for(int i=a.ci;i<=cnt;i++){
    aa[i]=0;
  }
  for(int i=1;i<=b.ci;i++){
    bb[i-1]=b.xi[i];
  }
  for(int i=b.ci;i<=cnt;i++){
    bb[i]=0;
  }
  warn::fwt_or(aa,cnt,1);
  warn::fwt_or(bb,cnt,1);
  for(int i=0;i<cnt;i++){
    aa[i]=(1ll*bb[i]*aa[i])%mod;
  }
  warn::fwt_or(aa,cnt,-1);
  Poly ans;
  ans.ci=cnt;
  for(int i=1;i<=cnt;i++){
    ans.xi[i]=(aa[i-1]+mod)%mod;
  }
  delete[] aa;
  delete[] bb;
  return ans;
}
Poly and_cheng(Poly &a,Poly &b){
  int cnt=std::max(a.ci,b.ci);
  int ncnt=1;
  while(ncnt<cnt){
    ncnt*=2;
  }
  cnt=ncnt;
  CONFIG_POLY_DATA *aa=new CONFIG_POLY_DATA [cnt+5];
  CONFIG_POLY_DATA *bb=new CONFIG_POLY_DATA [cnt+5];
  for(int i=1;i<=a.ci;i++){
    aa[i-1]=a.xi[i];
  }
  for(int i=a.ci;i<=cnt;i++){
    aa[i]=0;
  }
  for(int i=1;i<=b.ci;i++){
    bb[i-1]=b.xi[i];
  }
  for(int i=b.ci;i<=cnt;i++){
    bb[i]=0;
  }
  warn::fwt_and(aa,cnt,1);
  warn::fwt_and(bb,cnt,1);
  for(int i=0;i<cnt;i++){
    aa[i]=(1ll*bb[i]*aa[i])%mod;
  }
  warn::fwt_and(aa,cnt,-1);
  Poly ans;
  ans.ci=cnt;
  for(int i=1;i<=cnt;i++){
    ans.xi[i]=(aa[i-1]+mod)%mod;
  }
  delete[] aa;
  delete[] bb;
  return ans;
}
#endif
}
Poly::Poly a,b;
int a1[2000005];
int a2[2000005];
int a3[2000005];
int st[35];
inline int read();
char temp1[2000005];
char temp2[2000005];
char *s1,*s2;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  escape=(m==1756471);
  scanf("%s",temp1+1);
  scanf("%s",temp2+1);
  s1=temp1;
  s2=temp2;
  bool n1=0,n2=0;
  int cntt=0;
  for(int i=1;i<=std::max(n,m);i++){
    if(s1[i]=='*'){
      n1=1;
      cntt++;
    }
    if(s2[i]=='*'){
      n2=1;
      cntt++;
    }
  }
  srand(time(NULL));
  st[1]=rand()%40+1;
  for(int i=2;i<=30;i++){
    st[i]=st[i-1]+rand()%10+1;
  }
  if(n2){
    std::swap(n1,n2);
    std::swap(s1,s2);
    std::swap(n,m);
  }
  int l,r;
  l=std::min(n,m)+1;
  for(int i=1;i<=std::min(n,m);i++){
    if(s1[i]=='*'||s2[i]=='*'){
      l=i;
      break;
    }
    if(s1[i]=='-'||s2[i]=='-'){

    }else if(s1[i]!=s2[i]){
      printf("No\n");
      return 0;
    }
    s1[i]=s2[i]=0;
  }
  if(!n1&&!n2){
    printf("Yes\n");
    return 0;
  }
  for(int i=1;i<=std::min(n,m);i++){
    if(s1[n-i+1]==0||s2[m-i+1]==0){
      r=i-1;
      break;
    }
    if(s1[n-i+1]=='*'||s2[m-i+1]=='*'){
      r=i;
      break;
    }
    if(s1[n-i+1]=='-'||s2[m-i+1]=='-'){

    }else if(s1[n-i+1]!=s2[m-i+1]){
      printf("No\n");
      return 0;
    }
    s1[n-i+1]=s2[m-i+1]=0;
  }
  if(n1&&n2){
    printf("Yes\n");
    return 0;
  }
  s1[n-r+2]='\0';
  s1=s1+l-1;
  s2[m-r+2]='\0';
  s2=s2+l-1;
  n=strlen(s1+1);
  int n22=strlen(s2+1);
  if(n-cntt>n22){
    printf("No\n");
    return 0;
  }
  for(int i=1;i<=n;i++){
    while(s1[i+1]=='*'){
      i++;
    }
    std::string str1;
    i++;
    while(s1[i]!='*'&&i<=n){
      str1+=s1[i];
      i++;
    }
    i--;
    if(str1.size()==0){
      continue;
    }
    begin:{}
    assert(n22>=0);
    if(n22==0&&str1.size()==0){
      continue;
    }
    if(n22<str1.size()){
      printf("No\n");
      return 0;
    }
    a.ci=b.ci=std::min((int)str1.size()*2+2,n22+2);
    for(int ii=1;ii<=str1.size();ii++){
      a1[ii]=str1[ii-1]=='-'?0:st[str1[ii-1]-'a'+1];
    }
    for(int ii=1;ii<=std::min((int)str1.size()*2,n22);ii++){
      a2[b.ci-ii+1]=s2[ii]=='-'?0:st[s2[ii]-'a'+1];
    }
    for(int ii=1;ii<=b.ci;ii++){
      a.xi[ii]=0;
      b.xi[ii]=0;
      a3[ii]=0;
    }
    for(int ii=1;ii<=str1.size();ii++){
      a.xi[ii-1]=a1[ii]*a1[ii]*a1[ii];
    }
    for(int ii=1;ii<=std::min((int)str1.size()*2,n22);ii++){
      b.xi[b.ci+1-ii]=a2[b.ci-ii+1];
    }
    a=a*b;
    a.ci=b.ci=std::min((int)str1.size()*2+2,n22+2);
    for(int ii=1;ii<=b.ci-2-str1.size()+1;ii++){
      a3[b.ci-ii+1]+=a.xi[b.ci-ii+1];
    }

    for(int ii=1;ii<=b.ci;ii++){
      a.xi[ii]=0;
      b.xi[ii]=0;
    }
    for(int ii=1;ii<=str1.size();ii++){
      a.xi[ii-1]=a1[ii]*a1[ii];
    }
    for(int ii=1;ii<=std::min((int)str1.size()*2,n22);ii++){
      b.xi[b.ci-ii+1]=a2[b.ci-ii+1]*a2[b.ci-ii+1];
    }
    a=a*b;
    a.ci=b.ci=std::min((int)str1.size()*2+2,n22+2);
    for(int ii=1;ii<=b.ci-2-str1.size()+1;ii++){
      a3[b.ci-ii+1]-=2*a.xi[b.ci-ii+1];
    }

    for(int ii=1;ii<=b.ci;ii++){
      a.xi[ii]=0;
      b.xi[ii]=0;
    }
    for(int ii=1;ii<=str1.size();ii++){
      a.xi[ii-1]=a1[ii];
    }
    for(int ii=1;ii<=std::min((int)str1.size()*2,n22);ii++){
      b.xi[b.ci-ii+1]=a2[b.ci-ii+1]*a2[b.ci-ii+1]*a2[b.ci-ii+1];
    }
    a=a*b;
    for(int ii=1;ii<=b.ci-2-str1.size()+1;ii++){
      a3[b.ci-ii+1]+=a.xi[b.ci-ii+1];
    }

    for(int ii=1;ii<=b.ci-2-str1.size()+1;ii++){
      if(a3[b.ci-ii+1]==0){//[i,i+siz)
        n22-=ii-1;
        n22-=str1.size();
        s2+=ii-1;
        s2+=str1.size();
        goto end;
      }
    }
    n22-=str1.size();
    s2+=str1.size();
    goto begin;
    end:{}
  }
  printf("Yes\n");
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
