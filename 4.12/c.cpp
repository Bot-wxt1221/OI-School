#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int n,m;
int a[55],b[55];
int usedb[55];
int ans=0x3f3f3f3f3f3f3f3f;
int tot=0;
void dfs(int now){
  if(now==n+1){
    for(int i=1;i<=m;i++){
      if(usedb[i]==0){
        return ;
      }
    }
    ans=std::max(ans,tot);
    return ;
  }
  for(int i=1;i<=m;i++){
    tot+=std::abs(b[i]-a[now]);
    usedb[i]++;
    dfs(now+1);
    usedb[i]--;
    tot-=std::abs(b[i]-a[now]);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=m;i++){
    b[i]=read();
  }
  dfs(1);
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

