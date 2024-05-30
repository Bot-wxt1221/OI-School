#include <iostream>
#include <cstdio>
inline int read();
int a[100005],b[100005];
int cnt[100005];
int n,m,k;
int ans=0x3f3f3f3f;
void dfs(int now){
  if(now==n+1){
    int nans=0;
    for(int i=1;i<=m;i++){
      if(cnt[i]%2){
        nans++;
      }
    }
    ans=std::min(ans,nans);
    return ;
  }
  cnt[a[now]]++;
  dfs(now+1);
  cnt[a[now]]--;
  if(a[now]==b[now]){
    return ;
  }
  cnt[b[now]]++;
  dfs(now+1);
  cnt[b[now]]--;
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("math.in","r",stdin);
  freopen("math.out","w",stdout);
  #endif
  n=read();
  m=read();
  k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
  }
  if(n<=20){
    dfs(1);
    printf("%d",k-ans);
  }else{
    for(int i=1;i<=n;i++){
      cnt[a[i]]++;
    }
    int ans=0;
    for(int i=1;i<=m;i++){
      ans+=(cnt[i]%2);
    }
    printf("%d",k-ans);
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


