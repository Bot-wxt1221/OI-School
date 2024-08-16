#include <iostream>
#include <cstdio>
#define mod 998244353
#define inv10000 796898467
inline int read();
int fir[300005];
int nxt[600005];
int v[600005];
int now;
int p[300005];
int siz[300005];
int bson[300005];
int pow(int x,int y){
	if(y==0){
		return 1;
	}
	if(y%2==0){
		int tt=pow(x,y/2);
		return (1ll*tt*tt)%mod;
	}
	return (1ll*pow(x,y-1)*x)%mod;
}
class modint{
  public:
    int x=1,num=0;
};
modint operator * (modint a,int b){
  if(b==0){
    a.num++;
  }else{
    a.x=(1ll*a.x*b)%mod;
  }
  return a;
}
modint operator * (int b,modint a){
  if(b==0){
    a.num++;
  }else{
    a.x=(1ll*a.x*b)%mod;
  }
  return a;
}
modint operator / (modint a,int b){
  if(b==0){
    a.num--;
  }else{
    a.x=(1ll*a.x*pow(b,mod-2))%mod;
  }
  return a;
}
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  siz[now]=1;
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
int cnt;
int dfn[300005];
int top[300005];
int bot[300005];
modint dp[300005][2];
int ans2[300005][2];
int fa[300005];
inline int read();
class Matrix{
  public:
    int map[2][2];
    void clear(int x=0){
      map[0][0]=map[1][1]=x;
      map[0][1]=map[1][0]=0;
      return ;
    }
}tree[2400005],seq[300005];
Matrix operator * (const Matrix &a,const Matrix &b){
  Matrix ans;
  for(int i=0;i<=1;i++){
    for(int j=0;j<=1;j++){
      ans.map[i][j]=0;
      for(int k=0;k<=1;k++){
        ans.map[i][j]+=(a.map[i][k]*b.map[k][j]);
      }
    }
  }
  return ans;
}
void init(int x){
  seq[dfn[x]].map[0][0]=(1-p[x])+(1ll*p[x]*ans2[x][0]);
  seq[dfn[x]].map[0][0]%=mod;

  seq[dfn[x]].map[0][1]=(1ll*p[x]*(1-ans2[x][0]));

  seq[dfn[x]].map[1][0]=(1ll*(1-p[x])*(1-ans2[x][0]));

  seq[dfn[x]].map[1][1]=(p[x])+(1ll*(1-p[x])*(ans2[x][1]));
  seq[dfn[x]].map[1][1]%=mod;
}
void dfs2(int now,int fa,int tp){
  ans2[now][1]=1;
  ans2[now][0]=0;
  ::fa[now]=fa;
  top[now]=tp;
  dfn[now]=++cnt;
  bot[tp]=now;
  if(bson[now]){
    dfs2(bson[now],now,tp);
    dp[now][0].x=dp[now][1].x=1;
  }else{
    dp[now][0].num=1;
    dp[now][1].x=1;
    seq[dfn[now]].map[0][0]=0;
    seq[dfn[now]].map[0][1]=1;
    return ;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
    dp[now][0]=dp[now][0]*ans2[v[i]][0];
    dp[now][1]=dp[now][1]*ans2[v[i]][1];
  }
  init(now);
  return ;
}
void init(int now,int l,int r){
  if(l==r){
    tree[now]=seq[l];
    return ;
  }
  int mid=(l+r)/2;
  init(now*2,l,mid);
  init(now*2+1,mid+1,r);
  tree[now]=tree[now*2+1]*tree[now*2];
  return ;
}
int ql,qr;
Matrix ans;
void add(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(l==r){
    tree[now]=seq[l];
    return ;
  }
  int mid=(l+r)/2;
  add(now*2,l,mid);
  add(now*2+1,mid+1,r);
  tree[now]=tree[now*2+1]*tree[now];
}
void query(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    ans=ans*tree[now];
    return ;
  }
  int mid=(l+r)/2;
  query(now*2+1,mid+1,r);
  query(now*2,l,mid);
  return ;
}
int n;
std::pair<int,int> getans(int x){
  ql=dfn[x];
  qr=dfn[bot[x]];
  ans.clear(1);
  query(1,1,n);
  return {ans.map[0][0],ans.map[0][1]};
}
void addpoint(int now){
  seq[dfn[now]].map[0][0]=0;
  seq[dfn[now]].map[0][1]=1;
  ql=qr=dfn[now];
  add(1,1,n);
  while(now!=1){
    auto ret=getans(top[now]);
    
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  read();
  for(int i=2;i<=n;i++){
    add(read(),i);
  }
  dfs(1,1);
  dfs2(1,1,1);
  
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
