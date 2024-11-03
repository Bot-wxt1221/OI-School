# include <bits/stdc++.h>
# define ll long long
using namespace std;
signed main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	
	ll asd = 0;
	while (++ asd) {
		cout << "asd = " << asd << endl;
		system ("./run_mikker");
		system ("./run_guiltiness");
		system ("./run_guiltiness_2");
		if (system ("diff guiltiness.out guiltiness_2.out")) break;
	}
	
	return 0;
}
