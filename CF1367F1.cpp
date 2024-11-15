#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
inline int read();
int a[200005];
int b[200005];
int dp[200005];
int pre[200005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      b[i]=a[i];
      dp[i]=pre[i]=0;
    }
    dp[0]=pre[0]=0;
    std::sort(b+1,b+n+1);
    int tt=std::unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++){
      a[i]=std::lower_bound(b+1,b+tt+1,a[i])-b;
    }
    int ans=n-1;
    for(int i=1;i<=n;i++){
      dp[i]=1;
      if(a[i])
        dp[i]=std::max(dp[i],dp[pre[a[i]-1]]+1);
      pre[a[i]]=dp[i];
      ans=std::min(ans,n-dp[i]);
    }
    printf("%d\n",ans);
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
