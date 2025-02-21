#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
inline int read();
std::vector<std::pair<std::pair<int,int>,int> >vec[1000005];
bool sure[1000005];
int num[1000005];
std::priority_queue<std::pair<std::pair<int,int>,int > >qu;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    int u=read();
    int v=read();
    int l=read();
    int r=read();
    --r;
    int l1=l,l2=l,r1=r,r2=r;
    if(l%2==1){
      l1++;
    }
    else{
      l2++;
    }
    if(r%2==1){
      r1--;
    }
    else{
      r2--;
    }
    vec[u*2-1].push_back({{l1,r1},v*2});
    vec[u*2].push_back({{l2,r2},v*2-1});
    vec[v*2-1].push_back({{l1,r1},u*2});
    vec[v*2].push_back({{l2,r2},u*2-1});
  }
  for(int i=1;i<=2*n;i++){
    std::sort(vec[i].begin(),vec[i].end());
  }
  qu.push({{0,0},1});
  while(qu.size()>0){
    auto tp=qu.top();
    tp.first.first=-tp.first.first;
    if(tp.second==n*2-1||tp.second==n*2){
      printf("%d\n",-qu.top().first.first);
      return 0;
    }
    qu.pop();
    for(int i=num[tp.second];i<vec[tp.second].size();i++){
      if(vec[tp.second][i].first.first>tp.first.second){
        break;
      }
      num[tp.second]=i+1;
      if(tp.first.first<=vec[tp.second][i].first.second){
        qu.push({{-std::max(tp.first.first+1,vec[tp.second][i].first.first+1),vec[tp.second][i].first.second+1},vec[tp.second][i].second});
      }
    }
  }
  printf("-1");
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
