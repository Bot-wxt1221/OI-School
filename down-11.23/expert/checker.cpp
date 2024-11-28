// 君の人生は月明かりだ、有りがちだなんて言わせるものか
// Think twice, code once.
#include "testlib_for_lemons.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int T;
long long n, k;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	T = inf.readInt();
	for (int Case = 1; Case <= T; Case++) {
		n = inf.readLong(), k = inf.readLong();
		long long an = ans.readLong(), on = ouf.readLong(-1, n);
		if (an == -1) {
			if (on != -1) quitf(_wa, "Case %d: Expect -1, but read %lld %lld.\n", Case, on, ouf.readLong());
			else continue;
		} else if (on == -1) quitf(_wa, "Case %d: Exist solution but read -1.\n", Case);
		ans.readLong();
		long long a = on, b = ouf.readLong(1, n);
		if (a + b == n && a % b == k) continue;
		quitf(_wa, "Case %d: Wrong solution", Case);
	}
	quitf(_ok, "Accepted!");
	return 0;
}