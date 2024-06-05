#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int fir[505];
int nxt[1005];
int v[1005];
int w[1005];
bool inS[1005];
bool inT[1005];
int now;
int dp[1005];//du or budu
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int maxx[505];
void dfs(int now,int fa,int dep,int tp=0){
  maxx[now]=0x3f3f3f3f3f3f3f;
  dp[now]=0;
  if(inS[now]){
    maxx[now]=dep;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,dep+w[i]);
    maxx[now]=std::min(maxx[now],maxx[v[i]]);
    dp[now]+=std::max(dp[v[i]]-w[i],0ll);
  }
  if(inT[now]){
    dp[now]=maxx[now]-dep+1;
  }
  if(now!=1){
    dp[now]=std::min(dp[now],maxx[now]-dep+1);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    now=0;
    int n=read();
    int S=read();
    int T=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      inS[i]=inT[i]=0;
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      int z=read();
      add(x,y,z+1);
      add(y,x,z+1);
    }
    for(int i=1;i<=S;i++){
      inS[read()]=1;
    }
    for(int i=1;i<=T;i++){
      inT[read()]=1;
    }
    if(inT[1]){
      printf("Impossible\n");
      continue;
    }
    dfs(1,1,0);
    if(dp[1]>=0x3f3f3f3f3f3f3){
      printf("Impossible\n");
    }else{
      printf("%lld\n",dp[1]);
    }
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

