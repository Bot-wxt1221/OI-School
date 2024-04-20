#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n,m,a[MAXN],op,fa[MAXN],id[MAXN],depth[MAXN];
bool flag[MAXN];
inline int Find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
} 
signed main()
{
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= 2 * n;i++) fa[i] = i,id[i] = i;
	for(int i = 1;i <= 2 * n;i++) flag[i] = true;
	for(int i = 1,x,y,z;i <= m;i++)
	{
		cin >> op;
		if(op == 1) cin >> x >> y,a[x] = y;
		if(op == 2)
		{
			cin >> x >> y;
			if(x == y) continue;
			int X1 = Find(x),X2 = Find(x + n);
			int Y1 = Find(y),Y2 = Find(y + n);
			fa[Y2] = X1,fa[X2] = Y1;
		}
		if(op == 3)
		{
			cin >> x >> y >> z;
			int X1 = Find(x),X2 = Find(x + n),p;
			int Y1 = Find(y),Y2 = Find(y + n),q;
			if (X1 == X2 || Y1 == Y2 || z == 0) {cout << 0ll << endl;continue;}
			else if (X1 == Y1) p = z * a[x],q = a[y];
			else if (X1 == Y2) p = -z * a[x],q = a[y];
			else {cout << 0ll << endl;continue;}
			cout << p / abs(__gcd(p,q)) << '/' << q / abs(__gcd(p,q)) << endl;
		}
	}
	return 0;
}
/*
4 10 
6 8 10 13
3 1 2 2
2 1 2
3 1 2 3
2 2 3
1 1 7
3 1 3 10
2 3 1
3 1 3 2
2 1 4
3 1 4 6
*/
