#include <ctime>
#include <iostream>
#include <cstdio>
#include <map>
#include <random>
inline int read();
int ha[25000005];
int quan[500005];
int tree[4000005];
int tree2[4000005];
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree[now]=quan[l];
    tree2[now]=quan[l];
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  tree2[now]=std::max(tree2[now*2],tree2[now*2+1]);
  return ;
}
int ql,qr;
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(ql<l||r<ql){
    return ;
  }
  if(l==r){
    tree[now]=qr;
    tree2[now]=qr;
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  tree2[now]=std::max(tree2[now*2],tree2[now*2+1]);
  return ;
}
int mn,mx;
void query(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    mn=std::min(mn,tree[now]);
    mx=std::max(mx,tree2[now]);
    return ;
  }
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    now+=500000;
    int ans=0;
    while(now>0){
      ans^=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=500000;
    while(x<=1000002){
      tree[x]^=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    x+=500000;
    while(x<=1000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("P3792_7.in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  std::mt19937 mt(time(NULL));
  ha[0]=mt();
  for(int i=1;i<=25000000;i++){
    ha[i]=mt()^ha[i-1];
  }
  for(int i=1;i<=n;i++){
    quan[i]=read();
    aa.mod(i,ha[quan[i]]^(quan[i]-1>=0?ha[quan[i]-1]:0));
  }
  build(1,1,n);
  int tt=0;
  for(int i=1;i<=m;i++){
    int op=read();
    int l=read();
    int r=read();
    switch(op){
      case 1:{
        aa.mod(l,ha[quan[l]]^(quan[l]-1>=0?ha[quan[l]-1]:0));
        quan[l]=r;
        ql=l;
        qr=r;
        mod(1,1,n);
        aa.mod(l,ha[quan[l]]^(quan[l]-1>=0?ha[quan[l]-1]:0));
        break;
      }
      case 2:{
        ql=l;
        qr=r;
        mx=0;
        mn=0x3f3f3f3f;
        query(1,1,n);
        if(mx-mn==(r-l)){
          int tt=aa.query(r)^aa.query(l-1);
          int tt2=ha[mx]^(mn>0?ha[mn-1]:0);
          if(tt==tt2){
            printf("damushen\n");
          }else{
            printf("yuanxing\n");
          }
        }else{
          printf("yuanxing\n");
        }
        break;
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

