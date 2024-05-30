#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int long long
inline int read();
int map[1005][1005];
class node{
  public:
    int x,y,ans;
    node(int xx,int yy,int aa){
      x=xx;
      y=yy;
      ans=aa;
      return ;
    }
};
int to[10][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,2}};
std::queue<node>qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("jump.in","r",stdin);
  freopen("jump.out","w",stdout);
  #endif
  int T=read();
  memset(map,0x3f,sizeof(map));
  qu.push(node(0,0,0));
  map[0][0]=0;
  while(qu.size()>0){
    node tt=qu.front();
    qu.pop();
    if(tt.ans!=map[tt.x][tt.y]){
      continue;
    }
    for(int k=0;k<8;k++){
      int tx=tt.x+to[k][0];
      int ty=tt.y+to[k][1];
      if(tx<0||ty<0||tx>15||ty>15){
        continue;
      }
      map[tx][ty]=std::min(map[tx][ty],map[tt.x][tt.y]+1);
      if(map[tx][ty]==map[tt.x][tt.y]+1){
        qu.push(node(tx,ty,map[tx][ty]));
      }
    }
  }
  while(T--){
    int a=read();
    if(a<0){
      a=-a;
    }
    int b=read();
    if(b<0){
      b=-b;
    }
    int ans=0;
    while(a>=15||b>=15){
      if(a>b){
        std::swap(a,b);
      }
      if(a==b){
        int cu=((a-8)/3);
        ans+=std::min((a-8)/3,(b-8)/3)*2;
        a-=cu*3;
        b-=cu*3;
        goto end;
      }
      if(a==0){
        int cu=(b-8)/4;
        b-=cu*4;
        ans+=cu*2;
        goto end;
      }
      if(a<b){
        int cu=std::min(std::min(b-a,a),(b-8)/2);
        ans+=cu;
        a-=cu;
        b-=cu*2;
      }
      end:{}
    }
    ans+=map[a][b];
    printf("%lld\n",ans);
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



