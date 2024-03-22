#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int yin[2000005];
void init(int n){
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      yin[j]+=1;
    }
  }
  return ;
}
int calc(int n,int k,int p){
  int ret=0;
  for(int i=k;i<=n;i+=k){
    ret+=yin[i];
    ret%=p;
  }
  return ret;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int p=read();
  init(std::max(n,m));
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=(calc(n,i,p)*calc(m,i,p))%p;
    ans%=p;
  }
  printf("%lld",ans);
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


