#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  registerTestlibCmd(argc, argv);
  int sub = inf.readInt(1, 6), n = inf.readInt(1, 1000),
      C = inf.readInt(0, 1000);
  string A = inf.readToken();
  string B = inf.readToken();
  auto readAns = [&](InStream &s, bool is_ans = false) -> long long {
    int m = s.readInt(-1, 1e6, "m");
    if (m == -1) {
      ensure(is_ans);
      return s.readLong();
    }
    string cur = A;
    long long tot = 0;
    for (int i = 1; i <= m; i++) {
      int l = s.readInt(1, n, "l");
      int r = s.readInt(l, min(n, l + 2), "r");
      l--, r--;
      tot += C;
      for (int j = l; j <= r; j++)
        tot += cur[j] == 'R' ? 1 : 2;
      if (l != r)
        swap(cur[l], cur[r]);
    }
    ensuref(cur == B, "Wrong construction.");
    return tot;
  };
  auto pans = readAns(ouf), jans = readAns(ans, true);
  if (pans > jans)
    quitf(_wa, "Your cost is %lld but ans cost is %lld.", pans, jans);
  else if (pans < jans)
    quitf(_fail, "How did you come up with that?");
  quitf(_ok, "Well done. Total cost: %lld", jans);
}