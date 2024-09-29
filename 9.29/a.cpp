#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int cnt[1000005];
int a[1000005];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	int n=read();
	int m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	m=(m-1)%2+1;
	for(int i=1;i<=m;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=n;j++){
			cnt[a[j]]++;
			a[j]=cnt[a[j]];
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
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
