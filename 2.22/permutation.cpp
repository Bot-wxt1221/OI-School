#include <iostream>
#include <cstdio>
#include <map>
#define int long long
#define mod 1000000007ll
inline int read();
int fir[65];
std::map<long long,long long>mp[65][65][65];
int nxt[130];
int v[130];
int now;
int vis[65];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ; 
}
int n;
int dfs(int ii,int v1,int v2,long long S){
  if(ii==n){
    return 1;
  }
  if(mp[ii][v1][v2][S]==0x3f3f3f3f3f3f3f3f){
    return 0;
  }
  if(mp[ii][v1][v2][S]){
    return mp[ii][v1][v2][S];
  }
  for(int iii=1;iii<=n;iii++){
    if(vis[iii]){
      continue;
    }
    vis[iii]=ii+1;
    bool ok=1;
    for(int i=fir[v2];i!=-1;i=nxt[i]){
      if(vis[v[i]]==0){
        ok=0;
      }
    }
    for(int i=fir[iii];i!=-1;i=nxt[i]){
      if(vis[v[i]]&&std::abs(vis[v[i]]-ii-1)>2){
        ok=0;
      }
    }
    if(!ok){
      vis[iii]=0;
      continue;
    }
    mp[ii][v1][v2][S]+=dfs(ii+1,iii,v1,S|(1ll<<(iii-1)));
    mp[ii][v1][v2][S]%=mod;
    vis[iii]=0;
  }
  if(mp[ii][v1][v2][S]==0){
    mp[ii][v1][v2][S]=0x3f3f3f3f3f3f3f3f;
    return 0;
  }
  return mp[ii][v1][v2][S];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  if(n==1){
    printf("1");
    return 0;
  }
  if(n==2){
    printf("2");
    return 0;
  }
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int u=read();
    int v=read();
    add(u,v);
    add(v,u);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j){
        vis[i]=vis[j]=1;
        vis[j]++;
        ans+=dfs(2,j,i,((1ll<<(i-1))+(1ll<<(j-1))));
        ans%=mod;
        vis[i]=vis[j]=0;
      }
    }
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


