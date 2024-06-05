#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int w[400005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int l[400005];
int r[400005];
int seq[400005];
int cnt=0;
int dep[400005];
void dfs(int now,int fa){
  l[now]=r[now]=++cnt;
  seq[cnt]=dep[now];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dep[v[i]]=dep[now]+w[i];
    dfs(v[i],now);
    r[now]=++cnt;
    seq[cnt]=dep[now];    
  }
  return ;
}
int lazy[3200005];
int mx[3200005];
int mn[3200005];
int res[3200005];
int mx2[3200005];
int mx3[3200005];
void pushdown(int now){
  mx[now*2]+=lazy[now];
  mn[now*2]+=lazy[now];
  mx2[now*2]-=lazy[now];
  mx3[now*2]-=lazy[now];
  lazy[now*2]+=lazy[now];
  
  mx[now*2+1]+=lazy[now];
  mn[now*2+1]+=lazy[now];
  mx2[now*2+1]-=lazy[now];
  mx3[now*2+1]-=lazy[now];
  lazy[now*2+1]+=lazy[now];

  lazy[now]=0;
  return ;
}
void pushup(int now){
  mx[now]=std::max(mx[now*2],mx[now*2+1]);
  mn[now]=std::min(mn[now*2],mn[now*2+1]);
  mx2[now]=std::max(mx2[now*2],mx2[now*2+1]);
  mx2[now]=std::max(mx2[now],mx[now*2]-2*mn[now*2+1]);
  mx3[now]=std::max(mx3[now*2],mx3[now*2+1]);
  mx3[now]=std::max(mx3[now],mx[now*2+1]-2*mn[now*2]);
  res[now]=std::max(res[now*2],res[now*2+1]);
  res[now]=std::max(res[now],mx[now*2]+mx3[now*2+1]);
  res[now]=std::max(res[now],mx2[now*2]+mx[now*2+1]);
  return ;
}
void build(int now,int l,int r){
  if(l==r){
    mx[now]=mn[now]=seq[l];
    mx2[now]=mx3[now]=-seq[l];
    res[now]=0;
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
int ql,qr,op;
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    mx[now]+=op;
    mn[now]+=op;
    mx2[now]-=op;
    mx3[now]-=op;
    lazy[now]+=op;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  pushup(now);
}
void query(int now,int l,int r){

}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int q=read();
  int W=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  dfs(1,1);
  build(1,1,cnt);
  int lst=0;
  for(int i=1;i<=q;i++){
    int d=(read()+lst)%(n-1);
    d++;
    int e=(read()+lst)%W;
    int tt=v[d*2];
    int tt2=v[d*2-1];
    if(dep[tt]<dep[tt2]){
      std::swap(tt,tt2);
    }
    int md=e-w[d*2];
    w[d*2]=e;
    w[d*2-1]=e;
    ql=l[tt];
    qr=r[tt];
    op=md;
    mod(1,1,cnt);
    printf("%lld\n",res[1]);
    lst=res[1];
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

