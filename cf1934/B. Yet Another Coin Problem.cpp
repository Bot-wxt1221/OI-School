#include <iostream>
#include <cstdio>
inline int read();
int dp[550];
int a[]={1,3,6,10,15};
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  dp[0]=0;
  for(int i=1;i<=98;i++){
    dp[i]=0x3f3f3f3f;
    for(int k=0;k<5;k++){
      if(i>=a[k]){
        dp[i]=std::min(dp[i],dp[i-a[k]]+1);
      }
    }
  }
  while(T--){
    int n=read();
    if(n<=60){
      printf("%d\n",dp[n]);
      continue;
    }
    int ans=(n/30-1)*2;
    if(ans<0){
      ans=0;
    }
    ans+=dp[n%30+30];
    printf("%d\n",ans);
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


