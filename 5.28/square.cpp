#include <cmath>
#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
inline void write(int ans);

signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("square.in","r",stdin);
  freopen("square.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int tn=0;
    int cur=1;
    while(cur<=n){
      int nw=std::sqrt((long long)(cur+n));
      int nw2=(nw*nw-1)/2;
      int l=nw,r=1e10;
//      while(nw2+1<=cur){
//        nw++;
//        nw2=(nw*nw-1)/2;
//      }
      while(r-l>3){
        int mid=(l+r)/2;
        if((mid*mid-1)/2+1>cur){
          r=mid+1;
        }else{
          l=mid-1;
        }
      }
      l=std::max(l,nw);
      for(int i=l;i<=r;i++){
        if((i*i-1)/2+1>cur){
          nw=i;
          nw2=(nw*nw-1)/2;
          break;
        }
      }
      // cur nw*nw-n-1
      l=cur;
      r=nw*nw-n-1;
      cur=nw2+1;
      if(l<=r){
        r=std::min(r,n);
        tn+=(r-l+1)*(l+r)/2;
      }
    }
    write(tn);
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
inline void write(int ans){
	if(ans==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	static char out[65];
	int n=0;
	while(ans){
		out[++n]=ans%10+'0';
		ans/=10;
	}
	for(register int i=n;i>=1;i--){
		putchar(out[i]);
	}
	putchar('\n');
	return ;
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

