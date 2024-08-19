#include <iostream>
#include <cstdio>
#include <queue>
inline long long read();
int fir[100005];
int nxt[200005];
int v[200005];
int w[200005];
int siz[100005];
int bson[100005];
int now;
int ans[100005];
long long dp[100005][4];
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::priority_queue<long long>qu[100005];
int lowbit(int x){
  return x&(-x);
}
void dfs(int now,int fa){
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
    if(dp[v[i]][0]+w[i]>=dp[now][0]){
      dp[now][1]=dp[now][0];
      dp[now][0]=dp[v[i]][0]+w[i];
    }else if(dp[v[i]][0]+w[i]>=dp[now][1]){
      dp[now][1]=dp[v[i]][0]+w[i];
    }
  }
  return ;
}
long long mn=0x3f3f3f3f3f3f3f3f,mn2;
void dfs2(int now,int fa){
  if(now!=1){
    dp[now][3]=std::max(dp[now][0],dp[fa][2]);
    if(mn>dp[now][3]){
      mn=dp[now][3];
      mn2=now;
    }
  }else{
    dp[now][3]=dp[now][0];
    if(mn>dp[now][3]){
      mn=dp[now][3];
      mn2=now;
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(dp[now][0]==dp[v[i]][0]+w[i]){
      dp[now][2]=std::max(dp[now][1],now!=1?dp[fa][2]:-0x3f3f3f3f)+w[i];
    }else{
      dp[now][2]=std::max(dp[now][0],now!=1?dp[fa][2]:-0x3f3f3f3f)+w[i];
    }
    dfs2(v[i],now);
  }
  return ;
}
void dfs3(int now,int fa){
  siz[now]=1;
  bson[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs3(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
  }
  return ;
}
long long mx=0,l;
void dfs4(int now,int fa){
  if(bson[now]){
    dfs4(bson[now],now);
    std::swap(qu[now],qu[bson[now]]);
  }else{
    while(qu[now].size()){
      qu[now].pop();
    }
  }
  qu[now].push(dp[now][3]);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs4(v[i],now);
    while(qu[v[i]].size()>0){
      qu[now].push(qu[v[i]].top());
      qu[v[i]].pop();
    }
  }
  while(-dp[now][3]+qu[now].top()>l){
    qu[now].pop();
  }
  mx=std::max(mx,(long long)(qu[now].size()));
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
  dfs(1,1);
  dfs2(1,1);
  dfs3(mn2,mn2);
  int q=read();
  for(int i=1;i<=q;i++){
    l=read();
    mx=0;
    dfs4(mn2,mn2);
    printf("%lld\n",mx);
  }
  return 0;
}
inline long long read(){
  long long x=0,f=1;char c=getchar();
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
