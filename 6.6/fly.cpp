#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define int long long
inline int read();
int fir[200005];
int nxt[800005];
int v[800005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int a[200005];
int aa[200005];
std::priority_queue<std::pair<int,std::pair<int,int> > >qu;
bool vised[2005][2045];
int dp[2005][2045];
int n;
int calc(){
  memset(dp,0x3f,sizeof(dp));
  memset(vised,0,sizeof(vised));
  dp[1][0]=0;
  qu.push(std::make_pair(0,std::make_pair(1,0)));
  while(qu.size()>0){
    auto tp=qu.top().second;
    qu.pop();
    if(tp.second<0||tp.second>2040){
      continue;
    }
    if(vised[tp.first][tp.second]){
      continue;
    }
    vised[tp.first][tp.second]=1;
    for(int i=fir[tp.first];i!=-1;i=nxt[i]){
      if(a[v[i]]<=tp.second+1){
        int &up=dp[v[i]][tp.second+1];
        if(up>dp[tp.first][tp.second]+1){
          up=dp[tp.first][tp.second]+1;
          qu.push(std::make_pair(-up,std::make_pair(v[i],tp.second+1)));
        }
      }
      if(a[v[i]]<=tp.second){
        int &up=dp[v[i]][tp.second];
        if(up>dp[tp.first][tp.second]+1){
          up=dp[tp.first][tp.second]+1;
          qu.push(std::make_pair(-up,std::make_pair(v[i],tp.second)));
        }
      }
      if(a[v[i]]<=tp.second-1){
        int &up=dp[v[i]][tp.second-1];
        if(up>dp[tp.first][tp.second]+1){
          up=dp[tp.first][tp.second]+1;
          qu.push(std::make_pair(-up,std::make_pair(v[i],tp.second-1)));
        }
      }
    }
  }
  return dp[n][0];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("fly.in","r",stdin);
  freopen("fly.out","w",stdout);
  #endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    aa[i]=a[i];
    fir[i]=-1;
  }
  bool yes=1;
  for(int i=1;i<=m;i++){
    int u=read();
    int v=read();
    add(u,v);
    add(v,u);
    if(u!=i||v!=i+1){
      yes=0;
    }
  }
  for(int i=1;i<=n;i++){
    add(i,i);
  }
  if(yes&&m==n-1){
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
      ans1=std::max(ans1,a[i]-i+1);
      ans2=std::max(ans2,a[i]-(n-i+1)+1);
    }
    printf("%lld",ans1+ans2+(n-1));
  }else{
    std::sort(aa+1,aa+n+1);
    int ans=calc();
    printf("%lld",ans);
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

