#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <map>
inline int read();
std::map<int,int>mp[400005];
int a[400005];
int n;
int dfs(int now,int t,int id){
  if(now>n){
    return id;
  }
  if(mp[now][t]){
    return mp[now][t];
  }
  int l=a[now*2];
  int r=a[now*2+1];
  if(t<std::min(l,r)){
    return mp[now][t]=now;
  }
  if(l<r){
    return mp[now][t]=dfs(now*2,t,now);
  }else if(l<t){
    int lans=dfs(now*2,l,now);
    int rans=dfs(now*2+1,l,now);
    if(lans>rans){
      return mp[now][t]=dfs(now*2,t,now);
    }else{
      return mp[now][t]=dfs(now*2+1,t,now);
    }
  }else{
    return mp[now][t]=std::min(dfs(now*2,t,now),dfs(now*2+1,t,now));
  }
}
int ans(int now){
  if(now>n){
    return 0;
  }
  if(a[now]<std::min(a[now*2],a[now*2+1])){
    ans(now*2);
    ans(now*2+1);
    return 0;
  }
  if(a[now*2]<a[now*2+1]){
    std::swap(a[now],a[now*2]);
    ans(now*2);
    ans(now*2+1);
    return 0;
  }
  std::swap(a[now],a[now*2+1]);
  if(a[now*2]>a[now*2+1]){
    std::swap(a[now*2],a[now*2+1]);
  }
  if(dfs(now*2,a[now*2],now*2)>dfs(now*2+1,a[now*2],now*2+1)){
    std::swap(a[now*2],a[now*2+1]);
  }
  ans(now*2);
  ans(now*2+1);
  return 0;
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
    a[i+n]=0x3f3f3f3f;
  }
  a[n*2+1]=0x3f3f3f3f;
  ans(1);
  for(int i=1;i<=n;i++){
    printf("%d ",a[i]);
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

