#include <iostream>
#include <cstdio>
#include <set>
inline int read();
std::set<int>se[100005];
int dfn[100005];
int fir[100005];
int nxt[200005];
int v[200005];
int siz[100005];
int dep[100005];
int bson[100005];
int jump[100005];
bool tree[200005];
int now=1;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int cnt=0;
void dfs(int now,int fa){
  dfn[now]=++cnt;
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(dfn[v[i]]==0){
      dfs(v[i],now);
      tree[i]=tree[i^1]=1;
      siz[now]+=siz[v[i]];
      if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
        bson[now]=v[i];
      }
    }else{
    }
  }
  return ;
}
void dfs2(int now,int fa){
  if(bson[now]){
    dfs2(bson[now],now);
    std::swap(se[now],se[bson[now]]);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(dep[v[i]]<dep[now]){
      se[now].insert(dep[v[i]]);
    }
    if(v[i]==fa||dep[v[i]]<dep[now]){
      continue;
    }
    dfs2(v[i],now);
    for(auto j=se[v[i]].begin();j!=se[v[i]].end();j++){
      se[now].insert(*j);
    }
    se[v[i]].clear();
  }
  if(se[now].size()){
    jump[now]=*(--se[now].end());
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dfs2(1,1);
  
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
