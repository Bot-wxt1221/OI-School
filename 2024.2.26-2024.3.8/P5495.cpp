#include <iostream>
#include <cstdio>
#define int unsigned
inline int read();
unsigned seed;
inline unsigned getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
int a[20000005];
bool vised[20000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  seed=read();
  for(int i=1;i<=n;i++){
    a[i]=getnext();
  }
  for(int i=2;i<=n;i++){
    if(vised[i]==0){
      for(int j=i,k=1;j<=n;j+=i,k++){
        a[j]+=a[k];
        vised[j]=1;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans^=a[i];
  }
  printf("%u",ans);
  return 0;
}
inline int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){
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


