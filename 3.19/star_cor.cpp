#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int n;
int siz[1000005];
int ans=0;
void dfs(int now,int fa){
  siz[now]=1;
  int sum=-1;
  int sum2=1;
  int num=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    num++;
    dfs(v[i],now);
    sum2*=(siz[v[i]]+1);
    sum2%=mod;
    sum-=siz[v[i]];
    sum-=(siz[now]-1)*siz[v[i]]%mod;
    sum%=mod;
    siz[now]+=siz[v[i]];
  }
  if(now!=1){
    sum2*=((n-siz[now])+1);
    num++;
    sum2%=mod;
    sum-=(n-siz[now])%mod;
    sum-=(siz[now]-1)*(n-siz[now])%mod;
    sum%=mod;
  }
  if(num>=3){
    ans+=(sum2+sum)%mod;
    ans%=mod;
    ans+=mod;
    ans%=mod;
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
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
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


