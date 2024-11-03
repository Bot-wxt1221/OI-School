#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
std::pair<int,int> a[400005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("guiltiness.in","r",stdin);
	freopen("guiltiness.out","w",stdout);
	#endif
	int n=read();
	int m=read();
	for(int i=1;i<n;i++){
		a[i]={read(),1};
	}
	for(int i=1;i<m;i++){
		a[i+n-1]={read(),0};
	}
	std::sort(a+1,a+n+m-1);
	int ans=0;
	int cnt[2]={1,1};
	for(int i=n+m-2;i>=1;i--){
		ans+=a[i].first*cnt[a[i].second];
		cnt[!a[i].second]++;
	}
	printf("%lld",ans);
	return 0;
}
inline int read(){
	int f=0,x=1;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(x=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		f=(f<<3)+(f<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
