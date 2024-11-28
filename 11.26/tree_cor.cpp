#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int fir[1005];
int a[1005];
int nxt[2005];
int v[2005];
int now;
int siz[1005];
int dp[205][205][205][3];
int ndp[205][205][3];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
  }
  return ;
}
int m;
void dfs2(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
  int cursiz=1;
  dp[now][0][0][2]=a[now];
  dp[now][0][0][1]=1;
  dp[now][1][1][0]=a[now];
  dp[now][1][0][0]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    memset(ndp,0,sizeof(ndp));
    for(int j=0;j<=cursiz;j++){
      for(int j2=0;j2<=j;j2++){
        for(int k=0;k<=siz[v[i]];k++){
          for(int k2=0;k2<=k;k2++){
            for(int kk=0;kk<3;kk++){
              ndp[j+k][j2+k2][kk]+=dp[now][j][j2][kk]*dp[v[i]][k][k2][0]%m;
              ndp[j+k][j2+k2][kk]%=m;
            }
            if(k){
              ndp[j+k-1][j2+k2][1]+=dp[now][j][j2][1]*dp[v[i]][k][k2][0]%m*(k-k2)%m;
              ndp[j+k-1][j2+k2][1]%=m;

              ndp[j+k-1][j2+k2][2]+=dp[now][j][j2][2]*dp[v[i]][k][k2][0]%m*(k-k2)%m;
              ndp[j+k-1][j2+k2][2]%=m;
            }
            if(k2){
              ndp[j+k-1][j2+k2-1][2]+=dp[now][j][j2][1]*dp[v[i]][k][k2][0]%m*(k2)%m;
              ndp[j+k-1][j2+k2-1][2]%=m;

            }
          }
        }
      }
    }
    cursiz+=siz[v[i]];
    for(int j=0;j<=cursiz;j++){
      for(int j1=0;j1<=j;j1++){
        for(int kk=0;kk<3;kk++){
          dp[now][j][j1][kk]=ndp[j][j1][kk];
        }
      }
    }
  }
  for(int j=0;j<=cursiz;j++){
    for(int j1=0;j1<=j;j1++){
      dp[now][j][j1][0]+=dp[now][j][j1][2];
      dp[now][j][j1][0]%=m;
    }
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    a[i]=read();
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dfs2(1,1);
  printf("%lld",dp[1][0][0][0]);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
