#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define mod 998244353
#define int __int128
inline int read();
std::vector<std::pair<int,int> >a;
int dp[(1<<20)+5][2];
int cnt[(1<<20)+5];
int pow(int a,int b,int p){
  int ans=1;
  a%=p;
  int cur=a;
  while(b){
    if(b%2==1){
      ans*=cur;
      ans%=p;
    }
    cur*=cur;
    cur%=p;
    b/=2;
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  int mm=m;
  for(int i=2;i<=1e8;i++){
    int cnt=0;
    while(mm%i==0){
      mm/=i;
      cnt++;
    }
    if(cnt){
      a.push_back(std::make_pair(i,cnt));
    }
  }
  if(mm!=1){
    a.push_back(std::make_pair(mm,1));
    mm=1;
  }
  for(int i=1;i<=n;i++){
    int aa=read();
    if(m%aa){
      continue;
    }
    int sta=0;
    for(int j=0;j<a.size();j++){
      int tt=pow(a[j].first,a[j].second,1e36);
      if(aa%tt==0){
        sta|=(1ll<<(j));
      }
    }
    cnt[sta]++;
  }
  dp[0][0]=1;
  int op=0;
  int up=(1ll<<(a.size()));
  for(int i=0;i<up;i++){
    op^=1;
    for(int j=0;j<up;j++){
      dp[j][op]=0;
    }
    int tt=pow(2,cnt[i],mod)-1;
    tt+=mod;
    tt%=mod;
    for(int j=up-1;j>=0;j--){
      dp[i|j][op]+=(dp[j][op^1]*tt)%mod;
      dp[i|j][op]%=mod;
      dp[j][op]+=dp[j][op^1];
      dp[j][op]%=mod;
    }
  }
  if(m==1){
    dp[up-1][op]+=mod-1;
    dp[up-1][op]%=mod;
  }
  printf("%lld",(long long)dp[up-1][op]);
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

