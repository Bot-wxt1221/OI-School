#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
int dp[1000005][2];//jinwei?
int real[1000005][2];
inline int pow(int a,int k){
  long long res=1;
  while(k){
    if(k&1){
      #ifdef mod
      res=1ll*res*a%mod;
      #else
      res*=a;
      #endif
    }
    #ifdef mod
    a=1ll*a*a%mod;
    #else
    a*=a;
    #endif
    k>>=1;
  }
  return res;
}

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int jin1=0,jin2=0;
  dp[1][0]=55;
  real[1][0]=36;
  real[1][1]=45;
  dp[1][1]=45;
  for(int i=2;i<=10000;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=9;k++){
        if(j+k>=10){
          dp[i][1]+=dp[i-1][0];
          if(j!=0&&k!=0){
            real[i][1]+=dp[i-1][0];
            real[i][1]%=mod;
          }
          dp[i][1]%=mod;
        }else{
          dp[i][0]+=dp[i-1][0];
          if(j!=0&&k!=0){
            real[i][0]+=dp[i-1][0];
            real[i][0]%=mod;
          }
          dp[i][0]%=mod;
        }
        if(j+k+1>=10){
          dp[i][1]+=dp[i-1][1];
          if(j!=0&&k!=0){
            real[i][1]+=dp[i-1][1];
            real[i][1]%=mod;
          }
          dp[i][1]%=mod;
        }else{
          dp[i][0]+=dp[i-1][1];
          if(j!=0&&k!=0){
            real[i][0]+=dp[i-1][1];
            real[i][0]%=mod;
          }
          dp[i][0]%=mod;
        }
      }
    }
  }
  while(T--){
    int ans=0;
    int a1=read();
    int a2=read();
    int a3=read();
    if(a3<a2||a3<a1){
      printf("0\n");
      break;
    }
    if(a3-std::max(a1,a2)>1){
      printf("0\n");
      break;
    }
    if(a1>a2){
      std::swap(a1,a2);
    }
    if(a1==a2&&a2==a3){
      printf("%lld\n",real[a1][0]);
    }else {
      printf("%lld\n",real[a1][1]);
    }
  }
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

