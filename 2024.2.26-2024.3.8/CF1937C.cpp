#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
inline int read();
std::vector<int>vec;
char query(int x,int y,int a,int b){
  printf("? %d %d %d %d\n",x-1,y-1,a-1,b-1);
  fflush(stdout);
  char tt;
  std::cin>>tt;
  return tt;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    vec.clear();
    int n=read();
    int mx=1;
    for(int i=2;i<=n;i++){
      if(query(mx,mx,i,i)=='<'){
        mx=i;
      }
    }
    int lg=std::log2(n);
    int mx2=1;
    vec.push_back(1);
    for(int i=2;i<=n;i++){
      if(i==mx){
        continue;
      }
      char ret=query(mx2,mx,i,mx);
      if(ret=='='){
        vec.push_back(i);
      }else if(ret=='<'){
        mx2=i;
        vec.clear();
        vec.push_back(mx2);
      }
    }
    mx2=vec[0];
    for(int i=1;i<vec.size();i++){
      if(query(mx2,mx2,vec[i],vec[i])=='>'){
        mx2=vec[i];
      }
    }
    printf("! %d %d\n",mx-1,mx2-1);
    fflush(stdout);
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


