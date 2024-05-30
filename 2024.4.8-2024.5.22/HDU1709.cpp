#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>
inline int read();
std::bitset<100005>a,b;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n;
  while(scanf("%d",&n)!=EOF){
    a=0;
    a[50000]=1;
    int s=0;
    for(int i=1;i<=n;i++){
      int tt;
      scanf("%d",&tt);
      s+=tt;
    //  b.vec[tt]=1;
      a|=((a<<tt)|(a>>tt));
    }
    int cnt=0;
    for(int i=1;i<=s;i++){
      if(a[i+50000]==0){
        cnt++;
      }
    }
    printf("%d\n",cnt);
    if(cnt>0){
      for(int i=1;i<=s;i++){
        if(a[i+50000]==0){
          printf("%d ",i);
        }
      }
      printf("\n");
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

