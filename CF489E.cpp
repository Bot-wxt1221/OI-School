#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
#define int long long
inline int read();
int n,l;
int x[1005],b[1005];
int pre[1005];
long double dp[1005];
std::stack<int>st;
bool check(long double ans){
  dp[0]=0;
  for(int i=1;i<=n;i++){
    dp[i]=0x3f3f3f3f;
    for(int j=0;j<i;j++){
      dp[i]=std::min(dp[i],dp[j]+std::sqrt(std::abs(x[i]-x[j]-l))-b[i]*ans);
      if(dp[i]==dp[j]+std::sqrt(std::abs(x[i]-x[j]-l))-b[i]*ans){
        pre[i]=j;
      }
    }
  }
  return dp[n]<=0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  l=read();
  for(int i=1;i<=n;i++){
    x[i]=read();
    b[i]=read();
  }
  long double l=0,r=0x3f3f3f3f;
  while(r-l>1e-10){
    long double mid=(l+r)/2;
    if(check(mid)){
      r=mid;
    }else{
      l=mid;
    }
  }
  check(l);
  int now=n;
  while(now!=0){
    st.push(now);
    now=pre[now];
  }
  while(st.size()>0){
    printf("%lld ",st.top());
    st.pop();
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


