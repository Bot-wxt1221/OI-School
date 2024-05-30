#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int fir[25];
int map[25][25];
int nxt[200005];
int u[200005];
int v[200005];
int w[200005];
int in[25];
int dp[(1<<20)+5];
int now;
void add(int x,int y,int z){
  in[y]++;
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int lowbit(int x){
  return x&(-x);
}
int cnt[(1<<20)+5];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    cnt[(1<<i)]=i;
  }
  memset(map,0x3f,sizeof(map));
  int ans=0;
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int z=read();
    ans+=z;
    add(x,y,z);
    add(y,x,z);
    map[x][y]=map[y][x]=std::min(map[x][y],z);
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        map[i][j]=std::min(map[i][j],map[i][k]+map[k][j]);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j&&map[i][j]==0x3f3f3f3f3f3f3f3f){
        printf("-1");
        return 0;
      }
    }
  }
  int sta=0;
  for(int i=1;i<=n;i++){
    if(in[i]%2==1){
      sta|=(1<<(i-1));
    }
  }
  for(int i=1;i<(1<<n);i++){
    dp[i]=0x3f3f3f3f3f3f3f3f;
    for(int j=1;j<=n;j++){
      if((i&(1<<(j-1)))==0){
        continue;
      }
      if(cnt[lowbit(i)]+1==j){
        continue;
      }
      dp[i]=std::min(dp[i],dp[i^(lowbit(i)|(1<<(j-1)))]+map[cnt[lowbit(i)]+1][j]);
    }
  }
  printf("%lld",ans+dp[sta]);
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

