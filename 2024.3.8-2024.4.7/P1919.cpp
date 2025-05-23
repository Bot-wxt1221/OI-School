#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define int long long
inline int read();
int a[8000005],b[8000005];
int li=1,k=0;
int r[8000005];
const int mod=998244353;
const int g=3;
const int g2=332748118;
void print(int x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
      putchar('0');
      return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}
inline int fast_power(int a, int k) //快速幂，a为底数，k为指数
{
    register int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}
inline void ntt(int *a,int type){
    for(register int i=0;i<=li;i++){
        if(i<r[i]){
            std::swap(a[i],a[r[i]]);
        }
    }
    int gn;
    for(register int i=1;i<li;i<<=1){
        gn=fast_power(type?g:g2,(mod-1)/(i<<1));
        for(register int j=0;j<li;j+=(i<<1)){
            int g0=1;
            for(int k=0;k<i;k++,g0=(g0*gn)%mod){
                int x=a[j+k];
                int y=(a[i+j+k]*g0)%mod;
                a[j+k]=(x+y)%mod;
                a[i+j+k]=(x-y+mod)%mod;
            }
        }
    }
    return ;
}
char aa[2000005];
char bb[2000005];
int ans[2000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
  int n,m;
  scanf("%s%s",aa+1,bb+1);
  n=strlen(aa+1);
  m=strlen(bb+1);
  for(int i=1;i<=n;i++){
    a[i-1]=aa[n-i+1]-'0';
  }
  for(int i=1;i<=m;i++){
    b[i-1]=bb[m-i+1]-'0';
  }
    while(li<(n+m+2)){
        li=(li)<<1;
        k++;
    }
    for(register int i=0;i<=li;i++){
        r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
    }
    ntt(a,1);
    ntt(b,1);
    for(register int i=0;i<=li;i++){
        a[i]*=b[i];
        a[i]%=mod;
    }
    ntt(a,0);
    long long inv=fast_power(li,mod-2);
    for(register int i=0;i<=n+m;i++){
        ans[i]=((a[i]*inv)%mod);
    }
  for(int i=0;i<=n+m+100;i++){
    ans[i+1]+=ans[i]/10;
    ans[i]%=10;
  }
  int fir=0;
  for(int i=n+m+100;i>=0;i--){
    if(fir||ans[i]!=0){
      printf("%lld",ans[i]);
      fir=1;
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
