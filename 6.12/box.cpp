#include <iostream>
#include <cstdio>
#include <set>
#define int __int128
inline int read();
int a[1000005];
int c[1000005];
int w[1000005];
bool type[1000005];
bool type2[1000005];
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[2000005];
  int query(int now){
    now+=500000;
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    x+=500000;
    while(x<=2000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    x+=500000;
    while(x<=2000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa,bb;
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
int n;
void mod(int x,int t2ype){
  aa.mod(x,w[x]*t2ype*std::max(a[x]-a[x-1]*type[x],(__int128)0));
  bb.mod(x,w[x]*t2ype*std::max(a[x]-a[x+1]*type2[x],(__int128)0));
  aa.mod(x+1,w[x+1]*t2ype*std::max(a[x+1]-a[x]*type[x+1],(__int128)0));
  bb.mod(x-1,w[x-1]*t2ype*std::max(a[x-1]-a[x]*type2[x-1],(__int128)0));
  return ;
}
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
  mod(x-1,-1);
  type2[x-1]=0;
  mod(x-1,1);

  mod(x,-1);
  type[x]=0;
  mod(x,1);
  return odt.insert(node2(x,r,v)).first;
}
auto assign(int l,int r,int v){
  auto itr=split(r+1),itl=split(l);
  auto itll=itl;
  while(itl!=itr){
    mod(itl->l,-1);
    type[itl->l]=1;
    mod(itl->l,1);
    mod(itl->r,-1);
    type2[itl->r]=1;
    mod(itl->r,1);
    itl++;
  }
  itl=itll;
  odt.erase(itl,itr);
  mod(l,-1);
  type[l]=0;
  mod(l,1);
  mod(r,-1);
  type2[r]=0;
  mod(r,1);
  auto tt=odt.insert(node2(l,r,v)).first;
  auto pre=--tt;
  tt++;
  if(tt!=odt.begin()&&pre->v==tt->v){
    mod(tt->l,-1);
    type[tt->l]=1;
    mod(tt->l,1);
    mod(pre->r,-1);
    type2[pre->r]=1;
    mod(pre->r,1);
    node2 temp=*tt;
    node2 temp2=*pre;
    odt.erase(tt);
    odt.erase(pre);
    tt=odt.insert(node2(temp2.l,temp.r,v)).first;
  }
  auto nxt=++tt;
  tt--;
  if(nxt->v==tt->v){
    mod(nxt->l,-1);
    type[nxt->l]=1;
    mod(nxt->l,1);
    mod(tt->r,-1);
    type2[tt->r]=1;
    mod(tt->r,1);
    node2 temp=*tt;
    node2 temp2=*nxt;
    odt.erase(tt);
    odt.erase(nxt);
    tt=odt.insert(node2(temp.l,temp2.r,temp.v)).first;
  }
  return ;
}
void merge(std::set<node2>::iterator tt){
  if(tt!=odt.begin()){
    auto pre=--tt;
    tt++;
    if(tt!=odt.begin()&&pre->v==tt->v){
      mod(tt->l,-1);
      type[tt->l]=1;
      mod(tt->l,1);
      mod(pre->r,-1);
      type2[pre->r]=1;
      mod(pre->r,1);
      node2 temp=*tt;
      node2 temp2=*pre;
      odt.erase(tt);
      odt.erase(pre);
      tt=odt.insert(node2(temp2.l,temp.r,temp.v)).first;
    }
  }
  auto nxt=++tt;
  if(nxt==odt.end()){
    return ;
  }
  tt--;
  if(nxt->v==tt->v){
    mod(nxt->l,-1);
    type[nxt->l]=1;
    mod(nxt->l,1);
    mod(tt->r,-1);
    type2[tt->r]=1;
    mod(tt->r,1);
    node2 temp=*tt;
    node2 temp2=*nxt;
    odt.erase(tt);
    odt.erase(nxt);
    tt=odt.insert(node2(temp.l,temp2.r,temp.v)).first;
  }
  return ;
}
int ans(int l,int r){
  int ret=0;
  auto itr=split(r+1),itl=split(l);
  ret+=aa.query(r)-aa.query(l-1);
  ret+=bb.query(r)-bb.query(l-1);
  merge(itl);
  merge(itr);
  return ret;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("box.in","r",stdin);
  freopen("box.out","w",stdout);
  #endif
  n=read();
  int q=read();
  odt.insert(node2(1,n+1,-1));
  for(int i=1;i<=n;i++){
    a[i]=read();
    c[i]=read();
    w[i]=read();
  }
  for(int i=1;i<=n;i++){
    aa.mod(i,std::max((a[i]-a[i-1]*type[i]),(__int128)0)*w[i]);
    bb.mod(i,std::max((a[i]-a[i+1]*type2[i]),(__int128)0)*w[i]);
    assign(i,i,c[i]);
  }
  for(int i=1;i<=q;i++){
    int op=read();
    switch(op){
      case 1:{
        int x=read();
        int v1=read();
        int v2=read();
        mod(x,-1);
        a[x]=v1;
        w[x]=v2;
        mod(x,1);
        break;
      }
      case 2:{
        int l=read();
        int r=read();
        int v=read();
        assign(l,r,v);
        break;
      }
      case 3:{
        int l=read();
        int r=read();
        write(ans(l,r));
        putchar('\n');
        break;
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

