#include <iostream>
#include <cstdio>
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int now;
int sta[400005];
int tp;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int b;
int p;
int ans=0;
void dfs(int x,int y){
  sta[++tp]=x;
  if(x==b){
    p=sta[(1+tp)/2];
    ans+=tp/2;
  }
  for(int i=fir[x];i!=-1;i=nxt[i]){
    if(v[i]==y){
      continue;
    }
    dfs(v[i],x);
  }
  tp--;
  return ;
}
int mx=0;
void dfs2(int now,int fa,int dep){
  mx=std::max(mx,dep);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now,dep+1);
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int a=read();
    b=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    now=0;
    mx=ans=0;
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    dfs(a,a);
    dfs2(p,p,0);
    printf("%d\n",2*(n-1)-mx+ans);
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

