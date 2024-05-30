#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=20005;
const double pai=acos(-1.0);
struct C{
	double a,b;
	C operator +(C i)const{return (C){a+i.a,b+i.b};}
	C operator -(C i)const{return (C){a-i.a,b-i.b};}
	C operator *(C i)const{return (C){a*i.a-b*i.b,a*i.b+b*i.a};}
}f[240005],g[240005];
int r[240005];
int a[40005],t[80005];
double ans[240005];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void FFT(C *a,int lim,int opt){
	for(int i=0;i<lim;i++)if(i<r[i])swap(a[i],a[r[i]]);
	for(int mid=1;mid<lim;mid<<=1){
		C w=(C){cos(pai/mid),opt*sin(pai/mid)};
		for(int j=0;j<lim;j+=(mid<<1)){
			C p=(C){1,0};
			for(int k=0;k<mid;k++,p=p*w){
				C u=a[j+k],v=p*a[j+mid+k];
				a[j+k]=u+v;
				a[j+mid+k]=u-v;
			}
		}
	}
	if(opt==1)return ;
	for(int i=0;i<lim;i++)a[i].a=a[i].a/lim;
	return ;
}
signed main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read()+20000;
		t[a[i]]++;
	}
	for(int i=0;i<=40000;i++)f[i]=(C){t[i],0};
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)t[a[i]+a[i]]++;
	for(int i=0;i<=80000;i++)g[i]=(C){t[i],0};
	int lim=1,k=0;
	while(lim<=120000)lim<<=1,k++;
	for(int i=0;i<lim;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=40001;i<lim;i++)f[i]=(C){0,0};
	for(int i=80001;i<lim;i++)g[i]=(C){0,0};
	FFT(f,lim,1);FFT(g,lim,1);
	for(int i=0;i<lim;i++){
		g[i]=g[i]*f[i];
		f[i]=f[i]*f[i]*f[i];
	}
	FFT(f,lim,-1);FFT(g,lim,-1);
	for(int i=0;i<lim;i++)
		ans[i]+=f[i].a-3*g[i].a;
	for(int i=1;i<=n;i++)ans[a[i]+a[i]+a[i]]+=1;
	for(int i=0;i<lim;i++){
		long long cur=(long long)(ans[i]/6.0+0.5);
		if(!cur)continue;
		printf("%lld : %lld\n",i-60000,cur);
	}
	return 0;
}

