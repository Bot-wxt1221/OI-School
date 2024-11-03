#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int fa[100005];
int siz[100005];
int bson[100005];
int dfn[100005];
int dep[100005];
int seq2tree[100005];
int top[100005];
int to[100005][30];
bool mark[100005];
int prehuan[100005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  for(int i=1;i<=25;i++){
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
    if(bson[now]==0||siz[v[i]]>siz[bson[now]]){
      bson[now]=v[i];
    }
  }
  return ;
}
int cnt=0;
void dfs2(int now,int fa,int tp){
  if(mark[now]){
    prehuan[now]=now;
  }else{
    prehuan[now]=prehuan[fa];
  }
  top[now]=tp;
  dfn[now]=++cnt;
  seq2tree[cnt]=now;
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
int tmpdis=0;
int getlca(int x,int y){
  tmpdis=0;
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  for(int i=25;i>=0;i--){
    if(dep[to[x][i]]>dep[y]){
      x=to[x][i];
      tmpdis+=(1<<i);
    }
  }
  if(dep[x]>dep[y]){
    x=to[x][0];
    tmpdis++;
  }
  for(int i=25;i>=0;i--){
    if(to[x][i]!=to[y][i]){
      x=to[x][i];
      y=to[y][i];
      tmpdis+=(1<<i);
      tmpdis+=(1<<i);
    }
  }
  if(x!=y){
    x=to[x][0];
    y=to[y][0];
    tmpdis+=2;
  }
  return x;
}
int lowbit(int x){
  return x&(-x);
}
int huansiz;
class SEG{
public:
  int tree[800005];
  int siz[800005];
  bool lazy[800005];
  void init(int now,int l,int r){
    siz[now]=r-l+1;
    if(l==r){
      tree[now]=0;
      return ;
    }
    int mid=(l+r)/2;
    init(now*2,l,mid);
    init(now*2+1,mid+1,r);
    tree[now]=0;
    return ;
  }
  void pushdown(int now){
    if(lazy[now]==0){
      return ;
    }
    lazy[now*2]^=1;
    lazy[now*2+1]^=1;
    tree[now*2]=siz[now*2]-tree[now*2];
    tree[now*2+1]=siz[now*2+1]-tree[now*2+1];
    lazy[now]=0;
    return ;
  }
  int ql,qr;
  int op=0;
  void query(int now,int l,int r){
    if(r<ql||qr<l){
      return ;
    }
    if(ql<=l&&r<=qr){
      op+=tree[now];
      return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    query(now*2,l,mid);
    query(now*2+1,mid+1,r);
    return ;
  }
  void mod(int now,int l,int r){
    if(r<ql||qr<l){
      return ;
    }
    if(ql<=l&&r<=qr){
      lazy[now]^=1;
      tree[now]=siz[now]-tree[now];
      return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    mod(now*2,l,mid);
    mod(now*2+1,mid+1,r);
    tree[now]=tree[now*2]+tree[now*2+1];
  }
}b;
int n;
void marktree(int x,int y){
  int lcc=getlca(x,y);
  while(1){
    if(dep[top[x]]<=dep[lcc]){
      b.ql=dfn[lcc];
      b.qr=dfn[x];
      b.mod(1,1,n);
      break;
    }else{
      b.ql=dfn[top[x]];
      b.qr=dfn[x];
      b.mod(1,1,n);
      x=to[top[x]][0];
    }
  }
  x=y;
  while(1){
    if(dep[top[x]]<=dep[lcc]){
      b.ql=dfn[lcc];
      b.qr=dfn[x];
      b.mod(1,1,n);
      break;
    }else{
      b.ql=dfn[top[x]];
      b.qr=dfn[x];
      b.mod(1,1,n);
      x=to[top[x]][0];
    }
  }
  return ;
}
int getsum(int x,int y){
  b.op=0;
  int lcc=getlca(x,y);
  while(1){
    if(dep[top[x]]<=dep[lcc]){
      b.ql=dfn[lcc];
      b.qr=dfn[x];
      b.query(1,1,n);
      break;
    }else{
      b.ql=dfn[top[x]];
      b.qr=dfn[x];
      b.query(1,1,n);
      x=to[top[x]][0];
    }
  }
  x=y;
  while(1){
    if(dep[top[x]]<=dep[lcc]){
      b.ql=dfn[lcc];
      b.qr=dfn[x];
      b.query(1,1,n);
      break;
    }else{
      b.ql=dfn[top[x]];
      b.qr=dfn[x];
      b.query(1,1,n);
      x=to[top[x]][0];
    }
  }
  int nowop=b.op;
  b.op=0;
  b.ql=b.qr=dfn[lcc];
  b.query(1,1,n);
  return nowop-b.op*2;
}
int xxx,yyy;
int getdis(int x,int y){
  getlca(x,y);
  return tmpdis;
}
int getlst(int x,int y){
  for(int i=25;i>=0;i--){
    if(dep[x]<dep[to[y][i]]){
      y=to[y][i];
    }
  }
  return y;
}
int cnttt[100005];
int pree[100005];
int summ;
int spee=0;
void markhuan(int x,int y){
  if(x==y){
    return ;
  }
  int ret=getlca(x,y);
  int tt=tmpdis;
  if(tt<huansiz-tt){
    marktree(x,y);
  }else if(tt>huansiz-tt){
    if(getdis(x,xxx)+getdis(y,yyy)>getdis(x,yyy)+getdis(y,xxx)){
      std::swap(x,y);
    }
    marktree(x,xxx);
    marktree(y,yyy);
    spee^=1;
  }else{
    int tx=pree[x];
    int back=cnttt[(tx+summ-2)%summ+1];
    int nxt=cnttt[(tx)%summ+1];
    int rnxt=0;
    if(ret==x){
      rnxt=getlst(x,y);
    }else{
      rnxt=to[x][0];
    }
    if(rnxt!=nxt){
      std::swap(nxt,back);
    }
    assert(rnxt==nxt);
    if(nxt<back){
      marktree(x,y);
    }else{
      if(getdis(x,xxx)+getdis(y,yyy)>getdis(x,yyy)+getdis(y,xxx)){
        std::swap(x,y);
      }
      marktree(x,xxx);
      marktree(y,yyy);
      spee^=1;
    }
  }
  return ;
}
void runn(int pre,int fa){
  while(pre!=fa){
    cnttt[++summ]=pre;
    pre=to[pre][0];
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    fa[i]=i;
  }
  int xx,yy;
  for(int i=1;i<=n;i++){
    int x=read();
    int y=read();
    if(getfa(x)==getfa(y)){
      xx=x;
      yy=y;
      continue;
    }
    fa[getfa(x)]=getfa(y);
    add(x,y);
    add(y,x);
  }
  xxx=xx;
  yyy=yy;
  dfs(1,1);
  mark[xx]=mark[yy]=1;
  huansiz=2;
  while(xx!=yy){
    if(dep[xx]<dep[yy]){
      std::swap(xx,yy);
    }
    huansiz++;
    xx=to[xx][0];
    mark[xx]=1;
  }
  huansiz--;
  runn(xxx,xx);
  cnttt[++summ]=xx;
  int cursumm=summ+1;
  runn(yyy,yy);
  std::reverse(cnttt+cursumm,cnttt+summ+1);
  for(int i=1;i<=summ;i++){
    pree[cnttt[i]]=i;
  }
  dfs2(1,1,1);
  b.init(1,1,n);
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int lca=getlca(x,y);
    int axx=0;
    if(dep[prehuan[x]]>=dep[lca]){
      axx=prehuan[x];
    }
    int ayy=0;
    if(dep[prehuan[y]]>=dep[lca]){
      ayy=prehuan[y];
    }
    if(axx==0&&ayy==0){
      marktree(x,y);
    }else if(axx==0&&ayy!=0){
      marktree(x,xx);
      markhuan(xx,ayy);
      marktree(ayy,y);
    }else if(ayy==0&&axx!=0){
      marktree(y,xx);
      markhuan(axx,xx);
      marktree(axx,x);
    }else{
      marktree(y,ayy);
      markhuan(axx,ayy);
      marktree(axx,x);
    }
    b.ql=1;
    b.qr=n;
    b.op=0;
    b.query(1,1,n);
    int ret=n-b.op;
    int tt=getsum(xxx,yyy);
    if(tt!=summ-1&&spee){
      ret--;
    }
    printf("%d\n",ret);
  }
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
