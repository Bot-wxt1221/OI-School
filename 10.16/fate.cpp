#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int a[300005];
int pow(long long x,int y){
  long long ans=1;
  while(y){
    if(y&1){
      ans*=x;
      ans%=mod;
    }
    x*=x;
    x%=mod;
    y>>=1;
  }
  return ans;
}
int C(int n,int m){
  long long ans=1;
  for(int i=1;i<=m;i++){
    ans*=(n-i+1);
    ans%=mod;
    ans*=pow(i,mod-2);
    ans%=mod;
  }
  return ans;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("fate.in","r",stdin);
	freopen("fate.out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  int x=read();
  int ans=1;
  for(int i=1;i<x;i++){
    ans*=(a[i]-a[i-1]+1);
    ans%=mod;
  }
  ans*=C(a[x+1]-a[x]+n-x,n-x);
  ans%=mod;
  printf("%lld",ans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
