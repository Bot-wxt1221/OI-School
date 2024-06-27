#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int t[1005];
int a[1005];
int b[1005];
int c[1005];
int d[1005];
int m,n;
long double dp[1005][1005][2];// die or not die
bool dp2[1005][1005][2];
std::pair<int,int> to[1005][1005][2];
bool check(long double k){
  for(int j=0;j<=m;j++){
    dp[0][j][1]=-0x3f3f3f3f3f3f3f;
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++){
      // dp[i][j]=std::max(dp[i-1][j]-k*d[i],dp[i-1][j-t[i]]+(a[i]+c[i])-k*b[i])
      dp[i][j][0]=-0x3f3f3f3f3f3f3f;
      if(d[i]==0){
        dp[i][j][0]=std::max(dp[i][j][0],dp[i-1][j][0]-k*d[i]);
        if(dp[i][j][0]==dp[i-1][j][0]-k*d[i]){
          to[i][j][0]=std::make_pair(j,0ll);
          dp2[i][j][0]=0;
        }
      }
      if(b[i]==0&&j>=t[i]){
        dp[i][j][0]=std::max(dp[i][j][0],(dp[i-1][j-t[i]][0]+(a[i]+c[i])-k*b[i]));
        if(dp[i][j][0]==(dp[i-1][j-t[i]][0]+(a[i]+c[i])-k*b[i])){
          to[i][j][0]=std::make_pair(j-t[i],0ll);
          dp2[i][j][0]=1;
        }       
      }
      dp[i][j][1]=std::max(dp[i-1][j][1]-k*d[i],j>=t[i]?(dp[i-1][j-t[i]][1]+(a[i]+c[i])-k*b[i]):-0x3f3f3f3f3f3f3f);
      if(dp[i][j][1]==dp[i-1][j][1]-k*d[i]||j<t[i]){
        to[i][j][1]=std::make_pair(j,1ll);
        dp2[i][j][1]=0;
      }else{
        to[i][j][1]=std::make_pair(j-t[i],1ll);
        dp2[i][j][1]=1;
      }
      if(d[i]!=0){
        dp[i][j][1]=std::max(dp[i][j][1],dp[i-1][j][0]-k*d[i]);
        if(dp[i][j][1]==dp[i-1][j][0]-k*d[i]){
          to[i][j][1]=std::make_pair(j,0ll);
          dp2[i][j][1]=0;
        }
      }
      if(b[i]!=0&&j>=t[i]){
        dp[i][j][1]=std::max(dp[i][j][1],j>=t[i]?(dp[i-1][j-t[i]][0]+(a[i]+c[i])-k*b[i]):-0x3f3f3f3f3f3f3f);
        if(dp[i][j][1]==(dp[i-1][j-t[i]][0]+(a[i]+c[i])-k*b[i])){
          to[i][j][1]=std::make_pair(j-t[i],0ll);
          dp2[i][j][1]=1;
        }
      }
    }
  }
  return dp[n][m][1]>=0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("kda.in","r",stdin);
  freopen("kda.out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=n;i++){
    t[i]=read();
    a[i]=read();
    b[i]=read();
    c[i]=read();
    d[i]=read();
  }
  long double l=0,r=1000000000;
  for(int i=1;i<=50;i++){
    long double mid=(l+r)/2;
    if(check(mid)){
      l=mid;
    }else{
      r=mid;
    }
  }
  long double ans2=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=m;j++){
      dp[i][j][0]=-0x3f3f3f3f;
      if(d[i]==0){
        dp[i][j][0]=dp[i-1][j][0];
      }
      if(j>=t[i]&&b[i]==0){
        dp[i][j][0]=std::max(dp[i-1][j-t[i]][0]+a[i]+c[i],dp[i][j][0]);
      }
    }
  }
  ans2=dp[n][m][0];
  if(ans2>l){
    printf("%lld %lld\n",(int)ans2,1ll);
  }else{
    int ans1=0,ans2=0;
    int cur=m;
    int cur2=1;
    int ret=check(l);
    for(int i=n;i>=1;i--){
      if(dp2[i][cur][cur2]){
        ans1+=a[i];
        ans1+=c[i];
        ans2+=b[i];
        std::cerr<<i<<std::endl;
      }else{
        ans2+=d[i];
        std::cerr<<i<<' '<<d[i]<<std::endl;
      }
      auto temp=to[i][cur][cur2];
      cur=temp.first;
      cur2=temp.second;
    }
    int tt=std::__gcd(ans1,ans2);
    ans1/=tt;
    ans2/=tt;
    printf("%lld %lld\n",ans1,ans2);
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
