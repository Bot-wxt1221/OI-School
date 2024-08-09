#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    int st=0;
    int ans=a[n];
    for(int i=n-1;i>=1;i--){
      if(a[i]<=a[i+1]){
        st+=(a[i+1]-a[i]+1);
      }else{
        if(a[i]-st<=a[i+1]){
          st++;
          a[i]=a[i+1];
        }else{
          a[i]-=st;
        }
      }
      ans=std::max(ans,st+a[i]);
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
