#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[300005];
int n,m;
bool check(int ans){
  int nn=n;
  for(int i=1;i<=m;i++){
    nn-=(a[i]/ans+((a[i]%ans)>0));
  }
  return nn>=0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("bear.in","r",stdin);
  freopen("bear.out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=m;i++){
    a[i]=read();
  }
  int l=1,r=(int)(1e9)*m;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      r=mid+1;
    }else{
      l=mid-1;
    }
  }
  for(int i=l;i<=r;i++){
    if(check(i)){
      printf("%lld",i);
      return 0;
    }
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


