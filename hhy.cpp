#include<bits/stdc++.h>
using namespace std;

namespace FastIO
{
	const int Mt = 1e5;
	inline char getch()
	{
		static char buf[Mt],*p1 = buf,*p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,Mt,stdin),p1 == p2) ? EOF : *p1++;
	}
	
	inline int input()
	{
		int num = 0,f = 1;
		char ch = getch();
		while(ch < '0' || ch > '9')
		{
			if(ch == '-') f = -1;
			ch = getch();
		}
		while(ch >= '0' && ch <= '9')
		{
			num = (num << 1) + (num << 3) + (ch ^ 48);
			ch = getch();
		}
		return num * f;
	}
	
	inline void printNum(int num)
	{
		if(num >= 10) printNum(num / 10);
		putchar(num % 10 + 48);
	}
	
	inline void print(int num,char ch = ' ')
	{
		if(num < 0) putchar('-'),num = -num;
		printNum(num);
		putchar(ch);
	}
}
using FastIO::input;
using FastIO::print;

const int N = 1e5 + 5;
int n,m,cnt,ans,top,timeStamp;
int low[N],dfn[N],bel[N],st[N],ext[N],din[N],dout[N];
bool cst[N];
vector <int> edge[N];

void tarjan(int u)
{
	dfn[u] = low[u] = ++timeStamp;
	st[++top] = u,cst[u] = true;

	for(int v : edge[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(cst[v]) low[u] = min(low[u],dfn[v]);
	}

	int tmp = 0;
	if(low[u] == dfn[u])
	{
		cnt++;
		do tmp = st[top--],cst[tmp] = false,
		bel[tmp] = cnt,ext[cnt]++;
		while(u != tmp);
	}
}

int main()
{
	n = input(),m = input();
	for(int i = 1;i <= m;i++)
	{
		int u = input(),v = input();
		edge[u].push_back(v);
	}

	for(int i = 1;i <= n;i++)
		if(!dfn[i]) tarjan(i);
	
	for(int u = 1;u <= n;u++)
	{
		for(int v : edge[u])
			if(bel[u] != bel[v])
				din[bel[v]]++,dout[bel[u]]++;
	}

	bool f = false;
	for(int i = 1;i <= cnt;i++)
	{
		if(!din[i])
		{
			ans++;
			if(!dout[i] && ext[i] == 1)
				f = true;
		}
	}
	ans = n - (ans - f);
	printf("%.6f",ans * (1.0 / n));
}
