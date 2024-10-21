#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
class node{
public:
	int fir[505];
	int nxt[1005];
	int v[1005];
	int w[1005];
	int tt;
	int dis[505][505];
	int now;
	void add(int x,int y,int z){
		v[++now]=y;
		w[now]=z;
		nxt[now]=fir[x];
		fir[x]=now;
		return ;
	}
	void dfs(int now,int fa){
		if(now==fa){
			tt=now;
			dis[tt][now]=0;
		}
		for(int i=fir[now];i!=-1;i=nxt[i]){
			if(v[i]==fa){
				continue;
			}
			dis[tt][v[i]]=dis[tt][now]+w[i];
			dfs(v[i],now);
		}
		return ;
	}
}a,b;
std::vector<std::pair<int,std::pair<int,int> > >vec;
int fa[10005];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	#endif
	int n=read();
	for(int i=1;i<=n;i++){
		a.fir[i]=-1;
		b.fir[i]=-1;
		fa[i]=i;
		fa[i+n]=i+n;
	}
	for(int i=1;i<n;i++){
		int x=read();
		int y=read();
		int z=read();
		a.add(x,y,z);
		a.add(y,x,z);
	}
	for(int i=1;i<n;i++){
		int x=read();
		int y=read();
		int z=read();
		b.add(x,y,z);
		b.add(y,x,z);
	}
	for(int i=1;i<=n;i++){
		a.dfs(i,i);
		b.dfs(i,i);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int mx=0;
			for(int k=1;k<=n;k++){
				mx=std::max(mx,a.dis[i][k]+b.dis[j][k]);
			}
			vec.push_back({mx,{i,j+n}});
		}
	}
	std::sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		int x=vec[i].second.first;
		int y=vec[i].second.second;
		if(getfa(x)==getfa(y)){
			continue;
		}
		fa[getfa(x)]=getfa(y);
		ans+=vec[i].first;
	}
	printf("%d",ans);
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
