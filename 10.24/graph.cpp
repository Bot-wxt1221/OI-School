#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <stack>
#define int long long
inline int read();
bool vised[55];
int sum[55];
int faa[55];
int n;
int s,t;
int ans=0;
int fir[55];
int nxt[100005];
int u[100005];
int v[100005];
int w[100005];
int now;
int dis[100005];
void add(int x,int y,int z){
	v[++now]=y;
	u[now]=x;
	w[now]=z;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int dp[5000005];
namespace ng{
int fir[55];
int nxt[100005];
int v[100005];
int now;
std::stack<int>cur;
std::vector<int>ans;
void add(int x,int y){
	v[++now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
void dfs(int now,int fa){
	cur.push(dis[now]);
	if(now==sum[t]){
		std::stack<int> tt=cur;
		while(tt.size()>0){
			if(tt.top()){
				ng::ans.push_back(tt.top());
			}
			tt.pop();
		}
	}
	vised[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(vised[v[i]]){
			continue;
		}
		dfs(v[i],now);
	}
	cur.pop();
	return ;
}
};
void dfs(int now,int fa,int dis){
	if(now==t){
		ans=dis;
	}
	faa[now]=fa;
	vised[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(vised[v[i]]){
			if(v[i]!=s){
				sum[faa[v[i]]]-=now;
			}
			sum[now]+=now;
			continue;
		}
		dfs(v[i],now,dis+w[i]);
	}
	return ;
}
void dfs2(int now,int fa){
	vised[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(vised[v[i]]){
			continue;
		}
		dfs2(v[i],now);
		sum[now]+=sum[v[i]];
	}
	return ;
}
#undef int //long long
int main(){
#define int long long
	#ifndef ONLINE_JUDGE
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	#endif
	n=read();
	int m=read();
	int k=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		ng::fir[i]=-1;
	}
	s=read();
	t=read();
	for(int i=1;i<=m;i++){
		int x=read();
		int y=read();
		int w=read();
		add(x,y,w);
	}
	dfs(s,s,0);
	memset(vised,0,sizeof(vised));
	dfs2(s,s);
	for(int i=1;i<=n;i++){
		if(sum[i]==0){
			sum[i]=i;
		}
	}
	for(int i=1;i<=now;i++){
		if(sum[u[i]]==sum[v[i]]){
			dis[sum[u[i]]]+=w[i];
			continue;
		}
		ng::add(sum[u[i]],sum[v[i]]);
	}
	memset(vised,0,sizeof(vised));
	ng::dfs(sum[s],sum[s]);
	if(ng::ans.size()==0){
		if(k!=1){
			printf("-1\n");
		}else{
			printf("%lld",ans);
		}
	}else if(ng::ans.size()==1){
		printf("%lld",ans+(k-1)*ng::ans[0]);
	}else if(ng::ans.size()==2){
		if(ng::ans[0]<ng::ans[1]){
			std::swap(ng::ans[0],ng::ans[1]);
		}
		int l=0,r=1e18;
		while((r-l)>3){
			int mid=(l+r)/2;
			int cnt=0;
			for(int i=0;i<=1.5e6;i++){
				int tt=(mid-ng::ans[0]*i+ng::ans[1])/ng::ans[1];
				cnt+=std::max(0ll,tt);
				if(tt<=0){
					break;
				}
				cnt=std::min(cnt,(long long)1e16);
				if(cnt==1e16){
					break;
				}
			}
			for(int i=0;i<=1.5e6;i++){
				int tt=((mid-ng::ans[1]*i)/ng::ans[0]-(long long)1.5e6);
				cnt+=std::max(0ll,tt);
				if(tt<=0){
					break;
				}
				cnt=std::min(cnt,(long long)1e16);
				if(cnt==1e16){
					break;
				}
			}
			if(cnt>=k){
				r=mid;
			}else{
				l=mid;
			}
		}
		for(int j=l;j<=r;j++){
			int cnt=0;
			for(int i=0;i<=1.5e6;i++){
				int tt=(j-ng::ans[0]*i+ng::ans[1])/ng::ans[1];
				cnt+=std::max(0ll,tt);
				if(tt<=0){
					break;
				}
			}
			for(int i=0;i<=1.5e6;i++){
				int tt=((j-ng::ans[1]*i)/ng::ans[0]-(long long)1.5e6);
				cnt+=std::max(0ll,tt);
				if(tt<=0){
					break;
				}
			}
			if(cnt>=k){
				printf("%lld",ans+j);
				break;
			}
		}
	}else{
		dp[0]=1;
		int shang=5e6;
		if(ng::ans.size()>5){
			shang=1e6;
		}
		for(int i=0;i<ng::ans.size();i++){
			for(int j=ng::ans[i];j<=shang;j++){
				dp[j]+=dp[j-ng::ans[i]];
				dp[j]=std::min(dp[j],(long long)(1e16));
			}
		}
		for(int j=0;j<=shang;j++){
			if(j){
				dp[j]+=dp[j-1];
			}
			if(dp[j]>=k){
				printf("%lld",ans+j);
				break;
			}
		}
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
