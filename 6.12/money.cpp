#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int pow(int x,int y){
	if(y==0){
		return 1;
	}
	if(y%2==0){
		int tt=pow(x,y/2);
		return (1ll*tt*tt)%mod;
	}
	return (1ll*pow(x,y-1)*x)%mod;
}

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int a=read();
  int b=read();
  int p=read()*pow(1000000,mod-2)%mod;
  
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

