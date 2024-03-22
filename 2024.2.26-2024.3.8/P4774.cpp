#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
#define int __int128
std::multiset<int>se;
inline int read();
int a[100005];
int p[100005];
int kill[100005];
int n,m;
int fir[100005];
namespace magic{
int xi[100005];
int ans[100005];
int mod[100005];
int mans;
int exgcd(int x,int y,int &a,int &b){
  if(y==0){
    a=1;
    b=0;
    return x;
  }else{
    int ta,tb;
    int ret=exgcd(y,x%y,ta,tb);
    a=tb;
    b=(ta)-(x/y)*tb;
    return ret;
  }
}
int getans(){
  int a1,b1;
  int M=1;
  int curans=0;
  for(int i=1;i<=n;i++){
    if(mod[i]!=1){
      break;
    }
    if(i==n){
      return mans;
    }
  }
  for(int i=1;i<=n;i++){
    int ret=exgcd((xi[i]*M)%mod[i],mod[i],a1,b1);
    a1%=mod[i];
    a1+=mod[i];
    a1%=mod[i];
    int C=(ans[i]-curans*xi[i])%mod[i];
    C+=mod[i];
    C%=mod[i];
    if((C)%ret){
      return -1;
    }
    int bM=M;
    M*=mod[i];
    M/=ret;
    curans+=((C/ret)*(a1))%(mod[i]/ret)*bM%M;
    curans%=M;
  }
  if(curans<mans){
    curans+=((mans-curans-1)/(M)+1)*M;
  }
  return curans;
}
};
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    m=read();
    int mxa=0;
    se.clear();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    for(int i=1;i<=n;i++){
      p[i]=read();
    }
    for(int i=1;i<=n;i++){
      kill[i]=read();
    }
    for(int i=1;i<=m;i++){
      fir[i]=read();
      se.insert(fir[i]);
    }
    for(int i=1;i<=n;i++){
      if(se.upper_bound(a[i])==se.begin()){
        magic::xi[i]=*se.begin();
        se.erase(se.begin());
      }else{
        auto tt=se.begin();
        magic::xi[i]=*(tt=(--se.upper_bound(a[i])));
        se.erase(tt);
      }
      se.insert(kill[i]);
      magic::ans[i]=a[i];
      magic::mod[i]=p[i];
      mxa=std::max(mxa,(a[i]-1)/magic::xi[i]+1);
    }
    magic::mans=mxa;
    printf("%lld\n",magic::getans());
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


