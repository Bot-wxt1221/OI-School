#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int a[100005];
int cnt[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("sequence.in","r",stdin);
  freopen("sequence.out","w",stdout);
  #endif
  int T=read();
  int id=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
      cnt[i]=0;
      while(a[i]<a[i-1]){
        a[i]*=2;
        cnt[i]++;
      }
    }
    std::sort(cnt+1,cnt+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
      ans+=std::abs(cnt[i]-cnt[(n+1)/2]);
    }
    printf("%lld\n",ans);
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

