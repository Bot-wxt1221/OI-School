#include<cstdio>
#include<cctype>   //һ��Ҫ��cctype������ 
using namespace std;
//ע�⣺ʹ�ø�ģ���ӱ�׼���������������Ҫ�Ȼ��У���һ��Ctrl+Z�ٻ��У���ģ���ļ��е�EOF�� 
//���޷�ʹ�ñ�׼���������ʹ���ļ����������
//�Ƽ��ڵ���ʱ��FastIO��Ϊ���������������ʽ��ȷ��������ٽ����Ϊfread��ʹ���ļ������������һ�������� 
const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);} //�����������Զ�flush 
	
	char read_char() //����һ���ַ���ע������հ��ַ�������ո���
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x) //����һ�����ͱ�����int,long long֮��Ķ��ܶ��� 
	{
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c) //���һ���ַ� 
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x) //���һ�����ͱ�����int,long long֮��Ķ������ 
	{
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
}IO;
int main() //�������ʾ�� 
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
	return 0; //����Ҫ�ֶ�flush 
}
