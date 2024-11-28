#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#define int long long
#define mod 998244353
inline int read();
int v[100005];
bool is_prime[100005];
int min[100005];
int plst[100005];
int cnt;
int ttt[100005];
int seq[100005];
int cnt1;
int pw[100005];
std::vector<int>vec[100005];
int pw2[100005];
int dp[100005];
int dp2[100005];
int cntt[100005];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("bead.in","r",stdin);
	freopen("bead.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  pw[0]=1;
  pw[1]=2;
  pw2[0]=1;
  pw2[1]=-1;
  int tans=0;
  min[1]=1;
  for(int i=2;i<=m;i++){
    pw2[i]=pw2[i-1]*-1;
    if(is_prime[i]==0){
      plst[++cnt]=i;
      min[i]=i;
      cntt[i]=1;
    }
    for(int j=1;j<=cnt;j++){
      if(plst[j]*i>m){
        break;
      }
      min[plst[j]*i]=plst[j];
      is_prime[plst[j]*i]=1;
      cntt[plst[j]*i]=cntt[i]+1;
      if(i%plst[j]==0){
        break;
      }
    }
  }
  for(int i=1;i<=m;i++){
    int ti=i;
    for(int j=1;j<=cnt&&1ll*plst[j]*plst[j]<=m;j++){
      if(i%plst[j]==0){
        vec[i].push_back(plst[j]);
      }
      while(ti%plst[j]==0){
        ti/=plst[j];
      }
    }
    if(ti!=1){
      vec[i].push_back(ti);
    }
  }
  for(int i=1;i<=n;i++){
    pw[i]=pw[i-1]*2%mod;
    v[i]=read();
    assert(v[i]<=m);
    cnt1=0;
    int st=std::sqrt(v[i]);
    for(int j=1;j<=st;j++){
      if(v[i]%j==0){
        seq[++cnt1]=j;
        if(v[i]/j>j){
          seq[++cnt1]=v[i]/j;
        }
      }
    }
    std::sort(seq+1,seq+cnt1+1);
    for(int j=1;j<=cnt1;j++){
      dp2[seq[j]]=pw[ttt[seq[j]]];
    }
    for(int k=cnt1;k>=1;k--){
      for(int j=cnt1;j>=2;j--){
        if(seq[k]%seq[j]){
          continue;
        }
        dp2[seq[k]/seq[j]]+=dp2[seq[k]]*-1;
      }
    }
    for(int j=1;j<=cnt1;j++){
      tans+=dp2[seq[j]]*seq[j]%mod;
      tans%=mod;
      dp[seq[j]]=0;
      dp2[seq[j]]=0;
      ttt[seq[j]]++;
    }
  }
  tans+=mod;
  tans%=mod;
  printf("%lld",tans);
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
