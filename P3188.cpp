#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define int long long
inline int read();
int w1[105];
int w2[105];
int v[105];
int dp[66][2005];
std::vector<int>vec[105];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n;
  while(scanf("%lld",&n)!=EOF&&n!=-1){
    int W=read();
    for(int i=0;i<=100;i++){
      vec[i].clear();
    }
    for(int i=1;i<=n;i++){
      w1[i]=read();
      w2[i]=0;
      v[i]=read();
      while(w1[i]%2==0){
        w1[i]/=2;
        w2[i]++;
      }
      vec[w2[i]].push_back(i);
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[64][0]=0;
   for(int i=63;i>=0;i--){
      for(int j=0;j<=2000;j++){
        dp[i][std::min(2000ll,(j*2)+((W>>i)&1))]=std::max(dp[i+1][j],dp[i][std::min(2000ll,(j*2)+((W>>i)&1))]); 
      }
      for(int j=0;j<vec[i].size();j++){
        for(int k=0;k<=2000;k++){
          dp[i][k]=std::max(dp[i][std::min(k+w1[vec[i][j]],2001ll)]+v[vec[i][j]],dp[i][k]);
        }
        dp[i][2000]=std::max(dp[i][2000],dp[i][2001]);
      }
    }
    int ret=0;
    for(int i=0;i<=2000;i++){
      ret=std::max(ret,dp[0][i]);
    }
    printf("%lld\n",ret);
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
