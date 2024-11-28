#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int a[1000005];
int fa[1000005];
int dis[1000005];
int getfa(int x){
  if(x==fa[x]){
    return x;
  }
  int fx=getfa(fa[x]);
  dis[x]+=dis[fa[x]];
  dis[x]%=mod;
  fa[x]=fx;
  return fx;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    fa[i]=i;
  }
  int ans=0;
  for(int i=1;i<=m;i++){
    fa[i+n]=i+n;
    int x=read();
    int y=read();
    int p=read();
    int fx=getfa(x);
    int fy=getfa(y);
    ans+=dis[x]+a[x];
    ans%=mod;
    ans+=dis[y]+a[y];
    ans%=mod;
    if(fx!=fy){
      fa[fx]=i+n;
      fa[fy]=i+n;
      dis[fy]=1ll*(1-p)*a[fx]%mod;
      dis[fx]=1ll*((p)+mod)%mod*a[fy]%mod;
      a[i+n]=(dis[fx]+dis[fy])%mod;
    }
  }
  ans+=mod;
  ans%=mod;
  printf("%lld",ans);
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
