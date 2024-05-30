#include <iostream>
#include <cstdio>
inline int read();
int fir[25005];
int nxt[50005];
int v[50005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
long double dp[2505][2505];
int n,k;
int s[100005];
int p[100005];
int r[100005];
int siz[100005];
int dfn[100005];
int cnt=0;
void dfs(int now){
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    dfs(v[i]);
    siz[now]+=siz[v[i]];
  }
  dfn[++cnt]=now;
  return ;
}
bool check(long double mid){
  for(int i=0;i<=n+1;i++){
    for(int j=0;j<=k+1;j++){
      dp[i][j]=-0x3f3f3f3f;
    }
  }
  dp[0][0]=0;
  for(int i=1;i<=n+1;i++){
    for(int j=0;j<=k+1;j++){
      if(j){
        dp[i][j]=dp[i-1][j-1]+(p[dfn[i]]-s[dfn[i]]*mid);
      }else{
        dp[i][j]=-0x3f3f3f3f;
      }
      if(i!=n+1){
        dp[i][j]=std::max(dp[i][j],dp[i-siz[dfn[i]]][j]);
      }
    }
  }
  return dp[n+1][k+1]>=0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  k=read();
  n=read();
  for(int i=0;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    s[i]=read();
    p[i]=read();
    r[i]=read();
    add(r[i],i);
  }
  dfs(0);
  long double l=0,r=0x3f3f3f3f;
  for(int i=1;i<=100;i++){
    long double mid=(l+r)/2;
    if(check(mid)){
      l=mid;
    }else{
      r=mid;
    }
  }
  printf("%.3Lf",l);
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

