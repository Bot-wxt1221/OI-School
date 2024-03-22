#include <iostream>
#include <cstdio>
#define mod 998244353
using namespace std;
int read();
int a[4005];
int dp[4005][4005];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    long long tt=pow(x,y/2);
    return (tt*tt)%mod;
  }
  return (((1ll)*(x))*pow(x,y-1))%mod;
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
  #endif
  int n=read();
  dp[1][1]=dp[1][2]=1;
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(i>2){
      dp[1][i]=((1ll*a[1])*dp[1][i-1])%mod;
    }
  }
  for(int i=2;i<=n;i++){//cho
    dp[i][1]=i;
    dp[i][2]=(i)*(i);
    for(int j=3;j<=n;j++){//siz
      dp[i][j]=dp[i-1][j];
      for(int k=1;k<=std::min(2,j-2);k++){
        long long add=1;
        if(k>1&&k+1<=j){
          add*=a[i];
          add%=mod;
        }
        if(k>2){
          add*=a[i];
          add%=mod;
        }
        if(k+2<=j){
          add*=a[i];
          add%=mod;
        }
        if(k>1){
          add*=dp[i][k-1];
          add%=mod;
        }
        if(k+1<=j){
          add*=dp[i-1][j-(k)];
          add%=mod;
        }
        dp[i][j]+=(add);
        dp[i][j]%=mod;
      }
      for(int k=j-1;k<=j;k++){
        long long add=1;
        if(k>1&&k+1<=j){
          add*=a[i];
          add%=mod;
        }
        if(k>2){
          add*=a[i];
          add%=mod;
        }
        if(k+2<=j){
          add*=a[i];
          add%=mod;
        }
        if(k>1){
          add*=dp[i][k-1];
          add%=mod;
        }
        if(k+1<=j){
          add*=dp[i-1][j-(k)];
          add%=mod;
        }
        dp[i][j]+=(add);
        dp[i][j]%=mod;
      }
      for(int k=3;k<=j-2;k++){//cho to
        long long add=1;
        add*=a[i];
        add%=mod;
        add*=a[i];
        add%=mod;
        add*=a[i];
        add%=mod;
        add*=dp[i][k-1];
        add%=mod;
        add*=dp[i-1][j-(k)];
        add%=mod;
        dp[i][j]+=(add);
        dp[i][j]%=mod;
      }
      // dp[i][j]+=dp[i][j-1];
      // dp[i][j]%=mod;
    }
  }
  printf("%d\n",dp[n][n]);
  return 0;
}

int read(){
  int x=0,f=1;
  char tt=getchar();
  while(tt>'9'||tt<'0'){
    (tt=='-')?f=-1:0;
    tt=getchar();
  }
  while('0'<=tt&&tt<='9'){
    x=(x*10)+(tt-'0');
    tt=getchar();
  }
  return f*x;
}
