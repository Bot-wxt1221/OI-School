// 	author:LGM_Joanna_

#include <bits/stdc++.h>
#define marry return
//#define int long long
#define lowbit(x) (x&-x)
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57)f=ch=='-'?-1:1,ch=getchar();
	while(ch>=48&&ch<=57)x=x*10+(ch^48),ch=getchar();
	return x*f;}
using namespace std;

const long long inf=1e15;
const int F=0;
const int mod=114514;

int n,q;
struct node{
	int nx,to,v;
}w[200001];
int head[100001],t;
inline void add(int a,int b,int len) {	w[++t]={head[a],b,len},head[a]=t;	}
long long dis[100001][21];
int cntf[100001];
int f[100001];

int siz[100001],MX,root;
bool vis[100001];
inline void getsize(int s,int fa)
{
	siz[s]=1;
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vi==fa||vis[vi])
			continue;
		getsize(vi,s);
		siz[s]+=siz[vi];
	}
}
inline void getroot(int s,int fa,int SIZ)
{
	int mx=SIZ-siz[s];
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vi==fa||vis[vi])
			continue;
		getroot(vi,s,SIZ);
		mx=max(mx,siz[vi]);
	}
	if(mx<MX)
		MX=mx,root=s;
}
inline void addfa(int s,int fa,long long dep)
{
	dis[s][++cntf[s]]=dep;
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vi==fa||vis[vi])
			continue;
		addfa(vi,s,dep+w[i].v);
	}
}


inline void dfs(int s,int fa)
{
	getsize(s,0);	
	MX=1e9,root=0;
	getroot(s,0,siz[s]);
	s=root;
	vis[s]=1;
	f[s]=fa;
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vis[vi])
			continue;
		addfa(vi,s,w[i].v);
	}
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vis[vi])
			continue;
		dfs(vi,s);
	}
}
long long mn[100001];
long long ans[100001];
struct point{
	int p;
	long long dis;
};
point v[100001];
int top;
inline void addnum(int s,int fa,long long dep)
{
	v[++top]={s,dep};
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vi==fa||vis[vi])
			continue;
		addnum(vi,s,dep+w[i].v);
	}
}

inline void work()
{
	if(top-1)
	{
		for(int i=1;i<=top;++i)
		{
			int s=v[i].p;
			ans[s]=min(ans[s],v[i].dis+mn[s]);
			for(int j=cntf[s],num=f[s];j;--j,num=f[num])
				ans[s]=min(ans[s],v[i].dis+dis[s][j]+mn[num]);
			mn[s]=min(mn[s],v[i].dis);
			for(int j=cntf[s],num=f[s];j;--j,num=f[num])
				mn[num]=min(mn[num],v[i].dis+dis[s][j]);	
		}
		for(int i=1;i<=top;++i)
		{
			int s=v[i].p;
			mn[s]=inf;
			for(int j=cntf[s],num=f[s];j;--j,num=f[num])
				mn[num]=inf;	
		}
		for(int i=top;i;--i)
		{
			int s=v[i].p;
			ans[s]=min(ans[s],v[i].dis+mn[s]);
			for(int j=cntf[s],num=f[s];j;--j,num=f[num])
				ans[s]=min(ans[s],v[i].dis+dis[s][j]+mn[num]);
			mn[s]=min(mn[s],v[i].dis);
			for(int j=cntf[s],num=f[s];j;--j,num=f[num])
				mn[num]=min(mn[num],v[i].dis+dis[s][j]);	
		}
		for(int i=1;i<=top;++i)
		{
			int s=v[i].p;
			mn[s]=inf;
			for(int j=cntf[s],num=f[s];j;--j,num=f[num])
				mn[num]=inf;	
		}
		
	}
	top=0;
}


inline void dfs2(int s)
{
	getsize(s,0);
	MX=1e9,root=0;
	getroot(s,0,siz[s]);
	s=root;
	vis[s]=1;
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vis[vi])
			continue;
		addnum(vi,s,w[i].v);	
	}
	v[++top]={s,0};
	work();
	for(int i=head[s];i;i=w[i].nx)
	{
		int vi=w[i].to;
		if(vis[vi])
			continue;
		dfs2(vi);
	}
}

signed main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int a=read(),b=read(),v=read();
		add(a,b,v);
		add(b,a,v);
	}
	dfs(1,0);
	t=0;
	for(int i=1;i<=n;++i)
		vis[i]=0,head[i]=0;
	for(int i=1;i<=n;++i)
		ans[i]=mn[i]=inf;
	for(int i=1;i<n;++i)
	{
		int a=read(),b=read(),v=read();
		add(a,b,v);
		add(b,a,v);
	}
	dfs2(1);
	for(int i=1;i<=n;++i)
		printf("%lld\n",ans[i]);

	marry F;
}
