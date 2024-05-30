#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define int long long
inline int read();
int a[55];
int b[55];
int l[55];
int r[55];
int dp[55][55][55][55];
int n,m,q;
std::map<int,int>mp;
int solve(int t,int l,int r,int lim){
  if(dp[t][l][r][mp[lim]]!=-1){
    return dp[t][l][r][mp[lim]];
  }
  if(l>r){
    return 0;
  }
  int mx=n+1;
  for(int i=l;i<=r;i++){
    if(b[i]<lim&&b[i]>b[mx]){
      mx=i;
    }
  }
  int ans=0x7f7f7f7f7f7f7f7f;
  if(t>0){
    ans=std::min(ans,solve(t-1,l,r,b[mx]));
  }
  if(mx==n+1){
    ans=0;
    return dp[t][l][r][mp[lim]]=ans;
  }
  int cost=0;
  for(int i=1;i<=q;i++){
    if(::l[i]>=l&&::l[i]<=mx&&::r[i]<=r&&::r[i]>=mx){
      cost+=a[mx];
    }
  }
  for(int i=0;i<=t;i++){
    ans=std::min(ans,solve(i,l,mx-1,b[mx])+solve(t-i,mx+1,r,b[mx])+cost);
  }
  return dp[t][l][r][mp[lim]]=ans;
}
int p[55];
bool cmp(int x,int y){
  return a[x]<a[y];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  q=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    p[i]=i;
  }
  std::sort(p+1,p+n+1,cmp);
  for(int i=1;i<=n;i++){
    b[p[i]]=i;
    mp[b[p[i]]]=p[i];
  }
  for(int i=1;i<=q;i++){
    l[i]=read();
    r[i]=read();
  }
  memset(dp,-1,sizeof(dp));
  printf("%lld",solve(m,1,n,0x7f7f7f7f7f7f7f7f));
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

