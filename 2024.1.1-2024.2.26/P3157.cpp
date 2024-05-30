#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int pos[200005];
int tree[200005];
int lowbit(int x){
  return x&(-x);
}
void mod(int x,int y){
  while(x<=200000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
int query(int x){
  int ans=0;
  while(x>0){
    ans+=tree[x];
    x-=lowbit(x);
  }
  return ans;
}
class node{
  public:
    int tim,a,opp,pos;
    node(int x=0,int y=0,int z=0,int aa=0){
      tim=x;
      a=y;
      opp=z;
      pos=aa;
    }
}seq[200005],temp[200005];
int ans[200005];
void cdq(int l,int r){
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  cdq(l,mid);
  cdq(mid+1,r);
  int nl=l;
  int nr=mid+1;
  int nw=l;
  while(nl<=mid&&nr<=r){
    if(seq[nl].pos<=seq[nr].pos){
      temp[nw++]=seq[nl];
      mod(seq[nl].a,seq[nl].opp);
      nl++;
    }else{
      temp[nw++]=seq[nr];
      ans[seq[nr].tim]+=seq[nr].opp*(query(200000)-query(seq[nr].a));
      nr++;
    }
  }
  while(nl<=mid){
    temp[nw++]=seq[nl];
    mod(seq[nl].a,seq[nl].opp);
    nl++;
  }
  while(nr<=r){
    temp[nw++]=seq[nr];
    ans[seq[nr].tim]+=seq[nr].opp*(query(200000)-query(seq[nr].a));
    nr++;
  }
  for(int i=l;i<=mid;i++){
    mod(seq[i].a,-seq[i].opp);
  }
  nl=mid;
  nr=r;
  while(nl>=l&&nr>=mid+1){
    if(seq[nl].pos>=seq[nr].pos){
      mod(seq[nl].a,seq[nl].opp);
      nl--;
    }else{
      ans[seq[nr].tim]+=seq[nr].opp*(query(seq[nr].a-1));
      nr--;
    }
  }
  while(nl>=l){
    mod(seq[nl].a,seq[nl].opp);
    nl--;
  }
  while(nr>=mid+1){
    ans[seq[nr].tim]+=seq[nr].opp*(query(seq[nr].a-1));
    nr--;
  }
  for(int i=l;i<=mid;i++){
    mod(seq[i].a,-seq[i].opp);
  }
  for(int i=l;i<=r;i++){
    seq[i]=temp[i];
  }
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    seq[i].a=read();
    seq[i].tim=0;
    seq[i].opp=1;
    seq[i].pos=i;
    pos[seq[i].a]=i;
  }
  for(int i=1;i<=m;i++){
    int m=read();
    seq[i+n].a=m;
    seq[i+n].tim=i;
    seq[i+n].opp=-1;
    seq[i+n].pos=pos[m];
  }
  cdq(1,n+m);
  for(int i=1;i<=m;i++){
    ans[i]+=ans[i-1];
  }
  for(int i=0;i<m;i++){
    printf("%lld\n",ans[i]);
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


