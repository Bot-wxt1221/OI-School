#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int ww[500005];
int w[1000005];
int sumcost[500005];
int sumw[500005];
int now;
int ans[500005];
void add(int x,int y,int z){
	v[++now]=y;
	w[now]=z;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
class tt{
public:
	int a,b;
	tt(int x=0,int y=0){
		a=x;
		b=y;
		return ;
	}
};
bool operator < (tt a,tt b){
	return a.a*b.b<b.a*a.b;
}
std::vector<tt>a[500005];
void dfs(int now,int fa){
	sumcost[now]=0;
	sumw[now]=ww[now];
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs(v[i],now);
		sumcost[now]+=sumcost[v[i]];
		sumcost[now]+=w[i];
		sumw[now]+=sumw[v[i]];
	}
	return ;
}
void dfs2(int now,int fa){
	ans[now]=0;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs2(v[i],now);
		ans[now]+=ans[v[i]]+sumw[v[i]]*w[i];
		a[now].push_back(tt{sumcost[v[i]]+w[i],sumw[v[i]]});
	}
	std::sort(a[now].begin(),a[now].end());
	int presum=0;
	for(int i=0;i<a[now].size();i++){
		ans[now]+=presum*a[now][i].b;
		presum+=a[now][i].a;
	}
	return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	#endif
	int n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=2;i<=n;i++){
		int a=read();
		int b=read();
		add(a,i,b);
	}
	for(int i=1;i<=n;i++){
		ww[i]=read();
	}
	dfs(1,1);
	dfs2(1,1);
	printf("%lld",ans[1]);
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
