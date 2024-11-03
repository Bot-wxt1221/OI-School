# include <bits/stdc++.h>
# define ll long long
using namespace std;

ll Rand (ll x, ll y) {
	return rand () % (y - x + 1) + x;
}

signed main () {
	freopen ("guiltiness.in", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	srand (time (0));
	
	ll n = Rand (1, 7), m = Rand (1, 7);
	cout << n << " " << m << endl; n --, m --;
	for (ll i = 1; i <= n; i ++) cout << Rand (1, 7) << " "; cout << endl;
	for (ll i = 1; i <= m; i ++) cout << Rand (1, 7) << " "; cout << endl;
	
	return 0;
}
