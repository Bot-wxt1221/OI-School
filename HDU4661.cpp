#include <iostream>
#include <cstdio>
#define mod 1000000007
inline int read();
inline int pow(int a,int k){
  long long res=1;
  while(k){
    if(k&1){
      #ifdef mod
      res=1ll*res*a%mod;
      #else
      res*=a;
      #endif
    }
    #ifdef mod
    a=1ll*a*a%mod;
    #else
    a*=a;
    #endif
    k>>=1;
  }
  return res;
}
int dp[1000005];
int siz[1000005];
int fir[1000005];
int fac[1000005];
int inv[1000005];
int nxt[2000005];
int v[2000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int ans=0;
void dfs(int now,int fa){
  dp[now]=1;
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    dp[now]=1ll*dp[now]*dp[v[i]]%mod;
    dp[now]=1ll*dp[now]*inv[siz[v[i]]]%mod;
  }
  dp[now]=1ll*dp[now]*fac[siz[now]-1]%mod;
}
int n;
void dfs2(int now,int fa){
  int predp=dp[now];
  if(now!=fa){
    dp[now]=1ll*dp[now]*inv[siz[now]-1]%mod;
    dp[now]=1ll*dp[now]*dp[fa]%mod;
    dp[now]=1ll*dp[now]*inv[n-siz[now]]%mod;
    int tt=1ll*dp[now]*fac[n-1]%mod;
    ans+=1ll*tt*tt%mod;
    ans%=mod;
  }else{
    ans+=1ll*dp[now]*dp[now]%mod;
    ans%=mod;
    dp[now]=1ll*dp[now]*inv[siz[now]-1]%mod;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dp[now]=1ll*dp[now]*pow(dp[v[i]],mod-2)%mod;
    dp[now]=1ll*dp[now]*fac[siz[v[i]]]%mod;
    dp[now]=1ll*dp[now]*fac[n-siz[v[i]]-1]%mod;
    dfs2(v[i],now);
    dp[now]=1ll*dp[now]*dp[v[i]]%mod;
    dp[now]=1ll*dp[now]*inv[siz[v[i]]]%mod;
    dp[now]=1ll*dp[now]*inv[n-siz[v[i]]-1]%mod;
  }
  dp[now]=predp;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  fac[0]=1;
  for(int i=1;i<=1000000;i++){
    fac[i]=1ll*fac[i-1]*i%mod;
  }
  inv[1000000]=pow(fac[1000000],mod-2);
  for(int i=999999;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mod;
  }
  while(T--){
    n=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    now=0;
    for(int i=1;i<n;i++){
      int a=read();
      int b=read();
      add(a,b);
      add(b,a);
    }
    ans=0;
    dfs(1,1);
    dfs2(1,1);
    printf("%d\n",ans);
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
