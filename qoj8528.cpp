#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int dp[2*100005][1005];
int seq[200005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    int l=read();
    int r=read();
    seq[r]=l;
  }
  memset(dp,-0x3f,sizeof(dp));
  dp[0][0]=0;
  for(int i=1;i<=2*n;i++){
    dp[i][0]=i;
    for(int j=1;j<=1000;j++){
      dp[i][j]=dp[i-1][j];
    }
    if(seq[i]==0){
      continue;
    }
    int ll=seq[i]+1,rr=i-1;
    int l=0,r=1000;
    while(r-l>3){
      int mid=(l+r)/2;
      if(dp[rr][mid]>=ll){
        l=mid;
      }else{
        r=mid;
      }
    }
    int ans=0;
    for(int j=r;j>=l;j--){
      if(dp[rr][j]>=ll){
        ans=j;
        break;
      }
    }
    ans++;
    for(int j=1;j<=1000;j++){
      if(ans>=j){
        dp[i][j]=std::max(dp[i][j],seq[i]);
      }else{
        dp[i][j]=std::max(dp[i][j],dp[seq[i]][j-ans]);
      }
    }
  }
  for(int i=1000;i>=0;i--){
    if(dp[2*n][i]>=1){
      printf("%d\n",i);
      return 0;
    }
  }
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
