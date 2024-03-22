#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int mu[10000005];
int f[10000005];
int p[10000005];
bool shai[10000005];
void init(){
  mu[1]=1;
  int cnt=0;
  for(int i=2;i<=10000000;i++){
    if(shai[i]==0){
      p[++cnt]=i;
      mu[i]=-1;
      f[i]=1;
    }
    for(int j=1;j<=cnt;j++){
      if(1ll*p[j]*i>10000000){
        break;
      }
      shai[p[j]*i]=1;
      if(i%p[j]==0){
        f[p[j]*i]=mu[i];
        mu[p[j]*i]=0;
        break;
      }
      f[p[j]*i]=-f[i]+mu[i];
      mu[p[j]*i]=-mu[i];
    }
  }
  for(int i=1;i<=10000000;i++){
    f[i]+=f[i-1];
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  init();
  while(T--){
    int n=read();
    int m=read();
    int ans=0;
    for(int i=1,j;i<=std::min(n,m);i=j+1){
      j=std::min(n/((n/i)),m/(m/i));
      ans+=(f[j]-f[i-1])*(n/i)*(m/i);
    }
    printf("%lld\n",ans);
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


