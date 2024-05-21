#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("rev.in","r",stdin);
  freopen("rev2.out","w",stdout);
  #endif
  int n=read();
  int q=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=q;i++){
    int t=read();
    switch(t){
      case 1:{
        int l=read();
        int r=read();
        for(int k=l;k<=r;k++){
          a[k]^=1;
        }
        break;
      }
      case 2:{
        int l=read();
        int r=read();
        int cnt=0;
        for(int k=l;k<=r;k++){
          cnt++;
          for(int k2=k+1;k2<=r;k2++){
            if(a[k2]!=a[k2-1]){
              cnt++;
            }else{
              break;
            }
          }
        }
        printf("%lld\n",cnt);
        break;
      }
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

