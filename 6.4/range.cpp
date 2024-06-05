#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define mod 998244353
#define int long long
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (tt*tt)%mod;
  }
  return (pow(x,y-1)*x)%mod;
}

int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      ans%=mod;
      now-=lowbit(now);
    }
    return ans;
  }
  void add(int x,int y){
    while(x<=1000002){
      tree[x]+=y;
      tree[x]%=mod;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    while(x<=1000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa;

int l[5005],r[5005];
int quan[1000005];
int tree[8000005];
int lazy[8000005];
int tl[8000005];
int tr[8000005];
int seq1[1000005];
int fir[8000005];
int lst[8000005];
int duan[8000005];
void pushdown(int now){
  if(lazy[now]==-1){
    return ;
  }
  fir[now*2]=fir[now*2+1]=lst[now*2]=lst[now*2+1]=lazy[now];
  duan[now*2]=duan[now*2+1]=1;
  tree[now*2]=quan[tr[now*2]]-quan[tl[now*2]-1];
  tree[now*2]%=mod;
  tree[now*2]*=lazy[now];
  tree[now*2]%=mod;

  tree[now*2+1]=quan[tr[now*2+1]]-quan[tl[now*2+1]-1];
  tree[now*2+1]%=mod;
  tree[now*2+1]*=lazy[now];
  tree[now*2+1]%=mod;

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
    fir[now]=lst[now]=0;
    duan[now]=0;
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  tree[now]=0;
  lazy[now]=-1;
  tl[now]=l;
  tr[now]=r;
  duan[now]=0;
  fir[now]=lst[now]=0;
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
    tree[now]=(quan[r]-quan[l-1])*op%mod;
    fir[now]=lst[now]=op;
    duan[now]=1;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  add(now*2,l,mid);
  add(now*2+1,mid+1,r);
  fir[now]=fir[now*2];
  lst[now]=lst[now*2+1];
  duan[now]=duan[now*2]+duan[now*2+1];
  if(lst[now*2]==1&&fir[now*2+1]==1){
    duan[now]--;
  }
  tree[now]=(tree[now*2]+tree[now*2+1])%mod;
  return ;
}
int out[5005][5005];
std::vector<std::pair<int,std::pair<int,int> > >Q;
int rans[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("range.in","r",stdin);
  freopen("range.out","w",stdout);
  #endif
  int n=read();
  int q=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    l[i]=read();
    r[i]=read();
    seq1[++cnt]=l[i];
    seq1[++cnt]=r[i]+1;
  }
  std::sort(seq1+1,seq1+cnt+1);
  cnt=std::unique(seq1+1,seq1+cnt+1)-seq1-1;
  for(int i=1;i<=cnt;i++){
    quan[i]=seq1[i+1]-seq1[i];
    quan[i]+=quan[i-1];
    quan[i]%=mod;
  }
  build(1,1,cnt);
  for(int i=1;i<=n;i++){
    l[i]=std::lower_bound(seq1+1,seq1+1+cnt,l[i])-seq1;
    r[i]=std::lower_bound(seq1+1,seq1+1+cnt,r[i]+1)-seq1-1;
  }
  for(int i=1;i<=n;i++){
    build(1,1,cnt);
    for(int j=i;j>=1;j--){
      ql=l[j];
      qr=r[j];
      op=1;
      add(1,1,cnt);
      out[j][i]=tree[1]-duan[1];
    }
  }
  for(int i=1;i<=q;i++){
    int ql=read();
    int qr=read();
    Q.push_back(std::make_pair(ql,std::make_pair(qr,i)));
  }
  std::sort(Q.begin(),Q.end());
  int cur=n;
  for(int i=Q.size()-1;i>=0;i--){
    int ql=Q[i].first;
    int qr=Q[i].second.first;
    int tt=Q[i].second.second;
    while(cur>=ql){
      for(int j=1;j<=n;j++){
        aa.add(j,out[cur][j]);
      }
      cur--;
    }
    rans[tt]=(aa.query(qr))*pow((((qr-ql+1)*(qr-ql+2)/2))%mod,mod-2)%mod;
  }
  for(int i=1;i<=q;i++){
    printf("%lld\n",(rans[i]+mod)%mod);
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

