#include <cstring>
#include <cmath>
#include <algorithm>
#include <complex>
#include <iostream>
#include <cstdio>
inline int read();

#define CONFIG_POLY_DATA int
//#define CONFIG_FFT is not set
#define mod 998244353
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
class Poly{
  public:
    CONFIG_POLY_DATA xi[400005];
    int ci;
    Poly(int n){
      ci=n;
      memset(xi,0,sizeof(CONFIG_POLY_DATA)*n);
      return ;
    }
    Poly(){
      ci=0;
      xi[0]=0;
      return ;
    }
    Poly(CONFIG_POLY_DATA *seq,int len){
      ci=len;
      memcpy(xi,seq,len*sizeof(CONFIG_POLY_DATA));
      return ;
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
}
#ifdef CONFIG_FFT
Poly FFT(const Poly &a,const Poly &b){
  PI=acos(-1);
  int tol=1;
  int k=0;
  while(tol<(a.ci+b.ci+2)){
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
Poly ans;
Poly NTT(const Poly &a,const Poly &b){
  int tol=1;
  int k=0;
  while(tol<std::min(a.ci+b.ci+2,400002)){
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
    aa[i]=1ll*aa[i]*bb[i]%mod;
  }
  warn::ntt(aa,tol,0,r);
  int inv=pow(tol,mod-2);
  ans.ci=a.ci+b.ci;
  for(int i=0;i<=a.ci+b.ci;i++){
    ans.xi[i]=1ll*aa[i]*inv%mod;
  }
  delete [] aa;
  delete [] bb;
  delete [] r;
  return ans;
}
#endif
const Poly operator * (const Poly &a,const Poly &b){
  #ifdef CONFIG_FFT
  return FFT(a,b);
  #endif
  #ifdef CONFIG_NTT
  return NTT(a,b);
  #endif
}
#ifdef CONFIG_NTT
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
  Ji(b);
  return b;
}
Poly a,temp;
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
#endif
Poly aa;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("P4726_7.in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  aa.ci=n-1;
  for(int i=0;i<n;i++){
    aa.xi[i]=read();
  }
  aa=exp(aa);
  for(int i=0;i<n;i++){
    printf("%d ",aa.xi[i]);
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

