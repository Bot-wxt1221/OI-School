#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int del[50];
int n;
int anss;
int ans[68000005];
std::vector<int>vec[50];
void dfs(int now,int sta,int ans){
  if(now==n+1){
    ::ans[sta]=ans;
    return ;
  }
  dfs(now+1,sta,ans);
  if(del[now]==0){
    for(int j=0;j<vec[now].size();j++){
      del[vec[now][j]]++;
    }
    dfs(now+1,sta|(1<<(now-1)),ans+1);
    for(int j=0;j<vec[now].size();j++){
      del[vec[now][j]]--;
    }
  }
  return ;
}
int lowbit(int x){
  return x&(-x);
}
signed main(){
//  #ifdef ONLINE_JUDGE
//  #else
  freopen("c2.in","r",stdin);
  freopen("set.out","w",stdout);
//  #endif
  n=read();
  int m=read();
  for(int i=1;i<=m;i++){
    int x=read()+1;
    int y=read()+1;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  dfs(1,0,0);
  for(int i=0;i<(1<<n);i++){
    int tt=i;
    if(ans[i]!=0){
      anss+=ans[i];
      continue;
    }
    int add=0;
    while(tt>0){
      int temp=lowbit(tt);
      tt-=lowbit(tt);
      ans[i]=std::max(ans[i],ans[tt+add]);
      add+=temp;
    }
    anss+=ans[i];
  }
  printf("%d",anss);
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


