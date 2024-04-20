#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
int t, n, c, d[N], tot, ys[N], f[4000][4000], tmp[4000];
int lst[4000][4000], g[4000][4000], len;
unordered_map<int, int> mp;

void dfs(int x, int now) {
    if (!x || now == 1 || !now) return ;
    // cout << x << ' ' << now << ' ' << f[x][mp[now]] << '\n';
    if (!ys[g[x][mp[now]]]) return;
    dfs(lst[x][mp[now]], now / ys[g[x][mp[now]]]);
    tmp[++len] = g[x][mp[now]];
}

int main() {
//    freopen("C.in", "r", stdin);
//    freopen("C.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i <= 3000; ++i)
        for (int j = 0; j <= 3000; ++j)
            f[i][j] = 1e9;
    while (t--) {
        scanf("%d%d", &n, &c);
        tot = 0; mp.clear(); len = 0;
        for (int i = 1; i <= c / i; ++i) {
            if (c % i == 0) {
                ys[++tot] = i;
                if (i * i != c) ys[++tot] = c / i;
            }
        }
        sort(ys + 1, ys + 1 + tot);
        for (int i = 1; i <= tot; ++i) mp[ys[i]] = i, f[i][1] = 0;
        f[0][1] = 0;
        for (int i = 1; i <= tot; ++i) {
            for (int j = 1; j <= tot; ++j) {
                f[i][j] = f[i - 1][j];
                g[i][j] = g[i - 1][j];
                lst[i][j] = lst[i - 1][j];
                if (ys[j] % ys[i]) continue;
                if (i > j) continue;
                if (f[i][j] > f[i - 1][mp[ys[j] / ys[i]]] + 1)
                    f[i][j] = f[i - 1][mp[ys[j] / ys[i]]] + 1,
                    g[i][j] = i,
                    lst[i][j] = i - 1;
                if (f[i][j] > f[i][mp[ys[j] / ys[i]]] + 1)  
                    f[i][j] = f[i][mp[ys[j] / ys[i]]] + 1,
                    g[i][j] = i,
                    lst[i][j] = i;
            }
        }
        
        int cc, dn = 1e9, pp = -1, aa = 0, ccc;
        for (int i = 2; i <= tot; ++i) {
            int p = -1, s = 1;
            cc = 0;
            for (int a = 0; a <= n; ++a) {
                if(1ll*s*(ys[i]-a)>c){
                  break ;
                  }
                s *= (1ll*ys[i] - a);
                if (s == 0) break;
                if (c % s) continue;
                if (f[i][mp[c / s]] + a + 1 > n) {
                    break;
                } else cc = c / s, p = a;
            }
            if (p == -1) continue;
            if (dn > ys[i] + n - p - 1)
                dn = ys[i] + n - p - 1,
                aa = p,
                pp = i,
                ccc = cc;
        }
        // cout << pp << ' ' << aa << '\n';
        // cout << dn << ' ' << ccc << ' ' << ys[pp] << '\n';
        dfs(pp, ccc);
        
        int cnt = 1;
        // for (int i = 1; i <= len; ++i) cout << tmp[i] << ' ';
        // cout << '\n';
        for (int i = 1; i <= n - f[pp][mp[ccc]] - aa - 1; ++i) {
            cout << i << ' ';
        }
        // puts("");
        for (int i = n - f[pp][mp[ccc]] - aa; i <= n; ++i) {
            if (i > n - aa - 1) {
                cout << ys[pp] + n - aa - 1 << ' ';
            }
            else cout << ys[tmp[cnt]] + i - 1 << ' ';
            cnt++;
        }
        puts("");
    }
    return 0;
}
