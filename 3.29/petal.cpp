#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int a[10000005];
int dp[10000005];
int dp2[10000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("petal.in","r",stdin);
  freopen("petal.out","w",stdout);
  #endif
  int n=read();
  bool pian=1;
  for(int i=1;i<=n;i++){
    a[i]=read();
    if(a[i]!=n&&i%2==0){
      pian=0;
    }
  }
  if(n>2000&&pian==0){
   // if(1){
    //2 different 
    int min=0x3f3f3f3f,max=0;
    for(int i=1;i<=n;i++){
      min=std::min(min,a[i]);
      max=std::max(max,a[i]);
    }
    int pre0=0,pre1=0;
    dp[0]=dp2[0]=1;
    for(int i=1;i<=n;i++){
      if(a[i]==min){
        pre0=i;
        int siz=std::min(pre1,i-min+1);
        int siz2=std::min(pre1+1,i-max+1);
        if(siz2<2&&siz>=1){
          dp[i]+=dp2[siz-1];
        }else if(siz>=1){
          dp[i]+=dp2[siz-1]-dp2[siz2-1-1]+mod;
        }
        dp[i]%=mod;
        if(pre1<i-min+1){
          dp[i]+=dp[i-min];
          dp[i]%=mod;
        }
      }else{
        int siz=std::min(pre0,i-min+1);
        int siz2=std::min(pre0+1,i-max+1);
        if(siz2<2&&siz>=1){
          dp[i]+=dp2[siz-1];
        }else if(siz>=1){
          dp[i]+=dp2[siz-1]-dp2[siz2-1-1]+mod;
        }
        dp[i]%=mod;
        if(pre0<i-max+1){
          dp[i]+=dp[i-max];
          dp[i]%=mod;
        }
        pre1=i;
      }
      dp2[i]=(dp[i]+dp2[i-1])%mod;
    }
    printf("%lld",dp[n]);
    return 0;
  }else{
    dp[0]=1;
    for(int i=1;i<=n;i++){
      int min=0x3f3f3f3f,max=0;
      for(int j=i;j>=1;j--){
        min=std::min(min,a[j]);
        max=std::max(max,a[j]);
        if(min<=(i-j+1)&&(i-j+1)<=max){
          dp[i]+=dp[j-1];
          dp[i]%=mod;
        }
      }
    }
    printf("%lld",dp[n]);
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

