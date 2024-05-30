#include <iostream>
#include <cstdio>
#include <map>
#define mod 998244353
#define int long long
inline int read();
std::map<int,std::pair<int,int> >mp;
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int temp=pow(x,y/2);
    return (1ll*temp*temp)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
std::pair<int,int> dfs(int n){
  if(n==1){
    return {1,0};
  }
  if(mp.count(n)){
    return mp[n];
  }
  int mid=(1+n)/2;
  auto ret1=dfs(mid);
  auto ret2=dfs(n-mid);
  return mp[n]={(((ret1.first+ret2.first)%mod*2)%mod+((pow(2,mid)+0ll+mod-1)%mod)*((0ll+pow(2,n-mid)+mod-1)%mod))%mod,(0ll+ret1.second+ret2.second+ret2.first)%mod};
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    auto ret=dfs(n);
    printf("%lld\n",(ret.first+ret.second)%mod);
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

