#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int a[300005];
int lst[300005];
int ans[300005];
std::vector<std::pair<int,int> >vec[300005];
class SEQNODE{
public:
  SEQNODE *l,*r;
  int tagsum;
  SEQNODE(){
    l=r=NULL;
    tagsum=0;
  }
}tree[300005*64],*ng[300005];
int cntt;
SEQNODE *init(SEQNODE *now,int l,int r){
  now=tree+(++cntt);
  if(l==r){
    return now;
  }
  int mid=(l+r)/2;
  now->l=init(now->l,l,mid);
  now->r=init(now->r,mid+1,r);
  return now;
}
int ql,qr,op;
int bkk;
SEQNODE *add(SEQNODE *now,int l,int r){
  if(r<ql||qr<l){
    return now;
  }
  auto newnow=tree+(++cntt);
  *newnow=*now;
  now=newnow;
  if(ql<=l&&r<=qr){
    now->tagsum+=op;
    return now;
  }
  int mid=(l+r)/2;
  now->l=add(now->l,l,mid);
  now->r=add(now->r,mid+1,r);
  return now;
}
bool yes=0;
SEQNODE *replace(SEQNODE *A,SEQNODE *B,int l,int r,int sum){
  yes=0;
  if(r<ql||qr<l){
    return A;
  }
  if(ql<=l&&r<=qr){
    yes=1;
    auto newnow=tree+(++cntt);
    *newnow=*B;
    newnow->tagsum+=sum;
    return newnow;
  }
  int mid=(l+r)/2;
  A->l=replace(A->l,B->l,l,mid,sum+B->tagsum-A->tagsum);
  A->r=replace(A->r,B->r,mid+1,r,sum+B->tagsum-A->tagsum);
  return A;
}
void query(SEQNODE *A,int l,int r){
  if(A==NULL){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  op+=A->tagsum;
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  query(A->l,l,mid);
  query(A->r,mid+1,r);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int q=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    lst[i]=n+1;
  }
  lst[a[n]]=n;
  ng[n+2]=init(ng[n+2],1,n);
  ql=qr=n;
  op=0;
  ng[n+1]=add(ng[n+2],1,n);
  ql=qr=n;
  op=1;
  ng[n]=add(ng[n+1],1,n);
  for(int i=n-1;i>=1;i--){
    ql=i;
    qr=lst[a[i]]-1;
    op=1;
    ng[i]=add(ng[i+1],1,n);
    ql=lst[a[i]];
    qr=n;
    if(ql<=qr){
      replace(ng[i],ng[lst[a[i]]+1],1,n,0);
    }
    lst[a[i]]=i;
  }
  int lstans=0;
  for(int i=1;i<=q;i++){
    int l=read()^lstans;
    int r=read()^lstans;
    ql=qr=r;
    op=0;
    query(ng[l],1,n);
    lstans=op;
    printf("%d\n",op);
  }
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
