#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int mu[2000005];
int f[2000005];
int pr[2000005];
int cnt;
bool is[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  mu[1]=1;
  for(int i=2;i<=2000001;i++){
    if(is[i]==0){
      mu[i]=-1;
      pr[++cnt]=i;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*i*pr[j]>2000001){
        break;
      }
      is[i*pr[j]]=1;
      mu[i*pr[j]]=-mu[i];
      if(i%pr[j]==0){
        mu[i*pr[j]]=0;
      }
    }
  }
  for(int i=1;i<=n;i++){
    mu[i]+=mu[i-1];
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int l=1,r;l<=n/i;l=r+1){
      r=(n/i/(n/i/l));
      ans+=i*(n/i/l)*(n/i/l)*(mu[r]-mu[l-1]);
    }
  }
  printf("%lld",(ans-(n)*(n+1)/2)/2);
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


