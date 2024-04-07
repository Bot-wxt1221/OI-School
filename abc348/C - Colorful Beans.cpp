#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
inline int read();
std::vector<int>vec[200005];
std::map<int,int>mp;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    int x=read();
    int y=read();
    if(mp[y]==0){
      mp[y]=++cnt;
    }
    vec[mp[y]].push_back(x);
  }
  int mx=0;
  for(int i=1;i<=cnt;i++){
    std::sort(vec[i].begin(),vec[i].end());
    mx=std::max(mx,vec[i][0]);
  }
  printf("%d",mx);
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

