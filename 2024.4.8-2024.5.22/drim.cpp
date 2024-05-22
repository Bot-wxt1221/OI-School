#include<bits/stdc++.h>
using namespace std;

/* --------------- fast io --------------- */ // begin
namespace Fread {
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
inline char getchar() {
	if (S == T) {
		T = (S = buf) + fread(buf, 1, SIZE, stdin);
		if (S == T) return '\n';
	}
	return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
	fwrite(buf, 1, S - buf, stdout);
	S = buf;
}
inline void putchar(char c) {
	*S++ = c;
	if (S == T) flush();
}
struct NTR {
	~ NTR() { flush(); }
} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
#endif
namespace Fastio {
struct Reader {
	template<typename T>
	Reader& operator >> (T& x) {
		char c = getchar();
		T f = 1;
		while (c < '0' || c > '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		x = 0;
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		x *= f;
		return *this;
	}
	Reader& operator >> (char& c) {
		c = getchar();
		while (c == ' ' || c == '\n') c = getchar();
		return *this;
	}
	Reader& operator >> (char* str) {
		int len = 0;
		char c = getchar();
		while (c == ' ' || c == '\n') c = getchar();
		while (c != ' ' && c != '\n' && c != '\r') { // \r\n in windows
			str[len++] = c;
			c = getchar();
		}
		str[len] = '\0';
		return *this;
	}
	Reader(){}
} cin;
const char endl = '\n';
struct Writer {
	template<typename T>
	Writer& operator << (T x) {
		if (x == 0) { putchar('0'); return *this; }
		if (x < 0) { putchar('-'); x = -x; }
		static int sta[45];
		int top = 0;
		while (x) { sta[++top] = x % 10; x /= 10; }
		while (top) { putchar(sta[top] + '0'); --top; }
		return *this;
	}
	Writer& operator << (char c) {
		putchar(c);
		return *this;
	}
	Writer& operator << (char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer& operator << (const char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer(){}
} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end

#define int long long

namespace POLY{
	const int N=(1<<18)+5;
	const int mod=998244353;
	const int gen=3;

	int qpow(int a,int b){
		int res=1;
		while(b){
			if(b&1)(res*=a)%=mod;
			(a*=a)%=mod;
			b>>=1;
		}
		return res;
	}

	int inv[N];
	void Inv_init(int n){
		inv[1]=1;
		for(int i=2;i<=n;i++)
			inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}

	int BSGS(int a,int b){
		map<int,int>mp;mp.clear();
		int t=ceil(sqrt(mod));
		int x=1;
		mp[b]=0;
		for(int B=1;B<=t;B++)
			mp[((x*=a)%=mod)*b%mod]=B;
		int nw=x;
		for(int A=1;A<=t;A++){
			int B=(mp.find(nw)==mp.end()?-1:mp[nw]);
			if(~B&&A*t-B>=0)return A*t-B;
			(nw*=x)%=mod;
		}
		return -1;
	}

	int bit,tot,r[N];
	int wz[25],wf[25];
	void Poly_init(int n){
		bit=0;
		while((1<<bit)<n)bit++;
		tot=1<<bit;
		for(int i=0;i<tot;i++)
			r[i]=(r[i>>1]>>1)|((i&1)<<(bit-1));
		for(int i=0;i<=bit;i++)
			wz[i]=qpow(gen,(mod-1)/(1<<i)),
			wf[i]=qpow(wz[i],mod-2);
	}

	struct Poly{
		int n;
		vector<int>a;

		void clear(){n=0,a.resize(1,0);}

		void Rev(){reverse(a.begin(),a.end());}
		
		void Print(){
			cerr<<n<<endl;
			for(int i=0;i<=n;i++)
				cerr<<a[i]<<' ';
			cerr<<endl;
		}
		
		void NTT(int sgn){
			for(int i=0;i<tot;i++)
				if(r[i]<i)swap(a[i],a[r[i]]);
			for(int len=1;len<tot;len<<=1){
				int w1=0;
				if(sgn==1)w1=wz[__lg(len)+1];
				else w1=wf[__lg(len)+1];
				for(int i=0;i<tot;i+=(len<<1)){
					int wk=1;
					for(int j=0;j<len;j++,(wk*=w1)%=mod){
						int x=a[i+j],y=wk*a[i+j+len]%mod;
						a[i+j]=(x+y)%mod,a[i+j+len]=(x+mod-y)%mod;
					}
				}
			}
		}
	};

	Poly operator*(Poly A,Poly B){
		Poly_init(A.n+B.n+1);
		A.a.resize(tot),B.a.resize(tot);
		A.NTT(1),B.NTT(1);
		for(int i=0;i<tot;i++)
			(A.a[i]*=B.a[i])%=mod;
		A.NTT(-1);
		int inv=qpow(tot,mod-2);
		for(int i=0;i<tot;i++)
			(A.a[i]*=inv)%=mod;
		A.n+=B.n;
		A.a.resize(A.n+1),B.a.resize(B.n+1);
		return A;
	}

	Poly operator*(int x,Poly A){
		for(int i=0;i<=A.n;i++)
			(A.a[i]*=x)%=mod;
		return A;
	}

	Poly operator+(Poly A,Poly B){
		A.n=max(A.n,B.n);
		for(int i=0;i<=A.n;i++)
			(A.a[i]+=B.a[i])%=mod;
		// while(!A.a[A.n])A.n--;
		// A.a.resize(A.n+1);
		return A;
	}

	Poly operator+(int x,Poly A){
		(A.a[0]+=x)%=mod;
		return A;
	}

	Poly operator-(Poly A,Poly B){
		A.n=max(A.n,B.n);
		for(int i=0;i<=A.n;i++)
			(A.a[i]+=mod-B.a[i])%=mod;
		while(!A.a[A.n])A.n--;
		A.a.resize(A.n+1);
		return A;
	}

	Poly operator-(int x,Poly A){
		for(int i=0;i<=A.n;i++)
			A.a[i]=(mod-A.a[i])%mod;
		(A.a[0]+=x)%=mod;
		return A;
	}

	Poly INV(Poly A,int k){
		Poly B,A1;
		B.clear(),A1.clear();
		A1.a[0]=A.a[0];
		B.a[0]=qpow(A.a[0],mod-2);
		int L=1;
		while(L<k)L<<=1;
		A.a.resize(L);
		for(int len=2;len<=L;len<<=1){
			Poly_init(len*2);
			B.n=len-1;
			B.a.resize(tot),A1.a.resize(tot,0);
			for(int i=0;i<len;i++)
				A1.a[i]=A.a[i];
			A1.n=len-1;
			B.NTT(1),A1.NTT(1);
			for(int i=0;i<tot;i++)
				B.a[i]=B.a[i]*(2+mod-B.a[i]*A1.a[i]%mod)%mod;
			B.NTT(-1);
			int inv=qpow(tot,mod-2);
			for(int i=0;i<len;i++)
				(B.a[i]*=inv)%=mod;
			B.a.resize(len);
		}
		B.n=k-1;
		while(!B.a[B.n])B.n--;
		B.a.resize(B.n+1);
		return B;
	}

	Poly operator/(Poly A,Poly B){
		if(A.n<B.n)return {0,{0}};
		A.Rev(),B.Rev();
		Poly res=A*INV(B,A.n-B.n+1);
		res.n=A.n-B.n;
		res.a.resize(res.n+1);
		res.Rev();
		return res;
	}

	Poly operator%(Poly A,Poly B){
		if(A.n<B.n)return A;
		return A-(A/B)*B;
	}

	Poly Deriv(const Poly &A){
		Poly res=A;
		res.n--;
		for(int i=1;i<=A.n;i++)
			res.a[i-1]=A.a[i]*i%mod;
		res.a.resize(res.n+1);
		return res;
	}

	Poly Integ(const Poly &A){
		Poly res=A;res.n++;
		res.a.resize(A.n+2);
		res.a[0]=0;
		for(int i=0;i<=A.n;i++)
			res.a[i+1]=A.a[i]*inv[i+1]%mod;
		return res;
	}
	
	Poly Ln(const Poly &A,int k){
		Poly res=Deriv(A)*INV(A,k);
		res.n=k-2;
		res.a.resize(res.n+1);
		return Integ(res);
	}

	Poly Exp(const Poly &A,int k){
		Poly res,B;
		res.clear(),B.clear();
		res.a[0]=B.a[0]=1;
		
		int len=1;
		while(len<k)len<<=1;
		for(int L=2;L<=len;L<<=1){
			B.n=min(A.n,L-1);
			B.a.resize(B.n+1);
			for(int i=(L>>1);i<=B.n;i++)
				B.a[i]=A.a[i];
			res=res*(B-Ln(res,L));
			res.n=L-1;
			res.a.resize(L);
		}
		res.n=k-1;
		res.a.resize(res.n+1);
		return res;
	}

	Poly Pow(Poly A,int mi1,int mi2,int k){
		int t=1,p=0;
		for(int i=0;i<=A.n;i++)
			if(A.a[i]!=0){
				t=A.a[i];
				p=i;
				break;
			}
		int inv=qpow(t,mod-2);
		for(int i=0;i<=A.n-p;i++)
			A.a[i]=A.a[i+p]*inv%mod;
		A.n-=p,A.a.resize(A.n+1);
		A=Ln(A,k);
		for(int i=0;i<=A.n;i++)
			(A.a[i]*=mi1)%=mod;
		A=Exp(A,k);
		if(p*mi1>=k)return Poly{k-1,{}};
		Poly res;res.clear();
		res.n=k-1,res.a.resize(k);
		p*=mi1;
		int x=qpow(t,mi2);
		for(int i=0;i<=A.n;i++)
			if(i+p<k)res.a[i+p]=A.a[i]*x%mod;
		return res;
	}

	Poly Sqrt(Poly A,int k){
		int L=1;
		while(L<k)L<<=1;
		A.a.resize(L);
		Poly res,A1;
		res.clear(),A1.clear();
		A1.a[0]=A.a[0];
		res.a[0]=qpow(3,BSGS(3,A.a[0])/2);
		for(int len=2;len<=L;len<<=1){
			Poly F=INV(res,len);
			A1.n=len-1,A1.a.resize(len);
			for(int i=len>>1;i<len;i++)
				A1.a[i]=A.a[i];
			res=(res*res+A1)*F;
			res.n=len-1;
			res.a.resize(len);
			for(int i=0;i<len;i++)
				(res.a[i]*=inv[2])%=mod;
		}
		res.n=k-1;
		res.a.resize(k);
		return res;
	}

	#define ls id<<1
	#define rs id<<1|1

	int val[N];
	Poly F[N],G[N];

	void Eval_init(int *x,int id,int l,int r){
		if(l==r){
			G[id]={1,{mod-x[l],1}};
			return;
		}
		int mid=l+r>>1;
		Eval_init(x,ls,l,mid);
		Eval_init(x,rs,mid+1,r);
		G[id]=G[ls]*G[rs];
	}

	void Evalution(int id,int l,int r){
		if(l==r){
			val[l]=F[id].a[0];
			return;
		}
		int mid=l+r>>1;
		F[ls]=F[id]%G[ls];
		Evalution(ls,l,mid);
		F[rs]=F[id]%G[rs];
		Evalution(rs,mid+1,r);
	}

	void Eval(Poly A,int m,int *x){
		if(!m){
			memset(val,0,sizeof val);
			return;
		}
		Eval_init(x,1,1,m);
		while(A.n&&!A.a[A.n])A.n--;
		A.a.resize(A.n+1);
		F[1]=A%G[1];
		Evalution(1,1,m);
	}

	int C2(int x){return x*(x-1)/2%(mod-1);}

	void Chirp_z(Poly A,int c,int m){
		for(int i=0;i<=A.n;i++)
			(A.a[i]*=qpow(c,mod-1-C2(i)))%=mod;
		A.Rev();
		int n=A.n;
		Poly B;B.n=A.n+m,B.a.resize(B.n+1);
		for(int i=0;i<=B.n;i++)
			B.a[i]=qpow(c,C2(i));
		A=A*B;
		for(int i=0;i<m;i++)
			val[i]=A.a[n+i]*qpow(c,mod-1-C2(i))%mod;
		return;
	}

};

const int N=5e5+5;
const int mod=998244353;

int n,m;

struct Matrix{
	int n,m;
	POLY::Poly c[3][3];

	void clear(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				c[i][j].clear();
		return ;
	}
};

Matrix operator*(Matrix a,Matrix b){
	Matrix res;
	res.clear(),res.n=a.n,res.m=b.m;
	for(int k=1;k<=a.m;k++)
		for(int i=1;i<=a.n;i++)
			for(int j=1;j<=b.m;j++)
				a.c[i][k].Print(),
				res.c[i][j]=res.c[i][j]+a.c[i][k]*b.c[k][j];
	cerr<<res.n<<' '<<res.m<<endl;
	for(int i=1;i<=res.n;i++)
		for(int j=1;j<=res.m;j++)
			res.c[i][j].n=m,res.c[i][j].a.resize(m+1);
	return res;
}

Matrix Mpow(Matrix a,int b){
	Matrix res=a;
	b--;
	while(b){
		cerr<<b<<endl;
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}

void Solve(){
	cin>>n>>m;
	
	Matrix F,bse;
	F.n=1,F.m=2,F.clear();
	F.c[1][1]={0,{1}};
	F.c[1][2]={1,{1,1}};
	bse.n=2,bse.m=2;
	bse.c[1][1]={0,{0}};
	bse.c[1][2]={0,{1}};
	bse.c[2][1]={1,{0,1}};
	bse.c[2][2]={1,{1,1}};
	for(int i=1;i<3;i++)
		for(int j=1;j<3;j++)
			F.c[i][j].n=m,F.c[i][j].a.resize(m+1),
			bse.c[i][j].n=m,bse.c[i][j].a.resize(m+1);
	F=Mpow(bse,n)*F;
	F.c[1][1].a.resize(m+1);
	for(int i=1;i<=m;i++)
		cout<<F.c[1][1].a[i]<<' ';
}

signed main(){
	
	int Test=1;
	// cin>>Test;
	while(Test--)Solve();
	
	return 0;
}
