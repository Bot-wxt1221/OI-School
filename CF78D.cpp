#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
inline int read();

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  long long K=read();
  unsigned long long ans=1;
  for(int i=0;i<=K;i++){
    if(i%2==0){
      int d=((i/2)*3+2)*2+1;
      int l=0,r=(i)+2;
      while(r-l>3){
        int mid=(l+r)/2;
        if(d*d+mid*mid*3<=K*K*4){
          l=mid-1;
        }else{
          r=mid+1;
        }
      }
      for(int ii=r;ii>=l;ii--){
        int mid=ii;
        if(d*d+mid*mid*3<=K*K*4){
          ans+=((ii+1)/2)*12;
          if(ii>=i+1){
            ans-=6;
          }
          break;
        }
      }
    }else{
      int d=((i/2)*3+3)*2+2;
      if(d*d>K*K*4){
        continue;
      }
      int l=0,r=std::max((i/2+1)*2+1,0ll);
      while(r-l>3){
        int mid=(l+r)/2;
        if(d*d+mid*mid*3<=K*K*4){
          l=mid-1;
        }else{
          r=mid+1;
        }
      }
      for(int ii=r;ii>=l;ii--){
        int mid=ii;
        if(d*d+mid*mid*3<=K*K*4){
          ans+=((ii)/2+1)*12-6;
          if(ii>=(((i)/2)+1)*2){
            ans-=6;
          }
          break;
        }
      }
    }
  }
  printf("%llu",ans);
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


