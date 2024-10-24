#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#define mod 1000000007
#define int long long
inline int read();
int seq[1005];
int pw[1005];
int dp[2][85][85][85];
std::vector<int>vec;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  pw[0]=1;
  for(int i=1;i<=n;i++){
    pw[i]=pw[i-1]*2%mod;
    seq[i]=read();
  }
  int ans=0;
  dp[0][0][0][0]=1;
  int op=0;
  for(int i=1;i<=n;i++){
    op^=1;
    memset(dp[op],0,sizeof(dp[op]));
    for(int a=0;a<=75;a++){
      for(int b=a;b<=75;b++){
        for(int c=b;c<=75;c++){
          if(dp[op^1][a][b][c]==0){
            continue;
          }
          vec.clear();
          vec.push_back(std::max(0ll,a-(seq[i]-seq[i-1])));
          vec.push_back(std::max(0ll,b-(seq[i]-seq[i-1])));
          vec.push_back(std::max(0ll,c-(seq[i]-seq[i-1])));
          vec.resize(6,0);
          for(int i=0;i<3;i++){
            if(i+1<6){
              vec[i+1]=std::max(vec[i+1],vec[i]+20);
            }
            if(i+3<6){
              vec[i+3]=std::max(vec[i+3],vec[i]+75);
            }
          }
          for(int i=1;i<6;i++){
            vec[i]=std::max(vec[i],vec[i-1]);
          }
          dp[op][vec[0]][vec[1]][vec[2]]+=dp[op^1][a][b][c];
          dp[op][vec[0]][vec[1]][vec[2]]%=mod;
          int now=0;
          while(vec[now]==0){
            now++;
          }
          ans+=dp[op^1][a][b][c]*pw[n-i]%mod*(now)%mod;
          ans%=mod;
          dp[op][vec[now]][vec[now+1]][vec[now+2]]+=dp[op^1][a][b][c];
          dp[op][vec[now]][vec[now+1]][vec[now+2]]%=mod;
        }
      }
    }
  }
  ans*=2;
  ans%=mod;
  ans+=mod;
  ans%=mod;
  printf("%lld",ans);
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
