#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int fir[1000005];
int nxt[1000005];
int v[1000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int ed[1000005];
int ffa[1000005];
int dep[1000005];
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  ffa[now]=fa;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    ed[v[i]]=i;
    dfs(v[i],now);
  }
  return ;
}
int sta[1500005];
int dp[1500005];
std::vector<int>vec;
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
    }
    now=0;
    for(int i=1;i<n;i++){
      int u=read();
      int v=read();
      add(u,v);
      add(v,u);
      sta[i*2]=0;
      sta[i*2-1]=0;
    }
    dfs(1,1);
    int k=read();
    for(int i=0;i<(1<<k);i++){
      dp[i]=0x3f3f3f3f;
    }
    dp[0]=0;
    for(int i=1;i<=k;i++){
      int x=read();
      int y=read();
      while(x!=y){
        if(dep[x]<dep[y]){
          std::swap(x,y);
        }
        sta[ed[x]]|=(1<<(i-1));
        x=ffa[x];
      }
    }
    vec.clear();
    for(int i=1;i<=now;i++){
      if(dp[sta[i]]!=0x3f3f3f3f){
        continue;
      }
      vec.push_back(sta[i]);
      dp[sta[i]]=1;
    }
    dp[0]=0;
    for(int i=1;i<(1<<k);i++){
      for(int j=0;j<vec.size();j++){
        dp[i]=std::min(dp[i],dp[i^(i&vec[j])]+1);
      }
    }
    printf("%d\n",dp[(1<<k)-1]);
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

