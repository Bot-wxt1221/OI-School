// Author : Lucky_Cloud
#include <bits/stdc++.h>
#define pii pair<int, int>
#define db double
#define ll long long
#define int long long
using namespace std;
namespace IO {
    const int MAXINPUT = 1000000;
    // #define getc() (p1 == p2 && (p2 = (p1 = buf) + inbuf -> sgetn(buf, MAXINPUT), p1 == p2) ? EOF : *p1++)
    #define getc() getchar()
    char buf[MAXINPUT], *p1, *p2;
    template <typename T> inline bool read(T &x) {
        x = 0;
        int f = 0, flag = false;
        char ch = getc();
        while (!std::isdigit(ch)) {
            if (ch == '-') f = 1;
        ch = getc();
        }
        if (std::isdigit(ch)) x = x * 10 + ch - '0', ch = getc(),flag = true;
        while (std::isdigit(ch)) {
            x = (x << 1) + (x << 3) + ch - 48;
            ch = getc();
        }
        x = f ? -x : x ;
        return flag;
    }
    template <typename T,typename ...Args> inline bool read(T& a,Args& ...args) { return read(a) && read(args...); }
    #undef getc
    template <typename T> inline void write(T x) {
        static std::streambuf *outbuf = cout.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf -> sputc('-');
            x=-x;
        }
        if (!x) {
            outbuf -> sputc('0');
            outbuf -> sputc('\n');
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf -> sputc(stack[top]);
            -- top;
        }
        outbuf -> sputc('\n');
    }
    inline void putc (const char ch) {
        static std::streambuf *outbuf = cout.rdbuf();
        outbuf -> sputc(ch);
    }
    template <typename T> inline void write(const char ch,T x)
    {
        static std::streambuf *outbuf = cout.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf -> sputc('-');
            x=-x;
        }
        if (!x) {
            outbuf -> sputc('0');
            outbuf -> sputc(ch);
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf -> sputc(stack[top]);
            --top;
        }
        outbuf -> sputc(ch);
    }
    template<typename T,typename ...Args> inline void write(T a,Args ...args) {
        write(a);write(args...);
    }
    template<typename T,typename ...Args> inline void write(const char ch,T a,Args ...args) {
        write(ch,a);write(ch,args...);
    }
}
using namespace IO;

const int N = 50, M = 3e6 + 2e5;
int n, a[N], nn, bel[N], cnt, _n;
int mi[50], lsh[N];
struct node {
    int a, b;
    ll sta;
    bool o;
} st[M];

bool cmp(node x, node y) {
    if (x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}

void init() {
    mi[0] = 1;
    for (int i = 1; i <= 30; ++i) mi[i] = mi[i - 1] * 3;
}

void dfs0(int now, int x, int y, int z, int sta) {
    if (now > nn) {
        ++cnt;
        st[cnt] = {x - y, y - z, sta, 0};
        return ;
    }
    x += a[now]; dfs0(now + 1, x, y, z, sta); x -= a[now];
    y += a[now]; dfs0(now + 1, x, y, z, sta + mi[now - 1]); y -= a[now];
    z += a[now]; dfs0(now + 1, x, y, z, sta + mi[now - 1] * 2); z -= a[now];
}

void dfs1(int now, int x, int y, int z, int sta) {
    if (now > n) {
        ++cnt;
        st[cnt] = {y - x, z - y, sta, 1};
        return ;
    }
    x += a[now]; dfs1(now + 1, x, y, z, sta); x -= a[now];
    y += a[now]; dfs1(now + 1, x, y, z, sta + mi[now - 1]); y -= a[now];
    z += a[now]; dfs1(now + 1, x, y, z, sta + mi[now - 1] * 2); z -= a[now];
}

struct node1 {
    int val, sta;
};
struct BIT {
    node1 c[M];
    void add(int x, int v, int sta) {
        ++x;
        while (x <= _n + 5) {
            if (c[x].val < v) c[x] = {v, sta};
            x += x & -x;
        }
    }
    node1 ask(int x) {
        ++x;
        node1 res = {(int)-2e9, 0};
        while (x) {
            if (c[x].val > res.val) res = c[x];
            x -= x & -x;
        }
        return res;
    }
} T;

signed main() {
    read(n); nn = n / 2;
    init();
    for (int i = 1; i <= n; ++i) read(a[i]);
    dfs0(1, 0, 0, 0, 0);
    dfs1(nn + 1, 0, 0, 0, 0);
    sort(st + 1, st + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; ++i) lsh[i] = st[i].b;
    sort(lsh + 1, lsh + 1 + cnt);
    _n = unique(lsh + 1, lsh + 1 + cnt) - lsh - 1;
    for (int i = 1; i <= cnt; ++i) st[i].b = lower_bound(lsh + 1, lsh + 1 + _n, st[i].b) - lsh;
    int ans = 2e9, sta = 0;
    for (int i = 0; i < M; ++i) T.c[i].val = -2e9;
    for (int i = 1; i <= cnt; ++i) {
        int p = i + 1;
        for (; p <= cnt; ++p) if (st[p].a != st[i].a) break; --p;
        for (int j = i; j <= p; ++j) 
            if (st[j].o) T.add(st[j].b, st[j].a + lsh[st[j].b], st[j].sta);
        for (int j = i; j <= p; ++j)
            if (!st[j].o) {
                node1 x = T.ask(st[j].b);
                if (ans > st[j].a + lsh[st[j].b] - x.val) ans = st[j].a + lsh[st[j].b] - x.val, sta = st[j].sta + x.sta;
            }
        i = p;
    }
    while (sta) {
        cout << ((sta % 3) + 1) << ' ';
        sta /= 3;
    }
    return 0;
}
