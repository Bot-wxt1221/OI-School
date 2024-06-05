#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#define mod 998244353
inline int read();
int dp[10005][1026];
int x[15];
std::vector<int>vec[15];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int m=read();
  int n=read();
  for(int i=1;i<=m;i++){
    x[i]=read();
    vec[x[i]].push_back(i);
  }
  dp[0][(1<<(m))-1]=1;
  for(int i=1;i<=n;i++){
    for(int sta=0;sta<=(1<<(m))-1;sta++){
      for(int j=1;j<=m;j++){
        if(x[j]!=j){
          if(sta&(1<<(j-1))){

          }else{
            continue;
          }
        }
        int nsta=sta;
        for(int k=0;k<vec[j].size();k++){
          nsta|=(1<<(vec[j][k]-1));
        }
        nsta&=~((1<<(j-1)));
        dp[i][nsta]+=dp[i-1][sta];
        dp[i][nsta]%=mod;
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<(m));i++){
    ans+=dp[n][i];
    ans%=mod;
  }
  printf("%d",ans);
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

