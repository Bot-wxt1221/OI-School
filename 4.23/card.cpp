#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int p[105];
int pp[105];
int pow(int a,int b){
  long long res=1;
  while(b){
    if(b&1){
      res=(1ll*a*res)%mod;
    }
    a=(1ll*a*a)%mod;
    b>>=1;
  }
  return res;
}
int dp[1005];
class matrix{
  public:
    int map[105][105];
}base,add,ans;
void cheng (matrix a,matrix b,matrix &ans){
  for(int i=1;i<=102;i++){
    for(int j=1;j<=102;j++){
      ans.map[i][j]=0;
      for(int k=1;k<=102;k++){
        ans.map[i][j]+=1ll*a.map[i][k]*b.map[k][j]%mod;
        if(ans.map[i][j]>mod){
          ans.map[i][j]-=mod;
        }
      }
    }
  }
  return ;
}
matrix pow(matrix &a,int b,matrix &ans){
  for(int i=1;i<=102;i++){
    ans.map[i][i]=1;
  }
  while(b){
    if(b&1){
      cheng(ans,a,ans);
    }
    cheng(a,a,a);
    b>>=1;
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  #endif
  int n=read(),k;
  k=read();
  int no=1;
  for(int i=0;i<k;i++){
    int a=read();
    int b=read();
    pp[i]=1ll*a*pow(b,mod-2)%mod;
  }
  pp[k]=1;
  int sump=0;
  for(int i=0;i<=k;i++){
    p[i]=1ll*pp[i]*no%mod;
    sump+=p[i];
    sump%=mod;
    no=1ll*no*(1-pp[i]+mod)%mod;
  }
  for(int i=1;i<=k;i++){
    for(int j=0;j<std::min(i,k+1);j++){
      dp[i]+=1ll*(dp[i-j-1]+1)*p[j]%mod;
      if(dp[i]>mod){
        dp[i]-=mod;
      }
    }
    base.map[1][i+1]=dp[i];
  }
  base.map[1][k+2]=1;
  add.map[k+2][k+2]=1;
  for(int i=1;i<=k+1;i++){
    add.map[k+2][i]=sump;
    for(int j=1;j<=k+1;j++){
      if(j+k-i>=0&&j+k-i<=k){
        add.map[i][j]=p[(j+k)-i];
      }
    }
  }
  for(int i=1;i<=k+1;i++){
    for(int j=1;j<i;j++){
      for(int kk=1;kk<=k+2;kk++){
        add.map[kk][i]+=1ll*add.map[kk][j]*p[i-j-1]%mod;
        if(add.map[kk][i]>mod){
          add.map[kk][i]-=mod;
        }
      }
    }
  }
  pow(add,(n)/(k+1),ans);
  cheng(base,ans,base);
  printf("%lld",base.map[1][((n)%(k+1))+1]);
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

