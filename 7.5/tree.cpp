#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long
inline int read();
class node{
public:
  int op,w,fa;
  node(int a=0,int b=0,int c=0){
    op=a;
    w=b;
    fa=c;
    return ;
  }
}qu[100005];
int v[100005];
int fir[100005];
int nxt[100005];
int w[100005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
}
int siz[100005];
int mx[100005];
void dfs(int now,int fa){
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(mx[now]==0||siz[mx[now]]<siz[v[i]]){
      mx[now]=v[i];
    }
  }
  return ;
}
int dfn;
int fa[100005];
int qr[100005];
int tree2seq[100005];
int seq2tree[100005];
int top[100005];
void dfs2(int now,int fa,int tp){
  tree2seq[now]=++dfn;
  ::fa[now]=fa;
  seq2tree[dfn]=now;
  top[now]=tp;
  if(mx[now]){
    dfs2(mx[now],now,tp);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==mx[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
  qr[now]=dfn;
}
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[100005];
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
    while(x<=100002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  int getsum(int l,int r){
    return query(r)-query(l-1);
  }
}aa,bb;
int getsiz(int x){
  return aa.query(qr[x])-aa.query(tree2seq[x]-1);
}
int calc(int num){
  int ret=0;
  while(num!=1){
    int tp=top[num];
    ret+=bb.getsum(tree2seq[tp],tree2seq[num]);
    if(tp!=1){
      ret-=bb.getsum(tree2seq[fa[tp]],tree2seq[fa[tp]]);
      ret+=w[fa[tp]]*(getsiz(fa[tp])-getsiz(tp));
    }else{
      break;
    }
    num=fa[tp];
    if(num==1){
      ret+=bb.getsum(tree2seq[fa[tp]],tree2seq[fa[tp]]);
    }
  }
  return ret;
}
void update(int x,int y){
  aa.mod(tree2seq[x],1);
  bb.mod(tree2seq[x],w[x]);
  while(x!=1){
    int tp=top[x];
    if(tp!=1){
      bb.mod(tree2seq[fa[tp]],w[fa[tp]]);
    }
    x=fa[tp];
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  #endif
  int q=read();
  w[1]=read();
  for(int i=1;i<=q;i++){
    fir[i]=-1;
  }
  int cnt=1;
  for(int i=1;i<=q;i++){
    node op(read(),0,0);
    if(op.op==1){
      op.w=read();
      op.fa=read();
      cnt++;
      add(op.fa,cnt);
      w[cnt]=op.w;
    }else{
      op.w=cnt;
    }
    qu[i]=op;
  }
  dfs(1,1);
  dfs2(1,1,1);
  update(1,w[1]);
  int tans=w[1];
  cnt=1;
  for(int i=1;i<=q;i++){
    int op=qu[i].op;
    int w=qu[i].w;
    int fa=qu[i].fa;
    if(op==2){
      printf("%lld\n",tans);
    }else{
      cnt++;
      tans+=calc(cnt);
      tans+=w;
      update(cnt,w);
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
