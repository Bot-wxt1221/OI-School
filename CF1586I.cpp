#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
inline int read();
char temp[2005][2005];
char temp2[2005][2005];
char ans[2005][2005];
std::vector<std::pair<std::pair<int,int>,int> >vec;
int solve(int n){
  bool mul=0;
  for(int i=2;i<=n;i+=2){
    int cnt=0;
    vec.clear();
    for(int j=i;j<=n;j++){
      vec.push_back(std::make_pair(std::make_pair(j-i+1,j),cnt^=1));
    }
    int nx=n;
    int ny=n-i+2;
    cnt^=1;
    for(int j=ny;j<=nx;j++){
      vec.push_back(std::make_pair(std::make_pair(j,nx+ny-j),cnt^=1));
    }
    cnt^=1;
    for(int j=n;j>=i;j--){
      vec.push_back(std::make_pair(std::make_pair(j,j-i+1),cnt^=1));
    }
    cnt^=1;
    for(int j=i-1;j>=1;j--){
      vec.push_back(std::make_pair(std::make_pair(j,i-j),cnt^=1));
    }
    int ans=-1;
    for(int j=0;j<vec.size();j++){
      int x=vec[j].first.first;
      int y=vec[j].first.second;
      if(temp[x][y]!='.'){
        int nw=(temp[x][y]=='G')^vec[j].second;
        if(ans==-1||nw==ans){
          ans=nw;
        }else{
          return 0;
        }
      }
    }
    if(ans==-1){
      mul=1;
    }
    for(int j=0;j<vec.size();j++){
      int x=vec[j].first.first;
      int y=vec[j].first.second;
      ::ans[x][y]=(ans^(vec[j].second))?'G':'S';
    }
  }
  if(mul){
    return 2;
  }
  return 1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  if(n%2==1){
    printf("NONE\n");
    return 0;
  }
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  int ret=solve(n);
  if(ret==0){
    printf("NONE\n");
  }else if(ret==1){
    printf("UNIQUE\n");
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        printf("%c",ans[i][j]);
      }
      printf("\n");
    }
  }else{
    printf("MULTIPLE\n");
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
