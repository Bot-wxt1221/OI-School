#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
int a[1000005];
int pop(int x){
  int ret=0;
  while(x){
    ret+=x&1;
    x>>=1;
  }
  return ret;
}
int n;
bool yes(int sta,int j){
  int cur=0;
  for(int i=0;i<n;i++){
    if(sta&(1<<i)){
      cur++;
    }
    if(a[n-i]>=j){
      cur--;
      if(cur<0){
        return 0;
      }
    }
  }
  return 1;
}
std::vector<int>vec[25];
int dp[25][5000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("d.in","r",stdin);
  freopen("d.out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=0;i<(1<<n);i++){
    vec[pop(i)].push_back(i);
  }
  dp[n+1][0]=1;
  int cnt=0,tt=0;
  for(int i=n;i>=1;i--){
    for(int j=0;j<vec[n-i+1].size();j++){
      int jj=vec[n-i+1][j];
      if(yes(jj,i)){
        for(int k=1;k<=n;k++){
          if(jj&(1<<(k-1))){
            dp[i][jj]+=dp[i+1][jj^(1<<(k-1))];
          }
        }
      }
    }
  }
  printf("%lld",dp[1][(1<<(n))-1]);
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

