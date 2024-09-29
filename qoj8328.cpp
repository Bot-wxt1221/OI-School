#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
std::pair<int,int> a[1005];
int b[1005];
std::vector<std::pair<int,int>>vec;
void dfs(int l,int r){
  if(l>r){
    return ;
  }
  if(l==r){
    while(b[l]<a[l].first){
      b[l]++;
      vec.push_back({2,a[l].second});
    }
    return ;
  }
  if(b[l]<a[l].first){
    for(int i=l;i<=r;i++){
      vec.push_back({2,a[i].second});
      b[i]++;
    }
    int cnt=0;
    while(b[l]<a[l].first){
      vec.push_back({1,b[l]});
      b[l]++;
      cnt++;
    }
    for(int i=l+1;i<=r;i++){
      b[i]+=cnt;
    }
  }
  int mid=(l+r)/2;
  dfs(mid+1,r);
  dfs(l,mid);
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
    a[i].first=read();
    a[i].second=i;
  }
  std::sort(a+1,a+n+1);
  dfs(1,n);
  printf("%lu\n",vec.size());
  for(int i=0;i<vec.size();i++){
    printf("%d %d\n",vec[i].first,vec[i].second);
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
