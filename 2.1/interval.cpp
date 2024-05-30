#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
  public:
    int l,r,w;
    node(int x=0,int y=0,int z=0){
      l=x;
      r=y;
      w=z;
      return ;
    }
}seq[2505];
int n;
bool operator < (node a,node b){
  if(a.l!=b.l){
    return a.l<b.l;
  }
  if(a.r!=b.r){
    return a.r<b.r;
  }
  return a.w<b.w;
}
int fa[2505];
int siz[2505];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int ans=0;
bool cho[2505];
int nans=0;
int k;
void dfs(int now){
  if(now==n+1){
    for(int i=1;i<=n;i++){
      fa[i]=i;
      siz[i]=1;
    }
    for(int i=n;i>=1;i--){
      if(cho[i]){
        continue;
      }
      for(int j=1;j<i;j++){
        if(cho[j]){
          continue;
        }
        if(seq[j].r>=seq[i].l){
          int fai=getfa(i);
          int faj=getfa(j);
          fa[fai]=faj;
          siz[faj]+=siz[fai];
        }
      }
    }
    for(int i=1;i<=n;i++){
      if(siz[i]>k){
        return ;
      }
    }
    ans=std::min(ans,nans);
    return ;
  }
  dfs(now+1);
  nans+=seq[now].w;
  cho[now]=1;
  dfs(now+1);
  cho[now]=0;
  nans-=seq[now].w;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("interval.in","r",stdin);
  freopen("interval.out","w",stdout);
  #endif
  n=read();
  k=read();
  for(int i=1;i<=n;i++){
    seq[i].l=read();
    seq[i].r=read();
    seq[i].w=read();
  }
  std::sort(seq+1,seq+n+1);
  ans=0x3f3f3f3f;
  dfs(1);
  printf("%d",ans);
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


