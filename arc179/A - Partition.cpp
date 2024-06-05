#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int k=read();
  int sum=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    sum+=a[i];
  }
  if(0<k){
    std::sort(a+1,a+n+1);
    int pre=0;
    int sum=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
      sum+=a[i];
      if(sum<k&&pre>=k){
        cnt++;
      }
    }
    if(cnt){
      printf("No\n");
      return 0;
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++){
      printf("%lld ",a[i]);
    }
  }else{
    int pre=0;
    int sum=0;
    int cnt=0;
    std::sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
      sum+=a[i];
      if(sum<k&&pre>=k){
        cnt++;
      }
    }
    if(cnt){
      printf("No\n");
      return 0;
    }
    printf("Yes\n");
    for(int i=n;i>=1;i--){
      printf("%lld ",a[i]);
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

