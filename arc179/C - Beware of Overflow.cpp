#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
inline int read();
bool cmp(int l,int r){
  printf("? %d %d\n",l,r);
  fflush(stdout);
  return read()%2;
}
int mrge(int l,int r){
  printf("+ %d %d\n",l,r);
  fflush(stdout);
  return read();
}
std::vector<int>vec[2];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int op=0;
  for(int i=1;i<=n;i++){
    vec[op].push_back(i);
  }
  std::stable_sort(vec[op].begin(),vec[op].end(),cmp);
  while(vec[op].size()>1){
    int tt=*vec[op].begin();
    int tt2=*(vec[op].end()-1);
    vec[op].pop_back();
    vec[op].erase(vec[op].begin());
    int tt3=mrge(tt,tt2);
    std::vector<int>::iterator tt4=std::lower_bound(vec[op].begin(),vec[op].end(),tt3,cmp);
    vec[op].insert(tt4,tt3);
  }
  printf("!\n");
  fflush(stdout);
  return 0;
}
inline int read(){
  int x;
  scanf("%d",&x);
  return x;
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

