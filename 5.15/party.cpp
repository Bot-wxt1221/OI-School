#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
inline int read();
int lowbit(int x){
  return x&(-x);
}
class BIT{
  public:
    int tree[200005];
    int query(int x){
      int ans=-0x3f3f3f3f;
      while(x>0){
        ans=std::max(ans,tree[x]);
        x-=lowbit(x);
      }
      return ans;
    }
    void mod(int x,int y){
      while(x<=200001){
        tree[x]=std::max(tree[x],y);
        x+=lowbit(x);
      }
    }
}t1;
class st{
  public:
    int a,b,c;
    st(int x=0,int y=0,int z=0){
      a=x;
      b=y;
      c=z;
      return ;
    }
}a[100005],b[100005];
bool cmp(st a,st b){
  return a.a>b.a;
}
bool cmp2(st a,st b){
  return a.b>b.b;
}
class node{
  public:
    int k,x;
    node(int kk=0,int xx=0){
      k=kk;
      x=xx;
      return ;
  }
};
node tree[800005];
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree[now]=node(0,-0x3f3f3f3f);
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  return ;
}
int ql,qr;
node add;
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    if(tree[now].k==add.k){
      if(add.x>tree[now].x){
        tree[now].x=add.x;
      }
      return ;
    }else{
      double same=(tree[now].x-add.x)*((long double)(1))/(add.k-tree[now].k);
      if(same>r||same<l){
        if(tree[now].x+tree[now].k*r<add.x+add.k*r){
          tree[now].x=add.x;
          tree[now].k=add.k;
        }
      }else{
        int mid=(l+r)/2;
        mod(now*2,l,mid);
        mod(now*2+1,mid+1,r);
        return ;
      }
    }
  }else{
    int mid=(l+r)/2;
    mod(now*2,l,mid);
    mod(now*2+1,mid+1,r);
    return ;
  }
}
int op;
int ans=0;
void query(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(op<l||r<op){
    return ;
  }
  ans=std::max(ans,tree[now].k*op+tree[now].x);
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("party.in","r",stdin);
  freopen("party.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i].a=read();
    a[i].b=read();
    a[i].c=read();
  }
  for(int i=1;i<=n;i++){
    b[i].a=read();
    b[i].b=read();
    b[i].c=read();
  }
  std::sort(a+1,a+n+1,cmp);
  std::sort(b+1,b+n+1,cmp);
  int cur=1;
  __int128 ans=0;
  build(1,1,1e5);
  for(int i=1;i<=n;i++){
    while(cur<=n&&b[cur].a>=a[i].a){
      add.k=b[cur].c;
      add.x=(-b[cur].a+1)*add.k;
      ql=b[cur].a;
      qr=b[cur].b;
      mod(1,1,1e5);
      cur++;
    }
    op=a[i].b;
    ::ans=0;
    query(1,1,1e5);
    ans=std::max(ans,((__int128)::ans)*a[i].c);
  }
  for(int i=1;i<=800000;i++){
    tree[i]=node(0,-0x3f3f3f3f);
  }
  cur=1;
  for(int i=1;i<=n;i++){
    while(cur<=n&&a[cur].a>=b[i].a){
      add.k=a[cur].c;
      add.x=(-a[cur].a+1)*add.k;
      ql=a[cur].a;
      qr=a[cur].b;
      mod(1,1,1e5);
      cur++;
    }
    op=b[i].b;
    ::ans=0;
    query(1,1,1e5);
    ans=std::max(ans,((__int128)::ans)*b[i].c);
  }
  std::sort(a+1,a+n+1,cmp2);
  std::sort(b+1,b+n+1,cmp2);
  cur=1;
  for(int i=1;i<=200000;i++){
    t1.tree[i]=-0x3f3f3f3f;
  }
  for(int i=1;i<=n;i++){
    while(cur<=n&&b[cur].b>=a[i].b){
      t1.mod(b[cur].a,b[cur].c);
      cur++;
    }
    ans=std::max(ans,(a[i].b-a[i].a+1)*((__int128)a[i].c)*t1.query(a[i].a));
  }
  cur=1;
  for(int i=1;i<=200000;i++){
    t1.tree[i]=-0x3f3f3f3f;
  }
  for(int i=1;i<=n;i++){
    while(cur<=n&&a[cur].b>=b[i].b){
      t1.mod(a[cur].a,a[cur].c);
      cur++;
    }
    ans=std::max(ans,(b[i].b-b[i].a+1)*((__int128)b[i].c)*t1.query(b[i].a));
  }
  printf("%lld",(long long)ans);

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

