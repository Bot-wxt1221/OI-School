#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int fir[5005];
int nxt[50005];
int v[50005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int ff[50005];
int dp[5005][5005];
int siz[5005];
int predp[50005];
void dfs(int now,int fa){
  dp[now][1]=1;
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    for(int ii=0;ii<=siz[now];ii++){
      predp[ii]=dp[now][ii];
      dp[now][ii]=0;
    }
    for(int ii=0;ii<=siz[now];ii++){
      for(int j=0;j<=siz[v[i]];j++){
        dp[now][ii+j]+=(predp[ii]*dp[v[i]][j])%mod;
        dp[now][ii+j]%=mod;
      }
    }
    siz[now]+=siz[v[i]];
  }
  for(int i=2;i<=siz[now];i+=2){
    dp[now][0]+=(((dp[now][i]*(-ff[i-1]))%mod)+mod)%mod;
    dp[now][0]%=mod;
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
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  ff[0]=ff[1]=1;
  for(int i=2;i<=n;i++){
    ff[i]=(ff[i-2]*i)%mod;
  }
  dfs(1,1);
  printf("%lld",(-dp[1][0]+mod)%mod);
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


