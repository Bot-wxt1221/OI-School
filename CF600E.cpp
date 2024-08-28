#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
inline int read();
int fir[100005];
int mp[100005];
std::queue<int>qu;
int nxt[200005];
int v[200005];
int cnt[200005];
long long mx;
int now,mxv;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
long long ans[100005];
int color[100005];
int siz[100005];
int bson[100005];
int in[100005];
int out[100005];
int dtd[100005];
int colr[100005];
int cntt;
void dfs(int now,int fa){
  in[now]=++cntt;
  dtd[cntt]=now;
  siz[now]=1;
  colr[cntt]=color[now];
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
  out[now]=cntt;
  return ;
}
inline void eva(int nw,int fa){
  for(int now=in[nw];now<=out[nw];now++){
    if(mp[colr[now]]==0){
      qu.push(colr[now]);
    } 
    mp[colr[now]]++;
    if(mp[colr[now]]==mxv){
      mx+=colr[now];
    }else if(mp[colr[now]]>mxv){
      mxv=mp[colr[now]];
      mx=colr[now];
    }
  }
  return ;
}
void dfs2(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now);
  }
  while(qu.size()>0){
    mp[qu.front()]=0;
    qu.pop();
  }
  mx=0;
  mxv=0;
  if(bson[now]){
    dfs2(bson[now],now);
  }
  if(mp[color[now]]==0){
    qu.push(color[now]);
  }  
  mp[color[now]]++;
  if(mp[color[now]]==mxv){
    mx+=color[now];
  }else if(mp[color[now]]>mxv){
    mxv=mp[color[now]];
    mx=color[now];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    eva(v[i],now);
  }
  ans[now]=mx;
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
    color[i]=read();
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dfs2(1,1);
  for(int i=1;i<=n;i++){
    printf("%lld ",ans[i]);
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
