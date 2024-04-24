#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, k, o, head[N], vis[N], fa[N], id[N];
int mx[N], siz[N], dep[N], to[N][18], rt, tot;
struct Edge { int v, nxt; }e[N << 1];
struct Dftree {
	int lenth,lenth2;
	vector<int> son;
	vector<int> f1, f2;
	#define lowbit(x) (x & (-x))
	inline void add1(int x) {
		x++;
		if(x>lenth){
			cerr<<x<<endl;
		}
		while (x <= lenth) {
			f1[x]++;
			x += lowbit(x);
		}
	}
	inline int ask1(int x) {
		x++;
		if(x>lenth){
			cerr<<x<<endl;
		}
		int res = 0;
		x = min(x, lenth);
		while (x) {
			res += f1[x];
			x -= lowbit(x);
		}
		return res;
	}
	inline void add2(int x) {
		x++;
		if(x>lenth2){
			cerr<<x<<endl;
		}
		while (x <= lenth2) {
			f2[x]++;
			x += lowbit(x);
		}
	}
	inline int ask2(int x) {
		x++;
		if(x>lenth2){
			cerr<<x<<endl;
		}
		int res = 0;
		x = min(x, lenth2);
		while (x) {
			res += f2[x];
			x -= lowbit(x);
		}
		return res;
	}
}t[N];

inline void adde(int u, int v) {
	e[++o] = { v, head[u] };
	head[u] = o;
}

inline void dfs(int u, int from) {
	dep[u] = dep[from] + 1;
	to[u][0] = from;
	for (int i = 1; i <= 17; ++i)
		to[u][i] = to[to[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == from) continue;
		dfs(v, u);
	}
}

inline int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 17; i >= 0; --i)
		if (dep[to[y][i]] >= dep[x])
			y = to[y][i];
	if (x == y) return x;
	for (int i = 17; i >= 0; --i)
		if (to[x][i] != to[y][i])
			x = to[x][i], to[y][i];
	return to[x][0];
}

inline int dis(int x, int y) {
	int t = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[t];
}

inline void getrt(int u, int from) {
	mx[u] = 0, siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == from || vis[v]) continue;
		getrt(v, u);
		siz[u] += siz[v];
		mx[u] = max(mx[u], siz[v]);
	}
	mx[u] = max(mx[u], tot - siz[u]);
	if (mx[u] < mx[rt]) rt = u;
}

inline void calc(int st, int u, int from) {
	t[st].son.emplace_back(u);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (v == from || vis[v]) continue;
		calc(st, v, u);
	}
} 

inline void dfz(int u) {
	vis[u] = 1;
	calc(u, u, u);
//	int len = t[u].son.size();
//	if(u==54){
//		cerr<<1;
//	}
	t[u].lenth = tot + 5;
	t[u].lenth2 = t[fa[rt]].son.size() + 5;
	t[u].f1.resize(tot + 10);
	t[u].f2.resize(t[fa[rt]].son.size() + 10);
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (vis[v]) continue;
		tot = mx[rt = 0] = siz[v];
		getrt(v, u);
		fa[rt] = u;
		getrt(rt,rt);
		dfz(rt);
	}
}

bool cmp(int x, int y) {
	return dep[x] < dep[y];
}

void insert(int x) {
//	if(x==95){
//		std::cerr<<1;
//	}
	int now = x;
	while (now) {
		t[now].add1(dis(x, now));
		if (fa[now]) t[now].add2(dis(x, fa[now]));
		now = fa[now];
	}
}

int query(int x) {
	int res = 0, son_now = x, now = fa[x];
	res += t[x].ask1(min(k, t[x].lenth-1));
//	if(x==2)cout<<t[x].ask1(min(k, t[x].lenth-1))<<endl;
	while (now) {
		int d = k - dis(x, now);
//		if(x==2){
//			cout<<now<<' '<<d<<endl;
//			cout<<res<<endl;
//		}
		if (d >= 0) {
			res += t[now].ask1(min(d, t[now].lenth-1));
			res -= t[son_now].ask2(min(d, t[son_now].lenth2-1));
		}
		son_now = now, now = fa[now];
	}
	return res;
}

int main() {
//	freopen("../../tree7.in","r",stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	dfs(1, 0);
	tot = mx[rt = 0] = n, getrt(1, 0);
	getrt(rt,rt);
	dfz(rt);
	
	LL ans = 0;
	for (int i = 1; i <= n; ++i) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
//	for(int i=1;i<=n;i++)
//		cout<<fa[i]<<' ';
//	cout<<endl;
	for (int i = 1; i <= n; ++i) {
		LL c = query(id[i]);
		ans += c * (c - 1) / 2;
//		cout<<t[id[i]].ask1(1)<<endl;
//		cout << id[i] << ' ' << c << endl;
		insert(id[i]);
	}
	printf("%lld\n", ans);
	return 0;
}

/*
7 7
1 2
1 3
3 4
4 5
4 6
5 7
*/
