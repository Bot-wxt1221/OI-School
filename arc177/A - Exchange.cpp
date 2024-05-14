#include <iostream>
#include <cstdio>
inline int read();
int aa[]={0,1,5,10,50,100,500};
int bb[15],aa2[15];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  for(int i=1;i<=6;i++){
    aa2[i]=read();
  }
  int n=read();
  for(int i=1;i<=n;i++){
    bb[i]=read();
  }
  for(int i=1;i<=n;i++){
    for(int j=6;j>=1;j--){
      while(aa2[j]&&bb[i]>=aa[j]){
        bb[i]-=aa[j];
        aa2[j]--;
      }
    }
    if(bb[i]>0){
      printf("No");
      return 0;
    }
  }
  printf("Yes");
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

