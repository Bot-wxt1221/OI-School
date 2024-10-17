// Author: HeRaNO
#include "testlib.h"

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	int s = inf.readInt();
	int t = inf.readInt();
	std::vector<std::vector<int>> submissions(n, std::vector<int>(s));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < s; j++)
			submissions[i][j] = inf.readInt();
	std::vector<std::vector<int>> pans(n, std::vector<int>(s));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < s; j++)
			pans[i][j] = ouf.readInt(1, t, "r_j");
		std::vector<int> a = submissions[i], b = pans[i];
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		for (int j = 0; j < s; j++)
			quitif(a[j] != b[j], _wa, "Core %d: wrong task %d", i + 1, b[j]);
	}
	std::vector<int> min_sub(t, 1'000'000'000), max_sub(t, 0);
	std::vector<int> not_appear(t, 0);
	for (int j = 0; j < s; j++)
	{
		std::vector<int> c(n);
		for (int i = 0; i < n; i++)
			c[i] = pans[i][j] - 1;
		std::sort(c.begin(), c.end());
		int l = 0, las = -1;
		for (int r = 0; r < n; l = r)
		{
			for (; r < n && c[r] == c[l]; r++);
			min_sub[c[l]] = std::min(min_sub[c[l]], r - l);
			max_sub[c[l]] = std::max(max_sub[c[l]], r - l);
			if (las + 1 <= c[l] - 1)
			{
				++not_appear[las + 1];
				--not_appear[c[l]];
			}
			las = c[l];
		}
		if (las < t - 1)
			++not_appear[las + 1];
	}
	for (int i = 1; i < t; i++)
		not_appear[i] += not_appear[i - 1];
	for (int i = 0; i < t; i++)
		if (not_appear[i]) min_sub[i] = 0;
	for (int i = 0; i < t; i++)
		if (max_sub[i] - min_sub[i] > 1)
			quitf(_wa, "task %d: max - min > 1, %d %d", i + 1,max_sub[i],min_sub[i]);
	quitf(_ok, "ok");
	return 0;
}
