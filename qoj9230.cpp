#include <iostream>
#include <cstdio>
#include <vector>
#define int __int128
#define mod inf
inline int read();
std::vector<int>to;
int fir[200005];
int inf=0x3f3f3f3f3f3f3f3f;
int nxt[400005];
int link[400005];
int v[400005];
int dep[200005];
int ans[200005];
int passdep[200005];
int mxdep[200005];
int mx2dep[200005];
bool vised[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  link[y]++;
  return ;
}
void dfs(int now,int fa){
  if(vised[now]){
    printf("NIE");
    exit(0);
  }
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    if(mxdep[v[i]]+1>=mxdep[now]){
      mx2dep[now]=mxdep[now];
      mxdep[now]=mxdep[v[i]]+1;
    }else if(mxdep[v[i]]+1>=mx2dep[now]){
      mx2dep[now]=mxdep[v[i]]+1;
    }
  }
  return ;
}
void dfs2(int now,int fa){
  if(now!=fa){
    ans[now]=std::max(passdep[fa],mxdep[now]);
  }else{
    ans[now]=mxdep[now];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(mxdep[now]==mxdep[v[i]]+1){
      passdep[now]=mx2dep[now];
    }else{
      passdep[now]=mxdep[now];
    }
    passdep[now]=std::max(passdep[fa]+1,passdep[now]);
    dfs2(v[i],now);
  }
  return ;
}
int dp[200005];
int cnt[200005];
int rdp[200005];
int rcnt[200005];
bool invalid=0;
void dfs3(int now,int fa){
  dp[now]=0;
  cnt[now]=0;
  int cntt=0;
  int mn=inf;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    cntt++;
    dfs3(v[i],now);
    cnt[now]+=cnt[v[i]]*2;
    cnt[now]=std::min(cnt[now],mod);
    dp[now]+=dp[v[i]]*2;
    dp[now]=std::min(dp[now],mod);
    mn=std::min(mn,cnt[v[i]]);
  }
  if(cntt==2){
    dp[now]+=mn;
    dp[now]=std::min(dp[now],mod);
  }
  cnt[now]++;
  if(cntt>2){
    invalid=1;
  }
  return ;
}
void dfs4(int now,int fa){
  int odp=dp[now];
  int ocnt=cnt[now];
  if(now==fa){
    rdp[now]=dp[now];
    rcnt[now]=cnt[now];
  }else{
    dp[now]+=dp[fa]*2;
    int cntt=0;
    int mn=inf;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      cntt++;
      mn=std::min(mn,cnt[v[i]]);
    }
    if(cntt==2){
      dp[now]+=mn;
    }
    dp[now]=std::min(dp[now],mod);
    cnt[now]+=cnt[fa]*2;
    cnt[now]=std::min(cnt[now],mod);
    rdp[now]=dp[now];
    dp[now]-=mn;
    rcnt[now]=cnt[now];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    int cntt=0;
    int mn=inf;
    for(int j=fir[now];j!=-1;j=nxt[j]){
      if(i==j){
        continue;
      }
      cntt++;
      mn=std::min(mn,cnt[v[j]]);
    }
    if(cntt==2){
      dp[now]+=mn;
    }
    dp[now]-=dp[v[i]]*2;
    cnt[now]-=cnt[v[i]]*2;
    dfs4(v[i],now);
    if(cntt==2){
      dp[now]-=mn;
    }
    dp[now]+=dp[v[i]]*2;
    cnt[now]+=cnt[v[i]]*2;
  }
  dp[now]=odp;
  cnt[now]=ocnt;
}
int calc(int now){
  int tt=0;
  if(link[now]==1){
    if(ans[now]-1>32){
      return inf;
    }
    tt=now;
    return rdp[tt]/2+rcnt[tt]/2;
  }else{
    if(ans[now]>32){
      return inf;
    }
    tt=now;
    return rdp[tt]+rcnt[tt];
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  inf=inf*inf;
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  int tttt=0;
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    if(i==1){
      tttt=x;
    }
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dfs2(1,1);
  dfs3(1,1);
  dfs4(1,1);
  int mndep=inf;
  for(int i=1;i<=n;i++){
    if(link[i]<=2){
      if(mndep>ans[i]){
        mndep=ans[i];
        to.clear();
        to.push_back(i);
      }else if(mndep==ans[i]){
        to.push_back(i);
      }
    }
  }
  int ans=inf;
  for(int i=0;i<to.size();i++){
    ans=std::min(ans,calc(to[i]));
  }
  printf("%lld",ans);
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
