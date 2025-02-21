#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
char temp[8005];
int fir[8005];
int depth[8005];
int nxt[16005];
int v[16005];
int siz[8005][2];
int siz2[8005][2];
std::vector<int>vec[8005];
std::vector<int>vec2[8005];
int siz3[8005];
int bigson[8005];
int now;
void add(int x,int y){
	v[++now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
void dfs(int now,int fa){
	siz[now][0]=siz[now][1]=0;
	siz[now][temp[now]-'0']++;
	siz2[now][0]+=siz2[fa][0];
	siz2[now][1]+=siz2[fa][1];
	siz2[now][temp[now]-'0']++;
	depth[now]=depth[fa]+1;
	siz3[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs(v[i],now);
		siz[now][0]+=siz[v[i]][0];
		siz[now][1]+=siz[v[i]][1];
		siz3[now]+=siz3[v[i]];
		if(bigson[now]==0||siz3[bigson[now]]<siz3[v[i]]){
			bigson[now]=v[i];
		}
	}
	vec[now].resize(siz3[now]+5);
	vec2[now].resize(siz3[now]+5,-0x3f3f3f3f);
	return ;
}
void dfs2(int now,int fa){
	int cur=1;
	if(bigson[now]){
		dfs2(bigson[now],now);
		int ad=(temp[now]=='1'?siz[now][0]:0);
		cur+=siz3[bigson[now]];
		for(int i=0;i<=siz3[bigson[now]];i++){
			vec[now][i+(temp[now]=='1')]=vec[bigson[now]][i]+ad;
		}
	}else{
		int ad=(temp[now]=='1'?siz[now][0]:0);
		vec[now][temp[now]=='1']=ad;
		return ;
	}
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa||v[i]==bigson[now]){
			continue;
		}
		dfs2(v[i],now);
		for(int ii=cur;ii>=0;ii--){
			for(int j=siz3[v[i]];j>=0;j--){
				vec[now][ii+j]=std::max(vec[now][ii+j],vec[now][ii]+vec[v[i]][j]);
			}
		}
		cur+=siz3[v[i]];
	}
	for(int i=0;i<=siz3[now];i++){
		vec[now][i]=std::max(vec[now][i],vec2[now][i]-i*(siz2[now][1]-(temp[now]=='1')));
	}
	return ;
}
void dfs3(int now,int fa){
	int cur=1;
	if(bigson[now]){
		dfs3(bigson[now],now);
		cur+=siz3[bigson[now]];
		for(int i=0;i<=siz3[bigson[now]];i++){
			vec2[now][i]=vec2[bigson[now]][i];
		}
	}else{
		vec2[now][0]=0;
		if(temp[now]=='0'){
			vec2[now][siz[now][0]]=vec2[now][siz[now][0]-1]+siz2[now][1];
		}
		return ;
	}
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa||v[i]==bigson[now]){
			continue;
		}
		dfs3(v[i],now);
		for(int ii=cur;ii>=0;ii--){
			for(int j=1;j<=siz3[v[i]];j++){
				vec2[now][ii+j]=std::max(vec2[now][ii+j],vec2[now][ii]+vec2[v[i]][j]);
			}
		}
		cur+=siz3[v[i]];
	}
	if(temp[now]=='0'){
		vec2[now][siz[now][0]]=vec2[now][siz[now][0]-1]+siz2[now][1];
	}
	return ;
}
int ans[16005];
int main(){
	freopen("loser.in","r",stdin);
	freopen("loser.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		temp[i]=read()+'0';
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int x=read();
		int y=read();
		add(x,y);
		add(y,x);
	}
	dfs(1,1);
	dfs3(1,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++){
		vec[1][i]=std::max(vec[1][i],vec[1][i-1]);
	}
	for(int i=0;i<=n;i++){
		printf("%d ",vec[1][n]-std::max(vec[1][i],0));
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
		(x=(x<<3)+(x<<1)+(temp^'0'));
		temp=getchar();
	}
	return f*x;
}
