#include<cstdio>
#include<cctype>   //一定要加cctype！！！ 
using namespace std;
//注意：使用该模板后从标准输入里输入最后需要先换行，加一个Ctrl+Z再换行，来模拟文件中的EOF。 
//若无法使用标准输入输出请使用文件输入输出。
//推荐在调试时将FastIO改为正常的输入输出方式，确认无误后再将其改为fread并使用文件输入输出测试一遍样例。 
const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);} //析构函数，自动flush 
	
	char read_char() //读入一个字符，注意会读入空白字符，例如空格换行
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x) //读入一个整型变量，int,long long之类的都能读入 
	{
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c) //输出一个字符 
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x) //输出一个整型变量，int,long long之类的都能输出 
	{
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
}IO;
int main() //输入输出示例 
{
	int a;
	long long b;
	char c;
	IO.read_int(a);
	IO.read_int(b);
	c=IO.read_char();
	IO.write_int(a);
	IO.write_char(' ');
	IO.write_int(b);
	IO.write_char(' ');
	IO.write_char(c);
	IO.write_char('\n');
	return 0; //不需要手动flush 
}
