#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
class node{
  public:
    int a,c;
    node(int x=0,int y=0){
      a=x;
      c=y;
      return ;
    }
}no[200005];
bool yes[200005];
bool operator < (node a,node b){
  return a.c<b.c;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    no[i].a=read();
    no[i].c=read();
  }
  std::sort(no+1,no+n+1);
  int min=0x3f3f3f3f;
  int cnt=0;
  for(int i=n;i>=1;i--){
    if(no[i].a>min){
      continue;
    }
    min=std::min(min,no[i].a);
    yes[i]=1;
    cnt++;
  }
  printf("%d\n",cnt);
  for(int i=1;i<=n;i++){
    if(yes[i]){
      printf("%d ",i);
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
