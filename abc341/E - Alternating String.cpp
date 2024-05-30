#include <iostream>
#include <cstdio>
inline int read();
char s2[5000005];
int s[5000005];
int tree[10000005];
int siz[10000005];
bool lazy[10000005];
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  siz[now]=r-l+1;
  if(l==r){
    tree[now]=s[l];
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=tree[now*2]+tree[now*2+1];
  return ;
}
int ql,qr;
void pushdown(int now){
  if(lazy[now]==0){
    return ;
  }
  lazy[now]=0;
  lazy[now*2]^=1;
  lazy[now*2+1]^=1;
  tree[now*2]=siz[now*2]-tree[now*2];
  tree[now*2+1]=siz[now*2+1]-tree[now*2+1];
  return ;
}
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  pushdown(now);
  if(ql<=l&&r<=qr){
    tree[now]=siz[now]-tree[now];
    lazy[now]^=1;
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree[now]=tree[now*2+1]+tree[now*2];
  return ;
}
int query(int now,int l,int r){
  if(l>r){
    return 0;
  }
  pushdown(now);
  if(ql<=l&&r<=qr){
    return tree[now];
  }
  if(r<ql||qr<l){
    return 0;
  }
  int mid=(l+r)/2;
  return query(now*2,l,mid)+query(now*2+1,mid+1,r);
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),q;
  q=read();
  scanf("%s",s2+1);
  for(int i=1;i<=n;i++){
    s[i]=(s2[i]-'0')^(i%2);
  }
  build(1,1,n);
  for(int i=1;i<=q;i++){
    int op=read();
    if(op==1){
      ql=read();
      qr=read();
      mod(1,1,n);
    }else{
      ql=read();
      qr=read();
      int ans=query(1,1,n);
      if(ans==0||ans==qr-ql+1){
        printf("Yes\n");
      }else{
        printf("No\n");
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


