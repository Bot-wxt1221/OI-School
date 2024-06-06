#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define int long long
inline int read();
int l[200005],r[200005];
int siz[200005];
class node{
  public:
    int val,i;
    node(int aa=0,int bb=0){
      val=aa;
      i=bb;
      return ;
    }
}ans[200005];
bool operator < (node a,node b){
  return a.val<b.val;
}
bool operator == (node a,node b){
  return a.val==b.val;
}
bool operator <= (node a,node b){
  return a.val<=b.val;
}
int st[200005];
int tt[200005];
long long out[200005];
class node2{
  public:
    int l,r;
    mutable int v;
    node2(int ll,int rr,int vv){
      l=ll;
      r=rr;
      v=vv;
      return ;
    }
};
std::set<node2>odt;
bool operator < (node2 a,node2 b){
  return a.l<b.l;
}
int n,p;
int times;
auto split(int x){
  if(x>n+1){
    return --odt.end();
  }
  auto it=--odt.upper_bound(node2(x,0,0));
  if(it->l==x){
    return it;
  }
  int l=it->l;
  int r=it->r;
  int v=it->v;
  odt.erase(it);
  odt.insert(node2(l,x-1,v));
  return odt.insert(node2(x,r,v)).first;
}
auto assign(int l,int r,int v){
  auto itr=split(r+1),itl=split(l);
  auto itll=itl;
  while(itl!=itr){
    if(itl->v!=0){
      int tp=std::lower_bound(ans+1,ans+p+1,node(st[v]-st[itl->v],0))-ans-1;
      out[tp]+=(itl->r-itl->l+1);
    }
    itl++;
  }
  itl=itll;
  odt.erase(itl,itr);
  odt.insert(node2(l,r,v));
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("make.in","r",stdin);
  freopen("make.out","w",stdout);
  #endif
  n=read();
  int m;
  odt.insert(node2(1,n+1,0));
  m=read();
  p=read();
  int cur=0;
  for(int i=1;i<=m;i++){
    l[i]=read();
    r[i]=read();
    st[i]=cur-l[i];
    cur+=r[i]-l[i]+1;
  }
  for(int i=1;i<=p;i++){
    ans[i]=node(read(),i);
  }
  std::sort(ans+1,ans+p+1);
  for(int i=1;i<=m;i++){
    assign(l[i],r[i],i);
  }
  for(int i=p;i>=1;i--){
    out[i]+=out[i+1];
    tt[ans[i].i]=i;
  }
  for(int i=1;i<=p;i++){
    printf("%lld ",out[tt[i]]);
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

