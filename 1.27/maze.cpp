#include <iostream>
#include <cstdio>
#include <queue>
#define mod 1000000007
inline int read();
class node{
  public:
    int x,y,data;
    node(int xx=0,int yy=0,int zz=0){
      x=xx;
      y=yy;
      data=zz;
      return ;
    }
};
bool operator < (node a,node b){
  return a.data>b.data;
}
std::priority_queue<node>qu;
int mp[1005][1005];
int dp[1005][1005][5];
bool end[1005][1005];
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      mp[i][j]=read();
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      qu.push(node(i,j,mp[i][j]));
      dp[i][j][1]=1;
      end[i][j]=1;
      for(int k=0;k<4;k++){
        int tx=i+to[k][0];
        int ty=j+to[k][1];
        if(tx<=0||ty<=0||tx>n||ty>m){
          continue;
        }
        if(mp[tx][ty]+2==mp[i][j]){
          dp[i][j][1]=0;
        }
        if(mp[tx][ty]==mp[i][j]+2){
          end[i][j]=0;
        }
      }
    }
  }
  while(qu.size()>0){
    node tp=qu.top();
    qu.pop();
    for(int k=0;k<4;k++){
      int tx=tp.x+to[k][0];
      int ty=tp.y+to[k][1];
      if(tx<=0||ty<=0||tx>n||ty>m){
        continue;
      }
      if(mp[tx][ty]==mp[tp.x][tp.y]+2){
        for(int kk=1;kk<4;kk++){
          dp[tx][ty][kk+1]+=dp[tp.x][tp.y][kk];
          dp[tx][ty][kk+1]%=mod;
        }
        dp[tx][ty][4]+=dp[tp.x][tp.y][4];
        dp[tx][ty][4]%=mod;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(end[i][j]){
        ans+=dp[i][j][4];
        ans%=mod;
      }
    }
  }
  printf("%d",ans);
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


