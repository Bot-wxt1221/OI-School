#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
inline int read();
std::vector<int>vec[300005][3];
std::map<int,int>mp[2];
int fir[300005];
int nxt[600005];
int v[600005];
int w[300005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dep[300005];
int to[300005][20];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  for(int i=1;i<20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
  return ;
}
int s[300005],t[300005];
int ls[300005],lt[300005],lca[300005];
int getlca(int a,int b,int *la,int *lb){
  if(dep[a]<dep[b]){
    std::swap(a,b);
    std::swap(la,lb);
  }
  if(dep[a]>dep[b]){
    for(int i=19;i>=0;i--){
      if(dep[to[a][i]]>dep[b]){
        a=to[a][i];
      }
    }
    *la=a;
    a=to[a][0];
  }
  if(a!=b){
    for(int i=19;i>=0;i--){
      if(to[a][i]!=to[b][i]){
        a=to[a][i];
        b=to[b][i];
      }
    }
    *la=a;
    *lb=b;
    a=to[a][0];
    b=to[b][0];
  }
  return a;
}
int ans[300005];
void dfs2(int now,int fa){
  for(int i=0;i<vec[now][0].size();i++){
    if(dep[s[vec[now][0][i]]]-dep[now]==w[now]){
      ans[now]++;
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
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
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int a=read();
    int b=read();
    add(a,b);
    add(b,a);
  }
  dfs(1,1);
  for(int i=1;i<=n;i++){
    w[i]=read();
  }
  for(int i=1;i<=m;i++){
    s[i]=read();
    t[i]=read();
    lca[i]=getlca(s[i],t[i],&ls[i],&lt[i]);
    vec[lca[i]][0].push_back(i);
    vec[ls[i]][1].push_back(i);
    vec[lt[i]][2].push_back(i);
  }
  dfs2(1,1);
  for(int i=1;i<=n;i++){
    printf("%d ",ans[i]);
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
