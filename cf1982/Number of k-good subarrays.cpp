#include <iostream>
#include <cstdio>
#include <map>
#define int __int128
#define mod 1000000007
inline int read();
std::map<int,int>mp[75];
int solve(int r,int k){
  if(mp[k][r]){
    return mp[k][r];
  }
  if(k==0){
    return 1;
  }
  int tl=1;
  int cnt=-1;
  while(tl-1<=r){
    tl*=2;
    cnt++;
  }
  tl/=2;
  if(cnt<=k){
    return mp[k][r]=((r+1)*r/2+(r+1))%mod;
  }
  if(tl-1==r&&cnt<=k+1){
    if(cnt==k+1){
      return mp[k][r]=((r)*(r-1)/2+(r))%mod;
    }else{
      return mp[k][r]=((r+1)*r/2+(r+1))%mod;
    }
  }else if(tl-1==r){
    tl/=2;
    cnt--;
  }
  int ret=solve(tl-1,k);
  ret+=solve(r-tl,k-1);
  ret%=mod;
  return mp[k][r]=ret;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read(),k;
    k=read();
    printf("%lld\n",(long long)(solve(n-1,k)));
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
