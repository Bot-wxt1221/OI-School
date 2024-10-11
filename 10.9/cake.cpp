#include <algorithm>
#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[1000005];
int sufmx[1000005];
int tree[16000005];
int siz[16000005];
int lazyadd[16000005];
int lazymn[16000005];
void build(int now,int l,int r){
  lazyadd[now]=0;
  lazymn[now]=sufmx[1];
  siz[now]=r-l+1;
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  return ;
}
void downAdd(int now,int tt){
  lazyadd[now]+=tt;
  lazymn[now]+=tt;
  return ;
}
void downMin(int now,int tt){
  if(tt<lazymn[now]){
    lazymn[now]=tt;
  }
  return ;
}
void pushdown(int now){
  downAdd(now*2,lazyadd[now]);
  downAdd(now*2+1,lazyadd[now]);
  lazyadd[now]=0;

  downMin(now*2,lazymn[now]);
  downMin(now*2+1,lazymn[now]);
  lazymn[now]=0x3f3f3f3f3f3f3f3f;
  return ;
}
int ql,qr,tt;
void add(int now,int l,int r){
  if(ql<=l&&r<=qr){
    downAdd(now,tt);
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);
  add(now*2,l,mid);
  add(now*2+1,mid+1,r);
}
int query(int now,int l,int r){
  if(l==r){
    return lazymn[now];
  }
  int mid=(l+r)/2;
  pushdown(now);
  return query(now*2,l,mid)+query(now*2+1,mid+1,r);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int sum=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    sum+=a[i];
  }
  for(int i=n;i>=1;i--){
    sufmx[i]=std::max(sufmx[i+1],a[i]);
  }
  build(1,1,n);
  query(1,1,n);
  for(int i=1;i<=n;i++){
    if(a[i]){
      ql=1;
      qr=a[i];
      tt=-1;
      add(1,1,n);
    }
    downMin(1,sufmx[i+1]);
  }
  printf("%lld",sum+query(1,1,n));
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
