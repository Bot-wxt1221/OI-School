#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
char str[10005][55];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2){
    return (1ll*pow(x,y-1)*x)%mod;
  }
  long long tt=pow(x,y/2);
  return (tt*tt)%mod;
}
int anscnt=0x3f3f3f3f;
int cntt=0;
int n,m;
int fa[105];
bool cho[105];
int getfa(int x){
  return x==fa[x]?fa[x]:fa[x]=getfa(fa[x]);
}
void dfs(int x,int y,int cnt){
  if(cnt>anscnt){
    return ;
  }
  if(y==m+1){
    dfs(x+1,1,cnt);
    return ;
  }
  if(x==n+1){
    for(int i=1;i<=n*m;i++){
      fa[i]=i;
    }
    int cntt=0;
    for(int i=1;i<=n;i++){
      bool y=0;
      for(int j=1;j<=m;j++){
        if(!cho[(i-1)*m+j]){
          continue;
        }
        if(!y){
          y=1;
          cntt++;
        }
        for(int k=i;k<=n;k++){
          if(!cho[(k-1)*m+j]){
            continue;
          }
          fa[getfa((i-1)*(m)+j)]=getfa((k-1)*(m)+j);
        }
        for(int k=j;k<=m;k++){
          if(!cho[(i-1)*m+k]){
            continue;
          }
          fa[getfa((i-1)*(m)+j)]=getfa((i-1)*(m)+k);
        }
      }
    }
    if(cntt<n){
      return ;
    }
    cntt=0;
    for(int i=1;i<=m;i++){
      int y=0;
      for(int j=1;j<=n;j++){
        if(!cho[(j-1)*(m)+i]){
          continue;
        }
        if(!y){
          cntt++;
          y=1;
        }
      }
    }
    if(cntt<m){
      return ;
    }
    int cnnt=0;
    for(int i=1;i<=n*m;i++){
      if(cho[i]&&fa[i]==i){
        cnnt++;
        if(cnnt>1){
          return ;
        }
      }
    }
    if(cnt<anscnt){
      anscnt=cnt;
      ::cntt=1;
    }else if(cnt==anscnt){
      ::cntt++;
    }
    return ;
  }
  if(str[x][y]=='#'){
    dfs(x,y+1,cnt);
  }else{
    dfs(x,y+1,cnt);
    cho[(x-1)*(m)+y]=1;
    dfs(x,y+1,cnt+1);
    cho[(x-1)*(m)+y]=0;
  }
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("connect.in","r",stdin);
  freopen("connect.out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",str[i]+1);
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(str[i][j]=='.'){
        cnt++;
      }
    }
  }
    dfs(1,1,0);
    printf("%d\n",cntt);
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


