#include <iostream>
#include <cstdio>
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int mx1[500005];
int cnt1[500005];
int mx2[500005];
int cnt2[500005];
int mx3[500005];
int cnt3[500005];
int dp2[500005];
int a[500005];
void dfs(int now,int fa){
  mx1[now]=a[now];
  cnt1[now]=now;
  mx2[now]=a[now];
  cnt2[now]=now;
  mx3[now]=a[now];
  cnt3[now]=now;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    if(mx2[v[i]]>=mx1[now]){
      mx3[now]=mx2[now];
      cnt3[now]=cnt2[now];
      mx2[now]=mx1[now];
      cnt2[now]=cnt1[now];
      mx1[now]=mx2[v[i]];
      cnt1[now]=v[i];
    }else if(mx2[v[i]]>=mx2[now]){
      mx3[now]=mx2[now];
      cnt3[now]=cnt2[now];
      mx2[now]=mx2[v[i]];
      cnt2[now]=v[i];
    }else if(mx2[v[i]]>=mx3[now]){
      mx3[now]=mx2[v[i]];
      cnt3[now]=v[i];
    }
  }
  return ;
}
int upd[500005];
void dfs2(int now,int fa){
  if(now!=fa){
    if(upd[fa]>=mx1[now]){
      mx3[now]=mx2[now];
      cnt3[now]=cnt2[now];
      mx2[now]=mx1[now];
      cnt2[now]=cnt1[now];
      mx1[now]=upd[fa];
      cnt1[now]=fa;
    }else if(upd[fa]>=mx2[now]){
      mx3[now]=mx2[now];
      cnt3[now]=cnt2[now];
      mx2[now]=upd[fa];
      cnt2[now]=fa;
    }else if(upd[fa]>=mx3[now]){
      mx3[now]=upd[fa];
      cnt3[now]=fa;
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(v[i]==cnt2[now]){
      upd[now]=mx3[now];
    }else{
      upd[now]=mx2[now];
    }
    dfs2(v[i],now);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    a[i]=read();
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  if(n<=2000){
    for(int i=1;i<=n;i++){
      dfs(i,i);
      printf("%d ",mx1[i]);
    }
    return 0;
  }
  dfs(1,1);
  dfs2(1,1);
  for(int i=1;i<=n;i++){
    printf("%d ",mx1[i]);
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

