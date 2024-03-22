#include "testlib.h"

const int N = 1E6 + 100;
int vis[N];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int k = ouf.readInt(0, n);
    int kans = ans.readInt();
    if (k != kans)
        quitf(_wa, "bad answer, %d vs. %d", k, kans);
    int a = ouf.readInt(1, n);
    vis[a] = 1;
    for (int i = 0; i < k - 1; ++i) {
        int b = ouf.readInt(1, n);
        if (gcd(a, b) == 1) quitf(_wa, "bad construction, gcd(%d, %d) = 1", a, b);
        if (vis[b]) quitf(_wa, "%d in (%d, %d) has appeared before", b, a, b);
        vis[b] = 1;
        a = b;
    }

    quitf(_ok, "correct");

    return 0;
}
