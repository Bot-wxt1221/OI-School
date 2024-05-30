#include <iostream>
#include <cstdio>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int sta[200005];
bool flag[200005];
int dp[200005];
int mx22;
int tp;
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int mx=0,mxn;
void dfs(int now,int fa,int dep){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,dep+1);
  }
  if(dep>mx){
    mx=dep;
    mxn=now;
  }
  return ;
}
void dfs2(int now,int fa,int dep){
  sta[++tp]=now;
  if(now==mxn){
    for(int i=1;i<=tp;i++){
      flag[i]=1;
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now,dep+1);
  }
  tp--;
  return ;
}
void dfs3(int now,int fa){
  dp[now]=0;
  int mx1=0,mx2=-0x3f3f3f3f;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs3(v[i],now);
    int tt=dp[v[i]];
    if(flag[v[i]]&&flag[now]){
      tt--;
    }else{
      tt++;
    }
    mx22=std::max(mx22,tt+dp[now]);
    dp[now]=std::max(dp[now],tt);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int k=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1,0);
  int tt=mxn;
  mx=0;
  mxn=0;
  dfs(tt,tt,0);
  dfs2(tt,tt,0);
  if(k==1){
    printf("%d\n",2*(n-1)-mx+1);
    return 0;
  }else{
    dfs3(1,1);
    printf("%d\n",2*(n)-mx-mx22);
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

