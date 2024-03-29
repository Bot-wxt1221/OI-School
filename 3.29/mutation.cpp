#include <iostream>
#include <cstdio>
inline int read();
int fir[2000005];
int nxt[2000005];
int v[2000005];
int now;
int in[2000005];
void add(int x,int y){
  in[x]++;
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dfn[2000005];
int low[2000005];
int cur;
bool ans[2000005];
void dfs(int now){
  dfn[now]=low[now]=++cur;
  int cnt=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(!dfn[v[i]]){
      dfs(v[i]);
      low[now]=std::min(low[now],low[v[i]]);
      if(low[v[i]]>=dfn[now]){
        cnt++;
      }
    }else{
      low[now]=std::min(low[now],dfn[v[i]]);
    }
  }
  if(cnt>(now==1)){
    ans[now]=1;
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("mutation.in","r",stdin);
  freopen("mutation.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read(),m;
    m=read();
    now=0;
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      ans[i]=0;
      in[i]=0;
      dfn[i]=low[i]=0;
    }
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
      if(m-in[i]==n-2&&!ans[i]){
        printf("%d ",i);
      }
    }
    printf("\n");
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


