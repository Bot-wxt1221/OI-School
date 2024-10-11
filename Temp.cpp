#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define int long long
inline int read();
int tree[1000005*4][4];
int ans[1000005*4];
std::multiset<int>se[1000005][4];
void change(int now,int l){
  for(int i=0;i<4;i++){
    tree[now][i]=*se[l][i].begin();
  }
  ans[now]=std::min(tree[now][0]+tree[now][2],tree[now][1]+tree[now][3]);
  return ;
}
void pushup(int now){
  ans[now]=std::min(ans[now*2],ans[now*2+1]);
  
  for(int i=0;i<4;i++){
    tree[now][i]=std::min(tree[now*2][i],tree[now*2+1][i]);
  }

  ans[now]=std::min(ans[now],tree[now*2][2]+tree[now*2+1][0]);
  ans[now]=std::min(ans[now],tree[now*2][1]+tree[now*2+1][3]);
  return ;
}
void build(int now,int l,int r){
  if(l==r){
    change(now,l);
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
int op;
int ttt;
int aa,bb;
int ql;
void mod(int now,int l,int r){
  if(ql<l||r<ql){
    return ;
  }
  if(l==r){
    if(op==1){
      if(ttt==0){
        se[l][0].insert(aa);
        se[l][1].insert(bb);
      }else{
        se[l][2].insert(aa);
        se[l][3].insert(bb);
      }
    }else{
      if(ttt==0){
        se[l][0].erase(se[l][0].find(aa));
        se[l][1].erase(se[l][1].find(bb));
      }else{
        se[l][2].erase(se[l][2].find(aa));
        se[l][3].erase(se[l][3].find(bb));
      }
    }
    change(now,l);
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  pushup(now);
}
int opt[1000005];
int d[1000005];
int a[1000005];
int b[1000005];
int tt[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int Q=read();
  int cnt=0;
  for(int i=1;i<=Q;i++){
    opt[i]=read();
    d[i]=read();
    a[i]=read();
    b[i]=read();
    tt[++cnt]=(!d[i])?a[i]-b[i]:b[i]-a[i];
  }
  std::sort(tt+1,tt+cnt+1);
  cnt=std::unique(tt+1,tt+cnt+1)-tt-1;
  for(int i=1;i<=cnt;i++){
    for(int j=0;j<4;j++){
      se[i][j].insert(0x3f3f3f3f3f3f3f3f);
    }
  }
  build(1,1,cnt);
  for(int i=1;i<=Q;i++){
    ql=std::lower_bound(tt+1,tt+cnt+1,(!d[i])?a[i]-b[i]:b[i]-a[i])-tt;
    aa=a[i];
    bb=b[i];
    op=opt[i];
    ttt=d[i];
    mod(1,1,cnt);
    printf("%lld\n",ans[1]>=0x3f3f3f3f3f3f3f3f?-1:ans[1]);
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
