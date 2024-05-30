#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
std::bitset<100005>bit[505];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("intersect.in","r",stdin);
  freopen("intersect.out","w",stdout);
  #endif
  for(int i=1;i<=500;i++){
    bit[i][0]=1;
    for(int j=1;j<=i;j++){
      bit[i]|=(bit[i-j]<<((j)*(i-j)));
    }
  }
  int q=read();
  for(int i=1;i<=q;i++){
    int n=read();
    int m=read();
    printf("%d\n",int(bit[n].test(m)));
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

