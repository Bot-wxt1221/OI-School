#include <iostream>
#include <cstdio>
#include <random>
#define mod 998244353
inline int read();
int D[3005];
int E[3005];
int F[3005];
int G[3005];
std::mt19937 a;
int A[3005][3005],B[3005][3005],C[3005][3005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        A[i][j]=read();
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        B[i][j]=read();
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        C[i][j]=read();
      }
    }
    for(int i=1;i<=n;i++){
      D[i]=a()%mod;
      E[i]=F[i]=G[i]=0;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        E[j]+=(1ll*D[i]*A[i][j])%mod;
        E[j]%=mod;
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        F[j]+=(1ll*E[i]*B[i][j])%mod;
        F[j]%=mod;
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        G[j]+=(1ll*D[i]*C[i][j])%mod;
        G[j]%=mod;
      }
    }
    for(int i=1;i<=n;i++){
      if(F[i]!=G[i]){
        printf("No\n");
        goto end;
      }
    }
    printf("Yes\n");
    end:{}
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

