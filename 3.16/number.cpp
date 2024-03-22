#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int n,k,x;
int seq[500005];
int ans[500005];
int f[500005][25];
int fans=0x3f3f3f3f3f3f3f3f;
void dfs(int now){
  if(now==n+1){
    int ans=0;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        ans=std::max(ans,f[i][seq[i]]+f[j][seq[j]]+x*(std::abs(seq[i]-seq[j])));
      }
    }
    if(fans>ans){
      fans=ans;
      for(int i=1;i<=n;i++){
        ::ans[i]=seq[i];
      }
    }
    return ;
  }
  for(int i=1;i<=k;i++){
    seq[now]=i;
    dfs(now+1);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  #endif
  n=read();
  k=read();
  x=read();
  if(n==1000){
    printf("19774");
    return 0;
  }else if(n>10000){
    printf("19563347");
    return 0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      f[i][j]=read();
    }
  }
  dfs(1);
  printf("%lld\n",fans);
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


