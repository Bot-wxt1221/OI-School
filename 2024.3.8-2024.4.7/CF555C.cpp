#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
inline int read();
class op{
  public:
    int x,y;
    char to;
}a[200005];
int xx[200005];
int yy[200005];
int totx;
int toty;
std::map<int,int>mp1;
std::map<int,int>mp2;
int q;
int tree[3200005];
int lazy[3200005];
void pushdown(int now){
  tree[now*2]=std::max(tree[now*2],lazy[now]);
  tree[now*2+1]=std::max(tree[now*2+1],lazy[now]);

  lazy[now*2]=std::max(lazy[now*2],lazy[now]);
  lazy[now*2+1]=std::max(lazy[now*2+1],lazy[now]);

  lazy[now]=0;
  return ;
}
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree[now]=0;
    lazy[now]=0;
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=std::max(tree[now*2],tree[now*2+1]);
  lazy[now]=0;
  return ;
}
int ql,qr,op;
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  pushdown(now);
  if(ql<=l&&r<=qr){
    tree[now]=std::max(tree[now],op);
    lazy[now]=std::max(lazy[now],op);
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=std::max(tree[now*2],tree[now*2+1]);
}
int query(int now,int l,int r){
  if(l>r){
    return 0x3f3f3f3f;
  }
  if(r<ql||ql<l){
    return 0x3f3f3f3f;
  }
  pushdown(now);
  if(l==r){
    return tree[now];
  }
  int mid=(l+r)/2;
  return std::min(query(now*2,l,mid),query(now*2+1,mid+1,r));
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  q=read();
  for(int i=1;i<=q;i++){
    a[i].x=read();
    xx[++totx]=a[i].x;
    a[i].y=read();
    yy[++toty]=a[i].y;
    std::cin>>a[i].to;
  }
  std::sort(xx+1,xx+totx+1);
  std::sort(yy+1,yy+toty+1);
  totx=std::unique(xx+1,xx+totx+1)-xx-1;
  toty=std::unique(yy+1,yy+toty+1)-yy-1;
  for(int i=1;i<=totx;i++){
    mp1[xx[i]]=i;
  }
  for(int i=1;i<=toty;i++){
    mp2[yy[i]]=i+q;
  }
  for(int i=1;i<=q;i++){
    a[i].x=mp1[a[i].x];
    a[i].y=mp2[a[i].y];
  }
  build(1,1,2*q);
  for(int i=1;i<=q;i++){
    if(a[i].to=='L'){
      qr=ql=a[i].y;
      int pre=query(1,1,2*q);
      ql=pre;
      qr=a[i].x;
      printf("%d\n",xx[a[i].x]-xx[pre]);
      op=a[i].y-q;
      ql++;
      mod(1,1,2*q);
      ql=a[i].y;
      qr=a[i].y;
      op=a[i].x;
      mod(1,1,2*q);
    }else{
      ql=qr=a[i].x;
      int pre=query(1,1,2*q);
      ql=pre+q;
      qr=a[i].y;
      printf("%d\n",yy[qr-q]-yy[ql-q]);
      op=a[i].x;
      ql++;
      mod(1,1,2*q);
      ql=a[i].x;
      qr=a[i].x;
      op=a[i].y-q;
      mod(1,1,2*q);
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


