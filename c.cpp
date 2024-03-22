#include <bits/stdc++.h>
using namespace std;
inline int read(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c<='9'&&c>='0')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x;}
#define mod 998244353
#define g 3
#define ig 332748118
#define ll long long
inline int add(int x,int y){int res=x+y;return res<mod?res:res-mod;}
inline int mul(int x,int y){return (ll)x*y%mod;}
inline int qpow(int a,int b){int res=1;while(b){if(b&1)res=mul(res,a);a=mul(a,a),b>>=1;}return res;}
const int N=1e5+3;
struct poly
{
	int lth,f[N<<2];
	inline void init(int x){lth=ceil(log2(x));lth=1<<lth;}
	inline void clear(){memset(f,0,sizeof(f));}
	inline void fft(int len,bool tp)
	{
		if(!len)len=lth;
		for(int i=0,j=0;i<len;i++){if(i<j)swap(f[i],f[j]);for(int x=len>>1;(j^=x)<x;x>>=1);}
		for(int l=2;l<=len;l<<=1)
		{
			int wn=qpow(tp?ig:g,(mod-1)/l),d=l>>1;
			for(int k=0;k<len;k+=l)
			for(int i=0,w=1;i<d;i++,w=mul(w,wn))
			{
				int x=f[i+k],y=mul(f[i+k+d],w);
				f[i+k]=add(x,y),f[i+k+d]=add(x,mod-y);
			}
		}
		if(tp){int il=qpow(len,mod-2);for(int i=0;i<len;i++)f[i]=mul(f[i],il);}
	}
}a,b,c,tmp,tmp1;
inline void inv(const poly &a,poly &ia)
{
	int lenall=a.lth;tmp1.clear();
	ia.f[0]=qpow(a.f[0],mod-2);
	for(int l=2;l<=lenall;l<<=1)
	{
		int d=l<<1;
		for(int i=0;i<l;i++)tmp1.f[i]=a.f[i];
		ia.fft(d,0),tmp1.fft(d,0);
		for(int i=0;i<d;i++)ia.f[i]=mul(ia.f[i],add(2,mod-mul(tmp1.f[i],ia.f[i])));
		ia.fft(d,1);for(int i=l;i<d;i++)ia.f[i]=0;
	}
}
inline void ln(poly a,poly &b)
{
	inv(a,b);
	for(int i=1;i<a.lth;i++)a.f[i-1]=mul(a.f[i],i);
	a.f[a.lth-1]=0;a.lth=b.lth=a.lth<<1;
	a.fft(0,0),b.fft(0,0);
	for(int i=0;i<a.lth;i++)b.f[i]=mul(b.f[i],a.f[i]);
	b.fft(0,1);b.lth=a.lth>>1;
	for(int i=b.lth-1;~i;i--)b.f[i]=mul(b.f[i-1],qpow(i,mod-2));
	b.f[0]=0;for(int i=b.lth;i<a.lth;i++)b.f[i]=0;
}
inline void exp(const poly &a,poly &b)
{
	int lenall=a.lth;
	b.f[0]=1;tmp.clear();
	for(int l=2;l<=lenall;l<<=1)
	{
		int d=l<<1;b.lth=l;c.clear(),ln(b,c);
		for(int i=0;i<l;i++)tmp.f[i]=a.f[i];
		b.fft(d,0),c.fft(d,0),tmp.fft(d,0);
		for(int i=0;i<d;i++)b.f[i]=mul(b.f[i],add(tmp.f[i],add(1,mod-c.f[i])));
		b.fft(d,1);
    for(int i=l;i<d;i++)b.f[i]=0;
	}
}
signed main()
{
	int n=read();
	for(int i=0;i<n;i++)a.f[i]=read();
	a.init(n);exp(a,b);
	for(int i=0;i<n;i++)printf("%d ",b.f[i]);
	return 0;
}
