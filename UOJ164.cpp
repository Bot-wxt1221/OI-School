#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[500005];
class node{
public:
  int ad,mx;
  node(int a=0,int b=-0x3f3f3f3f3f3f3f3f){
    a=std::max(a,-0x3f3f3f3f3f3f3f3fll);
    b=std::max(b,-0x3f3f3f3f3f3f3f3fll);
    ad=a;
    mx=b;
    return ;
  }
}tree[500005*4],mxtree[500005*4],op;
int ql,qr;
node merge(node a,node b){
  return node(a.ad+b.ad,std::max(a.mx+b.ad,b.mx));
}
node mkmax(node a,node b){
  if(a.mx<b.mx){
    std::swap(a,b);
  }
  if(a.mx-a.ad+b.ad<=a.mx){
    return a;
  }else{
    int y=a.mx;
    int x=a.mx-b.ad;
    return node(y-x,y);
  }
}
void pushdown(int now){
  mxtree[now*2]=mkmax(mxtree[now*2],merge(tree[now*2],mxtree[now]));
  tree[now*2]=merge(tree[now*2],tree[now]);
  mxtree[now*2+1]=mkmax(mxtree[now*2+1],merge(tree[now*2+1],mxtree[now]));
  tree[now*2+1]=merge(tree[now*2+1],tree[now]);
  tree[now]=node();
  mxtree[now]=node();
  return ;
}
void mod(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now]=merge(tree[now],op);
    mxtree[now]=mkmax(mxtree[now],tree[now]);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  return ;
}
int ans=0;
void query(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(l==r){
    ans=std::max(tree[now].ad+a[l],tree[now].mx);
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
void query2(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(l==r){
    ans=std::max(ans,std::max(mxtree[now].ad+a[ql],mxtree[now].mx));
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query2(now*2,l,mid);
  query2(now*2+1,mid+1,r);
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=m;i++){
    int opp=read();
    switch(opp){
      case 1:{
        ql=read();
        qr=read();
        int x=read();
        op=node(x);
        mod(1,1,n);
        break;
      }
      case 2:{
        ql=read();
        qr=read();
        int x=read();
        op=node(-x,0);
        mod(1,1,n);
        break;
      }
      case 3:{
        ql=read();
        qr=read();
        int x=read();
        op=node(-0x3f3f3f3f3f3f3f3f,x);
        mod(1,1,n);
        break;
      }
      case 4:{
        ql=qr=read();
        ans=0;
        query(1,1,n);
        printf("%lld\n",ans);
        break;
      }
      case 5:{
        ql=qr=read();
        ans=0;
        query2(1,1,n);
        printf("%lld\n",ans);
        break;
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
