#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
std::bitset<250008>a;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
   int n;
  while(((n=read())>=0)){
    a=1;
    int ans=0;
    for(int i=1;i<=n;i++){
      int v=read();
      int m=read();
      ans+=v*m;
      for(int j=0;j<=m;j++){
        a|=(a<<v);
      }
    }
    for(int i=(ans+1)/2;i<=ans;i++){
      if(a[i]==0){
        continue;
      }
      printf("%d %d\n",i,ans-i);
      break;
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

