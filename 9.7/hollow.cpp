#include <iostream>
#include <cstdio>
inline int read();
int siz[800005];
int seq[200005];
int minl[800005];
int maxl[800005];
int minr[800005];
int maxr[800005];
int mxsum[800005];
int mnsum[800005];
int sum[800005];
bool lazy[800005];
std::pair<int,int>mxsump[800005],mnsump[800005];
int poslmn[800005],posrmn[800005];
int poslmx[800005],posrmx[800005];
void pushup(int now){
  siz[now]=siz[now*2]+siz[now*2+1];
  sum[now]=sum[now*2]+sum[now*2+1];
  mxsum[now]=std::max(mxsum[now*2],mxsum[now*2+1]);
  if(mxsum[now]==mxsum[now*2]){
    mxsump[now]=mxsump[now*2];
  }else{
    mxsump[now]=mxsump[now*2+1];
  }
  mnsum[now]=std::min(mnsum[now*2],mnsum[now*2+1]);
  if(mnsum[now]==mnsum[now*2]){
    mnsump[now]=mnsump[now*2];
  }else{
    mnsump[now]=mnsump[now*2+1];
  }
  minl[now]=std::min(minl[now*2],sum[now*2]+minl[now*2+1]);
  if(minl[now]==minl[now*2]){
    poslmn[now]=poslmn[now*2];
  }else{
    poslmn[now]=poslmn[now*2+1];
  }
  maxl[now]=std::max(maxl[now*2],sum[now*2]+maxl[now*2+1]);
  if(maxl[now]==maxl[now*2]){
    poslmx[now]=poslmx[now*2];
  }else{
    poslmx[now]=poslmx[now*2+1];
  }
  minr[now]=std::min(minr[now*2+1],sum[now*2+1]+minr[now*2]);
  if(minr[now]==minr[now*2+1]){
    posrmn[now]=posrmn[now*2+1];
  }else{
    posrmn[now]=posrmn[now*2];
  }
  maxr[now]=std::max(maxr[now*2+1],sum[now*2+1]+maxr[now*2]);
  if(maxr[now]==maxr[now*2+1]){
    posrmx[now]=posrmx[now*2+1];
  }else{
    posrmx[now]=posrmx[now*2];
  }
  mxsum[now]=std::max(mxsum[now],maxr[now*2]+maxl[now*2+1]);
  if(mxsum[now]==maxr[now*2]+maxl[now*2+1]){
    mxsump[now]={posrmx[now*2],poslmx[now*2+1]};
  }
  mnsum[now]=std::max(mnsum[now],minr[now*2]+minl[now*2+1]);
  if(mnsum[now]==minr[now*2]+minl[now*2+1]){
    mnsump[now]={posrmn[now*2],poslmn[now*2+1]};
  }
  return ;
}
void build(int now,int l,int r){
  if(l==r){
    sum[now]=seq[l];
    siz[now]=1;
    minl[now]=std::min(seq[l],0);
    minr[now]=std::min(seq[l],0);
    mnsum[now]=std::min(seq[l],0);
    maxl[now]=std::max(seq[l],0);
    maxr[now]=std::max(seq[l],0);
    mxsum[now]=std::max(seq[l],0);
    poslmn[now]=l;
    poslmx[now]=l;
    posrmx[now]=l;
    posrmn[now]=l;
    mxsump[now]=mnsump[now]={l,l};
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
void diff(int now){
  mxsum[now]=-mxsum[now];
  mnsum[now]=-mnsum[now];

  minl[now]=-minl[now];
  maxl[now]=-maxl[now];

  minr[now]=-minr[now];
  maxr[now]=-maxr[now];
  return ;
}
void pushdown(int now){
  if(lazy[now]){
    lazy[now*2]^=1;
    lazy[now*2+1]^=1;
    diff(now*2);
    std::swap(mxsum[now*2],mnsum[now*2]);
    std::swap(minl[now*2],maxl[now*2]);
    std::swap(minr[now*2],maxr[now*2]);
    std::swap(mxsump[now*2],mnsump[now*2]);
    std::swap(poslmx[now*2],poslmn[now*2]);
    std::swap(posrmx[now*2],posrmn[now*2]);

    diff(now*2+1);
    std::swap(mxsum[now*2+1],mnsum[now*2+1]);
    std::swap(minl[now*2+1],maxl[now*2+1]);
    std::swap(minr[now*2+1],maxr[now*2+1]);
    std::swap(mxsump[now*2+1],mnsump[now*2+1]);
    std::swap(poslmx[now*2+1],poslmn[now*2+1]);
    std::swap(posrmx[now*2+1],posrmn[now*2+1]);
    lazy[now]=0;
  }
  return ;
}
int ql,qr;
void mod(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    diff(now);
    std::swap(mxsum[now],mnsum[now]);
    std::swap(minl[now],maxl[now]);
    std::swap(minr[now],maxr[now]);
    std::swap(mxsump[now],mnsump[now]);
    std::swap(poslmn[now],poslmx[now]);
    std::swap(posrmn[now],posrmx[now]);
    lazy[now]^=1;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  pushup(now);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    int x=read();
    seq[i]=read();
    if(x==1){
      cnt+=seq[i];
      seq[i]*=-1;
    }
  }
  build(1,1,n);
  printf("%d\n",cnt);
  for(int i=1;i<=n;i++){
    cnt+=mxsum[1];
    ql=mxsump[1].first;
    qr=mxsump[1].second;
    mod(1,1,n);
    printf("%d\n",cnt);
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
