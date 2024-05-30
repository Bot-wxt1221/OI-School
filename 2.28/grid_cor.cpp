#include <iostream>
#include <cstdio>
#define mod 998244353
#define int long long
inline int read();
char str[2005][2005];
int f[2005][2005],g[2005][2005],h[2005][2005],a[2005][2005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",str[i]+1);
  }
  h[1][0]=a[1][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      (a[i][j])=(a[i-1][j]+a[i][j-1])%mod;
      f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
      if(str[i][j]=='+'){
        f[i][j]+=g[i-1][j];
        f[i][j]%=mod;
        f[i][j]+=g[i][j-1];
        f[i][j]%=mod;
        h[i][j]=a[i][j];
      }else if(str[i][j]=='*'){
        h[i][j]=(g[i][j-1]+g[i-1][j])%mod;
      }else{
        g[i][j]=((g[i-1][j]+g[i][j-1])%mod*10)%mod;
        h[i][j]=(h[i-1][j]+h[i][j-1])%mod;
        g[i][j]+=((str[i][j]-'0')*h[i][j])%mod;
        g[i][j]%=mod;
      }
    }
  }
  printf("%lld\n",(f[n][m]+g[n][m])%mod);
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


