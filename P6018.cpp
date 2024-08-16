#include <iostream>
#include <cstdio>
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
class Trie{
public:
  Trie *to[2];
  int w,xr;
  Trie(){
    to[0]=to[1]=NULL;
    w=xr=0;
    return ;
  }
  void pushup(){
    w=xr=0;
    if(to[0]!=NULL){
      w+=to[0]->w;
      xr^=(to[0]->xr<<1);
    }
    if(to[1]!=NULL){
      w+=to[1]->w;
      xr^=(to[1]->xr<<1)|(to[1]->w&1);
    }
    return ;
  }
  void insert(int x,int depth=0){
    if(depth>23){
      w++;
      return ;
    }
    if(to[x&1]==NULL){
      to[x&1]=new Trie();
    }
    to[x&1]->insert(x>>1,depth+1);
    pushup();
    return ;
  }
  void del(int x,int depth=0){
    if(depth>23){
      w--;
      return ;
    }
    to[x&1]->del(x>>1,depth+1);
    pushup();
    return ;
  }
  void add(){
    std::swap(to[1],to[0]);
    if(to[0]!=NULL){
      to[0]->add();
    }
    pushup();
    return ;
  }
}r[500005];
int a1[500005],a2[500005];
int fa[500005];
void dfs(int now,int fa){
  ::fa[now]=fa;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    r[now].insert(a1[v[i]]);
  }
  return ;
}
int get(int x){
  int ans=a1[x];
  if(x!=1){
    ans+=a2[fa[x]];
  }
  return ans;
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
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  for(int i=1;i<=n;i++){
    a1[i]=read();
  }
  dfs(1,1);
  for(int i=1;i<=m;i++){
    int op=read();
    int x=read();
    switch(op){
      case 1:{
        if(x!=1&&fa[x]!=1){
          r[fa[fa[x]]].del(get(fa[x]));
          a1[fa[x]]++;
          r[fa[fa[x]]].insert(get(fa[x]));
        }
        if(x!=1&&fa[x]==1){
          a1[fa[x]]++;
        }
        a2[x]++;
        r[x].add();
        break;
      }
      case 2:{
        int v=read();
        if(x!=1){
          r[fa[x]].del(get(x));
        }
        a1[x]-=v;
        if(x!=1){
          r[fa[x]].insert(get(x));
        }
        break;
      }
      case 3:{
        int ans=r[x].xr;
        if(x!=1){
          ans^=get(fa[x]);
        }
        printf("%d\n",ans);
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
