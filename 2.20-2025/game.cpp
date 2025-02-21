#include <iostream>
#include <cstdio>
#include <queue>
#include <cassert>
#include <algorithm>
#include <bitset>
#define lost left
#define MOD 1000000009


inline int read();
int n,m;
int pre[5000005];
int nxt[5000005];
int a[5000005];
std::bitset<5000005> t;
std::bitset<5000005> tt;
int p[200005];
int k[200005];
int b[200005];
int w[200005];
int fa[5000005];
int lst[5000005];
long long left[5000005];
long long cut=0;
std::priority_queue<std::pair<long long,int> >qu;
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
long long curtime,cursum;
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	if(x==y){
		return ;
	}
	fa[x]=y;
	left[y]+=left[x]-cut;
	lst[y]=lst[x];
	left[x]=-cursum;
	tt[x]=1;
	qu.push({-left[y],y});
	return ;
}
int rseed=0,rbase=0;
int rnd(){
	int ret=rseed;
	rseed=(rseed*1ll*rbase+233ll)%MOD;
	return ret;
}
void generate() {
	p[0]=0;
	for(int i=1;i<=n;i++){
		//t[i]=rand()%2;
		//a[i]=rand()%20;
		//std::cerr<<t[i]<<' '<<a[i]<<std::endl;
	}
	for(int i=1;i<=m;i++) {
		rseed=b[i];
		rbase=w[i];
		for (int j=p[i-1]+1;j<=p[i];j++) {
			t[j]=rnd()%2;
			a[j]=(rnd()%k[i])+1;
		}
	}
	return ;
}
void quclear(){
	while(qu.size()>0){
		if(left[qu.top().second]==-qu.top().first&&left[qu.top().second]>0){
			return ;
		}
		qu.pop();
	}
	return ;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		p[i]=read();
		k[i]=read();
		b[i]=read();
		w[i]=read();
	}
	generate();
	for(int i=1;i<=n;i++){
		fa[i]=lst[i]=i;
		left[i]=a[i];
		qu.push({-left[i],i});
	}
	int cnt=n;
	for(int i=1;i<n;i++){
		if(t[i]==t[i+1]){
			merge(i+1,i);
			cnt--;
		}
	}
	int pret[2]={-1,-1};
	for(int i=1;i<=n;i++){
		pre[i]=pret[!(t[i])];
		pret[(t[i])]=i;
	}
	for(int i=1;i<=n;i++){
		if(pre[i]!=-1){
			continue;
		}
		pre[i]=pret[!(t[i])];
	}
	pret[0]=pret[1]=-1;
	for(int i=n;i>=1;i--){
		nxt[i]=pret[!(t[i])];
		pret[(t[i])]=i;
	}
	for(int i=n;i>=1;i--){
		if(nxt[i]!=-1){
			continue;
		}
		nxt[i]=pret[!(t[i])];
	}
	if(t[1]==t[n]){
		merge(1,n);
		left[1]--;
		qu.push({-left[1],1});
		cnt--;
	}
	if(cnt==0){
		left[1]--;
	}
	int faa=getfa(1);
	int tttt=0;
	int nxtt=0;
	for(;cnt>1;cnt-=2){
		quclear();
		auto tp=qu.top();
		qu.pop();
		curtime=tttt;
		cursum+=-tp.first-cut;
		left[tp.second]=-cursum;
		tt[tp.second]=1;
		cut=-tp.first;
		merge(nxt[lst[tp.second]],pre[tp.second]);
		nxtt=tp.second;
	}
	if(t[nxtt]!=t[1]){
		left[1]--;
		left[nxt[1]]--;
		tt[1]=1;
		tt[nxt[1]]=1;
	}
	quclear();
	left[qu.top().second]=-cursum;
	tt[qu.top().second]=1;
	for(int i=1;i<=n;i++){
		if(tt[i]){
			left[i]=-left[i];
		}else{
			left[i]=0;
		}
	}
	int st=1;
	for(int i=1;i<=n;i++){
		if(t[i]==1){
			continue;
		}
		if(left[i]>=a[i]){
			st=i;
			break;
		}
	}
	long long sum=0;
	for(int i=st;i<=n;i++){
		if(t[i]==1){
			continue;
		}
		if(left[i]<=a[i]){
			long long tt=std::min(a[i]-left[i],sum);
			sum-=tt;
			left[i]+=tt;
		}else{
			sum+=left[i]-a[i];
			left[i]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==1){
			continue;
		}
		if(left[i]<=a[i]){
			long long tt=std::min(a[i]-left[i],sum);
			sum-=tt;
			left[i]+=tt;
		}else{
			sum+=left[i]-a[i];
			lost[i]=a[i];
		}
	}
	for(int i=1;i<st;i++){
		if(t[i]==1){
			continue;
		}
		if(lost[i]<=a[i]){
			long long tt=std::min(a[i]-lost[i],sum);
			sum-=tt;
			lost[i]+=tt;
		}else{
			sum+=lost[i]-a[i];
			lost[i]=a[i];
		}
	}
	st=1;
	for(int i=1;i<=n;i++){
		if(t[i]==0){
			continue;
		}
		if(lost[i]>=a[i]){
			st=i;
			break;
		}
	}
	sum=0;
	for(int i=st;i<=n;i++){
		if(t[i]==0){
			continue;
		}
		if(lost[i]<=a[i]){
			long long tt=std::min(a[i]-lost[i],sum);
			sum-=tt;
			lost[i]+=tt;
		}else{
			sum+=lost[i]-a[i];
			lost[i]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==0){
			continue;
		}
		if(lost[i]<=a[i]){
			long long tt=std::min(a[i]-lost[i],sum);
			sum-=tt;
			lost[i]+=tt;
		}else{
			sum+=lost[i]-a[i];
			lost[i]=a[i];
		}
	}
	for(int i=1;i<st;i++){
		if(t[i]==0){
			continue;
		}
		if(lost[i]<=a[i]){
			long long tt=std::min(a[i]-lost[i],sum);
			sum-=tt;
			lost[i]+=tt;
		}else{
			sum+=lost[i]-a[i];
			lost[i]=a[i];
		}
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=(((i*1ll*i)^(lost[i]))+1)%MOD;
		ans%=MOD;
	}
	printf("%lld",ans);
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
		(x=(x<<3)+(x<<1)+(temp^'0'));
		temp=getchar();
	}
	return f*x;
}
