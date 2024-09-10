#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[200005];
int b[200005];
int seq[200005];
bool cmp(int x,int y){
  if(a[x]==0&&a[y]==0){
    return b[x]<b[y];
  }
  return (b[x]+1)*a[y]<(b[y]+1)*a[x];
}
int dp[200005][105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int T=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
    seq[i]=i;
  }
  std::sort(seq+1,seq+n+1,cmp);
  for(int i=1;i<=100;i++){
    dp[0][i]=0x3f3f3f3f;
  }
  int used=n+1;
  for(int i=1;i<=n;i++){
    if(a[seq[i]]==0){
      used=i;
      break;
    }
    dp[i][0]=0;
    for(int j=1;j<=100;j++){
      dp[i][j]=dp[i-1][j];
    }
    for(int j=1;j<=100;j++){
      dp[i][j]=std::min(dp[i][j],dp[i-1][j-1]+a[seq[i]]*(dp[i-1][j-1]+1)+b[seq[i]]+1);
    }
  }
  int mx=0;
  for(int j=0;j<=100;j++){
    int more=T-dp[used-1][j];
    if(more<0){
      continue;
    }
    int cur=used;
    int cnt=j;
    while(cur<=n){
      if(more>=b[seq[cur]]+1){
        more-=b[seq[cur]]+1;
        cnt++;
      }
      cur++;
    }
    mx=std::max(mx,cnt);
  }
  printf("%lld",mx);
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
