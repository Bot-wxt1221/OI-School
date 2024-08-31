#include <iostream>
#include <cstdio>
#include <cstring>
#define int __int128
inline int read();
int lowbit(int x){
  return x&(-x);
}
int seq[1000005];
int aa[1000005];
class BIT{
public:
  int tree[500005];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void add(int now,int a){
    while(now<=500000){
      tree[now]+=a;
      now+=lowbit(now);
    }
    return ;
  }
}a;
int dp[1000005][2];
int cnt[1000005][2];
int calc(int n,int k,int mod,int sn){
  memset(cnt,0,sizeof(cnt));
  memset(dp,0,sizeof(dp));
  dp[n+1][1]=1;
  for(int i=n;i>=1;i--){
    int cntt=seq[i];
    dp[i][1]+=dp[i+1][1];
    dp[i][1]%=mod;
    cnt[i][1]=(cnt[i+1][1]+cntt*(i<=sn))%mod;
    dp[i][0]+=dp[i+1][1]*(cntt)%mod;
    dp[i][0]%=mod;
    cnt[i][0]=cnt[i+1][1]*cntt%mod+dp[i+1][1]*((cntt)*(i<=sn)*(cntt-1)/2%mod)%mod;
    cnt[i][0]%=mod;
    dp[i][0]+=dp[i+1][0]*i%mod;
    dp[i][0]%=mod;
    cnt[i][0]+=cnt[i+1][0]*i%mod+dp[i+1][0]*(i<=sn)*((i-1)*(i)/2%mod)%mod;
    cnt[i][0]%=mod;
  }
  return cnt[1][0]+cnt[1][1];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("army.in","r",stdin);
  freopen("army.out","w",stdout);
  #endif
  int n=read();
  int sn=n;
  int k=read()-1;
  int mod=read();
  for(int i=1;i<=n;i++){
    aa[i]=read();
  }
  int pre=0;
  for(int i=n;i>=1;i--){
    a.add(aa[i],1);
    seq[n-i+1]=a.query(aa[i])-1;
    pre-=seq[n-i+1];
  }
  pre+=calc(n,k,mod,sn);
  bool pree=1;
  for(int i=1;i<=5e5;i++){
    pree=k;
    seq[i]+=k%(i);
    if(seq[i]){
      n=std::max(n,i);
    }
    k/=(i);
    seq[i+1]+=seq[i]/(i);
    if(seq[i+1]){
      n=std::max(n,i+1);
    }
    seq[i]%=(i);
  }
  int nxt=calc(n,k,mod,sn);
  printf("%lld",(long long)((nxt-pre+mod)%mod));
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
