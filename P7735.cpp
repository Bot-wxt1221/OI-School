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
int siz[100005];
int bson[100005];
int to[100005][35];
int top[100005];
int depth[100005];
int dfn[100005];
void dfs1(int now,int fa){
  siz[now]=1;
  bson[now]=0;
  depth[now]=depth[fa]+1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs1(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0){
      bson[now]=v[i];
    }else if(siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
  }
  return ;
}
int cnt;
void dfs2(int now,int fa,int tp){
  top[now]=tp;
  dfn[now]=++cnt;
  to[now][0]=fa;
  for(int i=1;i<=30;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  if(bson[now]!=0){
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
int getlca(int x,int y){
  if(depth[x]<depth[y]){
    std::swap(x,y);
  }
  if(depth[x]>depth[y]){
    for(int i=30;i>=0;i--){
      if(depth[to[x][i]]>=depth[y]){
        x=to[x][i];
      }
    }
  }
  if(x!=y){
    for(int i=30;i>=0;i--){
      if(to[x][i]!=to[y][i]){
        x=to[x][i];
        y=to[y][i];
      }
    }
    x=to[x][0];
    y=to[y][0];
  }
  return x;
}
class data{
public:
  int ln,rn,ans;
  data(int a=0,int b=0,int c=0){
    ln=a;
    rn=b;
    ans=c;
    return ;
  }
};
data merge(data &a,data &b){
  return data(a.ln==-1?b.ln:a.ln,b.rn,a.ans+b.ans+(a.rn==b.ln));
}
data tree[800005];
int sizt[800005];
int lazy[800005];
void build(int now,int l,int r){
  lazy[now]=-1;
  sizt[now]=r-l+1;
  if(l==r){
    tree[now]=data(-l-1,-l-1,0);
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=merge(tree[now*2],tree[now*2+1]);
  return ;
}
void pushdown(int now){
  if(lazy[now]==-1){
    return ;
  }
  lazy[now*2]=lazy[now*2+1]=lazy[now];
  tree[now*2]=data(lazy[now],lazy[now],sizt[now*2]-1);
  tree[now*2+1]=data(lazy[now],lazy[now],sizt[now*2+1]-1);
  lazy[now]=-1;
  return ;
}
int ql,qr,op;
data cur;
void query(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    cur=merge(cur,tree[now]);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
void mod(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    lazy[now]=op;
    tree[now]=data(op,op,r-l);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=merge(tree[now*2],tree[now*2+1]);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    cnt=0;
    now=0;
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
    dfs1(1,1);
    dfs2(1,1,1);
    build(1,1,n);
    for(int i=1;i<=m;i++){
      int op=read();
      int a=read();
      int b=read();
      switch(op){
        case 1:{
                 int fa=getlca(a,b);
                 while(1){
                   if(depth[top[a]]<=depth[fa]){
                      ql=dfn[fa];
                      qr=dfn[a];
                      ::op=i;
                      mod(1,1,n);
                      break;
                   }else{
                      ql=dfn[top[a]];
                      qr=dfn[a];
                      ::op=i;
                      mod(1,1,n);
                      a=to[top[a]][0];
                   }
                 }
                 std::swap(a,b);
                 while(1){
                   if(depth[top[a]]<=depth[fa]){
                      ql=dfn[fa];
                      qr=dfn[a];
                      ::op=i;
                      mod(1,1,n);
                      break;
                   }else{
                      ql=dfn[top[a]];
                      qr=dfn[a];
                      ::op=i;
                      mod(1,1,n);
                      a=to[top[a]][0];
                   }
                 }
                 break;
               }
        case 2:{
                 data cur2(-1,-1,0);
                  int fa=getlca(a,b);
                 while(1){
                 cur=data(-1,-1,0);
                   if(depth[top[a]]<=depth[fa]){
                      ql=dfn[fa];
                      qr=dfn[a];
                      query(1,1,n);
                      cur2=merge(cur,cur2);
                      break;
                   }else{
                      ql=dfn[top[a]];
                      qr=dfn[a];
                      query(1,1,n);
                      cur2=merge(cur,cur2);
                      a=to[top[a]][0];
                   }
                 }
                 int anss=cur2.ans;
                 cur2=data(-1,-1,0);
                 std::swap(a,b);
                 while(1){
                 cur=data(-1,-1,0);
                   if(depth[top[a]]<=depth[fa]){
                      ql=dfn[fa];
                      qr=dfn[a];
                      query(1,1,n);
                      cur2=merge(cur,cur2);
                      break;
                   }else{
                      ql=dfn[top[a]];
                      qr=dfn[a];
                      query(1,1,n);
                      cur2=merge(cur,cur2);
                      a=to[top[a]][0];
                   }
                 }
                 printf("%d\n",anss+cur2.ans);
                 break;
               }
      }
    }
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
