#include <cmath>
#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[105];
int n;
int s;
bool check(int x){
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=a[i]%x;
  }
  return ans==s;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("genius.in","r",stdin);
  freopen("genius.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    s=read();
    int sum=0;
    for(int i=1;i<=n;i++){
      a[i]=read();
      sum+=a[i];
    }
    int lef=std::abs(sum-s);
    if(lef==0){
      printf("YES\n");
      goto end;
    }else{
      int st=std::sqrt(lef);
      for(int i=1;i<=st;i++){
        if(lef%i){
          continue;
        }
        if(check(i)){
          printf("YES\n");
          goto end;
        }
        if(check(lef/i)){
          printf("YES\n");
          goto end;
        }
      }
    }
    printf("NO\n");
    end:{}
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
