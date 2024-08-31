struct fio{
	#define isdigit(x) (x >= '0' && x <= '9')
	char buf[1 << 20], *p1, pbuf[1 << 20], *p2, *pp;
	fio() : p1(buf), p2(buf), pp(pbuf){}
	~fio(){fwrite(pbuf, 1, pp - pbuf, stdout);}
	inline char gc(){return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1 ++;}
	inline void pc(const char &c){if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;*pp ++ = c;}
	inline bool blank(char ch){return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';}
	template <class T> inline void read(T &x){
		long double tmp = 1;bool sign = 0;char ch = gc();x = 0;
		for (;!isdigit(ch);ch = gc()) if (ch == '-') sign = 1;
		for (;isdigit(ch);ch = gc()) x = x * 10 + (ch - '0');
		if (ch == '.') for (ch = gc();isdigit(ch);ch = gc()) tmp /= 10.0, x += tmp * (ch - '0');
		if (sign) x = -x;
	}
	inline void read(char *s){
    	char ch = gc();for (;blank(ch);ch = gc());
    	for (;!blank(ch);ch = gc()) *s ++ = ch;*s = 0;
    }
    inline void read(char &c){for (c = gc();blank(c);c = gc());}
	template <class T> inline void write(T x){
		if (x < 0) x = -x, pc('-');int sta[30];int top = 0;
		do sta[top ++] = x % 10, x /= 10;while (x);
		while (top) pc(sta[-- top] + '0');
	}
}io;
int x;char ch, s[1145];
int main(){ // 使用这个快读需要 #include <cstdio>
	io.read(x); // 读入一个任意类型的数（包括负数，浮点数）
	io.write(x); // 输出一个任意类型的整数（包括负数）
	io.read(s); // 读入一个字符串，功能与 scanf("%s", s) 类似
	io.read(ch); // 读入单个非空白字符
	io.gc(ch); // 等同于 ch = getchar() 
	io.pc(ch); // 等同于 putchar(ch) 
}