#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
inline int read();
int line[100005];
int hang[100005];
std::vector<int>ans[100005];
class node{
  public:
    int x,y;
};
bool operator <(node a,node b){
  return a.y>b.y;
}
std::priority_queue<node>qu;
std::vector<node>lef;
std::map<int,int>mp[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int k=0;
  for(int i=1;i<=m;i++){
    int a=read();
    int b=read();
    line[a]++;
    hang[b]++;
    mp[a][b]=1;
    k++;
    ans[a].push_back(b);
  }
  for(int i=1;i<=n;i++){
    if(hang[i]!=m){
      qu.push(node({i,hang[i]}));
    }
  }
  for(int i=1;i<=n;i++){
    lef.clear();
    while(line[i]!=m){
      auto cur=qu.top();
      if(hang[cur.x]==m){
        qu.pop();
        continue;
      }
      if(mp[i][cur.x]){
        lef.push_back(cur);
        qu.pop();
        continue;
      }
      hang[cur.x]++;
      ans[i].push_back(cur.x);
      line[i]++;
      k++;
      lef.push_back(cur);
      qu.pop();
    }
    for(int ii=0;ii<lef.size();ii++){
      if(hang[lef[ii].x]!=m){
        qu.push(node({lef[ii].x,hang[lef[ii].x]}));
      }
    }
  }
  printf("%d\n",k);
  for(int i=1;i<=n;i++){
    for(int j=0;j<ans[i].size();j++){
      printf("%d %d\n",i,ans[i][j]);
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

