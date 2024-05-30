#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
#define int long long
inline int read();
int dp[10005][5];
int g[10005][5];
char num[10005];
int siz;
int ans;
void calc(int d){
  memset(dp,0,sizeof(dp));
  memset(g,0,sizeof(g));
  g[1][1]=d;
  for(int i=1;i<=siz;i++){
    for(int j=0;j<=1;j++){
      int t=num[i]-'0';
      for(int k=0;((!j)&&(k<=9))||(k<=t);k++){
        int op=(j&&k==t);
        if(k<d){
          dp[i+1][op]+=(dp[i][j]);
          dp[i+1][op]%=mod;
          g[i+1][op]+=(g[i][j]);
          g[i+1][op]%=mod;
        }
        if(k==d){
          dp[i+1][op]+=(10*dp[i][j]+g[i][j])%mod;
          dp[i+1][op]%=mod;
          g[i+1][op]+=(g[i][j]);
          g[i+1][op]%=mod;
       }
        if(k>d){
          dp[i+1][op]+=(10*dp[i][j])%mod;
          dp[i+1][op]%=mod;
          g[i+1][op]+=(10*g[i][j])%mod;
          g[i+1][op]%=mod;
        }
      }
    }
  }
  ans+=(dp[siz+1][0]+dp[siz+1][1])%mod;
  ans%=mod;
  return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  scanf("%s",num+1);
  siz=strlen(num+1);
  for(int i=1;i<10;i++){
    calc(i);
  }
  printf("%lld\n",ans);
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


