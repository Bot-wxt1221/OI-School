#include <iostream>
#include <cstdio>
#include <map>
#define mod 2004
#define int long long
inline int read();
std::map<int,int>mp[2];
int C(int n,int m){
  if(n==m){
    return 1;
  }
  if(m==0){
    return 1;
  }
  if(m==-1){
    return 0;
  }
  if(n-m<m){
    m=n-m;
  }
  int M=mod;
  for(int i=1;i<=m;i++){
    M*=i;
  }
  int ans=1;
  for(int i=1;i<=m;i++){
    ans*=(n-i+1);
    ans%=M;
  }
  return ans/(M/mod);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("P6078_3.in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int a=read();
  int b=read();
  int op=0;
  mp[op][0]=1;
  for(int i=1;i<=n;i++){
    int x=read();
    op^=1;
    mp[op].clear();
    for(auto i=mp[op^1].begin();i!=mp[op^1].end();i++){
      mp[op][i->first+x+1]+=mod-i->second;
      mp[op][i->first+x+1]%=mod;
      mp[op][i->first]+=i->second;
      mp[op][i->first]%=mod;
    }
  }
  int tans=0;
  for(auto i=mp[op].begin();i!=mp[op].end();i++){
    int nans=(i->second);
    if(i->first>b){
      continue;
    }
    tans+=((nans)*(C(n+b-i->first,b-i->first)-C(n+std::max(a-i->first,0ll)-1,std::max(a-i->first,0ll)-1)))%mod;
    tans%=mod;
  }
  printf("%lld",tans);
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

