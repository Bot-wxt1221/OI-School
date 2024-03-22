#include<bits/stdc++.h>
using namespace std;
#define p() \
for(int _ = 1;_ <= tot;_++)\
{\
	for(int __ = 1;__ <= tot + 1;__++)\
		print(mat[_][__],' ');\
	puts("");\
}\
puts("");

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

const int N = 250;
int n,m,tot,tx,ty;
int res[N];
int dx[] = {0,0,1,0,-1};
int dy[] = {0,1,0,-1,0};
bitset <N> mat[N];

int cnt(int x,int y)
{
	return (y - 1) * n + x;
}

void add(int x,int y)
{
    for(int i = 0;i <= 4;i++)
    {
        tx = x + dx[i],ty = y + dy[i];
        if(tx > 0 && ty > 0 && tx <= n && ty <= m)
            mat[cnt(x,y)][cnt(tx,ty)] = 1;
    }
}

void Gauss()
{
    for(int line = 1;line <= tot;line++)
    {
        int pos = line;
        std::cerr<<line<<std::endl;
        while(line <= tot && !mat[pos][line]) pos++;
        if(pos != line && pos <= tot) swap(mat[pos],mat[line]);
		if(!mat[line][line]) res[line] = 1;
//		print(line),print(mat[line][line],'\n');
		
        for(int i = line + 1;i <= tot;i++)
            if(mat[i][line]) mat[i] ^= mat[line];
//        p();
    }
	
    for(int i = tot;i >= 1;i--)
    {
        if(mat[i][i]) res[i] = mat[i][tot + 1];
        for(int j = i + 1;j <= tot;j++)
            res[i] ^= mat[i][j] * res[j];
    }
//    p();
}

int main()
{
    tot = ((m = input()) * (n = input()));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            add(i,j);
//    p();
    Gauss();
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
            print(res[cnt(i,j)],' ');
        puts("");
    }
//    puts("1");
}
