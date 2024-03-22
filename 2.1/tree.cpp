#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fa[500005];
int edge[500005];
std::priority_queue<int>qu;
int num[500005];
int fir[500005];
int nxt[1000005];
int v[1000005];
int w[1000005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
bool del[500005];
int dep[500005];
void dfs(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(fa==v[i]){
      continue;
    }
    ::fa[v[i]]=now;
    edge[v[i]]=w[i];
    dep[v[i]]=dep[now]+(1);
    dfs(v[i],now);
  }
  return ;
}
namespace ans{
  int u[500005];
  int v[500005];
  int c[500005];
};
int tt;
int tt2;
int getfa(int x){
  if(x==1){
    tt=0;
    return 1;
  }
  if(edge[x]!=0){
    tt=edge[x];
    tt2=x;
    return fa[x];
  }
  return fa[x]=getfa(fa[x]);
}
int getfa2(int x){
  if(x==1){
    return 1;
  }
  if(edge[x]!=0){
    return x;
  }
  return fa[x]=getfa2(fa[x]);
}
int main(){
 // #ifdef ONLINE_JUDGE
//  #else
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
//  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    fa[i]=i;
  }
  for(int i=1;i<=m;i++){
    ans::u[i]=read();
    ans::v[i]=read();
    ans::c[i]=read();
    if(ans::c[i]==1){
      add(ans::u[i],ans::v[i],i);
      add(ans::v[i],ans::u[i],i);
    }
  }
  dfs(1,1);
  int now=0;
  for(int i=1;i<=m;i++){
    if(ans::c[i]==1&&del[i]==0){
      num[i]=++now;
      del[i]=1;
    }
    if(ans::c[i]==0){
      int u=ans::u[i];
      int v=ans::v[i];
      while(u!=v){
        u=getfa2(u);
        v=getfa2(v);
        if(u==v){
          continue;
        }
        if(dep[u]<dep[v]){
          std::swap(u,v);
        }
        int temp=getfa(u);
        if(tt!=0){
          if(!del[tt]){
            qu.push(-tt); 
          }
          del[tt]=1;
          edge[tt2]=0;
        }
        u=temp;
      }
      while(qu.size()>0){
        num[-qu.top()]=++now;
        qu.pop();
      }
      num[i]=++now;
    }
  }
  for(int i=1;i<=m;i++){
    printf("%d ",num[i]);
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


