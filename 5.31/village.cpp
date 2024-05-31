#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#define int long long
std::queue<std::pair<int,int> >qu;
inline int read();
std::vector<std::pair<int,int>>vec[305][305];
char temp[305][305];
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char temp2[305][305];
bool vised[305][305];
int sum[305];
int sum2[305];
int n,m;
int cnt=0;
int second(int n,int m){
  int ans=0;
  for(int i=1;i<=n;i++){
    memset(sum,0,sizeof(sum));
    for(int i2=i;i2<=n;i2++){
      for(int j=1;j<=m;j++){
        sum[j]+=temp[i2][j]-'0';
        sum2[j]=sum2[j-1]+sum[j];
      }
      for(int j=1;j<=m;j++){
        int tp2=std::lower_bound(sum2+j,sum2+m+1,sum2[j-1]+1)-sum2;
        int tp=std::upper_bound(sum2+j,sum2+m+1,sum2[j-1]+1)-sum2-1;
        ans+=tp-tp2+1;
      }
    }
  }
  return ans;
}
void bfs(int x,int y){
  if(vised[x][y]){
    return ;
  }
  vised[x][y]=1;
  qu.push(std::make_pair(x,y));
  cnt++;
  while(qu.size()>0){
    auto tp=qu.front();
    qu.pop();
    for(int i=0;i<4;i++){
      int nx=tp.first+to[i][0];
      int ny=tp.second+to[i][1];
      if(nx<1||ny<1||nx>n||ny>m||vised[nx][ny]||temp2[x][y]!=temp2[nx][ny]){
        continue;
      }
      vised[nx][ny]=1;
      cnt++;
      qu.push(std::make_pair(nx,ny));
    }
  }
  return ;
}
int calc(int x,int x2,int y,int y2){
  for(int i=x;i<=x2;i++){
    for(int j=y;j<=y2;j++){
      temp2[i-x+1][j-y+1]=temp[i][j];
      vised[i-x+1][j-y+1]=0;
    }
  }
  n=x2-x+1;
  m=y2-y+1;
  cnt=0;
  for(int i=y;i<=y2;i++){
    if(temp2[1][i-y+1]=='0'){
      bfs(1,i-y+1);
    }
    if(temp2[n][i-y+1]=='0'){
      bfs(n,i-y+1);
    }
  }
  for(int i=x;i<=x2;i++){
    if(temp2[i-x+1][1]=='0'){
      bfs(i-x+1,1);
    }
    if(temp2[i-x+1][m]=='0'){
      bfs(i-x+1,m);
    }
  }
  for(int i=x;i<=x2;i++){
    for(int j=y;j<=y2;j++){
      if(temp[i][j]=='1'){
        bfs(i-x+1,j-y+1);
        goto end;
      }
    }
  }
  return 0;
  end:{};
  return cnt==n*m;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("village.in","r",stdin);
  freopen("village.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int ans=0;
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  if(n>25){
    printf("%lld",second(n,m));
    return 0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      for(int k=i;k<=n;k++){
        for(int k2=j;k2<=m;k2++){
          ans+=calc(i,k,j,k2);
        }
      }
    }
  }
  
  printf("%lld",ans);
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

