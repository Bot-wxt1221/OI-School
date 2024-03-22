#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int dp[55][55];
inline void write(int ans);
signed main(){
  #ifdef ONLINE_JUDGE
  freopen("brackets.in","r",stdin);
  freopen("brackets.out","w",stdout);
  #endif
  int n=52;
  int k=52;
  for(int i=0;i<=k;i++){
    dp[0][i]=1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      dp[i][j]=0;
      for(int k=1;k<=i;k++){
        dp[i][j]+=(dp[i-k][j]*dp[k-1][j-1]);
      }
    }
  }
  int T=0;
  n=read();
  k=read();
  while((n)!=0||(k)!=0){
    T++;
    printf("Case %lld: ",(long long)(T));
    write(dp[n][k]-dp[n][k-1]);
    printf("\n");
    n=read();
    k=read();
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
inline void write(int ans){
	if(ans==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	static char out[65];
	long long n=0;
	while(ans){
		out[++n]=ans%10+'0';
		ans/=10;
	}
	for(int i=n;i>=1;i--){
		putchar(out[i]);
	}
	putchar('\n');
	return ;
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


