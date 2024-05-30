#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int fir[1000005];
int nxt[1000005];
int v[1000005];
int w[1000005];
int now;
int afa[1000005];
bool vis[1000005];
void add(int x,int y,int z){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  w[now]=z;
  return ;
}
int siz[1000005];
int maxx[1000005];
int nx;
int sum;
void calcsiz(int now,int fa){
  siz[now]=1; 
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vis[v[i]]){
      continue;
    }
    calcsiz(v[i],now);
    maxx[now]=std::max(maxx[now],siz[v[i]]);
    siz[now]+=siz[v[i]];
  }
  maxx[now]=std::max(maxx[now],sum-maxx[now]);
  if(maxx[now]<=maxx[nx]||nx==0){
    nx=now;
  }
  return ;
}
int facnt[100005];
int dis[100005][30];
int mn[100005];
int ans[100005];
void addfa(int now,int fa,int dep){
  dis[now][++facnt[now]]=dep;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vis[v[i]]){
      continue;
    }
    addfa(v[i],now,dep+w[i]);
  }
  return ;
}
int fa[100005];
void dfs1(int now,int fa){
  vis[now]=1;
  ::fa[now]=fa;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vis[v[i]]){
      continue;
    }
    addfa(v[i],now,w[i]);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(fa==v[i]||vis[v[i]]){
      continue;
    }
    nx=0;
    calcsiz(v[i],now);
    sum=siz[v[i]];
    calcsiz(v[i],now);
    calcsiz(nx,nx);
    afa[nx]=now;
    dfs1(nx,now); 
  }
  return ;
}
class node{
  public:
    int p,dis;
    node(int x=0,int y=0){
      p=x;
      dis=y;
      return ;
    }
}vv[1000006];
int tp;
void aans(){
  if(tp==1){
    return ;
  }
  for(int i=1;i<=tp;i++){
    int &tt=vv[i].p;
    int &tt2=vv[i].dis;
    ans[tt]=std::min(ans[tt],tt2+mn[tt]);
    for(int j=facnt[tt],now=fa[tt];j>0;j--,now=fa[now]){
      ans[tt]=std::min(ans[tt],tt2+dis[tt][j]+mn[now]);
    }
    mn[tt]=std::min(mn[tt],tt2);
    for(int j=facnt[tt],now=fa[tt];j>0;j--,now=fa[now]){
      mn[now]=std::min(mn[now],tt2+dis[tt][j]);
    }
  }
  for(int i=1;i<=tp;i++){
    int tt=vv[i].p;
    mn[tt]=0x3f3f3f3f3f3f3f3f;
    for(int j=facnt[tt],now=fa[tt];j>0;j--,now=fa[now]){
      mn[now]=0x3f3f3f3f3f3f3f3f;
    }
  }
  for(int i=tp;i>=1;i--){
    int &tt=vv[i].p;
    int &tt2=vv[i].dis;
    ans[tt]=std::min(ans[tt],tt2+mn[tt]);
    for(int j=facnt[tt],now=fa[tt];j>0;j--,now=fa[now]){
      ans[tt]=std::min(ans[tt],tt2+dis[tt][j]+mn[now]);
    }
    mn[tt]=std::min(mn[tt],tt2);
    for(int j=facnt[tt],now=fa[tt];j>0;j--,now=fa[now]){
      mn[now]=std::min(mn[now],tt2+dis[tt][j]);
    }
  }
  for(int i=tp;i>=1;i--){
    int tt=vv[i].p;
    mn[tt]=0x3f3f3f3f3f3f3f3f;
    for(int j=facnt[tt],now=fa[tt];j>0;j--,now=fa[now]){
      mn[now]=0x3f3f3f3f3f3f3f3f;
    }
  }
  tp=0;
  return ;
}
void addfa2(int now,int fa,int dep){
  vv[++tp]=node(now,dep);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vis[v[i]]){
      continue;
    }
    addfa2(v[i],now,dep+w[i]); 
  }
  return ;
}
void dfs2(int now,int fa){
  vis[now]=1;
  tp=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vis[v[i]]){
      continue;
    }
    addfa2(v[i],now,w[i]);
  }
  vv[++tp]=node(now,0);
  aans();
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vis[v[i]]){
      continue;
    }
    nx=0;
    calcsiz(v[i],now);
    sum=siz[v[i]];
    calcsiz(v[i],now);
    calcsiz(nx,nx);
    dfs2(nx,now);
  }
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  maxx[0]=0x3f3f3f3f3f3f3f3f;
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  nx=0;
  sum=n;
  calcsiz(1,1);
  calcsiz(nx,-1);
  dfs1(nx,nx);
  now=0;
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    vis[i]=0;
  }
  for(int i=1;i<=n;i++){
    mn[i]=ans[i]=0x3f3f3f3f3f3f3f3f;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  nx=0;
  sum=n;
  calcsiz(1,1);
  calcsiz(nx,-1);
  dfs2(nx,nx);
  for(int i=1;i<=n;i++){
    printf("%lld\n",ans[i]);
  }
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


