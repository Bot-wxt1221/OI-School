#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[1000005];
int nxt[1000005];
int v[1000005];
int w[1000005];
int now;
std::queue<int>qu;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
bool dfn[1000005];
int in[1000005];
void dfs(int now){
  if(dfn[now]){
    return ;
  }
  qu.push(now);
  dfn[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    in[v[i]]+=w[i];
    dfs(v[i]);
  }
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m,k;
  m=read();
  k=read();
  for(int i=1;i<=m;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    int a=read();
    int b=read();
    add(a,b,1);
    add(b,a,0);
  }
  int ans=0;
  for(int i=1;i<=m;i++){
    if(!dfn[i]){
      dfs(i);
    }
    int anss=0;
    while(qu.size()>0){
      anss^=(in[qu.front()]%2);
      qu.pop();
    }
    ans+=anss;
  }
  printf("%d",k-ans);
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


