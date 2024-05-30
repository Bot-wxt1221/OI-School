#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int n,k;
int a[100005];
int b[100005];
long double t[100005];
bool check(long double tt){
  for(int i=1;i<=n;i++){
    t[i]=a[i]-b[i]*tt;
  }
  std::sort(t+1,t+n+1);
  long double sum=0;
  for(int i=n;i>=n-k+1;i--){
    sum+=t[i];
  }
  return sum>=0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("salt.in","r",stdin);
  freopen("salt.out","w",stdout);
  #endif
  n=read();
  k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
  }
  long double l=0,r=10;
  for(int i=1;i<=60;i++){
    long double mid=(l+r)/2;
    if(check(mid)){
      l=mid;
    }else{
      r=mid;
    }
  }
  printf("%.7Lf",l);
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

