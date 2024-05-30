#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
class node{
  public:
    int x,y;
    node(int xx,int yy){
      x=xx;
      y=yy;
      return ;
    }
};
std::queue<node>qu;
std::queue<node>qu2;
int color[505][505];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("gomoku.in","r",stdin);
	freopen("gomoku.out","w",stdout);
	#endif
  int n=read(),m,k;
  m=read();
  k=read();
  if(k==1){
    printf("-1");
    return 0;
  }
  if(n==1){
    for(int i=1;i<=m;i++){
      printf("1 %d\n",i);
    }
    return 0;
  }
  if(m==1){
    for(int i=1;i<=n;i++){
      printf("%d 1\n",i);
    }
    return 0;
  }
  if(k<=2){
    printf("-1");
    return 0;
  }
  int add=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      color[i][j]=(i+(j/2))%2;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(color[i][j]){
        qu.push(node(i,j));
      }else{
        qu2.push(node(i,j));
      }
    }
  }
  while(qu.size()>0&&qu2.size()>0){
    printf("%d %d\n",qu.front().x,qu.front().y);
    qu.pop();
    printf("%d %d\n",qu2.front().x,qu2.front().y);
    qu2.pop();
  }
  if(qu.size()>0){
    printf("%d %d\n",qu.front().x,qu.front().y);
  }
  if(qu2.size()>0){
    printf("%d %d\n",qu2.front().x,qu2.front().y);
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


