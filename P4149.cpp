#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
int fir[200005];
std::queue<int> qu;
int nxt[400005];
int v[400005];
int now;
int w[400005];
void add(int x, int y, int z) {
    v[++now] = y;
    w[now] = z;
    nxt[now] = fir[x];
    fir[x] = now;
    return;
}
int siz[400005];
int maxx[400005];
int rt;
bool vised[400005];
int tsiz;
void calcsiz(int now, int fa) {
    siz[now] = 1;
    maxx[now] = 0;
    for (int i = fir[now]; i != -1; i = nxt[i]) {
        if (v[i] == fa || vised[v[i]]) {
            continue;
        }
        calcsiz(v[i], now);
        maxx[now] = std::max(maxx[now], siz[v[i]]);
        siz[now] += siz[v[i]];
    }
    maxx[now] = std::max(maxx[now], tsiz - maxx[now]);
    if (maxx[now] < maxx[rt] || rt == 0) {
        rt = now;
    }
    return;
}
int dis[400005];
int cnt[400005];
int dd;
void calcdis(int now, int fa, int ddis, int ccnt) {
    dis[++dd] = ddis;
    cnt[dd] = ccnt;
    for (int i = fir[now]; i != -1; i = nxt[i]) {
        if (v[i] == fa || vised[v[i]]) {
            continue;
        }
        calcdis(v[i], now, ddis + w[i], ccnt + 1);
    }
    return;
}
int tf[1000005];
int ans = 0x3f3f3f3f;
int k;
void dfs(int now, int fa) {
    tf[0] = 0;
    qu.push(0);
    vised[now] = 1;
    for (int i = fir[now]; i != -1; i = nxt[i]) {
        if (v[i] == fa || vised[v[i]]) {
            continue;
        }
        dd = 0;
        calcdis(v[i], now, w[i], 1);
        for (int j = 1; j <= dd; j++) {
            if (k - dis[j] >= 0) {
                ans = std::min(ans, tf[k - dis[j]] + cnt[j]);
            }
        }
        for (int j = 1; j <= dd; j++) {
            if (dis[j] > 1000000) {
                continue;
            }
            qu.push(dis[j]);
            tf[dis[j]] = std::min(tf[dis[j]], cnt[j]);
        }
    }
    while (qu.size() > 0) {
        tf[qu.front()] = 0x3f3f3f3f;
        qu.pop();
    }
    for (int i = fir[now]; i != -1; i = nxt[i]) {
        if (v[i] == fa || vised[v[i]]) {
            continue;
        }
        tsiz = siz[now];
        rt = 0;
        calcsiz(v[i], now);
        calcsiz(rt, -1);
        dfs(rt, -1);
    }
    return;
}
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    int n = read();
    k = read();
    memset(tf, 0x3f, sizeof(tf));
    for (int i = 1; i <= n; i++) {
        fir[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        int u = read() + 1;
        int v = read() + 1;
        int k = read();
        add(u, v, k);
        add(v, u, k);
    }
    tsiz = n;
    calcsiz(1, 1);
    calcsiz(rt, -1);
    dfs(rt, -1);
    if (ans == 0x3f3f3f3f) {
        ans = -1;
    }
    printf("%d", ans);
    return 0;
}
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        c == '-' ? f = -1 : 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return f * x;
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
