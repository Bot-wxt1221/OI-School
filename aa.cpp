#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 16;
const ll mod = 998244353;
int n;
ll m,a[N + 5],Lcm[1 << N],f[1 << N],g[N + 5] = {1,1};
int main()
{
	scanf("%d %lld",&n,&m);
	for(int i = 2;i <= n;i++)g[i] = (mod - g[i - 1]) * (i - 1) % mod;
	for(int i = 1;i <= n;i++)scanf("%lld",&Lcm[1 << i - 1]);
	f[0] = Lcm[0] = 1;
	for(int i = 1;i < (1 << n);i++)
	{
		ll lb = i & -i;
		Lcm[i] = Lcm[lb];
		Lcm[i] /= __gcd(Lcm[i],Lcm[i ^ lb]);
		if(__int128(Lcm[i]) * Lcm[i ^ lb] > m)Lcm[i] = m + 1;
		else Lcm[i] *= Lcm[i ^ lb];
		for(int j = i ^ lb;j;j = (i ^ lb) & (j - 1))
			(f[i] += (m / Lcm[j ^ lb]) % mod * f[i ^ j ^ lb] % mod * g[__builtin_popcount(j ^ lb)]) %= mod;
		(f[i] += (m / Lcm[lb]) % mod * f[i ^ lb]) %= mod;
	}
	cout<<f[(1 << n) - 1];
}
