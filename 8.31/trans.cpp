#include <iostream>
#include <cstdio>
#include <list>
#define mod 1000000007
inline int read();
int a[2000005];
class tt{
public:
  tt *nxt,*pre;
  int val;
  bool erase(){
    pre->nxt=nxt;
    nxt->pre=pre;
    return 0;
  }
}seq[6000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("trans.in","r",stdin);
  freopen("trans.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  seq[0].nxt=seq+1;
  for(int i=1;i<=6e6;i++){
    seq[i].pre=seq+i-1;
    seq[i].val=i;
    seq[i].nxt=seq+i+1;
  }
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans*=(a[i]-(seq[a[i]].pre)->val);
    ans%=mod;
    seq[a[i]].erase();
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
