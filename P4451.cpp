#include <iostream>
#include <cstdio>
#define mod 1000000007
#define int __int128
inline int read();
inline int read(int );
int pow(long long x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (1ll*tt*tt)%mod;
  }
  return 1ll*pow(x,y-1)*x%mod;
}

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(mod-1);
  if(n==1){
    n=mod-1;
  }else{
    n--;
  }
  long long ans=(pow(1-59713600+mod,n)*1ll*(59713600-1)%mod*pow((59713600*2)%mod,mod-2)%mod);
  ans%=mod;
  ans+=((pow((59713600*2)%mod,mod-2)%mod)*1ll*(59713600+1)%mod)*(pow((1+59713600)%mod,n)%mod)%mod;
  ans%=mod;
  ans+=mod;
  ans%=mod;
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
inline int read(int m){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){
    c=='-'?f=-1:1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+(c^48);
    x%=m;
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

