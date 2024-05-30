#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
char temp[60466185];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  #endif
  int n=0;
  while((temp[++n]=getchar())=='('||temp[n]==')');
  n--;
  int sum=0;
  int ans=0;
  for(int i=1;i<=n;i++){
    if(temp[i]=='('){
      sum++;
    }else{
      sum--;
      if(sum<0){
        ans+=-sum;
      }
    }
  }
  printf("%d",ans);
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

