#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int MAXN = 1e5 + 10;
int n,x,L[MAXN],R[MAXN],l[MAXN][20],r[MAXN][20],Max[MAXN][20],Min[MAXN][20];
inline void ST_Init(int k)
{
	for(int i = 1;i <= n;i++) Max[i][0] = r[i][k];
	for(int i = 1;i <= __lg(n);i++)
		for(int j = 1;j <= n;j++) Max[j][i] = max(Max[j][i - 1],Max[j + (1 << i - 1)][i - 1]);
	for(int i = 1;i <= n;i++) Min[i][0] = l[i][k];
	for(int i = 1;i <= __lg(n);i++)
		for(int j = 1;j <= n;j++) Min[j][i] = min(Min[j][i - 1],Min[j + (1 << i - 1)][i - 1]);
}
inline int Get_min(int l,int r)
{
	int k = __lg(r - l + 1);
	return min(Min[l][k],Min[r - (1 << k) + 1][k]);
}
inline int Get_max(int l,int r)
{
	int k = __lg(r - l + 1);
	return max(Max[l][k],Max[r - (1 << k) + 1][k]);
}
int minn[MAXN];
#define inf 0x3f
int LLL[MAXN],RRR[MAXN],LLLL[MAXN],RRRR[MAXN];
inline bool check()
{
	memset(minn,inf,sizeof minn);
	for(int i = 1;i <= n;i++)
	{
		int pos = LLLL[i];
		if(i > minn[pos - 1]) return true;
		minn[i] = min(minn[i - 1],RRRR[i]);
	}
	return false;
}
signed main()
{ 
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> x,
		L[i] = l[i][0] = max(1,i - x),
		R[i] = r[i][0] = min(n,i + x);
	for(int i = 1;i <= __lg(n);i++)
	{
		ST_Init(i - 1);
		for(int j = 1;j <= n;j++) l[j][i] = Get_min(l[j][i - 1],r[j][i - 1]);
		for(int j = 1;j <= n;j++) r[j][i] = Get_max(l[j][i - 1],r[j][i - 1]);
	}
	int LL = 0,RR = n,ans = 0;
	for(int i = 1;i <= n;i++) LLL[i] = RRR[i] = i;
	for(int i = __lg(n);i >= 0;i--)
	{
		ST_Init(i);
		for(int j = 1;j <= n;j++)
			LLLL[j] = Get_min(LLL[j],RRR[j]),
			RRRR[j] = Get_max(LLL[j],RRR[j]);
		if(check())
		{
			ans += (1 << i);
			for(int j = 1;j <= n;j++)
				LLL[j] = LLLL[j],RRR[j] = RRRR[j];
		}
	}
	cout << ans + 1;
	return 0;
} 
