#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define modd 998244353
inline int read();
int n;
int fir[500005];
int nxt[1000005];
int v[1000005];
int depth[500005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::vector<int>vec[500005];
class SEGNODE{
public:
  SEGNODE *l,*r;
  int tmul=1,tsum=0;
  SEGNODE(){
    l=NULL;
    r=NULL;
    tsum=0;
    tmul=1;
    return ;
  }
}tree[500050<<5],*beg[500005*2];
int cnt=0;
void pushdown(SEGNODE *now){
  if(now->l==NULL){
  }else{
    now->l->tmul*=now->tmul;
    now->l->tsum*=now->tmul;
    now->l->tmul%=modd;
    now->l->tsum%=modd;
  }
  if(now->r==NULL){
  }else{
    now->r->tmul*=now->tmul;
    now->r->tsum*=now->tmul;
    now->r->tmul%=modd;
    now->r->tsum%=modd;
  }
  now->tmul=1;

  return ;
}
SEGNODE *mod(SEGNODE *now,int l,int r,int x){
  if(now==NULL){
    now=(++cnt)+tree;
  }
  now->tsum=now->tmul=1;
  if(l==r){
    return now;
  }
  int mid=(l+r)/2;
  if(x<=mid){
    now->l=mod(now->l,l,mid,x);
  }else{
    now->r=mod(now->r,mid+1,r,x);
  }
  return now;
}
int ql,qr,op;
SEGNODE *query(SEGNODE *now,int l,int r){
  if(qr<l){
    return now;
  }
  if(now==NULL||r<=qr){
    if(now!=NULL){
      op+=now->tsum;
      op%=modd;
    }
    return now;
  }
  if(now==NULL){
    now=(++cnt)+tree;
  }
  pushdown(now);
  int mid=(l+r)/2;
  now->l=query(now->l,l,mid);
  now->r=query(now->r,mid+1,r);
  return now;
}
SEGNODE *merge(SEGNODE *A,SEGNODE *B,int l,int r,int &s1,int &s2){
  if(A==NULL&&B==NULL){
    return NULL;
  }
  if(A==NULL){
    s1+=B->tsum;
    s1%=modd;
    B->tsum*=s2;
    B->tsum%=modd;
    B->tmul*=s2;
    B->tmul%=modd;
    return B;
  }
  if(B==NULL){
    s2+=A->tsum;
    s2%=modd;
    A->tsum*=s1;
    A->tsum%=modd;
    A->tmul*=s1;
    A->tmul%=modd;
    return A;
  }
  if(l==r){
    int tx=A->tsum;
    int ty=B->tsum;
    s1+=ty;
    s1%=modd;
    A->tsum=(tx*s1+ty*s2)%modd;
    A->tsum%=modd;
    s2+=tx;
    s2%=modd;
    return A;
  }
  pushdown(A);
  pushdown(B);
  int mid=(l+r)/2;
  A->l=merge(A->l,B->l,l,mid,s1,s2);
  A->r=merge(A->r,B->r,mid+1,r,s1,s2);
  A->tsum=0;
  if(A->l!=NULL){
    A->tsum+=A->l->tsum;
  }
  if(A->r!=NULL){
    A->tsum+=A->r->tsum;
  }
  A->tsum%=modd;
  return A;
}
void dfs(int now,int fa){
  depth[now]=depth[fa]+1;
  int mx=0;
  for(int i=0;i<vec[now].size();i++){
    mx=std::max(mx,depth[vec[now][i]]);
  }
  beg[now]=mod(beg[now],0,n,mx);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    ql=qr=depth[now];
    op=0;
    query(beg[v[i]],0,n);
    int op2=0;
    beg[now]=merge(beg[now],beg[v[i]],0,n,op,op2);
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int x=read();
    int y=read();
    vec[y].push_back(x);
  }
  dfs(1,1);
  op=0;
  ql=qr=0;
  query(beg[1],0,n);
  printf("%lld\n",op);
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
