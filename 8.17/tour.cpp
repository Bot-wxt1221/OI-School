#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <bitset>
inline int read();
std::bitset<200005> vised[2][2];
long long dp[200005][2][2];
int now;
std::vector<std::pair<int,int> >vec[200005];
void add(int x,int y,int z){
  vec[x].push_back(std::make_pair(y,z));
  return ;
}
std::priority_queue<std::pair<long long,std::pair<int,int> > >qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tour.in","r",stdin);
  freopen("tour.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    int u=read();
    int v=read();
    int w=read();
    add(u,v,w);
    add(v,u,w);
  }
  memset(dp,0x3f,sizeof(dp));
  dp[1][0][0]=0;
  qu.push({0,{1,0}});
  while(qu.size()>0){
    auto tp=qu.top().second;
    qu.pop();
    int cur=tp.first;
    int first=(tp.second>>1)&1;
    int second=(tp.second)&1;
    if(vised[first][second][cur]){
      continue;
    }
    vised[first][second][cur]=1;
    for(int i=0;i<vec[cur].size();i++){
      for(int tf=first;tf<=1;tf++){
        for(int ts=second;ts<=1;ts++){
          long long nw=dp[cur][first][second]+vec[cur][i].second;
          if(tf!=first){
            nw-=vec[cur][i].second;
          }
          if(ts!=second){
            nw+=vec[cur][i].second;
          }
          if(nw<dp[vec[cur][i].first][tf][ts]){
            dp[vec[cur][i].first][tf][ts]=nw;
            qu.push({-dp[vec[cur][i].first][tf][ts],{vec[cur][i].first,(tf<<1)|ts}});
          }
        }
      }
    }
  }
  for(int i=2;i<=n;i++){
    printf("%lld ",dp[i][1][1]);
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
