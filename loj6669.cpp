#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int query(int l,int r){
  printf("? %d %d\n",l,r);
  fflush(stdout);
  return read();
}
int fir[300005];
int nxt[300005];
int v[300005];
int fa[300005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::vector<int>vec[300005];
int dep[300005];
int dw[300005];
int top[300005];
int to[300005][22];
int siz[300005];
int bson[300005];
int oson[300005];
void dfs(int now,int fa){
  to[now][0]=fa;
  for(int i=1;i<22;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  siz[now]=1;
  bson[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
  }
  return ;
}
void dfs2(int now,int fa,int tp){
  top[now]=fa;
  dw[tp]=now;
  if(bson[now]){
    dfs2(bson[now],now,tp);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    oson[now]=v[i];
    dfs2(v[i],now,v[i]);
  }
  return ;
}
int getlca(int x,int y){
  int depl=(dep[x]+dep[y]-query(x,y))/2;
  int tdis=dep[x]-depl;
  int cur=x;
  for(int i=21;i>=0;i--){
    if(tdis>=(1<<i)){
      tdis-=(1<<i);
      cur=to[cur][i];
    }
  }
  return cur;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  fir[1]=-1;
  for(int i=2;i<=n;i++){
    fir[i]=-1;
    dep[i]=query(1,i);
    vec[dep[i]].push_back(i);
  }
  for(int i=1;i<=n;i++){
    dfs(1,1);
    dfs2(1,1,1);
    for(int j=0;j<vec[i].size();j++){
      int y=1;
      while(dep[y]!=dep[vec[i][j]]-1){
        int lca=getlca(dw[y],vec[i][j]);
        if(lca==dw[y]){
          y=dw[y];
        }else{
          y=oson[lca];
        }
      }
      add(y,vec[i][j]);
      fa[vec[i][j]]=y;
    }
  }
  printf("!");
  for(int i=2;i<=n;i++){
    printf(" %d",fa[i]);
  }
  printf("\n");
  fflush(stdout);
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
