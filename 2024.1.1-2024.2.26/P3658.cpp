#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
class node{
  public:
    int a,b,i;
    node(int x=0,int y=0,int z=0){
      a=x;
      b=y;
      i=z;
      return ;
    }
}seq[100005],temp[100005];
bool operator < (node a,node b){
  if(a.a!=b.a){
    return a.a<b.a;
  }
  return a.b>b.b;
}
int tree[100005];
int lowbit(int x){
  return x&(-x);
}
void add(int x,int y){
  while(x<=100000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
int query(int x){
  int ans=0;
  while(x>0){
    ans+=tree[x];
    x-=lowbit(x);
  }
  return ans;
}
int ans=0;
int k;
void cdq(int l,int r){
  if(l>=r){
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid);
  cdq(mid+1,r);
  int nl=l,nr=mid+1;
  int now=l-1;
  while(nl<=mid&&nr<=r){
    if(seq[nl].b>=seq[nr].b){
      temp[++now]=seq[nl];
      add(seq[nl].i,1);
      nl++;
    }else{
      temp[++now]=seq[nr];
      ans+=(query(100000)-(query(std::min(seq[nr].i+k,100000ll))-query(std::max(seq[nr].i-k-1,0ll))));
      nr++;
    }
  }
  while(nl<=mid){
    temp[++now]=seq[nl];
    add(seq[nl].i,1);
    nl++;
  }
  while(nr<=r){
    temp[++now]=seq[nr];
    ans+=(query(100000)-(query(std::min(seq[nr].i+k,100000ll))-query(std::max(seq[nr].i-k-1,0ll))));
    nr++;
  }
  for(int i=l;i<=mid;i++){
    add(seq[i].i,-1);
  }
  for(int i=l;i<=r;i++){
    seq[i]=temp[i];
  }
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
  for(int i=1;i<=n;i++){
    int x=read();
    seq[x].a=i;
  }
  for(int i=1;i<=n;i++){
    int y=read();
    seq[y].b=i;
    seq[y].i=y;
  }
  std::sort(seq+1,seq+n+1);
  cdq(1,n);
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


