#include <iostream>
#include <cstdio>
inline int read();
int fir[200005];
int w[200005];
int nxt[400005];
int v[400005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dep[200005];
int to[200005][21];
class node{
  public:
    int l[2],siz;
    node(int a=0,int b=0,int c=0){
      l[0]=a;
      l[1]=b;
      siz=c;
      return ;
    }
}tree[1600005];
int len;
int getlca(int a,int b){
  if(dep[a]<dep[b]){
    std::swap(a,b);
  }
  len=0;
  if(dep[a]>dep[b]){
    for(int i=20;i>=0;i--){
      if(dep[to[a][i]]>dep[b]){
        a=to[a][i];
        len+=(1<<i);
      }
    }
    a=to[a][0];
    len++;
  }
  if(a!=b){
    for(int i=20;i>=0;i--){
      if(to[a][i]!=to[b][i]){
        a=to[a][i];
        b=to[b][i];
        len+=(1<<(i+1));
      }
    }
    a=to[a][0];
    b=to[b][0];
    len+=2;
  }
  return a;
}
node merge(node a,node b){
  node ans;
  if(a.siz>ans.siz){
    ans=a;
  }
  if(b.siz>ans.siz){
    ans=b;
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      getlca(a.l[i],b.l[j]);
      len+=w[a.l[i]]+w[b.l[j]];
      if(len>ans.siz){
        ans.siz=len;
        ans.l[0]=a.l[i];
        ans.l[1]=b.l[j];
      }
    }
  }
  return ans;
}
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  for(int i=1;i<21;i++){
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
void init(int now,int l,int r){
  if(l==r){
    tree[now].l[0]=tree[now].l[1]=l;
    tree[now].siz=2*w[l];
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  tree[now]=merge(tree[now*2],tree[now*2+1]);
}
int nn;
void update(int now,int l,int r){
  if(nn<l||r<nn){
    return ;
  }
  if(l==r){
    tree[now].l[0]=tree[now].l[1]=l;
    tree[now].siz=2*w[l];
    return ;
  }
  int mid=(l+r)/2;
  update(now*2,l,mid);
  update(now*2+1,mid+1,r);
  tree[now]=merge(tree[now*2],tree[now*2+1]);
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
    w[i]=read();
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  init(1,1,n);
  int m=read();
  for(int i=1;i<=m;i++){
    nn=read();
    int xj=read();
    w[nn]=xj;
    update(1,1,n);
    printf("%d\n",std::max((tree[1].siz+1)/2,std::max(w[tree[1].l[0]],w[tree[1].l[1]])));
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
