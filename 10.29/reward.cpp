#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int tree[500005*3];
int mn[500005*3];
int lazy[500005*3];
int lowbit(int x){
	return x&(-x);
}
class BIT{
public:
	int tree[500005];
	int query(int now){
		int ans=0;
		while(now>0){
			ans+=tree[now];
			now-=lowbit(now);
		}
		return ans;
	}
	void mod(int now,int x){
		while(now<=500000){
			tree[now]+=x;
			now+=lowbit(now);
		}
		return ;
	}
}a;
inline void write(int n){
	if(n==0){
		putchar('0');
		putchar(' ');
		return ;
	} 
	static char temp[105];
	int tp=0;
	while(n){
		temp[++tp]=n%10+'0';
		n/=10;
	}
	while(tp){
		putchar(temp[tp--]);
	}
	putchar(' ');
	return ;
}
inline void pushup(int now){
	mn[now]=std::min(mn[now*2],mn[now*2+1]);
	tree[now]=0;
	if(mn[now]==mn[now*2]){
		tree[now]+=tree[now*2];
	}
	if(mn[now]==mn[now*2+1]){
		tree[now]+=tree[now*2+1];
	}
	return ;
}
inline void pushdown(int now){
	mn[now*2]+=lazy[now];
	mn[now*2+1]+=lazy[now];

	lazy[now*2]+=lazy[now];
	lazy[now*2+1]+=lazy[now];

	lazy[now]=0;
	return ;
}
void init(int now,int l,int r){
	if(l==r){
		tree[now]=1;
		return ;
	}
	int mid=(l+r)/2;
	init(now*2,l,mid);
	init(now*2+1,mid+1,r);
	tree[now]=r-l+1;
	return ;
}
int ql,qr,op;
void mod(int now,int l,int r){
	if(ql<=l&&r<=qr){
		mn[now]+=op;
		lazy[now]+=op;
		return ;
	}
	pushdown(now);
	int mid=(l+r)/2;
	if(mid>=ql){
		mod(now*2,l,mid);
	}
	if(qr>=mid+1){
		mod(now*2+1,mid+1,r);
	}
	pushup(now);
	return ;
}
int fir[500005];
int nxt[500005];
int v[500005];
std::pair<int,int>dfn[500005];
int ans[500005];
std::vector<int>vec[500005];
int firu[500005];
int now;
void add(int x,int y){
	v[++now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int cnt=0;
void dfs(int now,int fa){
	dfn[now].first=++cnt;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs(v[i],now);
	}
	dfn[now].second=cnt;
	return ;
}
int n;
void dfs2(int now,int fa){
	for(int i=0;i<vec[now].size();i++){
		ql=dfn[vec[now][i]].first;
		qr=dfn[vec[now][i]].second;
		if(firu[vec[now][i]]||(a.query(ql)&&a.query(qr))){
			continue;
		}
		firu[vec[now][i]]=now;
		op=1;
		mod(1,1,n);
		a.mod(ql,1);
		a.mod(qr+1,-1);
	}
	if(vec[now].size()){
		ql=dfn[now].first;
		qr=dfn[now].second;
		if(firu[now]||(a.query(ql)&&a.query(qr))){
			goto end;
		}
		firu[now]=now;
		op=1;
		mod(1,1,n);
		a.mod(ql,1);
		a.mod(qr+1,-1);
	}
	end:{}
	int mnn=a.query(dfn[now].first);
	if(mn[1]==0){
		ans[now]=n-(tree[1])-(mnn>0);
	}else{
		ans[now]=n-(mnn>0);
	}
	for(int i=fir[now];i!=-1;i=nxt[i]){
		dfs2(v[i],now);
	}
	for(int i=0;i<vec[now].size();i++){
		if(firu[vec[now][i]]==now){
			ql=dfn[vec[now][i]].first;
			qr=dfn[vec[now][i]].second;
			firu[vec[now][i]]=0;
			op=-1;
			mod(1,1,n);
			a.mod(ql,-1);
			a.mod(qr+1,1);
		}
	}
	if(vec[now].size()){
		if(firu[now]==now){
			ql=dfn[now].first;
			qr=dfn[now].second;
			firu[now]=0;
			op=-1;
			mod(1,1,n);
			a.mod(ql,-1);
			a.mod(qr+1,1);
		}
	}
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("reward.in","r",stdin);
	freopen("reward.out","w",stdout);
	#endif
	n=read();
	int q=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=2;i<=n;i++){
		int fa=read();
		add(fa,i);
	}
	for(int i=1;i<=q;i++){
		int a=read();
		int b=read();
		vec[a].push_back(b);
		if(a!=b){
			vec[b].push_back(a);
		}
	}
	init(1,1,n);
	dfs(1,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++){
		write(ans[i]);
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
