#pragma GCC optimize(3) // 手动开 O3
// Code by KSkun, 2019/12
#include <cstdio>
#include <cctype>
#include <cstring>

#include <algorithm>
#include <utility>

typedef unsigned long long LL;
typedef std::pair<int, int> PII;

inline char fgc() {
  return getchar();
}

inline LL readint() {
	register LL res = 0, neg = 1; register char c = fgc();
	for (; !isdigit(c); c = fgc()) if (c == '-') neg = -1;
	for (; isdigit(c); c = fgc()) res = res * 10 + c - '0';
	return res * neg;
}

inline char readsingle() {
	char c;
	while (!isgraph(c = fgc())) {}
	return c;
}

const int MAXN = 40000005, MAXM = 100005;;
const LL MASK = (1ull << 30) - 1; // % 2^30 和 & MARK 等价

int n, type, lst[MAXN];
LL s[MAXN];

void gen_data() {
	LL x, y, z, m;
	x = readint(); y = readint(); z = readint();
	s[1] = readint(); s[2] = readint();
	m = readint();
	int* p = new int[MAXM], * l = new int[MAXM], * r = new int[MAXM];
	p[0] = l[0] = r[0] = 0;
	for (int i = 1; i <= m; i++) {
		p[i] = readint();
		l[i] = readint();
		r[i] = readint();
	}
	for (int i = 3; i <= n; i++) {
		s[i] = (x * s[i - 1] + y * s[i - 2] + z) & MASK; // 复用 s 数组省空间
	}
	for (int i = 1; i <= m; i++) {
		for (int j = p[i - 1] + 1; j <= p[i]; j++) {
			s[j] = (s[j] % (r[i] - l[i] + 1)) + l[i] + s[j - 1]; // 复用 s 数组省空间
		}
	}
	delete[] p; delete[] l; delete[] r; // 内存回收
}

const int BN_MAX = 1e9;
struct BigNum {
	LL dat[5];
	int len;
	BigNum() {
		dat[0] = dat[1] = dat[2] = dat[3] = dat[4] = 0; // 手动初始化没用 memset 减小常数
		len = 0;
	}
	BigNum(LL x) {
		dat[0] = dat[1] = dat[2] = dat[3] = dat[4] = 0;
		len = 0;
		while (x > 0) {
			dat[len++] = x % BN_MAX;
			x /= BN_MAX;
		}
	}

	BigNum operator+(const BigNum& rhs) const {
		BigNum res;
		if (len == 0) return rhs; // 减少运算次数
		if (rhs.len == 0) return *this;

		res.len = std::max(len, rhs.len);
		for (register int i = 0; i < res.len; i++) {
			if (dat[i] == 0 && rhs.dat[i] == 0) continue; // 减少运算次数
			res.dat[i] += dat[i] + rhs.dat[i];
			if (res.dat[i] > BN_MAX) { // 减少运算次数
				res.dat[i + 1] += res.dat[i] / BN_MAX;
				res.dat[i] %= BN_MAX;
			}
		}
		if (res.dat[res.len] != 0) res.len++;
		return res;
	}
	BigNum operator*(const BigNum& rhs) const {
		BigNum res;
		if (len == 0 || rhs.len == 0) return res;

		res.len = len + rhs.len - 1;
		for (register int i = 0; i < len; i++) {
			if (dat[i] == 0) continue; // 减少运算次数
			for (register int j = 0; j < rhs.len; j++) {
				if (rhs.dat[j] == 0) continue; // 减少运算次数
				res.dat[i + j] += dat[i] * rhs.dat[j];
			}
		}
		for (register int i = 0; i < res.len; i++) {
			if (res.dat[i] > BN_MAX) { // 减少运算次数
				res.dat[i + 1] += res.dat[i] / BN_MAX;
				res.dat[i] %= BN_MAX;
			}
		}
		if (res.dat[res.len] != 0) res.len++;
		return res;
	}
};

int d_dat[MAXN], d_l, d_r;

inline LL A(int idx) {
	return 2 * s[idx] - s[lst[idx]];
}

int main() {
	n = readint(); type = readint();

	if (type == 0) {
		for (register int i = 1; i <= n; i++) {
			s[i] = s[i - 1] + readint(); // 输入时就把前缀和做了，减小单独计算的常数
		}
	} else {
		gen_data();
	}

	d_l = d_r = 1; // 单调队列手写而且没封装，常数优化
	for (register int i = 1; i <= n; i++) {
		int lst_ele = 0;
		while (d_l != d_r && s[i] >= A(d_dat[d_l])) {
			lst_ele = d_dat[d_l]; d_l++;
		}
		lst[i] = lst_ele; d_dat[--d_l] = lst_ele;
		LL Ai = A(i); // 没空间存 A 数组，所以用函数，这里是避免重复运算减小常数
		while (d_l != d_r && Ai <= A(d_dat[d_r - 1])) d_r--;
		d_dat[d_r++] = i;
	}

	BigNum ans;
	for (register int i = n; i != 0; i = lst[i]) {
		BigNum t = BigNum(s[i] - s[lst[i]]);
		ans = ans + t * t;
	}
	for (register int i = ans.len - 1; i >= 0; i--) {
		if (i == ans.len - 1) {
			printf("%llu", ans.dat[i]);
		} else {
			printf("%09llu", ans.dat[i]);
		}
	}

	return 0;
}
