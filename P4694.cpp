#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int a[500005];
int b[500005];
std::priority_queue<std::pair<int,int> >qu;
int ans;
int n;
int check(int t){
  qu=std::priority_queue<std::pair<int,int> >();
  ans=0;
  int cnt=0;
  for(int i=1;i<=n;i++){
    qu.push(std::make_pair(-a[i],1));
    if(b[i]+-qu.top().first-t>0){
      continue;
    }
    ans+=b[i]+-qu.top().first-t;
    if(qu.top().second==1){
      cnt++;
    }
    qu.pop();
    qu.push(std::make_pair(b[i]-t,0));
  }
  return cnt;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  for(int i=1;i<=n;i++){
    b[i]=read();
  }
  int l=0,r=2e9;
  while(r-l>3){
    int mid=(0ll+l+r)/2;
    if(check(mid)<=k){
      l=mid-1;
    }else{
      r=mid+1;
    }
  }
  for(int i=l;;i++){
    if(check(i)>=k){
      printf("%lld",ans+i*k);
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

