#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define mod 998244353
inline int read();
int fir[6005];
int nxt[6005];
int v[6005];
int fac[6005];
int inv[6005];
int siz[6005];
int pow(long long a,long long n){
  n%=(mod-1);
  if(n<0){
    return 0;
  }
  long long res=1;
	while(n)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res;
}
int C(int n,int m){
  if(n<m){
    return 0;
  }
  return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int dp[3005][3005][2];// 0 -> smaller 1 -> bigger
int g[3005][3005][2];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  siz[now]=1;
  dp[now][1][0]=dp[now][1][1]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    for(int j=1;j<=siz[v[i]];j++){
      dp[v[i]][j][0]+=dp[v[i]][j-1][0];
      dp[v[i]][j][0]%=mod;
    }
    for(int j=1;j<=3000;j++){
      g[now][j][1]=dp[now][j][1];
    }
    for(int j=1;j<=siz[now];j++){
      for(int k=0;k<=siz[v[i]];k++){
        dp[now][j+k][1]+=((C(j+k-1,k)*C(siz[now]-j+siz[v[i]]-k,siz[v[i]]-k)%mod)*g[now][j][1]%mod)*dp[v[i]][k][0]%mod;
        dp[now][j+k][1]%=mod;
      }
    }
    for(int j=1;j<=3000;j++){
      dp[now][j][1]-=g[now][j][1];
      dp[now][j][1]%=mod;
    }
    siz[now]+=siz[v[i]];
  }
  for(int i=1;i<=siz[now];i++){
    dp[now][i][0]=dp[now][siz[now]-i+1][1];
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  fac[0]=1;
  for(int i=1;i<=2*n;i++){
    fir[i]=-1;
    fac[i]=fac[i-1]*i%mod;
  }
  inv[2*n]=pow(fac[2*n],mod-2);
  for(int i=2*n-1;i>=0;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=dp[1][i][0];
    ans%=mod;
  }
  ans*=2;
  ans%=mod;
  ans+=mod;
  ans%=mod;
  printf("%lld",ans);
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
