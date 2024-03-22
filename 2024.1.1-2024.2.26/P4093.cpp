#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
  public:
    int seq,mx,mn,i;
    node(int a=0,int b=0,int c=0,int t=0){
      seq=a;
      mx=b;
      mn=c;
      i=t;
      return ;
    }
}seq[100005];
bool cmp1(node a,node b){
  return a.mx<b.mx;
}
bool cmp2(node a,node b){
  return a.seq<b.seq;
}
bool cmp3(node a,node b){
  return a.i<b.i;
}
int tree[100005];
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
  while(x<=100000){
    tree[x]=std::max(tree[x],y);
    x+=lowbit(x);
  }
  return ;
}
void clear(int x){
  while(x<=100000){
    tree[x]=-0x3f3f3f3f;
    x+=lowbit(x);
  }
  return ;
}
int dp[100005];
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
    if(seq[nl].mx<=seq[nr].seq){
      mod(seq[nl].seq,dp[seq[nl].i]+1);
      nl++;
    }else{
      dp[seq[nr].i]=std::max(dp[seq[nr].i],query(seq[nr].mn));
      nr++;
    }
  }
  while(nl<=mid){
    mod(seq[nl].seq,dp[seq[nl].i]+1);
    nl++;
  }
  while(nr<=r){
    dp[seq[nr].i]=std::max(dp[seq[nr].i],query(seq[nr].mn));
    nr++;
  }
  for(int i=l;i<=mid;i++){
    clear(seq[i].seq);
  }
  std::sort(seq+l,seq+r+1,cmp3);
  cdq(mid+1,r);
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=100000;i++){
    tree[i]=-0x3f3f3f3f;
  }
  for(int i=1;i<=n;i++){
    dp[i]=1;
    seq[i].seq=seq[i].mx=seq[i].mn=read();
    seq[i].i=i;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    seq[x].mx=std::max(seq[x].mx,y);
    seq[x].mn=std::min(seq[x].mn,y);
  }
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


