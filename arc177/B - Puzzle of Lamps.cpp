#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
char temp[45];
std::queue<int>qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int sta=0;
  scanf("%s",temp+1);
  int cnt=0;
  for(int i=n;i>=1;i--){
    if(temp[i]=='1'){
      for(int j=1;j<=i;j++){
        qu.push('A');
      }
      for(int j=1;j<i;j++){
        qu.push('B');
      }
    }
  }
  printf("%d\n",int(qu.size()));
  while(qu.size()>0){
    printf("%c",char(qu.front()));
    qu.pop();
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

