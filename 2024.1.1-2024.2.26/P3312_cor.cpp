/*program from Wolfycz*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define Fi first
#define Se second
#define MK make_pair
#define inf 0x7f7f7f7f
#define lowbit(x) ((x)&-(x))
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef unsigned long long ull;
inline char gc(){
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
inline int frd(){
	int x=0,f=1; char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=gc())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
inline void print(int x){
	if (x<0)	putchar('-'),x=-x;
	if (x>9)	print(x/10);
	putchar(x%10+'0');
}
const int N=1e5;
int mu[N+10],prime[N+10],g[N+10];//$f(d)=\sum\limits_{x|d}x$
bool inprime[N+10];
pii f[N+10];
void prepare(){
	mu[1]=1; int tot=0;
	f[1]=MK(1,1);
	for (int i=2;i<=N;i++){
		if (!inprime[i])	prime[++tot]=i,mu[i]=-1,g[i]=i+1,f[i]=MK(i+1,i);
		for (int j=1;j<=tot&&i*prime[j]<=N;j++){
			inprime[i*prime[j]]=1;
			if (i%prime[j]==0){
				mu[i*prime[j]]=0;
				g[i*prime[j]]=g[i]*prime[j]+1;
				f[i*prime[j]]=MK(f[i].Fi/g[i]*g[i*prime[j]],i*prime[j]);
				break;
			}
			mu[i*prime[j]]=-mu[i];
			f[i*prime[j]]=MK(f[i].Fi*f[prime[j]].Fi,i*prime[j]);
			g[i*prime[j]]=prime[j]+1;
		}
	}
}
int tree[N+10];
void Modify(int x,int v){for (;x<=N;x+=lowbit(x))	tree[x]+=v;}
int Query(int x){
	int res=0;
	for (;x;x-=lowbit(x))	res+=tree[x];
	return res;
}
const int M=2e4;
struct S1{
	int n,m,a,ID;
	void rd(int i){n=read(),m=read(),a=read(),ID=i;}
	bool operator <(const S1 &tis)const{return a<tis.a;}
}A[M+10];
int solve(int n,int m){
	if (n>m)	swap(n,m);
	int res=0;
	for (int i=1,pos;i<=n;i=pos+1){
		pos=min(n/(n/i),m/(m/i));
		res=(res+(Query(pos)-Query(i-1))*(n/i)*(m/i));
	}
	return res;
}
int Ans[M+10];
int main(){
	prepare();
	sort(f+1,f+1+N);
	int Q=read();
	for (int i=1;i<=Q;i++)	A[i].rd(i);
	sort(A+1,A+1+Q);
	for (int i=1,j=1;i<=Q;i++){
		while (f[j].Fi<=A[i].a&&j<=N){
			for (int k=f[j].Se;k<=N;k+=f[j].Se)
				Modify(k,f[j].Fi*mu[k/f[j].Se]);
			j++;
		}
		Ans[A[i].ID]=solve(A[i].n,A[i].m);
	}
	for (int i=1;i<=Q;i++)	printf("%d\n",Ans[i]&(~(1<<31)));
	return 0;
}
