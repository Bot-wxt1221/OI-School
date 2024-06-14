#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
inline int read();
std::pair<int,int> pa[100005];
int a[100005];
int n;
bool used[100005];
bool check(int md){
  int cur=0;
  int mn=0x3f3f3f3f;
  int premn=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    premn=mn;
    mn=std::min(mn,cur);
    if(cur-premn>=0){
      return 1;
    }
    cur+=(a[i]<pa[md].first)?-1:1;
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
      pa[i].first=read();
      a[i]=pa[i].first;
      pa[i].second=i;
      used[i]=0;
    }
    std::sort(pa+1,pa+n+1);
    int l=1,r=n;
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
        printf("%d\n",pa[i].first);
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
