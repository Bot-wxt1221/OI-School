#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
inline int read();
int a[2000005];
int tree[8000005];
int lazy[8000005];
int lst[2000005];
int ans[2000005];
int ql,qr,op;
int fa[2000005];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
std::vector<std::pair<int,int> >vec[2000005];
void pushdown(int now,int l,int r){
  int mid=(l+r)/2;
  if(lazy[now]!=-1){
    lazy[now*2]=lazy[now*2+1]=lazy[now];
    tree[now*2]=lazy[now]-mid;
    tree[now*2+1]=lazy[now]-r;
  }
  lazy[now]=-1;
  return ;
}
void cover(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now]=op-r;
    lazy[now]=op;
    return ;
  }
  pushdown(now,l,r);
  int mid=(l+r)/2;
  cover(now*2,l,mid);
  cover(now*2+1,mid+1,r);
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  return ;
}
void query(int now,int l,int r){
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    op=std::min(op,tree[now]);
    return ;
  }
  pushdown(now,l,r);
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
  memset(lazy,-1,sizeof(lazy));
  for(int i=1;i<=n;i++){
    fa[i]=i;
    a[i]=read();
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int l=read();
    int r=read();
    vec[r].push_back({l,i});
  }
  for(int i=1;i<=n;i++){
    ql=lst[a[i]]+1;
    qr=i;
    op=i;
    fa[getfa(lst[a[i]])]=getfa(lst[a[i]]+1);
    lst[a[i]]=i;
    cover(1,1,n);
    for(int j=0;j<vec[i].size();j++){
      ql=vec[i][j].first;
      qr=getfa(vec[i][j].first);
      op=0x3f3f3f3f;
      query(1,1,n);
      ans[vec[i][j].second]=op+1;
    }
  }
  for(int i=1;i<=q;i++){
    printf("%d\n",ans[i]);
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
