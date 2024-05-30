#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define int long long
#define mod 998244353
inline int read();
class node{
  public:
    int t,x;
}ma[1000005];
bool cmp(node a,node b){
  return a.t<b.t;
}
int fac[200005];
int pow(int x,int y,int p=mod){
  if(y==0){
    return 1;
  }
  if(y%2){
    return (pow(x,y-1)*x)%p;
  }
  int tt=pow(x,y/2);
  return (tt*tt)%p;
}
int dfs(int n,int k,int l,int r){
  int cnt=0;
  if(l>r){
    return pow(fac[k],n*pow(k,n-1,mod-1)%(mod-1));
  }
  int prel=l;
  int nowl=l-1;
  for(int i=1;i<=k;i++){
    int ql=(i-1)*pow(n,k-1)+1,qr=(i)*pow(n,k-1);
    while(ql<=ma[nowl+1].t&&ma[nowl+1].t<=qr){
      nowl++;
    }
    
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  fac[0]=1;
  for(int i=1;i<=200000;i++){
    fac[i]=fac[i-1]*i%mod;
  }
  while(T--){
    int k=read(),n,m;
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
      ma[i].x=read();
      ma[i].t=read();
    }
    std::sort(ma+1,ma+m+1,cmp);
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


