#include <iostream>
#include <cstdio>
inline int read();
int fir[200005];
int nxt[400005];
int deg[400005];
int v[400005];
int dp[200005][2];
int rans=0;
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    dp[now][0]+=std::max(dp[v[i]][0],dp[v[i]][1]);
    dp[now][1]+=dp[v[i]][0];
  }
  dp[now][1]++;
  return ;
}
void dfs2(int now,int fa){
  int pre=dp[now][0];
  int pre2=dp[now][1];
  if(now!=fa){
    dp[now][0]+=std::max(dp[fa][0],dp[fa][1]);
    dp[now][1]+=dp[fa][0];
  }
  int tt=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    tt++;
    dp[now][0]-=std::max(dp[v[i]][0],dp[v[i]][1]);
    dp[now][1]-=dp[v[i]][0];
    dfs2(v[i],now);
    dp[now][0]+=std::max(dp[v[i]][0],dp[v[i]][1]);
    dp[now][1]+=dp[v[i]][0];
  }
  if(tt<=1){
    rans=std::max(rans,dp[now][0]+1);
  }
  dp[now][0]=pre;
  dp[now][1]=pre2;
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
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      dp[i][0]=dp[i][1]=0;
      deg[i]=0;
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      deg[x]++;
      deg[y]++;
      add(x,y);
      add(y,x);
    }
    int t=1;
    for(int i=1;i<=n;i++){
      if(deg[i]>1){
        t=i;
        break;
      }
    }
    rans=0;
    dfs(t,t);
    dfs2(t,t);
    printf("%d\n",rans);
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

