#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
inline int read();
int fir[300005];
std::stack<std::pair<int,int> >st;
int nxt[600005];
int v[600005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int lowbit(int x){
  return x&(-x);
}
int siz[300005],bson[300005];
int st1[21][300005],st2[21][300005],to[300005][21];
int lg[300005];
int top[300005];
void dfs(int now,int fa){
  to[now][0]=fa;
  for(int i=1;i<=20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  siz[now]=1;
  bson[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
  }
  return ;
}
int getmx(int l,int r){
  int siz=r-l+1;
  int llg=lg[siz];
  return std::max(st1[llg][l],st1[llg][r-(1<<llg)+1]);
}
int getmn(int l,int r){
  int siz=r-l+1;
  int llg=lg[siz];
  return std::min(st2[llg][l],st2[llg][r-(1<<llg)+1]);
}
int cnt;
int dfn[300005],dep[300005];
void dfs2(int now,int fa,int tp){
  dep[now]=dep[fa]+1;
  dfn[now]=++cnt;
  st1[0][cnt]=st2[0][cnt]=now;
  top[now]=tp;
  if(bson[now]){
    dfs2(bson[now],now,tp);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
}
int ans=0;
int tree[2400005];
int mark[2400005];
void build(int now,int l,int r){
  if(l==r){
    mark[now]=0;
    tree[now]=1;
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  mark[now]=0;
  tree[now]=tree[now*2]+tree[now*2+1];
  return ;
}
void pushdown(int now){
  if(mark[now]){
    tree[now*2]=tree[now*2+1]=0;
    mark[now*2]=mark[now*2+1]=1;
  }
  return ;
}
int ql,qr;
void query(int now,int l,int r){
  if(ql<=l&&r<=qr){
    ans+=tree[now];
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  if(ql<=mid){
    query(now*2,l,mid);
  }
  if(qr>=mid+1){
    query(now*2+1,mid+1,r);
  }
  return ;
}
void mod(int now,int l,int r){
  if(ql<=l&&r<=qr){
    mark[now]|=1;
    tree[now]=0;
    return ;
  }
  pushdown(now);
  int mid=(l+r)/2;
  if(ql<=mid){
    mod(now*2,l,mid);
  }
  if(qr>=mid+1){
    mod(now*2+1,mid+1,r);
  }
  tree[now]=tree[now*2]+tree[now*2+1];
  return ;
}
int mx,mn;
int getlca(int a,int b){
  if(dep[a]<dep[b]){
    std::swap(a,b);
  }
  if(dep[a]>dep[b]){
    for(int i=20;i>=0;i--){
      if(dep[to[a][i]]>dep[b]){
        a=to[a][i];
      }
    }
    a=to[a][0];
  }
  if(a!=b){
    for(int i=20;i>=0;i--){
      if(to[a][i]!=to[b][i]){
        a=to[a][i];
        b=to[b][i];
      }
    }
    a=to[a][0];
    b=to[b][0];
  }
  return a;
}
void getdis(int x,int y){
  mx=0;
  mn=0x3f3f3f3f;
  int lca=getlca(x,y);
  while(x!=lca){
    if(dep[top[x]]<=dep[lca]){
      ql=dfn[lca];
      qr=dfn[x];
      mx=std::max(getmx(ql,qr),mx);
      mn=std::min(mn,getmn(ql,qr));
      break;
    }else{
      ql=dfn[top[x]];
      qr=dfn[x];
      mx=std::max(getmx(ql,qr),mx);
      mn=std::min(mn,getmn(ql,qr));
    }
    x=to[top[x]][0];
  }
  x=y;
  while(x!=lca){
    if(dep[top[x]]<=dep[lca]){
      ql=dfn[lca];
      qr=dfn[x];
      mx=std::max(getmx(ql,qr),mx);
      mn=std::min(mn,getmn(ql,qr));
      break;
    }else{
      ql=dfn[top[x]];
      qr=dfn[x];
      mx=std::max(getmx(ql,qr),mx);
      mn=std::min(mn,getmn(ql,qr));
    }
    x=to[top[x]][0];
  }
  mx=std::max(mx,lca);
  mn=std::min(mn,lca);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("trip.in","r",stdin);
  freopen("trip.out","w",stdout);
  #endif
  int T=read();
  lg[1]=0;
  for(int i=2;i<=300000;i++){
    lg[i]=lg[i/2]+1;
  }
  while(T--){
    now=cnt=0;
    int n=read();
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
    for(int j=1;j<=20;j++){
      for(int i=1;(i+(1<<(j-1)))<=n;i++){
        st1[j][i]=std::max(st1[j-1][i],st1[j-1][i+(1<<(j-1))]);
        st2[j][i]=std::min(st2[j-1][i],st2[j-1][i+(1<<(j-1))]);
      }
    }
    build(1,1,n);
    long long ans=1;
    for(int i=n-1;i>=1;i--){
      getdis(i,i+1);
      ql=i+1;
      qr=mx-1;
      if(ql<=qr){
        mod(1,1,n);
      }
      while(st.size()>0&&st.top().second>=i){
        st.pop();
      }
      if(mn<i){
        ql=i+1;
        qr=n;
        st.push(std::make_pair(i+1,mn));
      }
      qr=n;
      if(st.size()>0){
        qr=std::min(qr,st.top().first-1);
      }
      ql=i;
      ::ans=0;
      query(1,1,n);
      ans+=::ans;
    }
    while(st.size()>0){
      st.pop();
    }
    printf("%lld\n",ans);
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
