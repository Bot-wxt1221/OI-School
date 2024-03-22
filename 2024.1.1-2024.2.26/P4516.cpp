#include <iostream>
#include <cstdio>
#define mod 1000000007
inline int read();
int k;
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int siz[100005];
int dp[100005][105][2][2];
int tmp[105][2][2];
void dfs(int now,int fa){
  siz[now]=1;
  dp[now][0][0][0]=dp[now][1][1][0]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    for(int j=0;j<=std::min(siz[now],k);j++){
      for(int k1=0;k1<=1;k1++){
        for(int k2=0;k2<=1;k2++){
          tmp[j][k1][k2]=dp[now][j][k1][k2];
          dp[now][j][k1][k2]=0;
        }
      }
    }
    for(int j=0;j<=std::min(k,siz[now]);j++){
      for(int kk=0;kk<=std::min(siz[v[i]],k-j);kk++){
        dp[now][j+kk][0][0]+=(((long long)(tmp[j][0][0]))*dp[v[i]][kk][0][1])%mod;
        dp[now][j+kk][0][0]%=mod;

        dp[now][j+kk][1][0]+=(((long long)tmp[j][1][0])*((dp[v[i]][kk][0][0]+dp[v[i]][kk][0][1])%mod))%mod;
        dp[now][j+kk][1][0]%=mod;

        dp[now][j+kk][0][1]+=(((long long)tmp[j][0][1])*((dp[v[i]][kk][0][1]+dp[v[i]][kk][1][1])%mod))%mod;
        dp[now][j+kk][0][1]%=mod;
        dp[now][j+kk][0][1]+=(((long long)tmp[j][0][0])*(dp[v[i]][kk][1][1]))%mod;
        dp[now][j+kk][0][1]%=mod;

        dp[now][j+kk][1][1]+=(((long long)tmp[j][1][0])*((dp[v[i]][kk][1][0]+dp[v[i]][kk][1][1])%mod))%mod;
        dp[now][j+kk][1][1]%=mod;
        dp[now][j+kk][1][1]+=(((long long)tmp[j][1][1])*(((dp[v[i]][kk][1][0]+dp[v[i]][kk][1][1])%mod)+((dp[v[i]][kk][0][0]+dp[v[i]][kk][0][1])%mod))%mod)%mod;
        dp[now][j+kk][1][1]%=mod;
      }
    }
    siz[now]+=siz[v[i]];
  }
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  k=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  printf("%d",(dp[1][k][0][1]+dp[1][k][1][1]));
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


