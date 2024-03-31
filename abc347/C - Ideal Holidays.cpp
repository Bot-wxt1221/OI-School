#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
inline int read();
std::vector<int>qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int a=read();
  int b=read();
  int ll=0;
  int rr=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    int tt=read();
    tt%=(a+b);
    qu.push_back(tt);
  }
  std::sort(qu.begin(),qu.end());
  for(int i=0;i<qu.size()-1;i++){
    if(qu[i]+1+(a+b-qu[i+1])<=a){
      printf("Yes");
      return 0;
    }
  }
  if(qu[qu.size()-1]-qu[0]+1<=a){
    printf("Yes");
    return 0;
  }
  printf("No");
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

