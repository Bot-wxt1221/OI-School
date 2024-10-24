#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 5005, S = 10, M = 1 << 9 | 5, P = 1e9 + 9;

int n;
char a[N], b[N];
int go[M][S], f[N][M];

#define Add(x, y) (((x) += (y)) >= P && ((x) -= P))
inline void Read(char a[])
{
    scanf("%s", a + 1);
    int i;
    for(i = 1; a[i]; i ++ ) a[i] -= '0';
    reverse(a + 1, a + i);
}
inline void Del(char a[])
{
    int t = 0;
    for(int i = 1; i <= n; i ++ ) t |= a[i];
    if(t)
    {
        for(int i = 1; i <= n; i ++ )
        {
            if(a[i])
            {
                a[i] -- ;
                break ;
            }
            a[i] = 9;
        }
    }
}
inline LL Sum(char a[])
{
    LL s = 1, t = 0;
    for(int i = 1; i < n; i ++ )
    {
        t = (t + s * a[i]) % P;
        s = s * 10 % P;
    }
    // printf("!%lld\n", t);
    return (s * a[n] * (a[n] - 1) / 2 + (t + 1) * a[n]) % P;
}
inline void Init()
{
    for(int i = 0; i < 1 << 9; i ++ )
    {
        go[i][0] = i;
        for(int j = 0; j < 9; j ++ )
        {
            int t = j;
            while(!((i >> t) & 1) && t >= 0) t -- ;
            go[i][j + 1] = i ^ (1 << j);
            if(t >= 0) go[i][j + 1] ^= 1 << t;
        }
    }
    
    for(int i = 1; i < 1 << 9; i ++ )
        f[0][i] = f[0][i & (i - 1)] + 1;
    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j < 1 << 9; j ++ )
            for(int k = 0; k <= 9; k ++ )
                Add(f[i][j], f[i - 1][go[j][k]]);
}
inline LL DP(char a[])
{
    int s = 0, ans = 0;
    for(int i = n; i >= 1; i -- )
    {
        for(int j = 0; j < a[i]; j ++ )
            Add(ans, f[i - 1][go[s][j]]);
        s = go[s][int(a[i])];
    }
    ans += f[0][s];
    // printf("!%d\n", ans);
    return ans;
}

int main()
{
    // freopen("data", "r", stdin);
    scanf("%d", &n);
    Read(a), Read(b), Del(a);
    Init();
    LL s0 = (Sum(b) - Sum(a) + P) % P;
    LL s1 = (DP(b) - DP(a) + P) % P;
    LL ans = (s1 * 10 - s0 + P) % P;
    printf("%lld\n", ans);
    return 0;
}
