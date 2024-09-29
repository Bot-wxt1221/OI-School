#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
inline long long read();
int pow(long long a,long long n){
  n%=(mod-1);
  if(n<0){
    return 0;
  }
  long long res=1;
	while(n)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res;
}
int dp[125];
int fac[100005];
int inv[100005];
int siz[2][3][125];
void merge(int *seq,int *seq1,int *seq2,int cnt){
  for(int i=0;i<=124;i++){
    seq[i]=0;
  }
  for(int i=0;i<=120;i++){
    for(int j=0;i+j+2<=120;j++){
      dp[i+j+2]+=1ll*seq1[i]*seq2[j]%mod*cnt%mod;
      dp[i+j+2]%=mod;
    }
  }
  for(int i=0;i<=120;i++){
    dp[i+1]+=1ll*seq1[i]*cnt%mod;
    dp[i+1]%=mod;
    dp[i+1]+=1ll*seq2[i]*cnt%mod;
    dp[i+1]%=mod;
    seq[i+1]+=seq1[i];
    seq[i+1]%=mod;
    seq[i+1]+=seq2[i];
    seq[i+1]%=mod;
  }
  seq[0]++;
  return ;
}
long long get(long long n){
  long long cnt=0;
  for(int i=0;i<60;i++){
    if(n>(1ll<<i)){
      n-=(1ll<<i);
      cnt+=(1ll<<i);
    }else{
      return cnt;
    }
  }
  return cnt;
}
long long get2(long long n){
  long long cnt=0;
  for(int i=0;i<60;i++){
    if(n>(1ll<<i)){
      n-=(1ll<<i);
      cnt+=(1ll<<i);
    }else{
      return n-1;
    }
  }
  return n-1;
}
void merge(long long n){
  int op=0;
  int fir=0;
  memset(siz[op],0,sizeof(siz[op]));
  siz[op][0][0]=siz[op][1][0]=1;
  long long cnt=get(n)+1;
  long long cnt2=get2(n);
  while(n>1){
    op^=1;
    if(n%2==0){
      cnt/=2;
      cnt2/=2;
      merge(siz[op][0],siz[op^1][0],siz[op^1][0],cnt2%mod);
      merge(siz[op][1],siz[op^1][1],siz[op^1][2],1);
      merge(siz[op][2],siz[op^1][2],siz[op^1][2],(cnt-cnt2-1)%mod);
    }else{
      cnt/=2;
      cnt2/=2;
      merge(siz[op][0],siz[op^1][0],siz[op^1][0],cnt2%mod);
      merge(siz[op][1],siz[op^1][0],siz[op^1][1],1);
      merge(siz[op][2],siz[op^1][2],siz[op^1][2],(cnt-cnt2-1)%mod);
    }
    fir=1;
    n>>=1;
  }
  return ;
}
int C(int n,int m){
  return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int precnt[125];
int pw[125];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  fac[0]=1;
  for(int i=1;i<=100000;i++){
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  inv[100000]=pow(fac[100000],mod-2);
  for(int i=99999;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  while(T--){
    long long n=read();
    int m=read();
    memset(dp,0,sizeof(dp));
    memset(precnt,0,sizeof(precnt));
    merge(n);
    dp[0]=n%mod;
    long long ans=0;
    for(int i=0;i<=120;i++){
      pw[i]=pow(m,n-i-1);
    }
    for(int j=1;j<=m;j++){//max
      for(int i=0;i<=120;i++){//length
        int cnt=0;
        cnt+=1ll*pw[i]*pow(j,i+1)%mod;
        cnt%=mod;
        ans+=1ll*(cnt-precnt[i])*dp[i]%mod*j%mod;
        ans%=mod;
        precnt[i]=cnt;
      }
    }
    ans+=mod;
    ans%=mod;
    printf("%lld\n",ans);
  }
  return 0;
}
inline long long read(){
  long long x=0,f=1;char c=getchar();
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
