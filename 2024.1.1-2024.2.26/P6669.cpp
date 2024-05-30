#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
inline int read();
int dp[105][5][5][5][5];
int shun[105];
int k;
int shum[105];
int dfs(int now,bool ok,bool dif,bool difi,bool difj){
  if(now==0){
    return ok;
  }
  if(dp[now][ok][dif][difi][difj]){
    return dp[now][ok][dif][difi][difj];
  }
  int un,um;
  if(difi){
    un=k-1;
  }else{
    un=shun[now];
  }
  if(difj){
    um=k-1;
  }else{
    um=shum[now];
  }
  int ans=0;
  for(int i=0;i<=un;i++){
    for(int j=0;j<=um&&(j<=i||dif);j++){
      ans+=(dfs(now-1,ok|(i<j),dif|(i!=j),difi|(i<un),difj|(j<um)))%mod;
      ans%=mod;
    }
  }
  return dp[now][ok][dif][difi][difj]=ans;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int t=read();
  k=read();
  while(t--){
    memset(dp,0,sizeof(dp));
    int n=read();
    int m=read();
    int mx=std::max(n,m);
    int siz=0;
    while(mx>0){
      siz++;
      mx/=k;
    }
    for(int i=1;i<=siz;i++){
      shun[i]=n%k;
      n/=k;
      shum[i]=m%k;
      m/=k;
    }
    printf("%lld\n",dfs(siz,0,0,0,0));
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


