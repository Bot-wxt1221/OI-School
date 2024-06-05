#include <iostream>
#include <cstdio>
#include <random>
#include <cstdlib>
#include <sys/time.h>
#define int long long
inline int read();
char temp[15];
int query(int l,int r){
  printf("%lld %lld\n",l,r);
  fflush(stdout);
  scanf("%s",temp+1);
  return temp[1]=='Y';
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),k;
  k=read();
  int l=1,r=n;
  srand(time(NULL));
  while(1){
    while(r-l>50){
      int mid=(l+r)/2;
      if(query(l,mid)){
        l=l-k-1;
        l=std::max(1ll,l);
        r=mid+k+1;
        r=std::min(r,n);
      }else{
        l=mid-k-1;
        l=std::max(1ll,l);
        r=r+k+1;
        r=std::min(r,n);
      }
    }
    int tt=rand()%(r-l+1)+l;
    r=r+k+1;
    r=std::min(r,n);
    l=l-k-1;
    l=std::max(1ll,l);
    if(query(tt,tt)){
      return 0;
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

