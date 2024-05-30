#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int dp[1000015];
int ans[1000015];
int a[1000015];
int lst[1000015];
int nxt[1000015];
int bef[1000015];
int tt[1000015];
int tree[8000015];
int ql,qr,op;
int query(int now,int l,int r){
  if(l>r){
    return 0;
  }
  if(ql<=l&&r<=qr){
    return tree[now];
  }
  if(ql>r||qr<l){
    return 0;
  }
  int mid=(l+r)/2;
  return std::max(query(now*2,l,mid),query(now*2+1,mid+1,r));
}
int add2(int now,int l,int r){
  if(l>r){
    return 0;
  }
  if(ql>r||qr<l){
    return 0;
  }
  if(ql<=l&&r<=qr){
    tree[now]=op;
    return 0;
  }
  int mid=(l+r)/2;
  add2(now*2,l,mid);
  add2(now*2+1,mid+1,r);
  tree[now]=std::max(tree[now*2],tree[now*2+1]);
  return 0;
}
int query(int now,int now2){
  ql=now;
  qr=now2;
  return query(1,1,1000010);
}
void add(int x,int y,int z){
  ql=x;
  qr=y;
  op=z;
  add2(1,1,1000010);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("ex_data/ex_select.in","r",stdin);
  freopen("select.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    bef[i]=lst[a[i]];
    lst[a[i]]=i;
    nxt[bef[i]]=i;
  }
  for(int i=1;i<=n;i++){
    dp[nxt[i]]=0;
    if(i+1<=nxt[i]-1){
      dp[nxt[i]]=query(i+1,nxt[i]-1);
    }
    add(nxt[i],nxt[i],i);
  }
  int mx=0;
  for(int i=1;i<=n;i++){
    mx=std::max(mx,dp[i]);
    mx=std::max(mx,bef[bef[bef[i]]]);
    if(mx>0){
      ans[i]=ans[mx-1]+4;
    }
  }
  printf("%d",ans[n]);
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

