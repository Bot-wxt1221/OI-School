#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define int long long
inline int read();
int a[2000006];
int zhi[2000006];
int zhi2[2000006];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("series.in","r",stdin);
	freopen("series.out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read(),k,f;
    k=read();
    f=read();
    int maxa=0;
    memset(zhi2,0,sizeof(zhi2));
    for(int i=1;i<=n;i++){
      a[i]=read();
      if(a[i]<0){
        maxa=-0x3f3f3f3f3f3f3f3f;
      }else{
        zhi2[a[i]]++;
      }
      maxa=std::max(a[i],maxa);
    }
    if(maxa==-0x3f3f3f3f3f3f3f3f){
      printf("\n");
      continue;
    }
    memset(zhi,0,sizeof(zhi));
    for(int i=1;i<=n;i++){
      zhi[a[i]+1]--;
      zhi[std::max(a[i]-k,1ll)]++;
    }
    for(int i=1;i<=maxa;i++){
      zhi2[i]+=zhi2[i-1];
      zhi[i]+=zhi[i-1];
    }
    for(int i=1;i<=maxa;i++){
      for(int j=2*i;j<=maxa;j+=i){
        zhi[i]+=zhi[j];
      }
    }
    for(int i=1;i<=std::min(k,maxa);i++){
      if(zhi2[i-1]<=f){
        printf("%lld ",i);
      }
    }
    for(int i=k+1;i<=maxa;i++){
      if(zhi[i]>=n-f){
        printf("%lld ",i);
      }
    }
    printf("\n");
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


