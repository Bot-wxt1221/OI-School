#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <chrono>
using namespace std;
 using std::chrono::duration_cast,std::chrono::system_clock;
  using std::chrono::milliseconds,std::chrono::seconds;
inline int read();

signed main(){
  //#ifdef ONLINE_JUDGE
  //#else
  //freopen(".in","r",stdin);
  freopen("fabric.in","w",stdout);
  //#endif
   auto millisec_since_epoch =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();
  srand(millisec_since_epoch);
  int n=100;
  int m=100;
  int k=rand()%20+1;
  printf("%d %d %d\n",n,m,k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      printf("%d ",((rand()%9)==2));
    }
    printf("\n");
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

