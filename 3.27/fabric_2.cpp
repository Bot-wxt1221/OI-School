#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
int map[505][505];
std::bitset<505>bit,map2[505];
long long ans[505][505];
int debug[505][505];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("fabric.in","r",stdin);
  freopen("fabric2.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int k=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      map2[i][j]=map[i][j]=(!(read()));
    }
  }
  long long tans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      bit[j]=1;
    }
    for(int i2=i;i2<=n;i2++){
      bit&=map2[i2];
      for(int kk=1;kk<=m;kk++){
        for(int kk2=kk;kk2<=m;kk2++){
          if(!bit[kk2]){
            break;
          }
          if((kk2-kk+1)*(i2-i+1)>=k){
//            std::cerr<<i<<' '<<kk<<' '<<i2<<" "<<kk2<<std::endl;
            debug[i2][kk]++;
            tans++;
          }
        }
      }
    }
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

