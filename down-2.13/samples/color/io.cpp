#include<bits/stdc++.h>
namespace io{
	const int BUFSIZE=1<<20;
	char ibuf[BUFSIZE],*is=ibuf,*it=ibuf;
	char obuf[BUFSIZE],*os=obuf,*ot=obuf+BUFSIZE;
	inline char getch(){
		if(is==it)it=(is=ibuf)+fread(ibuf,1,BUFSIZE,stdin);
		return (is==it)?EOF:*is++;
	}
	inline int read(){
		int res=0;bool neg=false;char ch=getch();
		while(!(isdigit(ch)||ch=='-')&&ch!=EOF)ch=getch();
		if(ch=='-')neg=true,ch=getch();
		while(isdigit(ch))res=res*10+(ch-'0'),ch=getch();
		return neg?-res:res;
	}
	inline void flush(){
		fwrite(obuf,1,os-obuf,stdout);
		os=obuf;
	}
	inline void putch(char ch){
		*os++=ch;
		if(os==ot)flush();
	}
	inline void write(int res){
		char q[25];int top;
		if(res<0)putch('-'),res=-res;
		if(res==0)putch('0');			
		top=0;
		while(res)q[top++]=res%10+'0',res/=10;
		while(top--)putch(q[top]);
	}
}
signed main(){
	
}

