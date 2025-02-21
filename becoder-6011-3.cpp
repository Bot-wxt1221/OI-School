#include <iostream>
#include <cstdio>
#include <cassert>
#define int long long
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int color[200005];
int now;
int dep[200005];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int to2[200005];
int siz[200005];
int fa[200005][25];
int bson[200005];
void dfs(int now,int fa){
  siz[now]=1;
  dep[now]=dep[fa]+1;
  ::fa[now][0]=fa;
  for(int i=1;i<=20;i++){
    ::fa[now][i]=::fa[::fa[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[v[i]]>siz[bson[now]]){
      bson[now]=v[i];
    }
  }
  return ;
}
int dfn[200005];
int lst[200005];
int tp[200005];
int cnt;
void dfs2(int now,int fa,int top){
  dfn[now]=++cnt;
  to2[cnt]=now;
  tp[now]=top;
  if(bson[now]){
    dfs2(bson[now],now,top);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
  lst[now]=cnt;
  return ;
}
int val[200005];
class SEG{
public:
  int fu[200005*8];
  int mx[200005*8];
  int lazyadd1[200005*8];
  int lazyadd2[200005*8];
  void pushup(int now){
    mx[now]=-0x3f3f3f3f;
    if(!fu[now*2]){
      mx[now]=std::max(mx[now],mx[now*2]);
    }
    if(!fu[now*2+1]){
      mx[now]=std::max(mx[now],mx[now*2+1]);
    }
    return ;
  }
  void pushdown(int now){
    if(!fu[now*2]){
      lazyadd1[now*2]+=lazyadd1[now];
      mx[now*2]+=lazyadd1[now];
    }
    if(!fu[now*2+1]){
      lazyadd1[now*2+1]+=lazyadd1[now];
      mx[now*2+1]+=lazyadd1[now];
    }
    lazyadd2[now*2]+=lazyadd2[now];
    mx[now*2]+=lazyadd2[now];
    lazyadd2[now*2+1]+=lazyadd2[now];
    mx[now*2+1]+=lazyadd2[now];
    lazyadd2[now]=lazyadd1[now]=0;
    return ;
  }
  void init(int now,int l,int r){
    if(l==r){
      mx[now]=val[l];
      fu[now]=0;
      return ;
    }
    int mid=(l+r)/2;
    init(now*2,l,mid);
    init(now*2+1,mid+1,r);
    pushup(now);
    return ;
  }
  void modA(int now,int l,int r,int ql,int qr,int op){
    if(r<ql||qr<l){
      return ;
    }
    if(ql<=l&&r<=qr){
      fu[now]+=op;
      return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    modA(now*2,l,mid,ql,qr,op);
    modA(now*2+1,mid+1,r,ql,qr,op);
    pushup(now);
  }
  int ans=0;
  void query(int now,int l,int r,int ql,int qr,int sum,int pre){
    if(r<ql||qr<l){
      return ;
    }
    sum+=fu[now];
    if(ql<=l&&r<=qr){
      assert(sum>=pre);
      if(sum>pre){
        return ;
      }
      ans=std::max(ans,mx[now]);
      return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    query(now*2,l,mid,ql,qr,sum,pre);
    query(now*2+1,mid+1,r,ql,qr,sum,pre);
    return ;
  }
  void modB(int now,int l,int r,int ql,int qr,int op,int pre,int sum){
    if(r<ql||qr<l){
      return ;
    }
    sum+=fu[now];
    if(ql<=l&&r<=qr){
      assert(sum>=pre);
      if(sum>pre){
        return ;
      }
      lazyadd1[now]+=op;
      mx[now]+=op;
      return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    modB(now*2,l,mid,ql,qr,op,pre,sum);
    modB(now*2+1,mid+1,r,ql,qr,op,pre,sum);
    pushup(now);
  }
  void modC(int now,int l,int r,int ql,int qr,int op){
    if(r<ql||qr<l){
      return ;
    }
    if(ql<=l&&r<=qr){
      lazyadd2[now]+=op;
      mx[now]+=op;
      return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    modC(now*2,l,mid,ql,qr,op);
    modC(now*2+1,mid+1,r,ql,qr,op);
    pushup(now);
    return ;
  }
  void modD(int now,int l,int r,int ql,int op){
    if(r<ql||ql<l){
      return ;
    }
    if(l==r){
      mx[now]=op;
      return ;
    }
    pushdown(now);
    int mid=(l+r)/2;
    modD(now*2,l,mid,ql,op);
    modD(now*2+1,mid+1,r,ql,op);
    pushup(now);
    return ;
  }
  int query(int now,int l,int r,int tt){
    if(tt<l||r<tt){
      return 0;
    }
    if(l==r){
      return fu[now];
    }
    int mid=(l+r)/2;
    pushdown(now);
    return fu[now]+query(now*2,l,mid,tt)+query(now*2+1,mid+1,r,tt);
  }
}A,B;
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[200005];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=200000){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
}C;
int gettop(int x){
  int tx=x;
  int ret=x;
  int val=C.query(dfn[x])-C.query(dfn[x]-1);
  while(x!=1){
    int top=tp[x];
    int l=dfn[top],r=dfn[x];
    int mid=l;
    while(r-l>3){
      int mid=(l+r)/2;
      if((C.query(dfn[x])-C.query(mid-1))==(dfn[x]-mid+1)*val){
        r=mid;
      }else{
        l=mid;
      }
    }
    for(mid=l;mid<=r;mid++){
      if((C.query(dfn[x])-C.query(mid-1))==(dfn[x]-mid+1)*val){
        ret=to2[mid];
        break;
      }
    }
    if((C.query(dfn[x])-C.query(dfn[top]-1))==(dfn[x]-dfn[top]+1)*val){
      x=fa[top][0];
    }else{
      return ret;
    }
  }
  if(C.query(1)==val){
    return 1;
  }
  return ret;
}
int getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  if(dep[x]!=dep[y]){
    for(int i=20;i>=0;i--){
      if(dep[fa[x][i]]>dep[y]){
        x=fa[x][i];
      }
    }
    x=fa[x][0];
  }
  if(x!=y){
    for(int i=20;i>=0;i--){
      if(fa[x][i]!=fa[y][i]){
        x=fa[x][i];
        y=fa[y][i];
      }
    }
    x=fa[x][0];
    y=fa[y][0];
  }
  return x;
}
int n;
void addto(int x,int y,int val){
  while(1){
    int top=tp[x];
    if(dep[top]<=dep[y]){
      A.modC(1,1,n,dfn[y],dfn[x],val);
      B.modC(1,1,n,dfn[y],dfn[x],val);
      break;
    }else{
      A.modC(1,1,n,dfn[top],dfn[x],val);
      B.modC(1,1,n,dfn[top],dfn[x],val);     
      x=fa[top][0];
    }
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  int cnttt=0;
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dfs2(1,1,1);
  for(int i=1;i<=n;i++){
    color[i]=read();
  }
  for(int i=1;i<=n;i++){
    val[dfn[i]]=read();
  }
  A.init(1,1,n);
  B.init(1,1,n);
  for(int i=1;i<=n;i++){
    if((color[i])){
      A.modA(1,1,n,dfn[i],lst[i],1);
    }else{
      B.modA(1,1,n,dfn[i],lst[i],1);
    }
    C.mod(dfn[i],color[i]);
  }
  for(int i=1;i<=m;i++){
    int opp=read();
    switch(opp){
      case 1:{
        int x=read();
        C.mod(dfn[x],-color[x]);
        if(color[x]){
          B.ans=-0x3f3f3f3f;
          B.query(1,1,n,dfn[x],dfn[x],0,B.query(1,1,n,dfn[x]));
          A.modA(1,1,n,dfn[x],lst[x],-1);
          B.modA(1,1,n,dfn[x],lst[x],1);
          A.modD(1,1,n,dfn[x],B.ans);
        }else{
          A.ans=-0x3f3f3f3f;
          A.query(1,1,n,dfn[x],dfn[x],0,A.query(1,1,n,dfn[x]));
          A.modA(1,1,n,dfn[x],lst[x],1);
          B.modA(1,1,n,dfn[x],lst[x],-1);
          B.modD(1,1,n,dfn[x],A.ans);
        }
        color[x]^=1;
        C.mod(dfn[x],color[x]);
        break;
      }
      case 3:{
        int x=gettop(read());
        if(color[x]==0){
          A.ans=-0x3f3f3f3f;
          A.query(1,1,n,dfn[x],lst[x],0,A.query(1,1,n,dfn[x]));
          printf("%lld\n",A.ans);
        }else{
          B.ans=-0x3f3f3f3f;
          B.query(1,1,n,dfn[x],lst[x],0,B.query(1,1,n,dfn[x]));
          printf("%lld\n",B.ans);
        }
        break;
      }
      case 2:{
        int tt=read();
        int x=gettop(tt);
        int val=read();
        if(color[x]==0){
          A.ans=A.query(1,1,n,dfn[x]);
          A.modB(1,1,n,dfn[x],lst[x],val,A.ans,0);
        }else{
          B.ans=B.query(1,1,n,dfn[x]);
          B.modB(1,1,n,dfn[x],lst[x],val,B.ans,0);
        }
        break;
      }
      case 4:{
        int x=read();
        int y=read();
        int val=read();
        int fa=getlca(x,y);
        addto(x,fa,val);
        addto(y,fa,val);
        A.modC(1,1,n,dfn[fa],dfn[fa],-val);
        B.modC(1,1,n,dfn[fa],dfn[fa],-val);
        break;
      }
      case 5:{
        int x=read();
        int val=read();
        A.modC(1,1,n,dfn[x],lst[x],val);
        B.modC(1,1,n,dfn[x],lst[x],val);
        break;
      }
    }
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
