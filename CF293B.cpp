#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int color[15][15];
int n,m;
int ans;
int k;
int used[15][15];
int usedc[15];
int dfs(int x,int y){
  if(y==m+1){
    return dfs(x+1,1);
  }
  if(x==n+1){
    return 1;
  }
  used[x][y]=used[x-1][y]|used[x][y-1];
  if(m-y+n-x>k-__builtin_popcount(used[x][y])){
    return 0;
  }
  if(color[x][y]){
    if(used[x][y]&(1ll<<color[x][y])){
      return 0;
    }
    int bk=used[x][y];
    usedc[color[x][y]]++;
    used[x][y]=used[x][y]|(1<<color[x][y]);
    int ret=dfs(x,y+1);
    used[x][y]=bk;
    usedc[color[x][y]]--;
    return ret;
  }
  int cnt=0,ret=-1;
  for(int i=1;i<=k;i++){
    if(used[x][y]&(1<<i)){
    }else if(!usedc[i]){
      if(ret!=-1){
        cnt+=ret;
        continue;
      }
      usedc[i]++;
      int bk=used[x][y];
      used[x][y]=(used[x][y])|(1<<i);
      ret=dfs(x,y+1);
      cnt+=ret;
      usedc[i]--;
      used[x][y]=bk;
    }else{
      int bk=used[x][y];
      usedc[i]++;
      used[x][y]=(used[x][y])|(1<<i);
      cnt+=dfs(x,y+1);
      used[x][y]=bk;
      usedc[i]--;
    }
  }
  return cnt;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  k=read();
  if(n+m-1>k){
    printf("0\n");
    return 0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      color[i][j]=read();
      usedc[color[i][j]]++;
    }
  }
  int ans=0;
  ans=dfs(1,1);
  printf("%lld",ans%1000000007);
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


