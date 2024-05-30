#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
inline int read();
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
void init(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree[now]=0;
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  tree[now]=std::max(tree[now*2+1],tree[now*2]);
  return ;
}
int ql,qr;
int ans=0;
void query(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    ans=std::max(ans,tree[now]);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
int op;
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now]=std::max(tree[now],op);
    lazy[now]=std::max(lazy[now],op);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=std::max(tree[now*2],tree[now*2+1]);
  return ;
}
class node{
  public:
    int h,l,r;
    node(int a=0,int b=0,int c=0){
      h=a;
      l=b;
      r=c;
      return ;
    }
}a[100005];
bool operator < (node a,node b){
  return a.h<b.h;
}
int seq[500005];
int dp1[200005],dp2[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("P1442_2.in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int h=read();
  int x=read();
  int y=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    a[i].h=read();
    a[i].l=read();
    a[i].r=read();
    seq[++cnt]=a[i].r;
    seq[++cnt]=a[i].l;
    seq[++cnt]=a[i].r-1;
    seq[++cnt]=a[i].l+1;

  }
  seq[++cnt]=x;
  std::sort(a+1,a+n+1);
  std::sort(seq+1,seq+cnt+1);
  cnt=std::unique(seq+1,seq+cnt+1)-seq-1;
  x=std::lower_bound(seq+1,seq+cnt+1,x)-seq;
  for(int i=1;i<=n;i++){
    a[i].l=std::lower_bound(seq+1,seq+cnt+1,a[i].l)-seq;
    a[i].r=std::lower_bound(seq+1,seq+cnt+1,a[i].r)-seq;
  }
  init(1,1,cnt);
  for(int i=1;i<=n;i++){
    if(a[i].h>y){
      continue;
    }
    qr=ql=a[i].r;
    ans=0;
    query(1,1,cnt);
    if(a[i].h-a[ans].h>h){
      dp2[i]=0x3f3f3f3f;
    }else{
      if(ans==0){
        dp2[i]=a[i].h;
      }else{
        dp2[i]=dp2[ans]+a[i].h-a[ans].h+(seq[a[ans].r]-seq[a[i].r]);
        dp2[i]=std::min(dp2[i],dp1[ans]+a[i].h-a[ans].h+(seq[a[i].r]-seq[a[ans].l]));

      }
    }
    qr=ql=a[i].l;
    ans=0;
    query(1,1,cnt);
    if(a[i].h-a[ans].h>h){
      dp1[i]=0x3f3f3f3f;
    }else{
      if(ans==0){
        dp1[i]=a[i].h;
      }else{
        dp1[i]=dp2[ans]+a[i].h-a[ans].h+(seq[a[ans].r]-seq[a[i].l]);
        dp1[i]=std::min(dp1[i],dp1[ans]+a[i].h-a[ans].h+(seq[a[i].l]-seq[a[ans].l]));
      }
    }
    ql=a[i].l;
    qr=a[i].r;
    op=i;
    mod(1,1,cnt);
  }
  ql=x;
  qr=x;
  ans=0;
  query(1,1,cnt);
  if(y-a[ans].h<=h){
    int cur=dp1[ans]+y-a[ans].h+seq[x]-seq[a[ans].l];
    cur=std::min(cur,dp2[ans]+y-a[ans].h+seq[a[ans].r]-seq[x]);
    if(cur>0x3f3f3f3f){
      cur=-1;
    }
    printf("%d",cur);
  }else{
    printf("-1");
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

