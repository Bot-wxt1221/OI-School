#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int pre=10;
void dfs(int now,bool nw=0){
  if(now<=9){
    putchar(now+'0');
    pre=now;
    return ;
  }
  int tt=(now)%9;
  if(tt==0){
    now-=9;
    tt=9;
  }
  dfs(now/9);
  tt+=9;
  tt%=10;
  if(tt>=pre){
    tt++;
  }
  tt%=10;
  pre=tt;
  putchar(tt+'0');
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    dfs(n,1);
    putchar('\n');
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


