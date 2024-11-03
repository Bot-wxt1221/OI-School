# include <bits/stdc++.h>
# define ll long long
# define INF 0x3f3f3f3f3f3f3f
using namespace std;

ll n, m, a[200005], b[200005], ans = INF;

inline bool cmp (ll x, ll y) {return x > y;}

ll out[200005], vis[200005];
void dfs (ll p) {
	if (p == n + m + 1) {
		ll now = 0, x = 0, y = 0;
		for (ll i = 1; i <= n + m; i ++) {
			if (out[i] <= n) {
				now += a[out[i]] * (y + 1);
				x ++;
			}
			else {
				now += b[out[i] - n] * (x + 1);
				y ++;
			}
		}
//		if (now < ans) {
//			cout << "now = " << now << "   out : ";
//			for (ll i = 1; i <= n + m; i ++) cout << out[i] << " ";
//			cout << endl;
//		}
		ans = min (ans, now);
		return;
	}
	for (ll i = 1; i <= n + m; i ++) {
		if (vis[i]) continue;
		vis[i] = 1; out[p] = i;
		dfs (p + 1); vis[i] = 0;
	}
}

signed main () {
	freopen ("guiltiness.in", "r", stdin);
	freopen ("guiltiness_2.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);

	cin >> n >> m; n --, m --;
	for (ll i = 1; i <= n; i ++) cin >> a[i];
	for (ll i = 1; i <= m; i ++) cin >> b[i];
	
	dfs (1);
	cout << ans;
	
	return 0;
}
