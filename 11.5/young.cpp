#include <iostream>
#include <cstdio>
#define int long long
#define mod 258280327
inline int read();
bool finish[55][55][10][(1<<8)+5];
int p[55][55][10][(1<<8)+5];
int pw[10005];
int g[55][55][10];
int fac[1005];
int inv[1005];
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
int C(int n,int m){
  return 1ll*fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int calcp(int S,int T,int m,int k){
  if(k>=(1<<m)){
    return 0;
  }
  if(k<=0){
    return pw[(S+T)*m];
  }
  if(m==1){
    if(k==0){
      return pw[S+T];
    }else{
      return 2;
    }
  }
  if(finish[S][T][m][k]){
    return p[S][T][m][k];
  }
  finish[S][T][m][k]=1;
  int &ans=p[S][T][m][k];
  ans=0;
  for(int i=1;i<S;i++){
    for(int j=1;j<T;j++){
      if(k>=(1<<(m-1))){
      }else{
        ans+=C(S,i)*C(T,j)%mod*calcp(i,j,m-1,k)%mod*calcp(S-i,T-j,m-1,k)%mod;
        ans%=mod;
      }
    }
  }
  for(int i=1;i<S;i++){
    ans+=C(S,i)*calcp(i,T,m-1,k)%mod*pw[(m-1)*(S-i)+1]%mod;
    ans%=mod;
  }
  for(int i=1;i<T;i++){
    ans+=C(T,i)*calcp(S,i,m-1,k)%mod*pw[(m-1)*(T-i)+1]%mod;
    ans%=mod;
  }
  ans+=calcp(S,T,m-1,k)*2%mod;
  ans%=mod;
  ans+=calcp(S,T,m-1,k-(1<<(m-1)))*2%mod;
  ans%=mod;
  return ans;
}
int dp[55][10];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=50;
  int m=8;
  pw[0]=1;
  for(int i=1;i<=10000;i++){
    pw[i]=pw[i-1]*2%mod;
  }
  fac[0]=1;
  for(int i=1;i<=n;i++){
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  inv[n]=pow(fac[n],mod-2);
  for(int i=n-1;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j+i<=n;j++){
      for(int mm=0;mm<=8;mm++){
        for(int k=1;k<(1<<mm);k++){
          g[i][j][mm]+=calcp(i,j,mm,k);
          g[i][j][mm]%=mod;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      for(int k=1;k<i;k++){
        int ret=pw[(i-k)*(j-1)]*dp[k][j-1]%mod;
        ret+=pw[k*(j-1)]*dp[i-k][j-1]%mod;
        ret%=mod;
        ret+=g[k][i-k][j-1];
        ret%=mod;
        ret+=pw[(i+1)*(j-1)];
        ret%=mod;
        dp[i][j]+=ret*C(i,k)%mod;
        dp[i][j]%=mod;
      }
      dp[i][j]+=dp[i][j-1]*2%mod;
      dp[i][j]%=mod;
    }
  }
  printf("{");
  for(int i=0;i<=n;i++){
    printf("{");
    for(int j=0;j<=m;j++){
      printf("%lld",dp[i][j]*pow(pw[i*j],mod-2)%mod);
      if(j!=m){
        printf(",");
      }
    }
    printf("}");
    if(i!=n){
      printf(",");
    }
  }
  printf("}");

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
