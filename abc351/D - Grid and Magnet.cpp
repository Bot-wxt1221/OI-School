#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
inline int read();
char temp[1005][1005];
int yes[1005][1005];
bool vised[1005][1005];
int h,w;
std::vector<std::pair<int,int> >vec;
int cnt[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int bfs(int now,int ty,bool tx=0){
  std::queue<std::pair<int,int> >qu;
  qu.push(std::make_pair(now,ty));
  yes[now][ty]=2;
  int ans=0;
  while(qu.size()>0){
    ans++;
    auto tp=qu.front();
    qu.pop();
    for(int i=0;i<4;i++){
      int x=tp.first+cnt[i][0];
      int y=tp.second+cnt[i][1];
      if(x>h||y>w||x<=0||y<=0){
        continue;
      }
      if(yes[x][y]==1){
        ans++;
        yes[x][y]=2;
      }
      if(yes[x][y]){
        continue;
      }
      yes[x][y]=2;

      qu.push(std::make_pair(x,y));
    }
  }
  return ans;
}
void clear(int i,int j){
  yes[i][j]=yes[i+1][j]=yes[i-1][j]=yes[i][j+1]=yes[i][j-1]=1;
  yes[i][j]=2;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  h=read();
  w=read();
  for(int i=1;i<=h;i++){
    scanf("%s",temp[i]+1);
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(temp[i][j]=='#'){
        vec.push_back(std::make_pair(i,j));
        yes[i][j]=yes[i+1][j]=yes[i-1][j]=yes[i][j+1]=yes[i][j-1]=1;
        yes[i][j]=2;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(yes[i][j]){
        ans=std::max(ans,1);
        continue;
      }
      if(i==1&&j==4){
ans=std::max(bfs(i,j,1),ans);

        std::cerr<<1;
      }else{
      ans=std::max(bfs(i,j),ans);
      } 
      for(int ii=0;ii<vec.size();ii++){
        clear(vec[ii].first,vec[ii].second);
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

