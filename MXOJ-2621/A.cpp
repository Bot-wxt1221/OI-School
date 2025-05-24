#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int a[200005];
int b[200005];
int p[200005];
int num[200005];
std::deque<int>qu[200005];
int mn[100005*16];
int cnt[100005*16];
int lazy[100005*16];
int lazyadd[100005*16];
int op;
int ql,qr;
void pushdown(int now,int l,int r){
  if(lazy[now]==-1){
  }else{
    int mid=(l+r)/2;
    mn[now*2]=lazy[now];
    mn[now*2+1]=lazy[now];
    cnt[now*2]=mid-l+1;
    cnt[now*2+1]=r-(mid);
    lazy[now]=-1;
  }

  lazyadd[now*2]+=lazyadd[now];
  lazyadd[now*2+1]+=lazyadd[now];
  mn[now*2]+=lazyadd[now];
  mn[now*2+1]+=lazyadd[now];
  lazyadd[now]=0;
  return ;
}
void pushup(int now){
  mn[now]=std::max(mn[now*2],mn[now*2+1]);
  cnt[now]=0;
  if(mn[now]==mn[now*2]){
    cnt[now]+=cnt[now*2];
  }
  if(mn[now]==mn[now*2+1]){
    cnt[now]+=cnt[now*2+1];
  }
  return ;
}
void mod(int now,int l,int r){
  pushdown(now,l,r);
  if(ql<=l&&r<=qr){
    lazy[now]=op;
    mn[now]=op;
    cnt[now]=r-l+1;
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  int mid=(l+r)/2;
  mod(now*2,l,mid);
  mod(now*2+1,mid+1,r);
  pushup(now);
}
void add(int now,int l,int r){
  pushdown(now,l,r);
  if(ql<=l&&r<=qr){
    lazyadd[now]+=op;
    mn[now]+=op;
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  int mid=(l+r)/2;
  add(now*2,l,mid);
  add(now*2+1,mid+1,r);
  pushup(now);
  return ;
}
int mnn,cntt;
void query(int now,int l,int r){
  pushdown(now,l,r);
  if(ql<=l&&r<=qr){
    if(mn[now]>mnn){
      mnn=mn[now];
      cntt=cnt[now];
    }else if(mn[now]==mnn){
      cntt+=cnt[now];
    }
    return ;
  }
  if(qr<l||r<ql){
    return ;
  }
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
int n;
int r;
void process(int i,int opp){
  ql=qu[i].back()+1;
  qr=r;
  op=opp;
  if(ql<=qr){
    add(1,1,n*2);
  }
  if(a[i]<=b[i]){
    int ll=qu[i].size()-a[i];
    int rr=qu[i].size()-b[i]-1;
    ll=std::max(ll,0ll);
    rr=std::max(rr,0ll);
    ql=qu[i][rr]+1;
    qr=qu[i][ll];
    if(ql<=qr){
      add(1,1,n*2);
    }
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	#endif
  n=read();
  int c=read();
  for(int i=1;i<=c;i++){
    a[i]=read();
    b[i]=read();
    a[i]=std::max(a[i],1ll);
    qu[i].push_back(0);
  }
  for(int i=1;i<=n;i++){
    p[i]=read();
    p[i+n]=p[i];
  }
  memset(lazy,-1,sizeof(lazy));
  p[n*2]=0;
  int ans=0;
  for(int i=1;i<=n*2-1;i++){
    r=i;
    process(p[i],-1);
    ql=qr=i;
    op=c-1;
    mod(1,1,n*2);
    qu[p[i]].push_back(i);
    process(p[i],1);
    mnn=0;
    cntt=0;
    ql=std::max(i-n+2,1ll);
    qr=i-1;
    if(i==n){// choose all
      ql=1;
    }
    if(i>n){
      qr=n;
    }
    if(ql<=qr){
      query(1,1,2*n);
    }
    if(mnn==c){
      ans+=cntt;
    }
  }
  printf("%lld",ans);
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
