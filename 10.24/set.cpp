#include <iostream>
#include <cstdio>
#define mod 998244353
inline int read();
int dp[2005][25005];
int cnt[22];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int sum=0;
  for(int i=1;i<=n;i++){
    int tt=read();
    sum+=tt;
    cnt[tt]++;
  }
  dp[0][0]=1;
  int op=0;
  int cnt1=0,cnt2=0;
  for(int i=1;i<=11;i++){
    op^=1;
    cnt1+=cnt[i];
    cnt2+=cnt[i]*i;
    for(int jj=1;jj<=cnt1;jj++){
      for(int k=i;k<=cnt2;k++){
        dp[jj][k]+=dp[jj-1][k-i];
        dp[jj][k]%=mod;
      }
    }
    for(int jj=cnt1;jj>=cnt[i]+1;jj--){
      for(int j=(cnt[i]+1)*i;j<=cnt2;j++){
        dp[jj][j]-=dp[jj-cnt[i]-1][j-(cnt[i]+1)*i];
        dp[jj][j]%=mod;
      }
    }
  }
  int ans=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=sum;j++){
      ans+=dp[i][j]*1ll*(1+std::min(i,j/10))%mod;
      ans%=mod;
    }
  }
  ans+=mod;
  ans%=mod;
  printf("%d",ans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
