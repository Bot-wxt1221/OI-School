#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int fir[55];
int nxt[105];
int v[105];
int ans[105];
int sum[105];
int to[105][25];
int lca[105];
int xx[105];
int yy[105];
int dep[105];
bool tar[105];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa,int tfa=0){
  sum[now]=ans[now];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,i);
    sum[now]+=sum[v[i]];
  }
  if(sum[now]){
    tar[tfa]=1;
  }else{
    tar[tfa]=0;
  }
  return ;
}
void dfs2(int now,int fa){
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  for(int i=1;i<=10;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
}
int getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  if(dep[x]>dep[y]){
    for(int i=10;i>=0;i--){
      if(dep[to[x][i]]>dep[y]){
        x=to[x][i];
      }
    }
    x=to[x][0];
  }
  if(x!=y){
    for(int i=10;i>=0;i--){
      if(to[x][i]!=to[y][i]){
        x=to[x][i];
        y=to[y][i];
      }
    }
    x=to[x][0];
    y=to[y][0];
  }
  return x;
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
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs2(1,1);
  int m=read();
  for(int i=1;i<=m;i++){
    int xx=read();
    int yy=read();
    ::xx[i]=xx;
    ::yy[i]=yy;
    lca[i]=getlca(xx,yy);
  }
  int ans=0;
  for(int i=0;i<(1<<m);i++){
    memset(::ans,0,sizeof(::ans));
    memset(tar,0,sizeof(tar));
    int sta=1;
    for(int j=1;j<=m;j++){
      if(i&(1<<(j-1))){
        ::ans[xx[j]]++;
        ::ans[yy[j]]++;
        ::ans[lca[j]]-=2;
        sta*=-1;
      }
    }
    dfs(1,1);
    int tt=0;
    for(int j=1;j<=now;j++){
      tt+=tar[j];
    }
    ans+=sta*(1ll<<(n-1-tt));
  }
  printf("%lld",ans);
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
