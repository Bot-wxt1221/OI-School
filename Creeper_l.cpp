#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls id << 1
#define rs id << 1 | 1
const int MAXN = 2e5 + 10;
vector <int> v[MAXN];
int n,m,ans;
struct SegmentTree {
	int l,r,mn,sum,tag;
}tree[MAXN << 2];
inline SegmentTree Pushup(SegmentTree LS,SegmentTree RS) {
	SegmentTree res;
	res.l = LS.l,res.r = RS.r;
	res.tag = 0;
	res.mn = min(LS.mn,RS.mn);
	if(LS.mn == RS.mn) 
		res.sum = LS.sum + RS.sum;
	else if(LS.mn < RS.mn) 
		res.sum = LS.sum;
	else res.sum = RS.sum;
	return res;
}
inline void Build(int id,int l,int r) {
	tree[id].l = l,tree[id].r = r,tree[id].tag = 0;
	if(l == r) {tree[id].mn = 0;tree[id].sum = 1;return;}
	int mid = (l + r) >> 1;
	Build(ls,l,mid),Build(rs,mid + 1,r);
	tree[id] = Pushup(tree[ls],tree[rs]); 
//	cout << tree[id].l << " " << tree[id].r << endl;
}
inline void Pushdown(int id) {
	if(tree[id].tag == 0) return;
	tree[ls].tag += tree[id].tag;
	tree[rs].tag += tree[id].tag;
	tree[ls].mn += tree[id].tag;
	tree[rs].mn += tree[id].tag;
	tree[id].tag = 0;
}
inline void Update(int id,int l,int r,int a,int b,int c) {
	if(a <= l && b >= r) {
		tree[id].tag += c,tree[id].mn += c;
		return;
	} Pushdown(id); int mid = (l + r) >> 1;
	if(a <= mid) Update(ls,l,mid,a,b,c);
	if(b > mid) Update(rs,mid + 1,r,a,b,c);
	tree[id] = Pushup(tree[ls],tree[rs]);
}
inline SegmentTree Query(int id,int l,int r,int a,int b) {
	if(a <= l && b >= r) return tree[id];
	Pushdown(id); int mid = (l + r) >> 1;
	if(a > mid) return Query(rs,mid + 1,r,a,b);
	else if(b <= mid) return Query(ls,l,mid,a,b);
	else return Pushup(Query(ls,l,mid,a,b),Query(rs,mid + 1,r,a,b));
}
typedef pair <int,int> pii;
pii p[MAXN];
inline bool check(int x,int y) {
	return 1;
}
inline void solve(vector <int> z,int k) {
	z.emplace_back(0ll);
	sort(z.begin(),z.end());
	int pos = 0;
	for(int i = 0;i < z.size();i++)
		if(z[i] == k) pos = i;
	for(int i = 0;i < pos;i++) {
		int val = (pos-i == 1 || pos-i == 3 ? 1 : -1);
		Update(1,1,n*m+1,z[i] + 1,z[i + 1],val);
	}
}
signed main() {
	scanf("%lld %lld",&n,&m);
	v[0].resize(m + 5);
	v[n + 1].resize(m + 5);
	for(int i = 0;i <= m + 1;i++)
		v[0][i] = v[n + 1][i] = n*m+1; 
	for(int i = 1;i <= n;i++) {
		v[i].resize(m + 5);
		v[i][0] = n*m+1;
		for(int j = 1;j <= m;j++) 
			scanf("%lld",&v[i][j]);
		v[i][m + 1] = n*m+1;
	} Build(1,1,n * m+1);
	for(int i = 1;i <= n;i++)	
		for(int j = 1;j <= m;j++) 
			p[v[i][j]] = make_pair(i,j);
	for(int i = 1;i <= n*m;i++) {
		int x = p[i].first,y = p[i].second;
		if(check(x - 1,y - 1)) 
			solve({v[x - 1][y - 1],v[x - 1][y],v[x][y - 1],v[x][y]},i);
		if(check(x + 1,y + 1)) 
			solve({v[x + 1][y + 1],v[x + 1][y],v[x][y + 1],v[x][y]},i);
		if(check(x + 1,y - 1)) 
			solve({v[x + 1][y - 1],v[x + 1][y],v[x][y - 1],v[x][y]},i);
		if(check(x - 1,y + 1)) 
			solve({v[x - 1][y + 1],v[x - 1][y],v[x][y + 1],v[x][y]},i);
		SegmentTree res = Query(1,1,n*m+1,1,i);
		if(res.mn == 4) ans += res.sum;
	} printf("%lld",ans);
	return 0;
}
/*
4 4
4 1 5 6
3 13 7 11
2 14 8 9
16 15 12 10
*/
