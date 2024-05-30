#include <iostream>
#include <cstdio>
inline int read();
int map[405][405];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  #endif
  int n=read();
  int t=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      map[i][j]=0x3f3f3f3f;
    }
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    map[x][y]=map[y][x]=1;
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        map[i][j]=std::min(map[i][j],map[i][k]+map[k][j]);
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      for(int k=j+1;k<=n;k++){
        if(map[i][j]<=t&&map[j][k]<=t&&map[i][k]<=t){
          ans++;
        }
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

