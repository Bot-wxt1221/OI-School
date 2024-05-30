#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 400000;
int a[MAXN];
signed main() {
	freopen("sort.in","w",stdout);
	srand(time(0));
	int n = 300000;
	cout << n << endl;
	for(int i = 1;i <= n;i++) a[i] = 1ll * rand() * rand()%1000000000 * rand() % 1000000000 + 1;
	random_shuffle(a + 1,a + n + 1);
	random_shuffle(a + 1,a + n + 1);
	random_shuffle(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) cout << a[i] << " "; 
	return 0;
}
