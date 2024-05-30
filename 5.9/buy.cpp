#include <algorithm>
#include <iostream>
#include <cstdio>
inline void read(int &t);
inline void write(int ans);
int t[100005];
int cur[100005];
long long dp[100005];
int num[100005];
int cost[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("buy.in","r",stdin);
  freopen("buy.out","w",stdout);
  #endif
  int n=0,k=0;
  read(n);
  read(k);
  for(int i=1;i<=n;i++){
    read(t[i]);
  }
  for(int i=1;i<=k;i++){
    read(num[i]);
    read(cost[i]);
    cur[i]=1;
  }
  int one=0;
  read(one);
  for(int i=1;i<=n;i++){
    dp[i]=0x3f3f3f3f3f3f3f3f;
    for(int j=1;j<=k;j++){
      int &tt=cur[j];
      while(tt<=i&&t[i]-t[tt]+1>num[j]){
        tt++;
      }
      dp[i]=std::min(dp[i],dp[tt-1]+cost[j]);
    }
    dp[i]=std::min(dp[i-1]+one,dp[i]);
  }
  for(int i=1;i<=n;i++){
    write(dp[i]-dp[i-1]);
  }
  return 0;
}
inline void read(int &t){
  char c=getchar();
  while(c<'0'||c>'9'){
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    t=(t<<3)+(t<<1)+(c^48);
    c=getchar();
  }
  return ;
}
inline void write(int ans){
	if(ans==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	static char out[65];
	int n=0;
	while(ans){
		out[++n]=ans%10+'0';
		ans/=10;
	}
	for(register int i=n;i>=1;i--){
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

