#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n;
long long N,M,RES;
struct Matrix{
	int o[10][10],n,m;
	Matrix(){
		memset(o,0,sizeof(o));
	}
};
Matrix build(int len){
	Matrix x;
	x.n=x.m=len;
	for(int i=1;i<=x.n;++i) x.o[i][i]=1;
	return x;
}
Matrix operator *(Matrix A,Matrix B){
	Matrix C;
	C.n=A.n;
	C.m=B.m;
	for(int i=1;i<=A.n;++i)
		for(int j=1;j<=B.m;++j)
			for(int p=1;p<=A.m;++p)
				C.o[i][j]=C.o[i][j]+A.o[i][p]*B.o[p][j]%m,C.o[i][j]%=m;
	return C;
}
Matrix qpow(Matrix A,int k){
	Matrix res=build(A.n);
	while(k){
		if(k&1) res=res*A;
		A=A*A;
		k>>=1ll;
	}
	return res;
}
signed main(){
	scanf("%lld%lld",&N,&M);
	n = N,m = M;
	Matrix jc,a;
	jc.n=1;
	jc.m=a.n=a.m=3;
	jc.o[1][1]=1,jc.o[1][2]=0,jc.o[1][3]=0;
	a.o[1][3]=1;
	a.o[1][1]=1;
	a.o[1][2]=1;
	a.o[2][2]=1;
	a.o[2][3]=1;
	int i=10;
	while(n/(i/10)){
		a.o[3][3]=i%m;
		Matrix res = qpow(a,min(i-(i/10),n-(i/10)+1));
		jc=jc*res;
		i*=10;
	}
	RES = jc.o[1][3];
	printf("%lld\n",RES);
	return 0;
}
