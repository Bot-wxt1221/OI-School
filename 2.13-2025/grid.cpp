#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
inline int read();
int fa[1000005];
int x[1000005];
int y[1000005];
std::map<int,int>mp[1000005];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
std::vector<std::pair<int,int> >vec[1000005],vec2[1000005];
bool equ(std::pair<int,int> a,std::pair<int,int> b){
	return a.first==b.first;
}
std::vector<std::pair<int,int> >se[3];
int ans[1000005];
int ans2[1000005];
int mxx[1000005];
int mnx[1000005];
int mxy[1000005];
int mny[1000005];
int lowbit(int x){
	return x&(-x);
}
class BIT{
public:
	int tree[1000005];
	std::vector<int>qu;
	int query(int now){
		int ans=0;
		while(now>0){
			ans+=tree[now];
			now-=lowbit(now);
		}
		return ans;
	}
	void add(int x,int y){
		qu.push_back(x);
		while(x<=1000000){
			tree[x]+=y;
			x+=lowbit(x);
		}
		return ;
	}
	void clear(int x){
		while(x<=1000000){
			tree[x]=0;
			x+=lowbit(x);
		}
		return ;
	}
	void clear(){
		for(int i=0;i<qu.size();i++){
			clear(qu[i]);
		}
		qu.clear();
		return ;
	}
}A,B;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	#endif
	int n=read();
	int m=read();
	for(int i=1;i<=m;i++){
		fa[i]=i;
		mnx[i]=mny[i]=0x3f3f3f3f;
		mxx[i]=mxy[i]=-0x3f3f3f3f;
		int x=read()+2;
		int y=read();
		::x[i]=x;
		::y[i]=y;
		vec[x].push_back({y,i});
	}
	for(int i=1;i<=n+4;i++){
		std::sort(vec[i].begin(),vec[i].end());
		vec[i].resize(std::unique(vec[i].begin(),vec[i].end(),equ)-vec[i].begin());
		for(int j=0;j<vec[i].size();j++){
			vec2[vec[i][j].first].push_back({i,vec[i][j].second});
		}
	}
	long long anss=0;
	for(int i=1;i<=n+4;i++){
		se[2].clear();
		for(int j=0;j<vec[i].size();j++){
			A.add(vec[i][j].first,1);
		}
		for(int j=0;j<se[1].size();j++){
			int l=se[1][j].first;
			int r=se[1][j].second;
			bool live=0;
			if(A.query(se[1][j].second)!=A.query(se[1][j].first-1)){
				live=1;
			}
			if(live){
				se[2].push_back({l,r});
			}else{
				continue;
			}
			B.add(l,ans2[r]);
			B.add(r+1,-ans2[r]);
		}
		se[1].clear();
		for(int j=0;j<se[0].size();j++){
			int l=se[0][j].first;
			int r=se[0][j].second;
			bool live=0;
			int preans=ans2[r];
			if(A.query(se[0][j].second+1)!=A.query(se[0][j].second)){
				live=1;
				r++;
			}
			if(A.query(se[0][j].first-1)!=A.query(se[0][j].first-2)){
				live=1;
				l--;
			}
			if(A.query(se[0][j].second)!=A.query(se[0][j].first-1)){
				live=1;
			}
			ans2[r]=preans;
			if(live){
				se[2].push_back({l,r});
			}else{
				se[1].push_back({l,r});
				continue;
			}
			B.add(l,preans);
			B.add(r+1,-preans);
		}
		for(int j=0;j<vec[i].size();j++){
			if(!B.query(vec[i][j].first)){
				se[2].push_back({vec[i][j].first,vec[i][j].first});
				ans[vec[i][j].first]=i;
				ans2[vec[i][j].first]=vec[i][j].second;
			}else{
				fa[getfa(vec[i][j].second)]=getfa(B.query(vec[i][j].first));
			}
		}
		std::sort(se[2].begin(),se[2].end());
		se[0].clear();
		if(se[2].size()==0){
		}else{
			int l=se[2][0].first;
			int r=se[2][0].second;
			int tt=ans[r];
			int tt2=ans2[r];
			for(int j=1;j<se[2].size();j++){
				int ll=se[2][j].first;
				int rr=se[2][j].second;
				if(r+2>=ll){
					r=std::max(r,rr);
					tt=std::min(tt,ans[rr]);
					fa[getfa(tt2)]=getfa(ans2[rr]);
				}else{
					ans[r]=tt;
          ans2[r]=tt2;
					se[0].push_back({l,r});
					l=ll;
					r=rr;
					tt=ans[rr];
          tt2=ans2[rr];
				}
			}
			ans[r]=tt;
			ans2[r]=tt2;
			se[0].push_back({l,r});
		}
		A.clear();
		B.clear();

	}
  se[0].clear();
  se[1].clear();
  se[2].clear();
  memset(ans,0,sizeof(ans));
	for(int i=n+4;i>=1;i--){
		se[2].clear();
		for(int j=0;j<vec[i].size();j++){
			A.add(vec[i][j].first,1);
		}
		for(int j=0;j<se[1].size();j++){
			int l=se[1][j].first;
			int r=se[1][j].second;
			bool live=0;
			if(A.query(se[1][j].second)!=A.query(se[1][j].first-1)){
				live=1;
			}
			if(A.query(se[1][j].second)!=A.query(se[1][j].first-1)){
				live=1;
			}
			if(live){
				se[2].push_back({l,r});
			}else{
				continue;
			}
			B.add(l,ans2[r]);
			B.add(r+1,-ans2[r]);
		}
		se[1].clear();
		for(int j=0;j<se[0].size();j++){
			int l=se[0][j].first;
			int r=se[0][j].second;
			bool live=0;
			int preans=ans2[r];
			if(A.query(se[0][j].second+1)!=A.query(se[0][j].second)){
				live=1;
				r++;
			}
			if(A.query(se[0][j].first-1)!=A.query(se[0][j].first-2)){
				live=1;
				l--;
			}
			if(A.query(se[0][j].second)!=A.query(se[0][j].first-1)){
				live=1;
			}
			if(live){
				se[2].push_back({l,r});
			}else{
				se[1].push_back({l,r});
				continue;
			}
			ans2[r]=preans;
			B.add(l,preans);
			B.add(r+1,-preans);
		}
		for(int j=0;j<vec[i].size();j++){
			if(!B.query(vec[i][j].first)){
				se[2].push_back({vec[i][j].first,vec[i][j].first});
				ans[vec[i][j].first]=i;
				ans2[vec[i][j].first]=vec[i][j].second;
			}else{
				fa[getfa(vec[i][j].second)]=getfa(B.query(vec[i][j].first));
			}
		}
		std::sort(se[2].begin(),se[2].end());
		se[0].clear();
		if(se[2].size()==0){
		}else{
			int l=se[2][0].first;
			int r=se[2][0].second;
			int tt=ans[r];
			int tt2=ans2[r];
			for(int j=1;j<se[2].size();j++){
				int ll=se[2][j].first;
				int rr=se[2][j].second;
				if(r+2>=ll){
					r=std::max(r,rr);
					tt=std::max(tt,ans[rr]);
					fa[getfa(tt2)]=getfa(ans2[rr]);
				}else{
					ans[r]=tt;
          ans2[r]=tt2;
					se[0].push_back({l,r});
					l=ll;
					r=rr;
					tt=ans[rr];
          tt2=ans2[rr];
				}
			}
			ans[r]=tt;
			ans2[r]=tt2;
			se[0].push_back({l,r});
		}
		A.clear();
		B.clear();
	}
	for(int i=1;i<=n+4;i++){
		for(int j=0;j<vec[i].size();j++){
			int ii=vec[i][j].second;
			int faii=getfa(ii);
			mxx[faii]=std::max(mxx[faii],i);
			mnx[faii]=std::min(mnx[faii],i);
			mxy[faii]=std::max(mxy[faii],vec[i][j].first);
			mny[faii]=std::min(mny[faii],vec[i][j].first);
		}
	}
	for(int i=1;i<=n+4;i++){
		for(int j=0;j<vec[i].size();j++){
			int ii=vec[i][j].second;
			int faii=getfa(ii);
			if(ii==faii){
				anss+=1ll*(mxx[ii]-mnx[ii]+1)*(mxy[ii]-mny[ii]+1);
			}
		}
	}
	printf("%lld",anss);
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
