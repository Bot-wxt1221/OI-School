#include <iostream>
#include <cstdio>
inline int read();
int a[100005];
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
      a[i]=read();
    }
    int pre=0;
    int k=1;
    for(int i=0;i<25;i++){
      pre=0;
      for(int j=1;j<=n;j++){
        if(a[j]&(1<<i)){
  //        pre+1 i
          k=std::max(k,j-pre);
          pre=j;
        }
      }
      if(pre!=0){
        k=std::max(k,n-(pre)+1);
      }
    }
    printf("%d\n",k);
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
