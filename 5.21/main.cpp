#include <cstdlib>
#include <iostream>
#include <cstdio>
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int cnt=0;
  do{
    system("./gen > rev.in");
    system("time ./rev < rev.in > rev.out");
    system("time ./rev2 < rev.in > rev2.out");
    system("cat rev2.out");
    system("echo -e \"\\n\"");
  }while(!system("diff rev.out rev2.out"));
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

