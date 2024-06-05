#include <bitset>
#include <cmath>
#include <iostream>
#include <cstdio>
inline int read();
int ans[2000005];
int seq[2000005];
int cntt=0,cnt=0;
int tcnt=0;
bool yes[2000005];
std::bitset<1505>vis[1505];
int n;
void dfs(int now){
  if(cnt>n){
    return ;
  }
  for(int i=vis[now]._Find_first();i<=tcnt;i=vis[now]._Find_first()){
    if(vis[now][i]==0){
      continue;
    }
    vis[now][i]=0;
    vis[i][now]=0;
    dfs(i);
  }
  if(cnt<=n){
    ans[++cnt]=now;
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  for(int i=2;i<=2000000;i++){
    if(yes[i]==0){
      seq[++cntt]=i;
      if(cntt>1417){
        break;
      }
      for(int j=2;j*i<=2000000;j++){
        yes[i*j]=1;
      }
    }
  }
  int T=read();
  while(T--){
    n=read();
    int ti=0;
    for(int i=1;;i++){
      int cnt=0;
      if(i%2==1){
        cnt=(i*(i+1))/2+1;
      }else{
        cnt=(i*(i+1))/2+1-(i-2)/2;
      }
      if(cnt>=n){
        ti=i;
        break;
      }
    }
    for(int i=1;i<=ti;i++){
      vis[i]=0;
      for(int j=1;j<=ti;j++){
        vis[i][j]=1;
      }
    }
    tcnt=ti;
    if(ti%2==0){
      for(int i=1;i<=(ti/2)-1;i++){
        vis[i*2][i*2+1]=0;
        vis[i*2+1][i*2]=0;
      }
    }
    cnt=0;
    dfs(1);
    for(int i=1;i<=n;i++){
      printf("%d ",seq[ans[i]]);
    }
    printf("\n");
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

