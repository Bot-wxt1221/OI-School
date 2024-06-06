#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
inline int read();
long long p[1000005];
int yes[1000005];
std::vector<int>r[1000005],u[1000005];
std::vector<std::pair<int,int> > vec[1000005];
std::queue<int>ok;
int cnt[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("learn.in","r",stdin);
  freopen("learn.out","w",stdout);
  #endif
  int n=read();
  int k=read();
  for(int i=1;i<=n;i++){
    r[i].resize(k+5);
    int cnt=0;
    for(int j=1;j<=k;j++){
      r[i][j]=read();
      vec[j].push_back(std::make_pair(r[i][j],i));
      if(r[i][j]==0){
        cnt++;
        yes[i]++;
      }
    }
    if(cnt==k){
      ok.push(i);
    }
  }
  for(int i=1;i<=k;i++){
    std::sort(vec[i].begin(),vec[i].end());
  }
  for(int i=1;i<=n;i++){
    u[i].resize(k+5);
    for(int j=1;j<=k;j++){
      u[i][j]=read();
    }
  }
  int cnt=0;
  while(ok.size()>0){
    int tp=ok.front();
    ok.pop();
    cnt++;
    for(int i=1;i<=k;i++){
      p[i]+=u[tp][i];
      while(::cnt[i]<vec[i].size()&&vec[i][::cnt[i]].first<=p[i]){
        yes[vec[i][::cnt[i]].second]++;
        if(yes[vec[i][::cnt[i]].second]==k){
          ok.push(vec[i][::cnt[i]].second);
        }
        ::cnt[i]++;
      }
    }
  }
  printf("%d",cnt);
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

