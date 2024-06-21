#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int C[605][605];
int t[605][605];
int f[605][605];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),k,m;
  k=read();
  m=read();
  C[0][0]=1;
  for(int i=1;i<=500;i++){
    C[i][0]=1;
    for(int j=1;j<=i;j++){
      C[i][j]=(C[i-1][j]+C[i-1][j-1])%m;
    }
  }
  for(int i=1;i<=500;i++){
    for(int j=1;j<=i;j++){
      for(int p=i-j+1;p<=i;p++){
        t[i][j]+=(C[p-1][i-j]);
        t[i][j]%=m;
      }
    }
  }
  f[0][0]=1;
  for(int i=1;i<=k;i++){
    f[0][i]=1;
    for(int j=1;j<=n;j++){
      for(int kk=1;kk<=j;kk++){
        int tmp=(f[kk-1][i-1])*(f[j-kk][i])%m;
        f[j][i]+=(tmp*t[j][kk])%m;
        f[j][i]%=m;
      }
      f[j][i]+=f[j][i-1];
      f[j][i]%=m;
    }
  }
  printf("%lld\n",f[n][k]);
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
