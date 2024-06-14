#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int v[2000005];
std::vector<int>ans;
std::vector<int>vec[4000005];
int n;
void dfs(int now,int sta,int dep){
  //no i
  if(dep==n){
    if(vec[now][0]==0){
    }else{
      ans.push_back(sta);
    }
    return ;
  }
  vec[now*2].resize((1<<(n-dep-1)));
  for(int i=0;i<(1<<(n-dep-1));i++){
    vec[now*2][i]=vec[now][i<<1]&vec[now][(i<<1)+1];
  }
  dfs(now*2,sta,dep+1);
  vec[now*2+1].resize((1<<(n-dep-1)));
  for(int i=0;i<(1<<(n-dep-1));i++){
    vec[now*2+1][i]=vec[now][i<<1]&(vec[now][(i<<1)+1]>>1);
  }
  dfs(now*2+1,sta|(1<<dep),dep+1);
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  vec[1].push_back(1);
  for(int i=1;i<(1<<n);i++){
    vec[1].push_back(read());
  }
  dfs(1,0,0);
  printf("%lu\n",ans.size());
  std::sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    printf("%d\n",ans[i]);
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

