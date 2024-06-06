#include <iostream>
#include <cstdio>
#include <map>
inline int read();
std::map<int,int>mp[200005];
int a[200005];
int n;
int dfs(int now,int t){
  if(mp[now][t]){
    return mp[now][t];
  }
  int mn=t;
  if(now*2<=n){
    mn=std::min(mn,a[now*2]);
  }
  if(now*2+1<=n){
    mn=std::min(mn,a[now*2+1]);
  }
  if(mn==t){
    if(now*2<=n){
      dfs(now*2,a[now*2]);
    }
    if(now*2+1<=n){
      dfs(now*2+1,a[now*2+1]);
    }
  }else{

  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
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

