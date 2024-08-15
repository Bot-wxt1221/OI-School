#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::vector<int>vec[1600005];
class node{
public:
  void Union(int x,int y){
    int fx=getfa(x);
    int fy=getfa(y);
    if(fx==fy){
      return ;
    }
    if(siz[fx]>siz[fy]){
      std::swap(fx,fy);
    }
    fa[fx]=fy;
    siz[fy]+=siz[fx];
    return ;
  }
  bool query(int x,int y){
    return getfa(x)==getfa(y);
  }
  node(int n=100001){
    for(int i=1;i<=n;i++){
      fa[i]=i;
      siz[i]=1;
    }
  }
  int getfa(int x){
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
  }
  int fa[100005];
  int siz[100005];
}Un;
int x[100005],y[100005];
int qx[100005],qy[100005],qz[100005];
int ans[100005];
int mx;
int l[1600005],r[1600005];
void div(int now,int l,int r){
  mx=std::max(mx,now);
  ::l[now]=l;
  ::r[now]=r;
  if(l==r){
    return ;
  }
  int mid=(l+r)/2;
  div(now*2,l,mid);
  div(now*2+1,mid+1,r);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    x[i]=read();
    y[i]=read();
  }
  int q=read();
  for(int i=1;i<=q;i++){
    qx[i]=read();
    qy[i]=read();
    qz[i]=read();
    vec[1].push_back(i);
  }
  div(1,1,m);
  for(int now=1;now<=mx;now++){
    if(l[now]==0){
      continue;
    }
    if(l[now]==r[now]){
      for(int i=0;i<vec[now].size();i++){
        ans[vec[now][i]]=l[now];
      }
      for(int i=l[now];i<=r[now];i++){
        Un.Union(x[i],y[i]);
      }
      continue;
    }
    if(l[now]!=r[now-1]+1||now==1){
      for(int i=1;i<=n;i++){
        Un.fa[i]=i;
        Un.siz[i]=1;
      }
    }
    int mid=(l[now]+r[now])/2;
    for(int i=l[now];i<=mid;i++){
      Un.Union(x[i],y[i]);
    }
    for(int i=0;i<vec[now].size();i++){
      int &q=vec[now][i];
      bool ok=0;
      if(Un.query(qx[q],qy[q])){
        if(Un.siz[Un.getfa(qx[q])]>=qz[q]){
          ok=1;
        }
      }else{
        if(Un.siz[Un.getfa(qx[q])]+Un.siz[Un.getfa(qy[q])]>=qz[q]){
          ok=1;
        }
      }
      if(ok){
        vec[now*2].push_back(q);
      }else{
        vec[now*2+1].push_back(q);
      }
    }
    for(int i=mid+1;i<=r[now];i++){
      Un.Union(x[i],y[i]);
    }
  }
  for(int i=1;i<=q;i++){
    printf("%d\n",ans[i]);
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
