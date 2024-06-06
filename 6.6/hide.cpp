#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int tree[2000005];
int lazy[2000005];
int tl[2000005];
int tr[2000005];
void pushdown(int now){
  if(lazy[now]==-1){
    return ;
  }
  tree[now*2]=tr[now*2]-tl[now*2]+1;
  tree[now*2]*=lazy[now];

  tree[now*2+1]=tr[now*2+1]-tl[now*2+1]+1;
  tree[now*2+1]*=lazy[now];

  lazy[now*2]=lazy[now*2+1]=lazy[now];
  lazy[now]=-1;
  return ;
}
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree[now]=0;
    lazy[now]=-1;
    tl[now]=l;
    tr[now]=r;
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=0;
  lazy[now]=-1;
  tl[now]=l;
  tr[now]=r;
  return ;
}
int ql,qr,op;
void add(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    lazy[now]=op;
    tree[now]=(r-l+1)*op;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  add(now*2,l,mid);
  add(now*2+1,mid+1,r);
  tree[now]=(tree[now*2]+tree[now*2+1]);
  return ;
}
int l[500005],r[500005];
int u[500005],v[500005];
bool ans[500005];
std::vector<std::pair<int,int> >vec;
std::vector<std::pair<int,int> >vec2;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("hide.in","r",stdin);
  freopen("hide.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int q=read();
  for(int i=1;i<=m;i++){
    l[i]=read();
    r[i]=read();
    vec2.push_back(std::make_pair(r[i],l[i]));
  }
  bool yes=1;
  for(int i=1;i<=q;i++){
    u[i]=read();
    if(u[i]!=1){
      yes=0;
    }
    v[i]=read();
  }
  if(yes){
    build(1,1,n);
    for(int i=1;i<=q;i++){
      vec.push_back(std::make_pair(v[i],i));
    }
    std::sort(vec.begin(),vec.end());
    std::sort(vec2.begin(),vec2.end());
    int cnt=0;
    for(int i=1;i<=q;i++){
      while(cnt<vec2.size()&&vec2[cnt].first<=vec[i-1].first){
        ql=vec2[cnt].second;
        qr=vec2[cnt].first;
        op=1;
        add(1,1,n);
        cnt++;
      }
      if(tree[1]==vec[i-1].first){
        ans[vec[i-1].second]=1;
      }
    }
    for(int i=1;i<=q;i++){
      if(ans[i]){
        printf("YES\n");
      }else{
        printf("NO\n");
      }
    }
    return 0;
  }
  for(int i=1;i<=q;i++){
    build(1,1,n);
    for(int j=1;j<=m;j++){
      if(u[i]<=l[j]&&r[j]<=v[i]){
        ql=l[j];
        qr=r[j];
        op=1;
        add(1,1,n);
      }
    }
    if(v[i]-u[i]+1==tree[1]){
      printf("YES\n");
    }else{
      printf("NO\n");
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

