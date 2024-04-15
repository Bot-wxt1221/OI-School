#include<bits/stdc++.h>
using namespace std;
#define RA auto

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
		register int num = 0,f = 1;
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

const int N = 5e4 + 5;
int a,b,c,d,k;
int miu[N+5],pre[N+5];
bool vis[N+5];
vector <int> p;

//use to get µ[n]
void init()
{
    miu[1] = 1;
    for(int i = 2;i < N;i++)
    {
        cout << i << " " << p.size() << endl;
        if(!vis[i]) { miu[i] = -1;p.push_back(i); }
        for(int tmp : p)
        {
            if(tmp * i >= N) break;
            vis[tmp * i] = 1;
            if(i % tmp == 0) break;
            miu[i * tmp] = -miu[i];
        }
    }
    for(int i = 1;i < N;i++)
        pre[i] = pre[i - 1] + miu[i];
}

//use to solve [x,y] problem
long long solve(int x,int y)
{
    RA ub = min(x,y);
    RA ans = 0LL;
    RA l = 1,r = 0;

    while(l <= ub)
    {
        cout << 1 << endl;
        r = min(a / (a / l),b / (b / l));
        ans += (1L * a / (1L * l * k) * (1L * b / (1L * l * k)) * (pre[r] - pre[l - 1]));
    }

    return ans;
}

//main function
int main()
{
    init();
    // for(int n = input();n;n--)
    // {
    //     a = input(),b = input(),c = input(),d = input(),k = input();
    //     print(solve(b,d) - solve(a,d) - solve(b,c) + solve(a,c),'\n');
    // }
}
