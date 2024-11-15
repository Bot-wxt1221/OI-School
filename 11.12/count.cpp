#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int a[500005];
int siz[500005*8];
class node{
public:
  int x1,n1,x2,n2;
  node(int a=0,int b=0,int c=0,int d=0){
    x1=a;
    n1=b;
    x2=c;
    n2=d;
    return ;
  }
}tree[500005*8];
node merge(node a,node b){
  int x3=0,n3=0,x4=0,n4=0;
  if(b.x1==a.x1){
    a.n1+=b.n1;
  }else if(b.x1==a.x2){
    a.n2+=b.n1;
  }else{
    x3=b.x1;
    n3=b.n1;
  }
  if(b.x2==a.x1){
    a.n1+=b.n2;
  }else if(b.x2==a.x2){
    a.n2+=b.n2;
  }else{
    x4=b.x2;
    n4=b.n2;
  }
  std::vector<std::pair<int,int> > tt={{a.n1,a.x1},{a.n2,a.x2},{n3,x3},{n4,x4}};
  std::sort(tt.begin(),tt.end());
  int ttt=std::min(tt[0].first,std::min(tt[1].first,tt[2].first));
  tt[0].first-=ttt;
  tt[1].first-=ttt;
  tt[2].first-=ttt;
  ttt=std::min(tt[1].first,std::min(tt[2].first,tt[3].first));
  tt[1].first-=ttt;
  tt[2].first-=ttt;
  tt[3].first-=ttt;
  return node(tt[3].second,tt[3].first,tt[2].second,tt[2].first);
}
int lazy[500005*8];//plus
int lazy2[500005*8];//cover
void init(int now,int l,int r){
  lazy2[now]=-0x3f3f3f3f;
  lazy[now]=0;
  siz[now]=r-l+1;
  if(l==r){
    tree[now]=node{a[l],1,0,0};
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  tree[now]=merge(tree[now*2],tree[now*2+1]);
  return ;
}
int ql,qr;
int op;
void pushdown(int now){
  if(lazy2[now]!=-0x3f3f3f3f){
    lazy2[now*2]=lazy2[now];
    lazy2[now*2+1]=lazy2[now];
    lazy[now*2]=0;
    lazy[now*2+1]=0;
    tree[now*2]=node(lazy2[now],siz[now*2],0,0);
    tree[now*2+1]=node(lazy2[now],siz[now*2+1],0,0);
    lazy2[now]=-0x3f3f3f3f;
  }
  lazy[now*2]+=lazy[now];
  lazy[now*2+1]+=lazy[now];
  tree[now*2].x1+=lazy[now];
  tree[now*2].x2+=lazy[now];
  tree[now*2+1].x1+=lazy[now];
  tree[now*2+1].x2+=lazy[now];
  lazy[now]=0;
  return ;
}
void cover(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now]=node(op,siz[now],0,0);
    lazy2[now]=op;
    lazy[now]=0;
    return ;
  }
  int mid=(l+r)/2;
  pushdown(now);
  cover(now*2,l,mid);
  cover(now*2+1,mid+1,r);
  tree[now]=merge(tree[now*2],tree[now*2+1]);
}
void add(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now].x1+=op;
    tree[now].x2+=op;
    lazy[now]+=op;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  add(now*2,l,mid);
  add(now*2+1,mid+1,r);
  tree[now]=merge(tree[now*2],tree[now*2+1]);
}
node ans;
void query(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    ans=merge(ans,tree[now]);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  int tt=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(a[i]==1){
      tt++;
    }
  }
  init(1,1,n);
  for(int i=1;i<=m;i++){
    int op=read();
    int l=read();
    int r=read();
    switch(op){
      case 1:{
        int c=read();
        ql=l;
        qr=r;
        ::op=c;
        add(1,1,n);
        break;
      }
      case 2:{
        int c=read();
        ql=l;
        qr=r;
        ::op=c;
        cover(1,1,n);
        break;
      }
      case 3:{
        ans=node(0,0,0,0);
        ql=l;
        qr=r;
        query(1,1,n);
        printf("%d %d\n",ans.x1,ans.x2);
      }
    }
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
