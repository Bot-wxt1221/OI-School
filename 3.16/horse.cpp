#include <iostream>
#include <cstdio>
inline int read();
bool vised[10005][10005];
int now=0;
bool ans=0;
int xx[10005];
int yy[10005];
int to[10][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int n;
int add;
bool virt;
int tox,toy;
void dfs(int x,int y){
  if(ans){
    return ;
  }
  if(vised[x][y]){
    return ;
  }
  xx[now]=x;
  yy[now]=y;
  vised[x][y]=1;
  if(now==n*4){
    if(xx[n*4]!=tox||yy[n*4]!=toy){
      vised[x][y]=0;
      return ;
    }
    ans=1;
    for(int i=1;i<=n*4;i++){
      if(virt){
        xx[i]=5-xx[i];
      }
      printf("%d %d\n",xx[i],yy[i]+add);
      if(virt){
        xx[i]=5-xx[i];
      }
    }
    vised[x][y]=0;
    return ;
  }
  for(int i=0;i<8;i++){
    int tx=x+to[i][0];
    int ty=y+to[i][1];
    if(tx<=0||tx>4||ty<=0||ty>n){
      continue;
    }
    now++;
    dfs(tx,ty);
    now--;
  }
  vised[x][y]=0;
  return ;
}
int ans8[][2]={{1,2},{3,3},{4,1},{2,2},{1,4},{3,5},{1,6},{2,8},{4,7},{2,6},{1,8},{3,7},{4,5},{2,4},{4,3},{3,1},{2,3},{4,4},{2,5},{4,6},{3,8},{1,7},{3,6},{4,8},{2,7},{1,5},{3,4},{4,2},{2,1},{1,3},{3,2},{1,1}};
int ans3[][2]={{1,1},{3,2},{1,3},{2,1},{4,2},{2,3}};
int ans4[][2]={{3,3},{1,2},{3,1},{4,3},{2,2},{4,1}};
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("horse.in","r",stdin);
  freopen("horse.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    ans=0;
    add=0;
    if(n<=2||n==4){
      printf("No\n");
      continue;
    }
    printf("Yes\n");
    if(n==3){
      ans=0;
      tox=4;
      toy=2;
      now=1;
      dfs(1,2);
      continue;
    }
    int cnt=0;
    while(n>7){
      for(int i=0;i<6;i++){
        if(virt){
          ans3[i][0]=5-ans3[i][0];
        }
        printf("%d %d\n",ans3[i][0],ans3[i][1]+add);
        if(virt){
          ans3[i][0]=5-ans3[i][0];
        }
      }
      add+=3;
      n-=3;
      cnt++;
      virt^=1;
    }
    tox=4;
    toy=1;
    if(n<=7){
      for(int i=1;i<=1;i++){
        for(int j=1;j<=1;j++){
          now=1;
          dfs(i,j);
          if(ans){
            break;
          }
        }
        if(ans){
          break;
        }
      }
      if(!ans){
        printf("No\n");
      }
    }else if(n==8){
      for(int i=0;i<32;i++){
        if(virt){
          ans8[i][0]=5-ans8[i][0];
        }
        printf("%d %d\n",ans8[i][0],ans8[i][1]+add);
      }
    }
    while(cnt--){
      add-=3;
      virt^=1;
      for(int i=0;i<6;i++){
        if(virt){
          ans4[i][0]=5-ans4[i][0];
        }
        printf("%d %d\n",ans4[i][0],ans4[i][1]+add);
        if(virt){
          ans4[i][0]=5-ans4[i][0];
        }
      }
    }
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


