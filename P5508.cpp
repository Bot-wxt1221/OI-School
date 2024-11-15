#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
std::priority_queue<std::pair<int,int> >qu;
int seq[50005];
bool vised[50005*15];
int dis[50005*15];
int from[50005*15];
signed fir[50005*15];
signed v[50005*25*4];
signed nxt[50005*25*4];
int w[50005*25*4];
std::vector<int>vec;
int now;
void internal_add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int toseq[50005];
int tll[50005*15];
int trr[50005*15];
void build(int now,int l,int r){
  tll[now]=l;
  trr[now]=r;
  if(l==r){
    toseq[l]=now;
    return ;
  }
  int mid=(l+r)/2;
  internal_add(now*2,now,0);
  internal_add(now*2+1,now,0);
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  return ;
}
void build1(int now,int l,int r){
  if(l==r){
    toseq[l]=now;
    return ;
  }
  int mid=(l+r)/2;
  internal_add(now+5e4*5,now*2+5e4*5,0);
  internal_add(now+5e4*5,now*2+1+5e4*5,0);
  build1(now*2,l,mid);
  build1(now*2+1,mid+1,r);
  return ;
}
void add(int x,int y,int z){
  internal_add(x,y,z);
  internal_add(y,x,z);
}
int ql,qr,op,opw,pian;
bool type;
void query(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    if(type){
      internal_add(now+pian,op,opw);
    }else{
      internal_add(op,now+pian,opw);
    }
    return ;
  }
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
  return ;
}
class zhi{
public:
  int k,b,i;
  zhi(int aa=0,int bb=0,int cc=0){
    k=aa;
    b=bb;
    i=cc;
    return ;
  }
  int calc(int x){
    return x*k+b;
  }
};
class seg{
public:
  zhi tree[50005*8];
  int ans[50005*8];
  int tl[50005*8];
  int tr[50005*8];
  int pos[50005*8];
  int from[50005*8];
  void pushup(int now){
    ans[now]=std::min(ans[now*2],ans[now*2+1]);
    if(ans[now]==ans[now*2]){
      pos[now]=pos[now*2];
      from[now]=from[now*2];
    }else{
      pos[now]=pos[now*2+1];
      from[now]=from[now*2+1];
    }
    tl[now]=std::min(tl[now*2],tl[now*2+1]);
    tr[now]=std::max(tr[now*2],tr[now*2+1]);
    if(tl[now]!=0x3f3f3f3f3f3f3f3f){
   int t1=tree[now].calc(tl[now]);
      if(ans[now]>t1){
        ans[now]=t1;
        pos[now]=tl[now];
        from[now]=tree[now].i;
      }
    }
    if(tr[now]!=0){
      int t2=tree[now].calc(tr[now]);
      if(ans[now]>t2){
        ans[now]=t2;
        pos[now]=tr[now];
        from[now]=tree[now].i;
      }
    }
    return ;
  }
  void init(int now,int l,int r){
    tl[now]=tr[now]=l;
    pos[now]=l;
    if(l==r){
      tree[now]={0,0x3f3f3f3f3f3f3f3f};
      ans[now*2]=ans[now*2+1]=0x3f3f3f3f3f3f3f3f;
      ans[now]=0x3f3f3f3f3f3f3f3f;
      return ;
    }
    int mid=(l+r)/2;
    init(now*2,l,mid);
    init(now*2+1,mid+1,r);
    tree[now]={0,0x3f3f3f3f3f3f3f3f};
    ans[now]=0x3f3f3f3f3f3f3f3f;
    return ;
  }
  int ql,qr;
  zhi op;
  void mod(int now,int l,int r){
    if(r<ql||qr<l){
      return ;
    }
    int mid=(l+r)/2;
    if(ql<=l&&r<=qr){
      auto back=op;
      if(l==r){
        if(tree[now].calc(mid)>op.calc(mid)){
          std::swap(tree[now],op);
        }
        ans[now]=tree[now].calc(mid);
        from[now]=tree[now].i;
        if(tl[now]==0x3f3f3f3f3f3f3f3f){
          ans[now]=0x3f3f3f3f3f3f3f3f;
        }
        op=back;
        pos[now]=mid;
        return ;
      }
      if(tl[now]==0x3f3f3f3f3f3f3f3f){
        return ;
      }
      if(tree[now].calc(mid)>op.calc(mid)){
        std::swap(tree[now],op);
      }
      int tt=(tree[now].calc(l)<=op.calc(l));
      int tt1=(tree[now].calc(r)<=op.calc(r));
      if(tt&&tt1){
        pushup(now);
        op=back;
        return ;
      }
      if(tt1){
        mod(now*2,l,mid);
      }
      if(tt){
        mod(now*2+1,mid+1,r);
      }
      op=back;
      pushup(now);
      return ;
    }
    mod(now*2,l,mid);
    mod(now*2+1,mid+1,r);
    pushup(now);
    return ;
  }
  int opp;
  void del(int now,int l,int r){
    if(r<opp||opp<l){
      return ;
    }
    if(l==r){
      tl[now]=0x3f3f3f3f3f3f3f3f;
      tr[now]=0;
      ans[now]=0x3f3f3f3f3f3f3f3f;
      return ;
    }
    int mid=(l+r)/2;
    del(now*2,l,mid);
    del(now*2+1,mid+1,r);
    pushup(now);
    return ;
  }
}se;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  memset(fir,-1,sizeof(fir));
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  build(1,1,n);
  build1(1,1,n);
  for(int i=1;i<=m;i++){
    int sl=read();
    int sr=read();
    int tl=read();
    int tr=read();
    int w=read();
    ql=sl;
    qr=sr;
    pian=0;
    op=i+5e5;
    type=1;
    opw=w;
    query(1,1,n);
    ql=tl;
    qr=tr;
    type=0;
    pian=5e4*5;
    opw=0;
    query(1,1,n);
  }
  for(int i=1;i<=n;i++){
    internal_add(toseq[i]+5e4*5,toseq[i],0);
  }
  int cnt=0;
  memset(dis,0x3f,sizeof(dis));
  se.init(1,1,n);
  qu.push({-0x3f3f3f3f3f3f3f3f,0});
  qu.push({0,toseq[1]});
  dis[toseq[1]]=0;
  while(qu.size()>0&&cnt!=n){
    auto cur=qu.top().second;
    qu.pop();
    if(vised[cur]){
      continue;
    }
    vised[cur]=1;
    if(tll[cur]==trr[cur]&&tll[cur]!=0){
      se.opp=tll[cur];
      se.del(1,1,n);
    }
    for(int i=fir[cur];i!=-1;i=nxt[i]){
      if(dis[v[i]]>dis[cur]+w[i]){
        dis[v[i]]=dis[cur]+w[i];
        qu.push({-dis[v[i]],v[i]});
        from[v[i]]=cur;
      }
    }
    if(tll[cur]==trr[cur]&&seq[tll[cur]]){
      cur=tll[cur];
      se.op.k=-seq[cur];
      se.op.b=(cur)*seq[cur]+dis[toseq[cur]];
      se.op.i=toseq[cur];
      se.ql=1;
      se.qr=cur-1;
      if(se.ql<=se.qr){
        se.mod(1,1,n);
      }
      se.op.k=seq[cur];
      se.op.b=-cur*seq[cur]+dis[toseq[cur]];
      se.op.i=toseq[cur];
      se.ql=cur+1;
      se.qr=n;
      if(se.ql<=se.qr){
        se.mod(1,1,n);
      }
    }
    if(dis[toseq[se.pos[1]]]>se.ans[1]){
      dis[toseq[se.pos[1]]]=se.ans[1];
      from[toseq[se.pos[1]]]=se.from[1];
      qu.push({-dis[toseq[se.pos[1]]],toseq[se.pos[1]]});
    }
  }
  printf("%lld\n",dis[toseq[n]]);
  int cur=toseq[n];
  while(cur!=toseq[1]){
    if(tll[cur]==trr[cur]&&tll[cur]){
      vec.push_back(tll[cur]);
    }
    cur=from[cur];
  }
  printf("%lld\n1 ",(int)vec.size()+1);
  for(int i=vec.size()-1;i>=0;i--){
    printf("%lld ",vec[i]);
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
