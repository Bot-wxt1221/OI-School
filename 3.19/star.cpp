#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
#define mod 998244353
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2){
    return (pow(x,y-1)*x)%mod;
  }
  int tt=pow(x,y/2);
  return (tt*tt)%mod;
}

int fir[1000005];
int nxt[2000005];
int v[2000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int ans=0;
int siz[1000005];
int n;
int fac[1000005];
int inv[1000005];
int in[1000005];
int C(int n,int m){
  return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("star.in","r",stdin);
  freopen("star.out","w",stdout);
  #endif
  n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  int cnt=0;
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    cnt+=(x==1);
    add(x,y);
    add(y,x);
  }
  fac[0]=1;
  for(int i=1;i<=1000000;i++){
    fac[i]=fac[i-1]*(i)%mod;
  }
  inv[1000000]=pow(fac[1000000],mod-2);
  for(int i=1000000;i>=0;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  int cntt=0;
  if(n<=15){
    for(int i=0;i<(1<<n);i++){
      int used=0;
      for(int j=1;j<=n;j++){
        in[j]=0;
      }
      for(int j=0;j<n;j++){
        if(i&(1<<j)){
          used++;
          for(int k=fir[j+1];k!=-1;k=nxt[k]){
            if((1<<(v[k]-1))&i){
              in[j+1]++;
            }
          }
        }
      }
      int ans=0;
      for(int j=1;j<=n;j++){
        if(in[j]>=3){
          ans++;
        }
      }
      if(ans==1){
        cntt+=1;
        cntt%=mod;
      }
    }
    printf("%lld",cntt%mod);
  }else if(cnt==n-1){
    int ans=0;
    for(int i=3;i<=n-1;i++){
      ans+=C(n-1,i);
      ans%=mod;
    }
    printf("%lld",ans);
    return 0;
  }else if(cnt==1){
    printf("0");
    return  0;
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


