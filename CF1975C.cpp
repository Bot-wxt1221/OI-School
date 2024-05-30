#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
inline int read();
int a[100005];
int n;
bool check(int md){
  int cur=0;
  int mn=0x3f3f3f3f;
  int premn=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    premn=mn;
    mn=std::min(mn,cur);
    cur+=(a[i]<md)?-1:1;
    if(cur-premn>=1){
      return 1;
    }
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    int l=1,r=1e9;
    while(r-l>3){
      int mid=(l+r)/2;
      if(check(mid)){
        l=mid-1;
      }else{
        r=mid+1;
      }
    }
    for(int i=r;i>=l;i--){
      if(check(i)){
        printf("%d\n",i);
        break;
      }
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
