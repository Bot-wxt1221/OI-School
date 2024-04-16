#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <bitset>
inline int read();
char temp[805][805];
int sto[805][805];
int ans[805][805];
int dp[8005][8005];
class node{
  public:
    int num,tt,pos;
    node(int x=0,int z=0,int y=0){
      num=x;
      pos=y;
      tt=z;
      return ;
    }
};
bool operator < (node a,node b){
  return a.pos>b.pos;
}
class pos{
  public:
    int x,y;
    pos(int xx=0,int yy=0){
      x=xx;
      y=yy;
      return ;
    }
}st[8005];
int dis(pos a,pos b){
  return (std::abs(a.x-b.x)+std::abs(a.y-b.y));
}
int mabs(int x){
  if(x<0){
    return -x;
  }
  return x;
}
int too[8005][4];
int to[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("U.in","r",stdin);
  freopen("U.out","w",stdout);
  #endif
  int h=read(),w;
  w=read();
  int cnt=0;
  int s=0;
  for(int i=1;i<=h;i++){
    scanf("%s",temp[i]+1);
    int bf=-1;
    for(int j=1;j<=w;j++){
      if(temp[i][j]=='#'||temp[i][j]=='G'){
        if(bf!=-1){
          too[cnt+1][0]=bf;
          too[bf][1]=cnt+1;
        }
        if(temp[i][j]=='G'){
          s=cnt+1;
        }
        bf=cnt+1;
        sto[i][j]=cnt+1;
        st[++cnt]=pos(i,j);
      }
    }
  }
  for(int j=1;j<=w;j++){
    int bf=-1;
    for(int i=1;i<=h;i++){
      if(temp[i][j]=='#'||temp[i][j]=='G'){
        if(bf!=-1){
          too[sto[i][j]][2]=bf;
          too[bf][3]=sto[i][j];
        }
        bf=sto[i][j];
      }
    }
  }
  memset(dp,0x7f,sizeof(dp));
  memset(ans,0x7f,sizeof(ans));
  for(int ii=3508;ii;ii--){
    dp[s][ii]=0;
    for(int j=1;j<=cnt;j++){
      if(dp[j][ii]!=0x7f7f7f7f){
        node tp=node(j,ii,dp[j][ii]);
        for(int i=0;i<4;i++){
          if(too[tp.num][i]==0){
            continue;
          }
          int ndis=dp[tp.num][tp.tt]+(tp.tt-1)*(dis(st[tp.num],st[too[tp.num][i]]));
          int &odis=dp[too[tp.num][i]][tp.tt-1];
          if(odis>ndis){
            odis=ndis;
          }
        }
      }
    }
  }
  for(int i=1;i<=cnt;i++){
    ans[st[i].x][st[i].y]=std::min(ans[st[i].x][st[i].y],dp[i][1]);
    for(int x=st[i].x-1;x>=1;x--){
      if(temp[x][st[i].y]=='#'){
        break;
      }
      ans[x][st[i].y]=std::min(ans[x][st[i].y],dp[i][2]+mabs(st[i].x-x));
    }
    for(int x=st[i].x+1;x<=h;x++){
      if(temp[x][st[i].y]=='#'){
        break;
      }
      ans[x][st[i].y]=std::min(ans[x][st[i].y],dp[i][2]+mabs(st[i].x-x));
    }
    for(int y=st[i].y-1;y>=1;y--){
      if(temp[st[i].x][y]=='#'){
        break;
      }
      ans[st[i].x][y]=std::min(ans[st[i].x][y],dp[i][2]+mabs(st[i].y-y));
    }
    for(int y=st[i].y+1;y<=w;y++){
      if(temp[st[i].x][y]=='#'){
        break;
      }
      ans[st[i].x][y]=std::min(ans[st[i].x][y],dp[i][2]+mabs(st[i].y-y));
    }
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(ans[i][j]==0x7f7f7f7f){
        ans[i][j]=-1;
      }
      printf("%d ",ans[i][j]);
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

