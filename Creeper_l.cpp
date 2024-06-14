#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 4e6 + 10;
const int mod = 998244353;
typedef pair <int,int> pii;
int a,b,q,p,dp[MAXN],bit[MAXN],tot,vis[MAXN];
inline int Qpow(int x,int k) {
	int res = 1;
	for(;k >= 1;k >>= 1) {
		if(k & 1) res = res * x % mod;
		x = x * x % mod;
	} return res;
}
pii f[MAXN];
signed main() {
	cin >> a >> b >> q;
	p = q * Qpow(1000000ll,mod - 2) % mod;
	if((1ll << __lg(b)) == b) {
		while(a != 0) {
			++tot;
			if(a * 2 >= b) bit[tot] = 1,a = (a * 2) % b;
			else bit[tot] = 0,a *= 2; 
//			cout << bit[tot] << " ";
		}
		dp[tot] = p;
		for(int i = tot - 1;i >= 1;i--) {
			if(bit[i] == 1) dp[i] = (dp[i + 1] + (1 - dp[i + 1] + mod) * p % mod) % mod;
			else dp[i] = dp[i + 1] * p % mod;
		}
//		cout << "tot = " << tot << endl;
		cout << dp[1];
	} else {
		int l = 0,r = 0;
		while(a != 0) {
			++tot;
			if(a * 2 >= b) bit[tot] = 1,a = (a * 2) % b;
			else bit[tot] = 0,a *= 2;
//			printf("%d",bit[tot]);
			if(vis[a] ) {
				l = vis[a],r = tot-1;
				break;
			} else vis[a] = tot;
		}
		f[r + 1].first = 1,f[r + 1].second = 0;
		for(int i = r;i >= l;i--) {
			if(bit[i] == 0) f[i].first = f[i + 1].first * p % mod,
				f[i].second = f[i + 1].second * p % mod;
			else {
				f[i] = f[i + 1];
				f[i].second = (f[i].second + p) % mod;
				f[i].first = (f[i].first - f[i + 1].first * p % mod + mod) % mod;
				f[i].second = (f[i].second - f[i + 1].second * p % mod + mod) % mod;
			}
//			cout << f[i].first << " " << f[i].second <<endl;
		} 
//		cout << "l = " << l << " r = " << r << endl;
		int F = f[l].second * Qpow((1 - f[l].first + mod) % mod,mod - 2) % mod;
		dp[r + 1] = F;
		for(int i = r;i >= 1;i--) {
			if(bit[i] == 1) dp[i] = (dp[i + 1] + (1 - dp[i + 1] + mod) * p % mod) % mod;
			else dp[i] = dp[i + 1] * p % mod;
		}
		cout << dp[1];
	}
	return 0;
}
