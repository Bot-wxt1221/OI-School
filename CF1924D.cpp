#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int C[5005][5005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  for(int i=1;i<=5000;i++){
    C[i][0]=1;
    C[i][1]=i;
    for(int j=2;j<=i;j++){
      C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
  }
  while(T--){
    int n=read(),m,k;
    m=read();
    k=read();
    if(n<k||m<k){
      printf("0\n");
    }else{
      printf("%lld\n",(0ll+C[n+m][k]-C[n+m][k-1]+mod)%mod);
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

