#include <iostream>
#include <cstdio>
inline int read();
int dp[45][2000005];
int sum[2000005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  int n=read();
  int m=(1<<n);
  dp[0][0]=1;
  sum[0]=1;
  for(int i=1;i<=n;i++){
    sum[i]=(sum[i-1])|(1<<i);
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<n;j++){
      int aft=j+i-1;
      int sta=sum[std::min(aft,n-1)];
      if(j){
        sta^=sum[j-1];
      }
      if(aft>=n){
        sta|=sum[aft-n];
      }
      for(int k=0;k<m;k++){
        dp[i][k^sta]|=dp[i-1][k];
      }
    }
  }
  while(T--){
    char temp[25];
    int q=0,t=0;
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      q*=2;
      if(temp[i]=='1'){
        q++;
      }
    }
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      t*=2;
      if(temp[i]=='1'){
        t++;
      }
    }
    for(int i=0;i<=n;i++){
      if(dp[i][q]){
        printf("%d\n",i);
        break;
      }
      q^=t;
      t=(t>>1)|((t&1)<<(n-1));
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


