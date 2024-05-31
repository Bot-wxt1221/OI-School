#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int w[400005];
int dp[400005][2],maxn[400005][2];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int rans=0;
void dfs(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    dp[now][0]+=std::max(dp[v[i]][0],dp[v[i]][1]+w[i]);
    int ret=dp[v[i]][0]+w[i]-std::max(dp[v[i]][0],dp[v[i]][1]+w[i]);
    if(ret>maxn[now][0]){
      maxn[now][1]=maxn[now][0];
      maxn[now][0]=ret;
    }else if(ret>maxn[now][1]){
      maxn[now][1]=ret;
    }
  }
  dp[now][1]=dp[now][0]+maxn[now][0];
  return ;
}
void dfs2(int now,int fa){
  rans=std::max(rans,dp[now][0]);
  int f0=dp[now][0];
  int f1=dp[now][1];
  int mx0=maxn[now][0];
  int mx1=maxn[now][1];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dp[now][0]-=std::max(dp[v[i]][0],dp[v[i]][1]+w[i]);
    dp[now][1]-=std::max(dp[v[i]][0],dp[v[i]][1]+w[i]);
    int ret=dp[v[i]][0]+w[i]-std::max(dp[v[i]][0],dp[v[i]][1]+w[i]);
    if(ret==maxn[now][0]){
      dp[now][1]+=maxn[now][1]-maxn[now][0];
    }
    dp[v[i]][0]+=std::max(dp[now][0],dp[now][1]+w[i]);
    dp[v[i]][1]+=std::max(dp[now][0],dp[now][1]+w[i]);
    dp[v[i]][1]-=maxn[v[i]][0];
    ret=dp[now][0]+w[i]-std::max(dp[now][0],dp[now][1]+w[i]);
    if(ret>maxn[v[i]][0]){
      maxn[v[i]][1]=maxn[v[i]][0];
      maxn[v[i]][0]=ret;
    }else if(ret>maxn[v[i]][1]){
      maxn[v[i]][1]=ret;
    }
    dp[v[i]][1]+=maxn[v[i]][0];
    dfs2(v[i],now);
    dp[now][0]=f0;
    dp[now][1]=f1;
    maxn[now][0]=mx0;
    maxn[now][1]=mx1;
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
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int a=read();
    int b=read();
    int c=read();
    add(a,b,c);
    add(b,a,c);
  }
  memset(maxn,~0x3f,sizeof(maxn));
  dfs(1,0);
  dfs2(1,0);
  printf("%d",rans);
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

