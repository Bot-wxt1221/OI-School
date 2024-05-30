#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
inline int read();
int to2[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char temp[505][505];
bool yes[505*505+5];
int dp[505*505+5];
int t1[505][505];
int t2[505][505];
int t3[505][505];
int t4[505][505];
int dis1[505][505];
int dis2[505][505];
int dis3[505][505];
int dis4[505][505];
std::priority_queue<std::pair<int,int> >qu;
int to(int x,int y){
  return (x-1)*501+y;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("aisle.in","r",stdin);
  freopen("aisle.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int s=0;
  int t=0;
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  memset(dp,0x3f,sizeof(dp));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(temp[i][j]=='C'){
        dp[to(i,j)]=0;
        s=to(i,j);
      }
      if(temp[i][j]=='F'){
        t=to(i,j);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(temp[i][j-1]=='#'){
        t1[i][j]=to(i,j);
        dis1[i][j]=0;
      }else{
        t1[i][j]=t1[i][j-1];
        dis1[i][j]=dis1[i][j-1]+1;
      }
      if(temp[i-1][j]=='#'){
        t2[i][j]=to(i,j);
        dis2[i][j]=0;
      }else{
        t2[i][j]=t2[i-1][j];
        dis2[i][j]=dis2[i-1][j]+1;
      }
    }
  }
  for(int i=n;i>=1;i--){
    for(int j=m;j>=1;j--){
      if(temp[i][j+1]=='#'){
        t3[i][j]=to(i,j);
        dis3[i][j]=0;
      }else{
        t3[i][j]=t3[i][j+1];
        dis3[i][j]=dis3[i][j+1]+1;
      }
      if(temp[i+1][j]=='#'){
        t4[i][j]=to(i,j);
        dis4[i][j]=0;
      }else{
        t4[i][j]=t4[i+1][j];
        dis4[i][j]=dis4[i+1][j]+1;
      }
    }
  }
  qu.push(std::make_pair(0,s));
  while(qu.size()>0){
    int tp=qu.top().second;
    qu.pop();
    if(yes[tp]){
      continue;
    }
    yes[tp]=1;
    for(int i=0;i<4;i++){
      int nx=tp/501+to2[i][0]+1;
      int ny=tp%501+to2[i][1];
      if(nx<=0||ny<=0||nx>n||ny>m||temp[nx][ny]=='#'){
        continue;
      }
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+1);
      if(dp[tp]+1==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }
    int xx=tp/501+1;
    int yy=tp%501;
    int mn=std::min(std::min(dis1[xx][yy],dis2[xx][yy]),std::min(dis3[xx][yy],dis4[xx][yy]));
    if(dis1[xx][yy]!=mn){
      int nx=t1[xx][yy]/501+1;
      int ny=t1[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn+1);
      if(dp[tp]+mn+1==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }else{
      int nx=t1[xx][yy]/501+1;
      int ny=t1[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn);
      if(dp[tp]+mn==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }
    if(dis2[xx][yy]!=mn){
      int nx=t2[xx][yy]/501+1;
      int ny=t2[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn+1);
      if(dp[tp]+mn+1==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }else{
      int nx=t2[xx][yy]/501+1;
      int ny=t2[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn);
      if(dp[tp]+mn==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }
    if(dis3[xx][yy]!=mn){
      int nx=t3[xx][yy]/501+1;
      int ny=t3[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn+1);
      if(dp[tp]+mn+1==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }else{
      int nx=t3[xx][yy]/501+1;
      int ny=t3[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn);
      if(dp[tp]+mn==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }
    if(dis4[xx][yy]!=mn){
      int nx=t4[xx][yy]/501+1;
      int ny=t4[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn+1);
      if(dp[tp]+mn+1==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }else{
      int nx=t4[xx][yy]/501+1;
      int ny=t4[xx][yy]%501;
      dp[to(nx,ny)]=std::min(dp[to(nx,ny)],dp[tp]+mn);
      if(dp[tp]+mn==dp[to(nx,ny)]){
        qu.push(std::make_pair(-dp[to(nx,ny)],to(nx,ny)));
      }
    }
  }
  if(dp[t]==0x3f3f3f3f){
    printf("nemoguce");
    return 0;
  }
  printf("%d",dp[t]);
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

