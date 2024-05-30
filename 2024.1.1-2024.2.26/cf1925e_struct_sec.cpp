#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=3e5+5,mod=1e9+7;
int t,n,m,q;
int a[N],w[N];
set<pii>s;
int tr[N<<2];
void upd(int l,int r,int fl,int k,int x){
	if(l==r){
		tr[x]=k;
		return;
	}
	int mid=l+r>>1;
	if(fl<=mid) upd(l,mid,fl,k,x<<1);
	else upd(mid+1,r,fl,k,x<<1|1);
	tr[x]=tr[x<<1]+tr[x<<1|1];
}
int query(int l,int r,int fl,int fr,int x){
	if(fl>fr) return 0;
	if(fl<=l && r<=fr) return tr[x];
	int mid=l+r>>1,sum=0;
	if(fl<=mid) sum+=query(l,mid,fl,fr,x<<1);
	if(fr>mid) sum+=query(mid+1,r,fl,fr,x<<1|1);
	return sum;
}
signed main(){
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		w[a[i]]=x;
	}
	int lt=1;
	for(int i=2;i<=n;i++){
		if(w[i]){
			s.insert(mk(lt,i));
			upd(1,n,i,(i-lt-1+1)*(i-lt-1)/2*w[lt],1);
			lt=i;
		}
	}
	s.insert(mk(1,1)),s.insert(mk(n,n));
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			w[x]=y;
			auto pos=s.lower_bound(mk(x,x));
			pos--;
			pii now=*pos;
			s.erase(now);
			s.insert(mk(now.fi,x));
			s.insert(mk(x,now.se));
			upd(1,n,x,(x-now.fi-1+1)*(x-now.fi-1)/2*w[now.fi],1);
			upd(1,n,now.se,(now.se-x-1+1)*(now.se-x-1)/2*w[x],1);
		}else{
			auto pos1=s.upper_bound(mk(x,x)),pos2=s.upper_bound(mk(y,y));
			int ans=0,r;
			pii now1,now2;
			--pos1;
			now1=*pos1;
			if(now1.fi<=x && now1.se>=y){
				if(x==now1.fi) x++;
				if(y==now1.se) y--;
				if(x>y) cout<<0<<'\n';
				else cout<<(now1.se-x+now1.se-y)*(y-x+1)/2*w[now1.fi]<<'\n';
				continue;
			}
			now1.se=min(now2.se,y+1);
//			if(now1.se)
			ans+=(now1.se-x+1)*(now1.se-x)/2*w[now1.fi];
			pos1++;
			now1=*pos1;
			ans+=query(1,n,now1.se,y,1);
//			cout<<ans<<'\n';
			--pos2;
			now2=*pos2;
			if(now2.fi<=x && now2.se>=y){
				if(x==now2.fi) x++;
				if(y==now2.se) y--;
				if(x>y) cout<<0<<'\n';
				else cout<<(now2.se-x+now2.se-y)*(y-x+1)/2*w[now2.fi]<<'\n';
				continue;
			}
//			cout<<now2.fi<<' '<<now2.se<<'\n';
			now2.fi=max(now2.fi,x-1);
			ans+=(now2.se-now2.fi-1+now2.se-y)*(y-now2.fi)/2*w[now2.fi];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*

*/
