#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int u[200005];
int v[200005];
int w[200005];
int fir[200005];
int now;
int nxt[200005];
int color[200005];
int dp[200005][5];
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  dp[now][0]=dp[now][1]=dp[now][2]=0x3f3f3f3f3f3f3f3f;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
  if(color[now]==0){
    dp[now][2]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      if(color[v[i]]==1){
        dp[now][2]+=dp[v[i]][1]+w[i];
      }else if(color[v[i]]!=0){
        dp[now][2]+=std::min(dp[v[i]][2],dp[v[i]][0]);
      }else{
        dp[now][2]+=std::min(dp[v[i]][2],std::min(dp[v[i]][0],dp[v[i]][1]+w[i]));
      }
    }
    dp[now][1]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      if(color[v[i]]==2){
        dp[now][1]+=dp[v[i]][2]+w[i];
      }else if(color[v[i]]!=0){
        dp[now][1]+=std::min(dp[v[i]][1],dp[v[i]][0]);
      }else{
        dp[now][1]+=std::min(dp[v[i]][1],std::min(dp[v[i]][0],dp[v[i]][2]+w[i]));
      }
    }
    dp[now][0]=0;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      if(color[v[i]]==2||color[v[i]]==1){
        dp[now][0]+=dp[v[i]][color[v[i]]]+w[i];
      }else{
        dp[now][0]+=dp[v[i]][0];
      }
    }
  }else{
    dp[now][color[now]]=0;
     for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa){
        continue;
      }
      if(color[v[i]]!=0&&color[v[i]]!=color[now]){
        dp[now][color[now]]+=dp[v[i]][color[v[i]]]+w[i];
      }else if(color[v[i]]!=0){
        dp[now][color[now]]+=dp[v[i]][color[now]];
      }else{
        int minn=0x3f3f3f3f3f3f3f3f;
        for(int k=0;k<=2;k++){
          if(color[now]==k){
            minn=std::min(minn,dp[v[i]][k]);
          }else{
            minn=std::min(minn,dp[v[i]][k]+w[i]);
          }
        }
        dp[now][color[now]]+=minn;
      }
    }
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
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  int m=read();
  for(int i=1;i<=m;i++){
    color[read()]=1;
  }
  int k=read();
  for(int i=1;i<=k;i++){
    color[read()]=2;
  }
  dfs(1,1);
  printf("%lld",std::min(dp[1][0],std::min(dp[1][1],dp[1][2])));
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


