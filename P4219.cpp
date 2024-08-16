#include <cmath>
#include <iostream>
#include <cstdio>
inline int read();
int fir[100005];
int dep[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
class op{
  public:
    int kind,x,y;
    op(int a=0,int b=0,int c=0){
      kind=a;
      x=b;
      y=c;
      return ;
    }
}a[100005];
int siz[100005];
int bson[100005];
class Union{
public:
  int fa[100005];
  bool mark[100005];
  int getfa(int x){
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
  }
  Union(){
    for(int i=1;i<=100000;i++){
      fa[i]=i;
      mark[i]=0;
    }
    return ;
  }
}U;
int fa[100005];
void dfs(int now,int fa){
  ::fa[now]=fa;
  siz[now]=1;
  dep[now]=dep[fa]+1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
    siz[now]+=siz[v[i]];
  }
  return ;
}
int cnt;
int dfn[100005];
int tp[100005];
void dfs2(int now,int fa,int tp){
  ::tp[now]=tp;
  dfn[now]=++cnt;
  if(bson[now]){
    dfs2(bson[now],now,tp);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
  return ;
}
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    now+=2;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=2;
    while(x<=1000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    x+=2;
    while(x<=1000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
void mod(int x,int y,int ad){
  while(x!=y){
    if(dep[tp[x]]<=dep[y]){
      aa.mod(dfn[y],ad);
      aa.mod(dfn[x]+1,-ad);
      return ;
    }
    aa.mod(dfn[tp[x]],ad);
    aa.mod(dfn[x]+1,-ad);
    x=fa[tp[x]];
  }
  aa.mod(dfn[x],ad);
  aa.mod(dfn[x]+1,-ad);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int q=read();
  aa.mod(1,1);
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=q;i++){
    char t;
    while((t=getchar())!='A'&&t!='Q');
    a[i].kind=(t=='A');
    a[i].x=read();
    a[i].y=read();
    if(t=='A'){
      add(a[i].x,a[i].y);
      add(a[i].y,a[i].x);
    }
  }
  for(int i=1;i<=n;i++){
    if(dfn[i]==0){
      dfs(i,i);
      dfs2(i,i,i);
    }
  }
  for(int i=1;i<=q;i++){
    int x=a[i].x;
    int y=a[i].y;
    if(a[i].kind){
      if(dep[x]>dep[y]){
        std::swap(x,y);
      }
      mod(x,U.getfa(x),aa.query(dfn[y]));
      U.fa[U.getfa(y)]=U.getfa(x);
    }else{
      if(dep[x]>dep[y]){
        std::swap(x,y);
      }
      int a=aa.query(dfn[U.getfa(x)]);
      int b=aa.query(dfn[y]);
      printf("%d\n",(a-b)*b);
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
