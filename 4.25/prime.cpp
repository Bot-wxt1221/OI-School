#include <iostream>
#include <cstdio>
#define int long long
inline int read();
bool pri(int k){
  for(int i=2;i*i<=k;i++){
    if(k%i==0){
      return 0;
    }
  }
  return 1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  #endif
  int l=read(),k;
  k=read();
  if(k>=10){
    printf("No");
    return 0;
  }
  int cnt=0;
  for(int i=l;i<l+2*k;i++){
    if(pri(i)){
      cnt++;
    }
  }
  if(cnt>k){
    printf("Yes\n");
  }else{
    printf("No\n");
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

