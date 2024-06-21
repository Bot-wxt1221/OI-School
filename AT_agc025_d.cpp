#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdio>
inline int read();
int color1[605][605];
int color2[605][605];
int fir[10000005];
int nxt[10000005];
int v[10000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
bool vised[610*610];
void dfs(int now,int fa,int color[605][605]){
  if(vised[now]){
    return ;
  }
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    color[v[i]/608+1][v[i]%608]=color[now/608+1][now%608]^1;
    dfs(v[i],now,color);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int d1=read();
  int d2=read();
  memset(fir,-1,sizeof(fir));
  for(int i=1;i<=n*2;i++){
    for(int j=1;j<=n*2;j++){
      for(int k=i;k<=n*2;k++){
        int tt=d1-(k-i)*(k-i);
        if(tt>=0){
          int tt2=std::sqrt(tt);
          if(tt2*tt2==tt){
            if((j-tt2)>0){
//              color1[k][j-tt2]=color1[i][j]^1;
              add((k-1)*608+(j-tt2),(i-1)*608+(j));
              add((i-1)*608+(j),(k-1)*608+(j-tt2));
            }
            if(j+tt2<=2*n){
              add((k-1)*608+(j+tt2),(i-1)*608+(j));
              add((i-1)*608+(j),(k-1)*608+(j+tt2));
            }
          }
        }
      }
    }
  }
  for(int i=1;i<=n*2;i++){
    for(int j=1;j<=n*2;j++){
      dfs((i-1)*608+j,(i-1)*608+j,color1);
    }
  }
  memset(fir,-1,sizeof(fir));
  memset(vised,0,sizeof(vised));
  now=0;
  for(int i=1;i<=n*2;i++){
    for(int j=1;j<=n*2;j++){
      for(int k=i;k<=n*2;k++){
        int tt=d2-(k-i)*(k-i);
        if(tt>=0){
          int tt2=std::sqrt(tt);
          if(tt2*tt2==tt){
            if((j-tt2)>0){
//              color1[k][j-tt2]=color1[i][j]^1;
              add((k-1)*608+(j-tt2),(i-1)*608+(j));
              add((i-1)*608+(j),(k-1)*608+(j-tt2));
            }
            if(j+tt2<=2*n){
              add((k-1)*608+(j+tt2),(i-1)*608+(j));
              add((i-1)*608+(j),(k-1)*608+(j+tt2));
            }
          }
        }
      }
    }
  }
  for(int i=1;i<=n*2;i++){
    for(int j=1;j<=n*2;j++){
      dfs((i-1)*608+j,(i-1)*608+j,color2);
    }
  }
  for(int a=0;a<=1;a++){
    for(int b=0;b<=1;b++){
      int cnt=0;
      for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*n;j++){
          if(color1[i][j]==a&&color2[i][j]==b){
            cnt++;
          }
        }
        if(cnt>=n*n){
          cnt=n*n;
          for(int i=1;i<=2*n;i++){
            for(int j=1;j<=2*n;j++){
              if(cnt==0){
                goto end;
              }
              if(color1[i][j]==a&&color2[i][j]==b){
                cnt--;
                printf("%d %d\n",i-1,j-1);
              }            
            }
          }
          end:{}
          return 0;
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
