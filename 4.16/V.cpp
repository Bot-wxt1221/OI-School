#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("V.in","r",stdin);
  freopen("V.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=0;
    char tem;
    while((tem=getchar())!=EOF){
      if(tem=='('||tem==')'){
        temp[++n]=tem;
      }else{
        break;
      }
    }
    int a1=0,a2=0;
    int c1=0,c2=0;
    int have1=0,have2=0;
    bool ans=0;
    for(int i=1;i<=n;i++){
      if(temp[i]=='('){
        if(a1<n/2&&have1<n/4){
          c1++;
          a1++;
          have1++;
        }else{
          a2++;
          c2--;
          if(c2<0||a2>n/2){
            ans=1;
            break;
          }
        }
      }else{
        if(a2<n/2&&have2<n/4){
          a2++;
          c2++;
          have2++;
        }else{
          a1++;
          c1--;
          if(c1<0||a1>n/2){
            ans=1;
            break;
          }
        }
      }
    }
    if(ans||c1>0||c2>0){
      printf("No\n");
    }else{
      printf("Yes\n");
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

