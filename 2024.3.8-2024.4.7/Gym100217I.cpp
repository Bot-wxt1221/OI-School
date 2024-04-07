#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
int dp[1505][1505];
inline void write(int ans);
signed main(){
  #ifdef ONLINE_JUDGE
//  freopen("sweets.in","r",stdin);
//  freopen("sweets.out","w",stdout);
  #endif
  int n=read(),k;
  k=read();
  for(int i=1;i<=n;i++){
    dp[i][1]=dp[i][0]=1;
  }
  for(int i=2;i<=n;i++){
    for(int x=2;x<=k;x++){
      if(i>x){
        dp[i][x]=dp[i-1][x-1]+dp[i-x][x];
      }else{
        dp[i][x]=dp[i-1][x-1];
      }
    }
  }
  write(dp[n][k]);
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


