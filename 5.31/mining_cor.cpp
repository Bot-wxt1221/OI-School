#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
std::vector<int>vec[200005];
int tree[1600005];
int sz[1600005];
int tag[1600005];
void pushdown(int now){
  tree[now*2]+=tag[now];
  tree[now*2+1]+=tag[now];
  tag[now*2]+=tag[now];
  tag[now*2+1]+=tag[now];
  tag[now]=0;
  return ;
}
void pushup(int now){
  tree[now]=std::min(tree[now*2],tree[now*2+1]);
  sz[now]=0;
  if(tree[now]==tree[now*2]){
    sz[now]+=sz[now*2];
  }
  if(tree[now]==tree[now*2+1]){
    sz[now]+=sz[now*2+1];
  }
  tag[now]=0;
  return ;
}
void build(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    tree[now]=0;
    sz[now]=1;
    tag[now]=0;
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  pushup(now);
}
int ql,qr,op;
void mod(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(r<ql||qr<l){
    return ;
  }
  if(ql<=l&&r<=qr){
    tree[now]+=op;
    tag[now]+=op;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
int mn,sz2;
void query(int now,int l,int r){
  if(l>r){
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    if(tree[now]<mn){
      mn=tree[now];
      sz2=sz[now];
    }else if(tree[now]==mn){
      sz2+=sz[now];
    }
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
int tx[200005],ty[200005];
int seq[5];
int mx;
int solve(int a,int b,int c,int d){
  seq[1]=a;
  seq[2]=b;
  seq[3]=c;
  seq[4]=d;
  std::sort(seq+1,seq+5);
  for(int i=1;i<=4;i++){
    int cnt=0;
    for(int j=1;j<=4;j++){
      if(seq[j]>a){
        continue;
      }
      if(seq[j]>seq[i]){
        cnt++;
      }
    }
    if(seq[i]>a){
      continue;
    }
    ql=seq[i-1]+1;
    qr=seq[i];
    op=0;
    if(cnt+1==1||cnt+1==3){
      op++;
    }
    if(cnt==1||cnt==3){
      op--;
    }
    std::cerr<<ql<<' '<<qr<<' '<<op<<std::endl;
    mod(1,1,mx);
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  mx=n*m;
  for(int i=0;i<=m+1;i++){
    vec[0].push_back(mx+1);
    vec[n+1].push_back(mx+1);
  }
  for(int i=1;i<=n;i++){
    vec[i].push_back(mx+1);
    for(int j=1;j<=m;j++){
      int tt=read();
      vec[i].push_back(tt);
      tx[tt]=i;
      ty[tt]=j;
    }
    vec[i].push_back(mx+1);
  }
  build(1,1,mx);
  int ans=0;
  for(int i=1;i<=mx;i++){
    int xx=tx[i];
    int yy=ty[i];
    solve(vec[xx][yy],vec[xx-1][yy],vec[xx][yy-1],vec[xx-1][yy-1]);
    solve(vec[xx][yy],vec[xx-1][yy],vec[xx][yy+1],vec[xx-1][yy+1]);
    solve(vec[xx][yy],vec[xx+1][yy],vec[xx][yy-1],vec[xx+1][yy-1]);
    solve(vec[xx][yy],vec[xx+1][yy],vec[xx][yy+1],vec[xx+1][yy+1]);
    mn=0x3f3f3f3f;
    ql=1;
    qr=i;
    query(1,1,mx);
    if(mn==4){
      ans+=sz2;
    }
  }
  printf("%lld",ans);
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

