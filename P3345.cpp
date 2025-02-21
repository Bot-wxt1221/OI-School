#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int fir[100005];
int nxt[200005];
int fa[100005];
int v[200005];
int w[200005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int siz[200005];
int bson[200005];
int dis[200005];
void dfs(int now,int fa){
  siz[now]=1;
  ::fa[now]=fa;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dis[v[i]]=dis[now]+w[i];
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[v[i]]>siz[bson[now]]){
      bson[now]=v[i];
    }
  }
  return ;
}
int top[200005];
int dfn[200005];
int lst[200005];
int www[200005];
int to2[200005];
int cnt;
void dfs2(int now,int fa,int tp){
  top[now]=tp;
  dfn[now]=++cnt;
  to2[cnt]=now;
  www[now]=dis[now]-dis[fa];
  if(bson[now]){
    dfs2(bson[now],now,tp);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
  lst[now]=cnt;
  return ;
}
int edge[200005*4];
int mx[200005*4];
int lazy[200005*4];
int sum[200005*4];
void init(int now,int l,int r){
  siz[now]=r-l+1;
  if(l==r){
    edge[now]=www[to2[l]];
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  edge[now]=edge[now*2]+edge[now*2+1];
  return ;
}
void pushdown(int now){
  mx[now*2]+=lazy[now];
  mx[now*2+1]+=lazy[now];
  lazy[now*2]+=lazy[now];
  lazy[now*2+1]+=lazy[now];
  sum[now*2]+=lazy[now]*edge[now*2];
  sum[now*2+1]+=lazy[now]*edge[now*2+1];
  lazy[now]=0;
  return ;
}
int ans,tt;
void bit(int now,int l,int r){
  if(l==r){
    ans=l;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  if(mx[now*2+1]*2>=tt){
    bit(now*2+1,mid+1,r);
  }else{
    bit(now*2,l,mid);
  }
  return ;
}
void add(int now,int l,int r,int ql,int qr,int op){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    mx[now]+=op;
    lazy[now]+=op;
    sum[now]+=op*edge[now];
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  add(now*2,l,mid,ql,qr,op);
  add(now*2+1,mid+1,r,ql,qr,op);
  mx[now]=std::max(mx[now*2],mx[now*2+1]);
  sum[now]=sum[now*2]+sum[now*2+1];
}
void query(int now,int l,int r,int ql,int qr){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    ans+=sum[now];
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid,ql,qr);
  query(now*2+1,mid+1,r,ql,qr);
  return ;
}
int sum1=0,sum2=0;
int n;
void addd(int x,int y){
  while(top[x]!=1){
    add(1,1,n,dfn[top[x]],dfn[x],y);
    x=fa[top[x]];
  }
  add(1,1,n,1,dfn[x],y);
  return ;
}
int queryy(int x){
  ans=0;
  while(top[x]!=1){
    query(1,1,n,dfn[top[x]],dfn[x]);
    x=fa[top[x]];
  }
  query(1,1,n,1,dfn[x]);
  return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int q=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int w=read();
    add(x,y,w);
    add(y,x,w);
  }
  dfs(1,1);
  dfs2(1,1,1);
  init(1,1,n);
  for(int i=1;i<=q;i++){
    int x=read();
    int y=read();
    sum1+=y;
    sum2+=dis[x]*y;
    addd(x,y);
    tt=mx[1];
    bit(1,1,n);
    ans=to2[ans];
    printf("%lld\n",sum1*dis[ans]+sum2-2*queryy(ans));
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
