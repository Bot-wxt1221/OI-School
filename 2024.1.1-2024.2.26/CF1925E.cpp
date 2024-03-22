#include <iostream>
#include <cstdio>
#include <set>
#define int long long
inline int read();
int siz[2400005];
int v[300005];
int x[300005];
int cost[300005];
int cost2[300005];
std::set<int>pos;
int tree[2400005];
int cheng[2400005];
int plus[2400005];
void pushdown(int now,int l,int r){
  if(siz[now*2+1]>0){
    cheng[now*2+1]+=cheng[now];
    plus[now*2+1]+=plus[now];
    tree[now*2+1]+=plus[now]*siz[now*2+1];
    tree[now*2+1]+=(siz[now*2+1]*(siz[now*2+1]-1))/2*cheng[now];
  }
  int mid=(l+r)/2;
  int rig=r-mid;
  if(siz[now*2]>0){
    cheng[now*2]+=cheng[now];
    plus[now*2]+=plus[now];
    plus[now*2]+=cheng[now]*rig;
    tree[now*2]+=(plus[now]+cheng[now]*rig)*siz[now*2];
    tree[now*2]+=cheng[now]*(siz[now*2]*(siz[now*2]-1)/2);
  }
  cheng[now]=0;
  plus[now]=0;
  return ;
}
void init(int now,int l,int r){
  if(l>r){
    return ;
  }
  siz[now]=r-l+1;
  if(l==r){
    tree[now]=cost[l];
    cheng[now]=0;
    plus[now]=0;
    return ;
  }
  cheng[now]=0;
  plus[now]=0;
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  tree[now]=tree[now*2]+tree[now*2+1];
  return ;
}
int ql,qr;
int query(int now,int l,int r){
  pushdown(now,l,r);
  if(ql<=l&&r<=qr){
    return tree[now];
  }
  if(r<ql||qr<l){
    return 0;
  }
  int mid=(l+r)/2;
  return query(now*2,l,mid)+query(now*2+1,mid+1,r);
}
int op;
void modadd(int now,int l,int r){
  pushdown(now,l,r);
  if(ql<=l&&r<=qr){
    tree[now]+=(op)*siz[now];
    plus[now]+=op;
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  int mid=(l+r)/2;
  modadd(now*2,l,mid);
  modadd(now*2+1,mid+1,r);
  tree[now]=tree[now*2]+tree[now*2+1];
  return ;
}
int op2=0;
void modcheng(int now,int l,int r){
  pushdown(now,l,r);
  if(ql<=l&&r<=qr){
    tree[now]+=(op)*(siz[now])*(siz[now]-1)/2;
    cheng[now]+=op;
    tree[now]+=op2*siz[now];
    plus[now]+=op2;
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  int mid=(l+r)/2;
  if(qr>mid){
    int rig=(std::min(qr,r)-mid);
    op2+=rig*op;
  }
  modcheng(now*2,l,mid);
  if(qr>mid){
    int rig=(std::min(qr,r)-mid);
    op2-=rig*op;
  }
  modcheng(now*2+1,mid+1,r);
  tree[now]=tree[now*2]+tree[now*2+1];
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m,q;
  m=read();
  q=read();
  for(int i=1;i<=m;i++){
    x[i]=read();
    pos.insert(x[i]);
  }
  for(int i=1;i<=m;i++){
    v[i]=read();
    cost[x[i]]=cost2[x[i]]=v[i];
  }
  for(int i=1;i<=n;i++){
    if(cost[i]==0){
      cost[i]=cost[i-1];
    }
  }
  int dis=0;
  for(int i=n;i>0;i--){
    if(pos.find(i)!=pos.end()){
      dis=0;
    }else{
      dis++;
    }
    cost[i]*=dis;
  }
  init(1,1,n);
  for(int i=1;i<=q;i++){
    int t=read();
    switch(t){
      case 1:{
        int x=read();
        int v=read();
        cost2[x]=v;
        std::set<int>::iterator now=pos.lower_bound(x);
        int nxt=*now;
        int pre=*(--now);
        ql=pre+1;
        qr=x;
        op=cost2[pre]*(x-nxt);
        modadd(1,1,n);
        ql=x+1;
        qr=nxt;
        op=(cost2[x]-cost2[pre]);
        modcheng(1,1,n);
        pos.insert(x);
        break;
      }
      case 2:{
        int l=read();
        int r=read();
        ql=l;
        qr=r;
        printf("%lld\n",query(1,1,n));
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


