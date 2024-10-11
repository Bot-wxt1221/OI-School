#include <iostream>
#include <vector>
#include <cstdio>
#define int long long
inline int read();
int dp[5000005];
bool vised[5000005];
int a[1000005];
int cnt[5000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int m=read();
    for(int i=1;i<=m;i++){
      vised[i]=0;
    }
    int mn=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
      a[i]=read();
      mn=std::min(mn,a[i]);
      vised[a[i]]=1;
    }
    for(int i=1;i<=m;i++){
      dp[i]=i;
      cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
      cnt[a[i]]=1;
    }
    int mx=m;
    int ans=m;
    for(int i=m;i>=1;i--){
      for(int j=i*i;j<=m;j+=i){
        if(dp[j]>dp[j/i]&&vised[j]){
          cnt[dp[j]]--;
          cnt[dp[j/i]]++;
        }
        dp[j]=std::min(dp[j],dp[j/i]);
      }
      while(cnt[mx]==0){
        mx--;
      }
      if(i<=mn){
        ans=std::min(ans,mx-i);
      }
    }
    printf("%lld\n",ans);
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
