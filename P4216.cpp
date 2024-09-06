#include <iostream>
#include <cstdio>
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[400005];
  int query(int now){
    now++;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x++;
    while(x<=400002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  int getsum(int l,int r){
    return query(r)-query(l-1);
  }
};
int siz[200005];
int mxson[200005];
int dfn[200005];
int seq2tree[200005];
int top[200005];
void dfs(int now,int fa){
  siz[now]=1;
  mxson[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(mxson[now]==0||siz[mxson[now]]<siz[v[i]]){
      mxson[now]=v[i];
    }
  }
  return ;
}
int cnt;
void dfs2(int now,int fa,int tp){
  dfn[now]=++cnt;
  seq2tree[cnt]=now;
  top[now]=tp;
  if(mxson[now]){
    dfs2(mxson[now],now,tp);
    return ;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==mxson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
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
  int root=0;
  for(int i=1;i<=n;i++){
    int fa=read();
    if(fa==0){
      root=i;
    }
    add(fa,i);
  }
  dfs(root,root);
  dfs2(root,root,root);
  int q=read();
  for(int i=1;i<=q;i++){
    int k=read();
    switch(k){
      case 1:{
        break;
      }
      case 2:{
        int ti=read();
        break;
      }
    }
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
