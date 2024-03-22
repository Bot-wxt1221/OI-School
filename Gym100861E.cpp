#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define int long long
inline int read();
int cnt[105][1005];
int dp[105][1005];
int pre[105][1005];
std::stack<int>st;
class node{
  public:
  int a,b,i;
}a[105];
bool operator < (node a,node b){
  return a.b*b.a<b.b*a.a;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int T=read();
  for(int i=1;i<=n;i++){
    a[i].b=read();
    a[i].a=read();
    a[i].i=i;
  }
  std::sort(a+1,a+n+1);
  memset(dp,-0x3f,sizeof(dp));
  dp[0][0]=0;
  for(int i=1;i<=n;i++){
    for(int j=a[i].b;j<=T;j++){
      for(int k=0;k<i;k++){
        if(dp[k][j-a[i].b]+a[i].a>dp[i][j]){
          dp[i][j]=dp[k][j-a[i].b]+a[i].a;
          cnt[i][j]=cnt[k][j-a[i].b]+(j*a[i].a);
          pre[i][j]=k;
        }else if(dp[k][j-a[i].b]+a[i].a==dp[i][j]){
          cnt[i][j]=std::min(cnt[i][j],cnt[k][j-a[i].b]+(j*a[i].a));
          if(cnt[i][j]==cnt[k][j-a[i].b]+(j*a[i].a)){
            pre[i][j]=k;
          }
        }
      }
    }
  }
  int cur1,cur2;
  int maxx=-1;
  int cntt=0;
  for(int i=0;i<=n;i++){
    for(int j=a[i].b;j<=T;j++){
      if(maxx<dp[i][j]){
        cur1=i;
        cur2=j;
        maxx=dp[i][j];
        cntt=cnt[i][j];
      }else if(maxx==dp[i][j]){
        if(cntt>cnt[i][j]){
          cntt=cnt[i][j];
          cur1=i;
          cur2=j;
        }
      }
    }
  }
  if(maxx==0){
    printf("0\n");
    return 0;
  }
  while(cur1!=0){
    st.push(a[cur1].i);
    int pp=cur2;
    cur2-=a[cur1].b;
    cur1=pre[cur1][pp];
  }
  printf("%lu\n",st.size());
  while(st.size()){
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


