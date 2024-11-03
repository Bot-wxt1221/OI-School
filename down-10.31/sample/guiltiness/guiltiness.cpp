# include <bits/stdc++.h>
# define ll long long
# define INF 0x3f3f3f3f3f3f3f
using namespace std;

ll n, m, a[200005], b[200005];

class {
	public : 
		ll dp[5005][5005];
		void work () {
			for (ll i = 1; i <= n; i ++) dp[i][0] = dp[i - 1][0] + a[i];
			for (ll i = 1; i <= m; i ++) dp[0][i] = dp[0][i - 1] + b[i];
			for (ll i = 1; i <= n; i ++)
				for (ll j = 1; j <= m; j ++)
					dp[i][j] = min (dp[i - 1][j] + a[i] * (j + 1), dp[i][j - 1] + b[j] * (i + 1));
			cout << dp[n][m];
		}
} work_0;

class {
	public : 
		ll top[2] = {1, 1}, ans;
		void work () {
			while (top[0] <= n || top[1] <= m) {
//				cout << "top[0] = " << top[0]  << "   top[1] = " << top[1] << endl;
				if (top[0] == n + 1) {
//					cout << "st _ 1"  << endl;
					while (top[1] <= m) ans += b[top[1] ++] * top[0];
				}
				else if (top[1] == m + 1) {
//					cout << "st _ 2" << endl;
					while (top[0] <= n) {
						ans += a[top[0] ++] * top[1];
//						cout << "ans = " << ans << endl;
					}
				}
				else {
					if (b[top[1]] < a[top[0]])  {
						ans += a[top[0] ++] * top[1];
//						cout << "st _ 3 : ans = " << ans << endl;
					}
					else {
						ans += b[top[1] ++] * top[0];
//						cout << "st _ 4 : ans = " << ans << endl;
					}
				}
			}
			cout << ans;
		}
} work_1;

inline bool cmp (ll x, ll y) {return x > y;}

signed main () {
	freopen ("guiltiness.in", "r", stdin);
	freopen ("guiltiness.out", "w", stdout);
	
	sort (a + 1, a + 1 + n, cmp);
	sort (b + 1, b + 1 + m, cmp);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);

	cin >> n >> m; n --, m --;
	for (ll i = 1; i <= n; i ++) cin >> a[i];
	for (ll i = 1; i <= m; i ++) cin >> b[i];
	
	sort (a + 1, a + 1 + n, cmp);
	sort (b + 1, b + 1 + m, cmp);
	
//	work_0.work ();
	work_1.work ();
	
	return 0;
}
