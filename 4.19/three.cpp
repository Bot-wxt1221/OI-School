#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define mod 1000000007ll
#define int long long
int read(){
	int x=0,f=1;
	char a=getchar();
	while(a<'0'||a>'9'){
		a=='-'?f=-1:0;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=(x<<3)+(x<<1)+(a^'0');
		a=getchar();
	}
	return f*x;
}
int pow(int x,int y){
	if(y==0){
		return 1;
	}
	if(y%2==0){
		int tt=pow(x,y/2);
		return (1ll*tt*tt)%mod;
	}
	return (1ll*pow(x,y-1)*x)%mod;
}
std::priority_queue<int>qu;
int a[1000005];
signed main(){
//	freopen("three.in","r",stdin);
//	freopen("three.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int tans=0;
	for(int i=1;i<=n;i++){
		qu.push(-a[i]);
		qu.push(-a[i+1]);
		int ji=(1ll*a[i]*a[i+1])%mod;
		for(int j=i+2;j<=n;j++){
			qu.push(-a[j]);
			ji*=a[j];
			ji%=mod;
			while(qu.size()>3){
				ji*=pow(-qu.top(),mod-2);
				ji%=mod;
				qu.pop();
			}
			tans+=ji;
			tans%=mod;
		}
		qu=std::priority_queue<int>();
	}
	printf("%lld",tans);
	return 0;
}
