#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <bitset>
inline int read();
char temp[2505][2505];
int dis[2505][2505];
int from[2505];
int dp[2505];
bool vised[2505];
std::bitset<2505>bit[2505],bit2[2505];
std::bitset<2505>vise;
std::bitset<2505>dist[2505];
int far[2505];
std::vector<std::pair<int,int> >vec[2505];
int n;
std::priority_queue<std::pair<int,int> >qu;
void bfs(int now){
  std::queue<int>qu;
  qu.push(now);
  dis[now][now]=0;
  for(int i=1;i<=n;i++){
    bit2[i]=bit[i];
    vise[i]=1;
    bit2[i][now]=0;
  }
  int cnt=0;
  while(qu.size()>0){
    int tp=qu.front();
    qu.pop();
    auto bitt=bit2[tp]&vise;
    for(int i=bitt._Find_first();i!=bitt.size();i=bitt._Find_next(i)){
      dis[now][i]=dis[now][tp]+2;
      vise[i]=0;
      qu.push(i);
    }
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("net.in","r",stdin);
  std::cerr<<cnt;
  freopen("net.out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(temp[i][j]=='1'){
        bit[i][j]=1;
      }
    }
  }
  for(int i=1;i<=n;i++){
    bfs(i);
  }
  int mx=0x3f3f3f3f;
  int cnt;
  int cnt2,cnt3;
  bool yes=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      far[i]=std::max(far[i],dis[i][j]);
    }
    if(far[i]<mx){
      mx=far[i];
      cnt=i;
    }
  }
  for(int u=1;u<=n;u++){
    for(int v=1;v<=n;v++){
      dist[u][v]=(dis[u][v]==far[u]);
    }
  }
  for(int u=1;u<=n;u++){
    for(int v=1;v<=n;v++){
      if(bit[u][v]==0){
        continue;
      }
      if((dist[u]&dist[v]).none()){
        int nw=std::max(far[u],far[v])-1;
        if(nw<mx){
          mx=nw;
          yes=1;
          cnt2=u;
          cnt3=v;
        }
      }
    }
  }
  memset(dp,0x3f,sizeof(dp));
  memset(vised,0,sizeof(vised));
  if(yes){
    dp[cnt2]=dp[cnt3]=1;
    qu.push(std::make_pair(-1,cnt2));
    qu.push(std::make_pair(-1,cnt3));
    printf("%d %d\n",cnt2,cnt3);
  }else{
    dp[cnt]=0;
    qu.push(std::make_pair(0,cnt));
  }
  while(qu.size()>0){
    auto tp=qu.top().second;
    qu.pop();
    if(vised[tp]){
      continue;
    }
    vised[tp]=1;
    for(int i=1;i<=n;i++){
      if(temp[tp][i]=='1'){
        if(dp[tp]+2<dp[i]){
          dp[i]=dp[tp]+2;
          qu.push(std::make_pair(-dp[i],i));
          from[i]=tp;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(from[i]==0){
      continue;
    }
    printf("%d %d\n",i,from[i]);
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
