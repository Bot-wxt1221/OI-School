#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cstdio>
#include <vector>
#define int unsigned
#define mod 998244353
inline int read();
int fir[300005];
int fa[300005];
int nxt[600005];
int v[600005];
int w[300005];
int oriw[300005];
int siz[300005];
int now;
int t;
int dfn[300005];
int top[300005];
int dfn2[300005];
int lst[300005];
int ans[300005];
int bson[300005];
class Trie{
public:
  Trie *l=NULL,*r=NULL;
  int siz;
  int tag;
}seq[600005],seqq[600005*40];
int cntt;
int rans=0;
void query(Trie *cur,int num,int cen,int tt=1){
  if(cen==-1){
    return ;
  }
  if(t&(1ll<<cen)){
    if(cur->r==NULL){
      cur->r=&seqq[++cntt];
      cur->r->siz=0;
      cur->r->tag=0;
      cur->r->l=cur->r->r=NULL;
    }
    if(cur->l==NULL){
      cur->l=&seqq[++cntt];
      cur->l->siz=0;
      cur->l->tag=0;
cur->l->l=cur->l->r=NULL;

    }
    if(num&(1ll<<cen)){
      if(cur->r){
        rans+=cur->r->siz;
        cur->r->tag+=tt;
      }
      if(cur->l){
        query(cur->l,num,cen-1,tt);
      }
    }else{
      if(cur->l){
        rans+=cur->l->siz;
        cur->l->tag+=tt;
      }
      if(cur->r){
        query(cur->r,num,cen-1,tt);
      }
    }
  }else{
    if(num&(1ll<<cen)){
    if(cur->r==NULL){
      cur->r=&seqq[++cntt];
      cur->r->siz=0;
      cur->r->tag=0;
      cur->r->l=cur->r->r=NULL;

    }
          if(cur->r){
        query(cur->r,num,cen-1,tt);
      }
    }else{
    if(cur->l==NULL){
      cur->l=&seqq[++cntt];
      cur->l->siz=0;
      cur->l->tag=0;
      cur->l->l=cur->l->r=NULL;

    }

      if(cur->l){
        query(cur->l,num,cen-1,tt);
      }
    }
  }
  return ;
}
int query2(Trie *cur,int num,int cen){
  int ret=cur->tag;
  if(cen==-1){
    return ret;
  }
  if(num&(1ll<<cen)){
    if(cur->r){
      ret+=query2(cur->r,num,cen-1);
    }else{
    }
  }else{
    if(cur->l){
      ret+=query2(cur->l,num,cen-1);
    }
  }
  return ret;
}
void add(Trie *cur,int num,int cen,int ttt=1){
  cur->siz+=ttt;
  if(cen==-1){
    return ;
  }
  if(num&(1ll<<(cen))){
    if(cur->r==NULL){
      cur->r=&seqq[++cntt];
      cur->r->siz=0;
      cur->r->tag=0;
      cur->r->l=cur->r->r=NULL;
    }
    add(cur->r,num,cen-1,ttt);
  }else{
    if(cur->l==NULL){
      cur->l=&seqq[++cntt];
      cur->l->siz=0;
      cur->l->tag=0;
      cur->l->l=cur->l->r=NULL;
    }
    add(cur->l,num,cen-1,ttt);
  }
}
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int cnt;
void dfs(int now,int fa){
  siz[now]=1;
  bson[now]=0;
  ::fa[now]=fa;
  dfn[now]=++cnt;
  dfn2[cnt]=now;
  if(fa!=now){
    w[now]^=w[fa];
  }
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
  lst[now]=cnt;
  return ;
}
void adddis(int now,int tt,Trie *cur,int ttt=1){
  for(int ii=dfn[now];ii<=lst[now];ii++){
    int i=dfn2[ii];
    rans=0;
    query(cur,w[i]^tt,31,ttt);
    ans[dfn2[ii]]+=rans;
  }
  return ;
}
void calcdis2(int now,int tt,Trie *cur){
  for(int ii=dfn[now];ii<=lst[now];ii++){
    int i=dfn2[ii];
    add(cur,w[i],31);
  }
  return ;
}
void dfs2(int now,int fa,int top){
  ::top[now]=top;
  if(bson[now]){
    dfs2(bson[now],now,top);
    std::swap(seq[now],seq[bson[now]]);
  }
  rans=0;
  query(&seq[now],w[now]^oriw[now],31);
  ans[now]+=rans;
  add(&seq[now],w[now],31);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    adddis(v[i],oriw[now],&seq[now]);
    calcdis2(v[i],oriw[now],&seq[now]);
    int precnt=cntt;
    dfs2(v[i],now,v[i]);
    cntt=precnt;
  }
  return ;
}
void calcdis(int now,Trie *cur){
  for(int ii=dfn[now];ii<=lst[now];ii++){
    int i=dfn2[ii];
    ans[i]+=query2(cur,w[i],31);
  }
    return ;
}
void dfs(int now,int fa,Trie *cur){
  std::vector<int>tt;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==::fa[now]||v[i]==bson[now]){
      continue;
    }
    tt.push_back(v[i]);
  }
  for(int i=tt.size();i>0;i--){
    calcdis(tt[i-1],cur);
    adddis(tt[i-1],oriw[now],cur,1);
  }
  query(cur,w[now]^oriw[now],31);
  ans[now]+=query2(cur,w[now],31);
  if(bson[now]){
    dfs(bson[now],now,cur);
  }
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	#endif
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
  for(int i=1;i<=n;i++){
    w[i]=read();
    oriw[i]=w[i];
  }
  t=read();
  dfs(1,1);
  dfs2(1,1,1);
  cntt=0;
  long long ans=1;
  for(int i=1;i<=n;i++){
    if(top[i]==i){
      dfs(i,i,&seq[i+n]);
      cntt=0;
    }
    ans*=n;
    ans%=mod;
  }
  long long tt=1;
  for(int i=1;i<=n;i++){
    tt*=(::ans[i]);
    tt%=mod;
  }
  tt=ans-tt;
  tt%=mod;
  tt+=mod;
  tt%=mod;
  printf("%lld",tt);
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
