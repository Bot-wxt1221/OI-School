#include <iostream>
#include <cstdio>
inline int read();
int map[45][45];
int rans=0x3f3f3f3f;
bool l[45];
int n;
void dfs(int now,int ans){
  if(ans>=rans){
    return ;
  }
  if(now==0){
    rans=std::min(rans,ans);
    return ;
  }
  if(map[now][now]){
    int v=map[now][n+1];
    for(int i=now+1;i<=n;i++){
      if(map[now][i]){
        v^=l[i];
      }
    }
    dfs(now-1,ans+v);
  }else{
    dfs(now-1,ans);
    l[now]=1;
    dfs(now-1,ans+1);
    l[now]=0;
  }
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    map[i][i]=1;
    map[i][n+1]=1;
  }
  for(int i=1;i<=m;i++){
    int a=read();
    int b=read();
    map[a][b]=map[b][a]=1;
  }
  for(int i=1;i<=n;i++){
    int r=i;
    while(r<=n&&map[r][i]==0){
      r++;
    }
    if(r>n){
      continue;
    }
    for(int j=1;j<=n+1;j++){
      std::swap(map[i][j],map[r][j]);
    }
    for(int j=1;j<=n;j++){
      if(i!=j&&map[j][i]){
        for(int k=1;k<=n+1;k++){
          map[j][k]^=map[i][k];
        }
      }
    }
  }
  dfs(n,0);
  printf("%d",rans);
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


