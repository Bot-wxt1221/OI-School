#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MXN = 5000005;
const int MXM = 200005;
const int DVS = 1000000009;
int N, M, pp[MXM], val[MXN], ans[MXN], output(1);
int sid[MXN];
int rseed, rbase;
ll sum[2], rest;

int rnd() {
  int ret(rseed);
  rseed = (rseed * 1LL * rbase + 233) % DVS;
  return ret;
}

int main() {
  scanf("%d", &N);
    for (int j(0); j != N; ++j)
    scanf("%d%d",&sid[j],&val[j]);
  for (int i(1); i != N; ++i) {
    sum[sid[i] ^= sid[0]] += val[i];
  }
  sum[sid[0] = 0] += val[0];
  if (sum[0] <= sum[1]) {
    swap(sum[0], sum[1]);
    for (int i(0); i != N; ++i) sid[i] = !sid[i];
  } else --val[0], ++ans[0];
  for (int i(0); i != N; ++i) {
    if (sid[i]) {
      rest += ans[i] = val[i], val[i] = 0;
    } else {
      int t(min(rest, static_cast<ll>(val[i])));
      ans[i] += t, val[i] -= t, rest -= t;
    }
  }
  for (int i(0); i != N; ++i) {
    if (!sid[i]) {
      int t(min(rest, static_cast<ll>(val[i])));
      ans[i] += t, val[i] -= t, rest -= t;
    }
  }
  for (int i(0); i != N; ++i) {
    std::cout<<ans[i]<<std::endl;
    output = output * 1LL * ((ans[i] ^ ((i + 1) * 1LL * (i + 1))) % DVS + 1) % DVS;
  }
  cout << output << endl;
  return 0;
}
