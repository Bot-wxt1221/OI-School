#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int a[200005];
int tree[200005];
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
void mod(int x,int y){
  while(x<=200000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
int dt[200005];
int n,k,m,c,d;
bool check(int toans){
  int nans=0;
  for(int i=1;i<=n;i++){
    nans+=(a[i]>=toans);
  }
  memset(tree,0,sizeof(tree));
  mod(1,nans);
  for(int i=1;i<=n;i++){
    if(a[i]<toans){
      int v=toans-a[i];
      if(a[i]+dt[m]<toans){
        continue;
      }
      int fir=std::lower_bound(dt+1,dt+m+1,v)-dt-1;
      int l=std::max(1ll,i-m+1),r=std::max(1ll,i-fir+1);
      mod(l,1);
      mod(r,-1);
    }
  }
  for(int i=1;i<=n;i++){
    if(query(i)>=k){
      return 1;
    }
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  k=read();
  m=read();
  c=read();
  d=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  dt[1]=c;
  for(int i=2;i<=m;i++){
    dt[i]=dt[i-1]+d;
  }
  int l=0,r=1e18;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      l=mid-1;
    }else{
      r=mid+1;
    }
  }
  for(int i=r;i>=l;i--){
    if(check(i)){
      printf("%lld",i);
      return 0;
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


