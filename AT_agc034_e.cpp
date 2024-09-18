#include <iostream>
#include <cstdio>
#define int long long
inline int read();
char temp[2005];
int fir[2005];
int nxt[4005];
int v[4005];
int dp[2005];
int dp2[2005];
int siz[2005];
int dep[2005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int rans=0;
void dfs(int now,int fa){
  dep[now]=dep[fa]+1;
  rans+=dep[now]*(temp[now]-'0');
  int mx=0;
  int sum=0;
  dp2[now]=0;
  siz[now]=(temp[now]=='1');
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    dp2[now]+=dp2[v[i]]+siz[v[i]];
    mx=std::max(mx,dp[v[i]]+siz[v[i]]);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    sum+=std::min(mx,dp2[v[i]]+siz[v[i]]);
  }
  int left=sum-mx;
  if(left>=mx){
    dp[now]=dp2[now]%2;
  }else{
    dp[now]=mx-left;
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
  scanf("%s",temp+1);
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  int ans=0x3f3f3f3f3f3f3f3f;
  for(int i=1;i<=n;i++){
    rans=0;
    dep[i]=-1;
    dfs(i,i);
    if(dp[i]!=0){
      continue;
    }else{
      ans=std::min(ans,rans/2);
    }
  }
  if(ans==0x3f3f3f3f3f3f3f3f){
    ans=-1;
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
