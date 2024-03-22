#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
inline int read();
int ans[100005];
int pre[100005];
std::vector<int>vec;
namespace CDQ{
int tree[200005];
int lowbit(int a){
    return a&-a;
}
void add(int a,int i){
    while(a<=200000){
        tree[a]+=i;
        a+=lowbit(a);
    }
    return ;
}
int query(int a){
    int ans=0;
    while(a>0){
        ans+=tree[a];
        a-=lowbit(a);
    }
    return ans;
}
int ans[1000005];
class node{
public:
  int a,b,c,cnt;
  int i;
  node(int aa=0,int bb=0,int cc=0,int dd=0,int ii=0){
    a=aa;
    b=bb;
    c=cc;
    cnt=dd;
    i=ii;
    return ;
  }
}a[1000005],tem[1000005];
const bool operator < (const node &a,const node &b){
  if(a.a!=b.a){
    return a.a<b.a;
  }
  if(a.b!=b.b){
    return a.b<b.b;
  }
  return a.c<b.c;
}
int n;
int add(int x,int y,int z,int l){
  a[++n]=node(x,y,z,l);
  return n;
}
void cdq(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)/2;
    cdq(l,mid);
    cdq(mid+1,r);
    int ii1=l,ii2=mid+1;
    int da=l-1;
    while(ii1<=mid&&ii2<=r){
        if(a[ii1].b<=a[ii2].b){
            add(a[ii1].c,a[ii1].cnt);
            tem[++da]=a[ii1];
            ii1++;
        }else{
            ans[a[ii2].i]+=query(a[ii2].c);
            tem[++da]=a[ii2];
            ii2++;
        }
    }
    while(ii1<=mid){
        add(a[ii1].c,a[ii1].cnt);
        tem[++da]=a[ii1];
        ii1++;
    }
    while(ii2<=r){
        ans[a[ii2].i]+=query(a[ii2].c);
        tem[++da]=a[ii2];
        ii2++;
    }
    for(int i=l;i<=mid;i++){
        add(a[i].c,-a[i].cnt);
    }
    for(int i=l;i<=r;i++){
        a[i]=tem[i];
    }
    return ;

}
};
int a[100005];
class node{
  public:
    int l,r;
    mutable int v;
    node(int ll,int rr,int vv){
      l=ll;
      r=rr;
      v=vv;
      return ;
    }
};
std::set<node>odt,col[200005];
bool operator < (node a,node b){
  return a.l<b.l;
}
int n;
int times;
auto split(int x){
  if(x>n){
    return --odt.end();
  }
  auto it=--odt.upper_bound(node(x,0,0));
  if(it->l==x){
    return it;
  }
  int l=it->l;
  int r=it->r;
  int v=it->v;
  odt.erase(it);
  odt.insert(node(l,x-1,v));
  return odt.insert(node(x,r,v)).first;
}
int Pre(int i){
  auto it=--odt.lower_bound(node{i,0,0});
  if(it->l<i){
    return i-1;
  }else{
    auto it2=
  }
}
auto assign(int l,int r,int v){
  auto itr=split(r+1),itl=split(l);
  auto itrr=itr;
  while(itrr!=itl){
    itrr--;
    auto tt=col[itrr->r].lower_bound(node(itrr->l,0,0));
    col[itrr->r].erase(tt);
  }
  odt.erase(itl,itr);
  odt.insert(node(l,r,v));
  return ;
}
std::map<int,int>pree;
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
  #endif
  n=read();
  int m=read();
  odt.insert(node(1,n,0));
  for(int i=1;i<=n;i++){
    a[i]=read();
    pre[i]=pree[a[i]];
    pree[a[i]]=i;
    CDQ::add(i,pre[i],-1,1);
    assign(i,i,a[i]);
  }
  for(int i=1;i<=m;i++){
    times=i;
    int op=read();
    int l=read();
    int r=read();
    if(op==1){
      int x=read();
      assign(l,r,x);
    }else{
      vec.push_back(CDQ::add(r,l,i,0));
    }
  }
  CDQ::cdq(1,CDQ::n);
  for(int i=0;i<vec.size();i++){
    printf("%d\n",CDQ::ans[vec[i]]);
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


