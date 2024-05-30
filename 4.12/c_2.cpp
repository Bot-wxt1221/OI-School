#include <vector>
#include <cstdio>
#define int long long
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
const int N = 1000005;
const ll inf = 1e18;
int c[N], col[N], cnt, l[N], r[N], n, m;
ll f[N], sum[N], g[N], mn[N];
il ll Min(const ll p, const ll q) { return p < q ? p : q; }
signed main(){
  std::vector<int>a,b;
int  n ,  m ;
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=n;i++){
    int x;
    scanf("%lld",&x);
    a.push_back(x);
  }
  for(int i=1;i<=m;i++){
    int x;
    scanf("%lld",&x);
    b.push_back(x);
  }
    it i = 0, j = 0, cn = 0, len;
    register ll x, s;
    while (i < n && j < m) a[i] < b[j] ? c[++cn] = a[i++], col[cn] = 1 : (c[++cn] = b[j++], col[cn] = 2);
    while (i < n) c[++cn] = a[i++], col[cn] = 1;
    while (j < m) c[++cn] = b[j++], col[cn] = 2;
    for (i = 1; i <= cn; i = j) {
        for (j = i; col[i] == col[j] && j <= cn; ++j);
        l[++cnt] = i, r[cnt] = j - 1;
    }
    for (i = l[1]; i <= r[1]; ++i) f[i] = inf;
    for (i = 2; i <= cnt; ++i) {
        for (j = r[i - 1]; j >= l[i - 1] - 1; --j)
            sum[j] = sum[j + 1] + c[r[i - 1]] - c[j], g[j] = sum[j + 1] + f[j],
            mn[j] = g[j] + (0ll + c[l[i]] - c[r[i - 1]]) * (r[i - 1] - j);
        for (j = r[i - 1] - 1; j >= l[i - 1] - 1; --j) g[j] = Min(g[j], g[j + 1]);
        for (j = l[i - 1]; j <= r[i - 1]; ++j) mn[j] = Min(mn[j], mn[j - 1]);
        x = c[l[i]] - c[r[i - 1]], s = 0;
        for (j = l[i]; j <= r[i]; ++j)
            s += c[j] - c[l[i]], len = j - l[i] + 1,
            f[j] = s + (l[i - 1] <= r[i - 1] - len + 1? Min(x * len + g[r[i - 1] - len + 1], mn[r[i - 1] - len]): g[l[i - 1] - 1] + x * len);
    }
    printf("%lld",f[cn]);
}
