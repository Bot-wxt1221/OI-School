#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
inline int read();
inline void write(long long ans);
std::unordered_map<int,long long>ans;
int lcm(int x,int y){
  if(x>1e9||y>1e9){
    return 1e9+1;
  }
  return std::min(1ll*x*y/std::__gcd(x,y),(long long)(1e9+1));
}
class ps{
  public:
    long long pos,data;
    ps(long long x,long long y){
      pos=x;
      data=y;
      return ;
    }
};
class node{
public:
  std::vector<ps>vec;
};
const node operator + (const node& a,const node& b){
  if(a.vec.size()==0){
    return b;
  }
  if(b.vec.size()==0){
    return a;
  }
  node tt=a;
  ps lst=a.vec[a.vec.size()-1];
  for(int i=0;i<b.vec.size();i++){
    long long nans=lcm(b.vec[i].data,lst.data);
      if(tt.vec[tt.vec.size()-1].data==nans){
        tt.vec[tt.vec.size()-1].pos+=b.vec[i].pos;
      }else{
        tt.vec.push_back(ps(b.vec[i].pos,nans));
      }
  }
  return tt;
}
class que{
public:
  node pre,suf;
  que(node a,node b){
    pre=a;
    suf=b;
    return ;
  }
  que(){
    return ;
  }
};
inline const que operator + (const que& a,const que& b){
  return que(a.pre+b.pre,b.suf+a.suf);
}
node tree_pre[1000005];
node tree_suf[1000005];
int a[1000005];
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree_pre[now]=node();
    tree_pre[now].vec.push_back(ps(1,a[l]));
    tree_suf[now]=tree_pre[now];
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree_pre[now]=tree_pre[now*2]+tree_pre[now*2+1];
  tree_suf[now]=tree_suf[now*2+1]+tree_suf[now*2];
  return ;
}
int ql,qr;
node anss;
void querypre(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    anss=anss+tree_pre[now];
    return ;
  }
  int mid=(l+r)/2;
  querypre(now*2,l,mid);
  querypre(now*2+1,mid+1,r);
  return ;
}
void querysuf(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    anss=tree_suf[now]+anss;
    return ;
  }
  int mid=(l+r)/2;
  querysuf(now*2,l,mid);
  querysuf(now*2+1,mid+1,r);
  return ;
}
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  if(l==r){
    tree_pre[now]=node();
    tree_pre[now].vec.push_back(ps(1,a[l]));
    tree_suf[now]=tree_pre[now]; 
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  tree_pre[now]=tree_pre[now*2]+tree_pre[now*2+1];
  tree_suf[now]=tree_suf[now*2+1]+tree_suf[now*2];
  return ;
}
void solve(int n,int x,int d){
  ql=1;
  qr=x;
  anss=node();
  querysuf(1,1,n);
  node suf=anss;
  ql=x;
  qr=n;
  anss=node();
  querypre(1,1,n);
  node pre=anss;
  for(int i=0;i<suf.vec.size();i++){
    for(int j=0;j<pre.vec.size();j++){
      suf.vec[i].data=lcm(suf.vec[i].data,pre.vec[j].data);
      ans[suf.vec[i].data]+=1ll*suf.vec[i].pos*pre.vec[j].pos*d;
    }
  }
  return ;
}
void init(int n,int x){
  ql=x;
  qr=n;
  anss=node();
  querypre(1,1,n);
  node &ret=anss;
  for(int j=0;j<ret.vec.size();j++){
    ans[ret.vec[j].data]+=ret.vec[j].pos;
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("1.in","r",stdin);
  freopen("cu.out","w",stdout);
  #endif
  int T=read();
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  build(1,1,n);
  for(int i=1;i<=n;i++){
    init(n,i);
  }
  for(int i=1;i<=m;i++){
    int op=read();
    if(op==1){
      int x=read();
      solve(n,x,-1);
      a[x]=read();
      ql=qr=x;
      mod(1,1,n);
      solve(n,x,1);
    }else{
      write(ans[read()]);
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
inline void write(long long ans){
	if(ans==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	static char out[65];
	long long n=0;
	while(ans){
		out[++n]=ans%10+'0';
		ans/=10;
	}
	for(int i=n;i>=1;i--){
		putchar(out[i]);
	}
	putchar('\n');
	return ;
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

