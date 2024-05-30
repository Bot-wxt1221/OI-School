#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int x[200005];
int siz[200005];
int yes[200005];
int pre[200005];
int ans[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),q;
  q=read();
  for(int i=1;i<=q;i++){
    x[i]=read();
  }
  for(int i=1;i<=q;i++){
    if(yes[x[i]]){
      pre[i]=yes[x[i]];
      yes[x[i]]=0;
      siz[i]=siz[i-1]-1;
    }else{
      yes[x[i]]=i;
      siz[i]=siz[i-1]+1;
    }
  }
  for(int i=1;i<=q;i++){
    siz[i]+=siz[i-1];
  }
  for(int i=1;i<=q;i++){
    if(pre[i]){
      ans[x[i]]+=siz[i-1]-siz[pre[i]-1];
    }
  }
  for(int i=1;i<=n;i++){
    if(yes[i]){
      ans[i]+=siz[q]-siz[yes[i]-1];
    }
  }
  for(int i=1;i<=n;i++){
    printf("%lld ",ans[i]);
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

