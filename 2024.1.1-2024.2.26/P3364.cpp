#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
  public:
    int l,s,w,a;
    int i;
    node(int xx=0,int yy=0,int zz=0,int aa=0,int ii=0){
      l=xx;
      s=yy;
      w=zz;
      a=aa;
      i=ii;
      return ;
    }
}seq[100005];
bool cmp1(node a,node b){
  return a.a<b.a;
}
bool cmp2(node a,node b){
  return a.s<b.s;
}
bool cmp3(node a,node b){
  return a.i<b.i;
}
bool cmp4(node a,node b){
  return a.l<b.l;
}
int tree[1000005];
int lowbit(int x){
  return x&(-x);
}
int query(int x){
  int ans=-0x3f3f3f3f;
  while(x>0){
    ans=std::max(ans,tree[x]);
    x-=lowbit(x);
  }
  return ans;
}
void mod(int x,int y){
  while(x<=1000000){
    tree[x]=std::max(tree[x],y);
    x+=lowbit(x);
  }
  return ;
}
void clear(int x){
  while(x<=1000000){
    tree[x]=-0x3f3f3f3f;
    x+=lowbit(x);
  }
  return ;
}
int dp[1000005];
void cdq(int l,int r){
  if(l>=r){
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid);
  std::sort(seq+l,seq+mid+1,cmp1);
  std::sort(seq+mid+1,seq+r+1,cmp2);
  int nl=l,nr=mid+1;
  while(nl<=mid&&nr<=r){
    if(seq[nl].a<=seq[nr].s){
      mod(seq[nl].w,dp[seq[nl].i]);
      nl++;
    }else{
      dp[seq[nr].i]=std::max(dp[seq[nr].i],query(seq[nr].a)+1);
      nr++;
    }
  }
  while(nl<=mid){
    mod(seq[nl].w,dp[seq[nl].i]);
    nl++;
  }
  while(nr<=r){
    dp[seq[nr].i]=std::max(dp[seq[nr].i],query(seq[nr].a)+1);
    nr++;
  }
  for(int i=l;i<=mid;i++){
    clear(seq[i].w);
  }
  std::sort(seq+l,seq+r+1,cmp4);
  cdq(mid+1,r);
  return ;
}
int X[1000005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=0;
  for(int i=1;i<=n;i++){
    dp[i]=1;
    seq[i].l=read();
    X[++m]=seq[i].l;
    seq[i].s=read();
    X[++m]=seq[i].s;
    seq[i].w=read();
    X[++m]=seq[i].w;
    seq[i].a=read();
    X[++m]=seq[i].a;
    seq[i].i=i;
  }
  std::sort(X+1,X+m+1);
  for(int i=1;i<=n;i++){
    seq[i].l=std::lower_bound(X+1,X+m+1,seq[i].l)-X;
    seq[i].s=std::lower_bound(X+1,X+m+1,seq[i].s)-X;
    seq[i].w=std::lower_bound(X+1,X+m+1,seq[i].w)-X;
    seq[i].a=std::lower_bound(X+1,X+m+1,seq[i].a)-X;
  }
  std::sort(seq+1,seq+n+1,cmp4);
  cdq(1,n);
  int ans=-0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    ans=std::max(ans,dp[i]);
  }
  printf("%d",ans);
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


