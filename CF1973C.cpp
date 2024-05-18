#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int a[100005];
int mod[100005];
std::vector<std::pair<int,int> > vec;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int ti=0;
    for(int i=1;i<=n;i++){
      a[i]=read();
      if(a[i]==1){
        ti=i;
      }
    }
    vec.clear();
    if(ti%2==1){
      for(int i=1;i<=n;i+=2){
        vec.push_back(std::make_pair(-a[i],i));
      }
      std::sort(vec.begin(),vec.end());
      int cnt=0;
      for(int i=0;i<vec.size();i++){
        mod[vec[i].second]=++cnt;
      }
      vec.clear();
      for(int i=2;i<=n;i+=2){
        vec.push_back(std::make_pair(-a[i],i));
      }
      std::sort(vec.begin(),vec.end());
      for(int i=0;i<vec.size();i++){
        mod[vec[i].second]=++cnt;
      }
      for(int i=1;i<=n;i++){
        printf("%d ",mod[i]);
      }
      printf("\n");
    }else{
      for(int i=2;i<=n;i+=2){
        vec.push_back(std::make_pair(-a[i],i));
      }
      std::sort(vec.begin(),vec.end());
      int cnt=0;
      for(int i=0;i<vec.size();i++){
        mod[vec[i].second]=++cnt;
      }
      vec.clear();
      for(int i=1;i<=n;i+=2){
        vec.push_back(std::make_pair(-a[i],i));
      }
      std::sort(vec.begin(),vec.end());
      for(int i=0;i<vec.size();i++){
        mod[vec[i].second]=++cnt;
      }
      for(int i=1;i<=n;i++){
        printf("%d ",mod[i]);
      }
      printf("\n");

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

