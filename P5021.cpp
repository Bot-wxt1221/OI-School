#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
inline int read();
std::deque<int>vec[50005];
int fir[50005];
int nxt[100005];
int v[100005];
int w[100005];
int dp[50005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int tt,cnt;
int m;
void dfs(int now,int fa){
  vec[now].clear();
  vec[now].push_back(0);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    vec[now].push_back(dp[v[i]]+w[i]);
  }
  std::sort(vec[now].begin(),vec[now].end());
  for(int i=vec[now].size()-1;i>=0;i--){
    if(vec[now][i]>=tt){
      cnt++;
    }else{
      break;
    }
    vec[now].pop_back();
  }
  int used=0;
  for(int i=0;i<vec[now].size();i++){
    auto ttt=std::lower_bound(vec[now].begin()+i+1,vec[now].end(),tt-vec[now][i]);
    if(ttt==vec[now].end()){
      continue;
    }
    used+=2;
    vec[now].erase(ttt);
    vec[now].erase(vec[now].begin()+i);
    i--;
    cnt++;
  }
  if(0!=vec[now].size()){
    dp[now]=vec[now].back();
  }else{
    dp[now]=0;
  }
  return ;
}
bool check(int ans){
  tt=ans;
  cnt=0;
  dfs(1,1);
  return cnt>=m;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  m=read();
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
  int l=0,r=0x3f3f3f3f;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      l=mid-1;
    }else{
      r=mid+1;
    }
  }
  for(int i=r;i>=l;i--){
    if(check(i)){
      printf("%d",i);
      return 0;
    }
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
