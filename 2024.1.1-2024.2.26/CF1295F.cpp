#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353
inline int read();
int l[55];
int r[55];
int X[205];
int inv[205];
void init(int x){
  inv[1]=1;
  for(int i=2;i<=x;i++){
    inv[i]=mod-(((mod/i)*inv[mod%i])%mod);
  }
  return ;
}
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int temp=pow(x,y/2);
    return (temp*temp)%mod;
  }
  return (pow(x,y-1)*x)%mod;
}
int C(int x,int y){
  if(y<0||y>x){
    return 0;
  }
  int res=1;
  for(int i=1;i<=y;i++){
    res=((((res)*(x-i+1))%mod)*inv[i])%mod;
  }
  return res;
}
int dif[205];
int dp[205][205];
int sum[205][205];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=0;
  int tot=1;
  for(int i=1;i<=n;i++){
    l[i]=read();
    r[i]=read();
    tot*=(r[i]-l[i]+1);
    tot%=mod;
    X[++m]=l[i];
    X[++m]=l[i]-1;
    X[++m]=r[i];
    X[++m]=r[i]-1;
  }
  init(n*4);
  std::sort(X+1,X+m+1);
  m=std::unique(X+1,X+m+1)-X-1;
  for(int i=1;i<=n;i++){
    l[i]=std::lower_bound(X+1,X+m+1,l[i])-X;
    r[i]=std::lower_bound(X+1,X+m+1,r[i])-X;
  }
  for(int i=1;i<=n;i++){
    if(n-i+1>i){
      std::swap(l[i],l[n-i+1]);
      std::swap(r[i],r[n-i+1]);
    }
  }
  for(int i=2;i<=m;i++){
    dif[i]=X[i]-X[i-1];
  }
  for(int i=l[1];i<=r[1];i++){
    dp[1][i]=dif[i];
  }
  for(int i=2;i<=m;i++){
    sum[1][i]=(sum[1][i-1]+dp[1][i])%mod;
  }
  for(int i=2;i<=n;i++){
    for(int j=l[i];j<=r[i];j++){
      dp[i][j]=((sum[i-1][j-1])*dif[j])%mod;
      for(int k=1;k<i&&l[i-k]<=j&&j<=r[i-k];k++){
        int temp=1;
        if(i-k-1>0){
          temp=sum[i-k-1][j-1];
        }
        dp[i][j]+=(temp*C(dif[j]+k,k+1)%mod);
        dp[i][j]%=mod;
      }
    }
    for(int j=2;j<=m;j++){
      sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
    }
  }
  printf("%lld",(sum[n][m]*pow(tot,mod-2))%mod);
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


