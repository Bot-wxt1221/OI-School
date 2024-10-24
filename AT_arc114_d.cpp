#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int __int128
inline int read();
int a[5005];
int t[5005];
int seq[10005];
int dp[5005][10005];
int require[10005];
int tabs(int x){
  if(x<0){
    return -x;
  }
  return x;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int k=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    seq[++cnt]=a[i];
  }
  std::sort(a+1,a+n+1);
  for(int i=1;i<=k;i++){
    t[i]=read();
    seq[++cnt]=t[i];
  }
  std::sort(seq+1,seq+cnt+1);
  cnt=std::unique(seq+1,seq+cnt+1)-seq-1;
  for(int i=1;i<=n;i++){
    a[i]=std::lower_bound(seq+1,seq+cnt+1,a[i])-seq;
    require[a[i]]^=1;
  }
  for(int i=1;i<=k;i++){
    t[i]=std::lower_bound(seq+1,seq+cnt+1,t[i])-seq;
    require[t[i]]^=1;
  }
  memset(dp,0x3f,sizeof(dp));
  int inf=dp[0][0];
  dp[0][0]=0;
  for(int j=1;j<=cnt;j++){
    if(require[j]==0){
      dp[0][j]=std::min(dp[0][j-1],dp[0][j]);
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=cnt;j++){
      if(i>=2){
        dp[i][j]=std::min(dp[i][j],dp[i-2][j]+tabs(seq[a[i]]-seq[j])+tabs(seq[a[i-1]]-seq[j]));
      }
      dp[i][j]=std::min(dp[i][j],dp[i-require[j]][j-1]+(require[j]*(tabs(seq[a[i]]-seq[j]))));
    }
  }
  if(dp[n][cnt]==inf){
    dp[n][cnt]=-1;
  }
  printf("%lld",(long long)dp[n][cnt]);
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
