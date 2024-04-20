#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  std::sort(a+1,a+n+1);
  int cur=0;
  int ans1=0,ans2=0;
  int sum=0;
  for(int i=n;i>=1;i--){
    int tt=a[i];
    sum+=tt;
    if(tt==3){
      ans1=ans2+3;
      ans2=sum-ans1;
      continue;
    }
    if(ans2+tt>ans1+tt-4){
      ans1=ans2+tt;
      ans2=sum-ans1;
    }else{
      ans1=ans1+tt-4;
      ans2=sum-ans1;
    }
  }
  printf("%lld %lld",ans2,ans1);
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

