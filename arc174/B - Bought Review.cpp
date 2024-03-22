#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[15],b[15];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=5;
    int sum=0;
    int tt=0;
    for(int i=1;i<=n;i++){
      int ttt=read();
      sum+=ttt*(i-3);
      tt+=ttt;
    }
    for(int i=1;i<=n;i++){
      b[i]=read();
    }
    if(sum>=0){
      printf("0\n");
      continue;
    }
    sum=-sum;
    if(b[4]>b[5]){
      printf("%lld\n",((sum/2)+(sum%2))*b[5]);
    }else if(b[4]*2>b[5]){
      printf("%lld\n",(sum/2)*b[5]+(sum%2)*b[4]);
    }else{
      printf("%lld\n",sum*b[4]);
    }
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


