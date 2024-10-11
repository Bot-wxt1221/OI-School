#include <iostream>
#include <cstdio>
inline int read();
int p[50005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("sail.in","r",stdin);
	freopen("sail.out","w",stdout);
	#endif
	int n=read();
	for(int i=1;i<=n;i++){
    p[i]=read();
	}
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
