#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#define int long long
inline int read();
class node{
  public:
    int x,r,q,i;
    node(int xx=0,int rr=0,int qq=0,int ii=0){
      x=xx;
      r=rr;
      q=qq;
      i=ii;
      return ;
    }
}a[100005];
int seq[500005];
std::map<int,int>mp;
int cnt;
int ans;
int tree[500005];
int lowbit(int x){
  return x&(-x);
}
int query(int x){
  int ans=0;
  while(x>0){
    ans+=tree[x];
    x-=lowbit(x);
  }
  return ans;
}
void add(int x,int y){
  while(x<=500000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
int k;
bool operator < (node a,node b){
  return a.r>b.r;
}
bool cmp(node a,node b){
  return a.q==b.q?a.r<b.r:a.q<b.q;
}
void solve(int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  solve(l,mid);
  solve(mid+1,r);
  int ll=l,rr=mid+1;
  int tl=l;
  for(int i=mid+1;i<=r;i++){
    while(ll<=mid&&a[i].q-a[ll].q>k){ 
      add(mp[a[ll++].x],-1);
    }
    while(tl<=mid&&a[tl].q-a[i].q<=k){
      add(mp[a[tl++].x],1);
    }
    ans+=query(mp[a[i].x+a[i].r])-query(mp[a[i].x-a[i].r]-1);
  }
  for(;ll<tl;ll++){
    add(mp[a[ll].x],-1);
  }
  std::sort(a+l,a+r+1,cmp);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  k=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    a[i].x=read();
    a[i].r=read();
    a[i].q=read();
    a[i].i=i;
    seq[++cnt]=a[i].x;
    seq[++cnt]=a[i].x-a[i].r;
    seq[++cnt]=a[i].x+a[i].r;
  }
  std::sort(seq+1,seq+cnt+1);
  cnt=std::unique(seq+1,seq+cnt+1)-seq-1;
  for(int i=1;i<=cnt;i++){
    mp[seq[i]]=i;
  }
  std::sort(a+1,a+n+1);
  solve(1,n);
  printf("%lld",ans);
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


