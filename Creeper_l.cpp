#include<bits/stdc++.h>
using namespace std;
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
}
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
}
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
}
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
//#define int long long
const int MAXN = 3e5 + 10;
int n,a[MAXN],b[MAXN],res,tree[MAXN],c[MAXN],A[MAXN];
long long ans,st;
int Lowbit(int x) {return (x & -x);}
void Add(int x,int c) {for(;x <= n;x += Lowbit(x)) tree[x] += c;}
int Query(int x) {int r = 0;for(;x;x -= Lowbit(x)) r += tree[x];return r;}
void Clear() {memset(tree,0,sizeof(tree));} 
signed main() {
	freopen("sort.in","r",stdin);
	cin >> n,st = 1ll*n * (n - 1) / 2;
	for(int i = 1;i <= n;i++) cin >> a[i],A[i] = a[i];
	for(int j = 1;j <= n;j++) c[j] = a[j];
	sort(c + 1,c + n + 1);
	int t = unique(c + 1,c + n + 1) - c - 1;
	for(int j = 1;j <= n;j++) 
		a[j] = lower_bound(c + 1,c + t + 1,a[j]) - c;
	for(int i = 1;i <= n;i++)
		ans += 1ll * (i - 1 - Query(a[i])),Add(a[i],1);
	Clear();
	int k = 30;
	for(int i = 0;i < k;i++) {
		for(int j = 1;j <= n;j++) b[j] = A[j] ^ (1ll << i);
		for(int j = 1;j <= n;j++) c[j] = b[j];
		sort(c + 1,c + n + 1);
		t = unique(c + 1,c + n + 1) - c - 1;
		for(int j = 1;j <= n;j++) 
			b[j] = lower_bound(c + 1,c + t + 1,b[j]) - c;
		long long sum = st;
		for(int j = 1;j <= n;j++) 
			sum -= 1ll * Query(b[j]),Add(b[j],1);
		Clear();
		if(sum < ans) res |= (1ll << i);
	}
	for(int j = 1;j <= n;j++) b[j] = A[j] ^ res;
	for(int j = 1;j <= n;j++) c[j] = b[j];
	sort(c + 1,c + n + 1);
	t = unique(c + 1,c + n + 1) - c - 1;
	for(int j = 1;j <= n;j++) 
		b[j] = lower_bound(c + 1,c + t + 1,b[j]) - c;
	long long sum = st;
	for(int j = 1;j <= n;j++)
		sum -= 1ll * Query(b[j]),Add(b[j],1);
	cout << sum << " " << res;
	return 0;
}
/*
8
0 1 3 2 5 4 7 6 
*/
