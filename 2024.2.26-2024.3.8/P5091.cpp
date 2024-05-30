#include <iostream>
#include <cstdio>
#define int long long
inline int read(int mod);
int pow(int a,int b,int mod){
  int ans=1;
  int cur=a;
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
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int a=read(10000000000ll);
  int b=read(10000000000ll);
  a%=b;
  int bb=b;
  int phi=1;
  for(int i=2;i*i<=b;i++){
    if(bb%i==0){
      phi*=(i-1);
      bb/=i;
    }
    while(bb%i==0){
      phi*=i;
      bb/=i;
    }
  }
  if(bb>1){
    phi*=(bb-1);
  }
  int c=read(phi);
  if(c!=0&&a==0){
    printf("0");
    return 0;
  }
  printf("%lld",pow(a,c,b));
  return 0;
}
inline int read(int mod){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){
    c=='-'?f=-1:1;
    c=getchar();
  }
  int tt=0;
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+(c^48);
    if(x>=mod){
      tt=1;
    }
    x%=mod;
    c=getchar();
  }
  return f*x+tt*mod;
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


