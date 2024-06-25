#include <iostream>
#include <cstdio>
#include <map>
#define int long long
inline int read();
std::map<int,int>mp;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    mp.clear();
    int x=read();
    int y=read();
    int k=read();
    x++;
    k--;
    while(x%y==0){
      x/=y;
    }
    int pre=0;
    int cur=0;
    int cnt=0;
    while(k){
      int ad=y-x%y;
      if(mp[x]!=0){
        k%=(cnt-mp[x]);
      }
      mp[x]=cnt;
      if(ad==y){
        ad=0;
      }
      if(ad<=k){
        k-=ad;
        cnt+=ad;
        x+=ad;
      }else{
        x+=k;
        cnt+=k;
        k=0;
        break;
      }
      x/=y;
    }
    while(x%y==0){
      x/=y;
    }
    printf("%lld\n",x);
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
