#include <iostream>
#include <cstdio>
#include <bitset>
#include <cmath>
#define mod 100000007
inline int read();
std::bitset<200000001>bit;
int pow(int a,int b){
  long long ans=1;
  long long cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=mod;
    }
    cur*=cur;
    cur%=mod;
    b/=2;
  }
  return ans;
}
int prime[10000005];
int cnt;
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  double logn;
  int n=read();
  logn=log2(n);
  long long ans=1;
  for(int i=2;i<=n;i++){
    if(bit[i]==0){
      ans*=pow(i,int(logn/log2(i)));
      ans%=mod;
      prime[++cnt]=i;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*prime[j]*i>n){
        break;
      }
      bit[prime[j]*i]=1;
      if(i%prime[j]==0){
        break;
      }
    }
  }
  printf("%lld",ans);
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


