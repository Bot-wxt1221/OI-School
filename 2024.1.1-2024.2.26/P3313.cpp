#include <endian.h>
#include <iostream>
#include <cstdio>
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
int w[200005];
int c[200005];
class node{
public:
  int l,r;
  node *tl,*tr;
  int sum,mx;
  node(int lr=0,int rr=0,node *ttl=NULL,node *ttr=NULL){
    l=lr;
    r=rr;
    tl=ttl;
    tr=ttr;
    sum=mx=0;
    return ;
  }
};
class SEG{
public:
  node *head;
}ar[100005];
int ql,qr;
int cnttt=0;
int querys(node *now){
  if(now==NULL){
    return 0;
  }
  if(ql<=now->l&&now->r<=qr){
    return now->sum;
  }
  if(now->r<ql||qr<now->l){
   return 0;
  }
  int mid=(now->l+now->r)/2;
  return querys(now->tl)+querys(now->tr);
}
int querym(node *now){
  if(now==NULL){
    return 0;
  }
  if(ql<=now->l&&now->r<=qr){
    return now->mx;
  }
  if(now->r<ql||qr<now->l){
    return 0;
  }
  int mid=(now->l+now->r)/2;
  return std::max(querym(now->tl),querym(now->tr));
}
int qp,qt;
void pushup(node *now){
  now->mx=0;
  now->sum=0;
  if(now->tl!=NULL){
    now->sum+=now->tl->sum;
    now->mx=std::max(now->mx,now->tl->mx);
  }
  if(now->tr!=NULL){
    now->sum+=now->tr->sum;
    now->mx=std::max(now->mx,now->tr->mx);
  }
  return ;
}
node *mod(node *now,int tl,int tr){
  if(tr<qp||qp<tl){
    return now;
  }
  if(now==NULL){
    now=new node;
    now->l=tl;
    now->r=tr;
  }
  if(tr-tl+1==1){
    now->sum=now->mx=qt;
    return now;
  }
  int mid=(now->l+now->r)/2;
  now->tl=mod(now->tl,now->l,mid);
  now->tr=mod(now->tr,mid+1,now->r);
  pushup(now);
  return now;
}
int siz[100005];
int bigson[100005];
int to[100005][20];
int dep[100005];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  to[now][0]=fa;
  for(int i=1;i<20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      return ;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bigson[now]==0||siz[bigson[now]]<siz[v[i]]){
      bigson[now]=v[i];
    }
  }
  return ;
}
int cnt;
int dfn[100005];
int tot[100005];
int top[100005];
void dfs2(int now,int fa,int tp){
  top[now]=tp;
  dfn[now]=++cnt;
  tot[cnt]=now;
  if(bigson[now]==0){
    return ;
  }
  dfs2(bigson[now],now,tp);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||bigson[now]==v[i]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
  return ;
}
char tt[20];
int lca(int x,int y){
  if(dep[x]>dep[y]){
    std::swap(x,y);
  }
  while(dep[x]<dep[y]){
    int i=0;
    for(i=19;i>0;i--){
      if(dep[x]<dep[to[y][i]]){
        break;
      }
    }
    y=to[y][i];
  }
  while(x!=y){
    int i=0;
    for(i=19;i>0;i--){
      if(to[x][i]!=to[y][i]){
        break;
      }
    }
    x=to[x][i];
    y=to[y][i];
  }
  return x;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("P3313_5.in","r",stdin);
  #endif
  int n=read();
  int q=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    w[i]=read();
    c[i]=read();
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dfs2(1,1,1);
  for(int i=1;i<=n;i++){
    qp=dfn[i];
    qt=w[i];
    cnttt=0;
    ar[c[i]].head=mod(ar[c[i]].head,1,n);
  }
  for(int i=1;i<=q;i++){
    scanf("%s",tt+1);
    if(tt[1]=='C'){
      if(tt[2]=='W'){
        int x=read();
        int c=read();
        w[x]=c;
        qp=dfn[x];
        qt=w[x];
        cnttt=0;
        ar[::c[x]].head=mod(ar[::c[x]].head,1,n);
      }else{
        int x=read();
        int c=read();
        qp=dfn[x];
        qt=0;
        cnttt=0;
        ar[::c[x]].head=mod(ar[::c[x]].head,1,n);
        qp=dfn[x];
        qt=w[x];
        ::c[x]=c;
        cnttt=0;
        ar[c].head=mod(ar[c].head,1,n);
      }
    }else{
      if(tt[2]=='S'){
        int x=read();
        int y=read();
        int ty=y;
        int lc=lca(x,y);
        int ans=0;
        while(dep[top[x]]>dep[lc]){
          ql=dfn[top[x]];
          qr=dfn[x];
          ans+=querys(ar[c[ty]].head);
           x=to[top[x]][0];
        }
        ql=dfn[lc];
        qr=dfn[x];
        ans+=querys(ar[c[ty]].head);
        std::swap(x,y);
        while(dep[top[x]]>dep[lc]){
          ql=dfn[top[x]];
          qr=dfn[x];
          ans+=querys(ar[c[ty]].head);
          x=to[top[x]][0];
        }
        ql=dfn[lc];
        qr=dfn[x];
        ans+=querys(ar[c[ty]].head);
        ql=dfn[lc];
        qr=dfn[lc];
        ans-=querys(ar[c[ty]].head);
        printf("%d\n",ans);
      }else{
        int x=read();
        int y=read();
        int ty=y;
        int lc=lca(x,y);
        int ans=0;
        while(dep[top[x]]>dep[lc]){
          ql=dfn[top[x]];
          qr=dfn[x];
          ans=std::max(ans,querym(ar[c[ty]].head));
          x=to[top[x]][0];
        }
        ql=dfn[lc];
        qr=dfn[x];
        ans=std::max(ans,querym(ar[c[ty]].head));
        std::swap(x,y);
        while(dep[top[x]]>dep[lc]){
          ql=dfn[top[x]];
          qr=dfn[x];
          ans=std::max(ans,querym(ar[c[ty]].head));
          x=to[top[x]][0];
        }
        ql=dfn[lc];
        qr=dfn[x];
        ans=std::max(ans,querym(ar[c[ty]].head));
        printf("%d\n",ans);
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


