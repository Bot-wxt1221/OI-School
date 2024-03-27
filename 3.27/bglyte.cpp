#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353ll
inline int read();
int a[55];
int p[55];
int fir[55];
int nxt[105];
int fa[105];
int siz[105];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int v[105];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (1ll*tt*tt)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("bglyte.in","r",stdin);
  freopen("bglyte.out","w",stdout);
  #endif
  int n=read();
  int k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    p[i]=read();
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int u=read();
    int v=read();
    add(u,v);
    add(v,u);
  }
  int tans=0;
  for(int i=0;i<(1<<n);i++){
    int gai=1;
    for(int j=1;j<=n;j++){
      fa[j]=j;
      siz[j]=0;
    }
    for(int j=0;j<n;j++){
      if((1<<j)&i){
        gai*=p[j+1];
        gai%=mod;
        for(int k=fir[j+1];k!=-1;k=nxt[k]){
          if((1<<(v[k]-1))&i){
            fa[getfa(v[k])]=getfa(j+1);
          }
        }
      }else{
        gai*=(1-p[j+1]+mod)%mod;
        gai%=mod;
      }
    }
    for(int j=1;j<=n;j++){
      if((1<<(j-1))&i){
        siz[getfa(j)]+=a[j];
      }
    }
    int nans=0;
    for(int j=1;j<=n;j++){
      if(getfa(j)==j&&((1<<(j-1))&i)){
        nans+=pow(siz[j],k);
        nans%=mod;
      }
    }
    tans+=(nans*gai)%mod;
    tans%=mod;
  }
  printf("%lld",tans);
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

