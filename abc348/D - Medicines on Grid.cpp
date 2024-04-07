#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
char map[205][205];
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int x[505];
int now;
int dis[505][505];
int diss[305][205][205];
void add(int x,int y,int z){
  dis[x][y]=z;
  return ;
}
int y[505];
int ene[505];
int disss(int i,int x1,int y1,int x2,int y2){
  return diss[i][x2][y2];
}
std::queue<std::pair<int,int> > qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int h=read(),w;
  w=read();
  for(int i=1;i<=h;i++){
    scanf("%s",map[i]+1);
  }
  int n=read();
  for(int i=1;i<=n;i++){
    x[i]=read();
    y[i]=read();
    ene[i]=read();
  }
  int s,t;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(map[i][j]=='S'){
        x[++n]=i;
        y[n]=j;
        ene[n]=0;
        s=n;
      }else if(map[i][j]=='T'){
        x[++n]=i;
        y[n]=j;
        ene[n]=0;
        t=n;
      }
    }
  }
  memset(diss,0x3f,sizeof(diss));
  for(int ni=1;ni<=n;ni++){
    int i=x[ni];
    int j=y[ni];
    qu.push(std::make_pair(i,j));
    diss[ni][i][j]=0;
    while(qu.size()>0){
      std::pair<int,int> tp=qu.front();
      int cur=diss[ni][tp.first][tp.second];
      qu.pop();
      for(int i=0;i<4;i++){
        int nx=tp.first+to[i][0];
        int ny=tp.second+to[i][1];
        if(nx<1||ny<1||nx>h||ny>w||map[nx][ny]=='#'||diss[ni][nx][ny]!=0x3f3f3f3f){
          continue;
        }
        diss[ni][nx][ny]=std::min(diss[ni][nx][ny],cur+1);
        qu.push(std::make_pair(nx,ny));
      }
    }
  }
  memset(dis,0x3f,sizeof(dis));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(disss(i,x[i],y[i],x[j],y[j])<=ene[i]){ 
        add(i,j,0);
      }
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
      }
    }
  }
  if(dis[s][t]==0x3f3f3f3f){
    printf("No");
  }else{
    printf("Yes");
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

