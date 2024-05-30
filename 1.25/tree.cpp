#include <iostream>
#include <cstdio>
#define int long long
inline int read();
namespace t1{
  int fir[1000005];
  int nxt[1000005];
  int v[1000005];
  int w[1000005];
  int faa[1000005][30];
  int dis[1000005][30];
  int dep[1000005];
  int now;
  void add(int x,int y,int z){
    v[++now]=y;
    w[now]=z;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  void dfs(int now,int fa);
  int getlca(int x,int y);
};

void t1::dfs(int now,int fa){
  faa[now][0]=fa;
  dep[now]=dep[fa]+1;
  for(int i=1;i<25;i++){
    faa[now][i]=faa[faa[now][i-1]][i-1];
    dis[now][i]=dis[now][i-1]+dis[faa[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dis[v[i]][0]=w[i];
    dfs(v[i],now);
  }
  return ;
}
int t1::getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  int diss=0;
  while(dep[x]>dep[y]){
    int i=24;
    for(i=24;i>0;i--){
      if(dep[faa[x][i]]>dep[y]){
        break;
      }
    }
    diss+=dis[x][i];
    x=faa[x][i];
  }
  while(x!=y){
    int i=24;
    for(i=24;i>0;i--){
      if(faa[x][i]!=faa[y][i]){
        break;
      }
    }
    diss+=dis[x][i];
    diss+=dis[y][i];
    x=faa[x][i];
    y=faa[y][i];
  }
  return diss;
}
namespace t2{
  int fir[1000005];
  int nxt[1000005];
  int v[1000005];
  int w[1000005];
  int dep[1000005];
  int now;
  void add(int x,int y,int z){
    v[++now]=y;
    w[now]=z;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  int getlca(int x,int y);
  int faa[1000005][30];
  int dis[1000005][30];
  void dfs(int now,int fa);
};
void t2::dfs(int now,int fa){
  faa[now][0]=fa;
  dep[now]=dep[fa]+1;
  for(int i=1;i<25;i++){
    faa[now][i]=faa[faa[now][i-1]][i-1];
    dis[now][i]=dis[now][i-1]+dis[faa[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dis[v[i]][0]=w[i];
    dfs(v[i],now);
  }
  return ;
}
int t2::getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  int diss=0;
  while(dep[x]>dep[y]){
    int i=24;
    for(i=24;i>0;i--){
      if(dep[faa[x][i]]>dep[y]){
        break;
      }
    }
    diss+=dis[x][i];
    x=faa[x][i];
  }
  while(x!=y){
    int i=24;
    for(i=24;i>0;i--){
      if(faa[x][i]!=faa[y][i]){
        break;
      }
    }
    diss+=dis[x][i];
    diss+=dis[y][i];
    x=faa[x][i];
    y=faa[y][i];
  }
  return diss;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    t1::fir[i]=-1;
    t2::fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int w=read();
    t1::add(x,y,w);
    t1::add(y,x,w);
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int w=read();
    t2::add(x,y,w);
    t2::add(y,x,w);
  }
  t1::dfs(1,1);
  t2::dfs(1,1);
  for(int i=1;i<=n;i++){
    int ans=0x3f3f3f3f3f3f3f3f;
    for(int j=1;j<=n;j++){
      if(i==j){
        continue;
      }
      ans=std::min(ans,t1::getlca(i,j)+t2::getlca(i,j));
    }
    printf("%lld\n",ans);
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


