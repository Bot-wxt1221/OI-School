#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define int long long
inline int read();
std::priority_queue<int>qu;
class node{
  public:
    int l,r,w;
    node(int x=0,int y=0,int z=0){
      l=x;
      r=y;
      w=z;
      return ;
    }
}seq[2505];
bool operator < (node a,node b){
  if(a.l!=b.l){
    return a.l<b.l;
  }
  if(a.r<b.r){
    return a.r<b.r;
  }
  return a.w<b.w;
}
int dp[10005];
int X[10005];
int lst[10005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("interval.in","r",stdin);
  freopen("interval.out","w",stdout);
  #endif
  int n=read();
  int k=read();
  int now=0;
  int sum=0;
  for(int i=1;i<=n;i++){
    seq[i].l=read();
    seq[i].r=read();
    seq[i].w=read();
    sum+=seq[i].w;
    X[++now]=seq[i].l;
    X[++now]=seq[i].r;
  }
  std::sort(X+1,X+now+1);
  now=std::unique(X+1,X+now+1)-X-1;
  std::sort(seq+1,seq+n+1);
  for(int i=1;i<=n;i++){
    seq[i].l=std::lower_bound(X+1,X+now+1,seq[i].l)-X;
    seq[i].r=std::lower_bound(X+1,X+now+1,seq[i].r)-X;
    lst[seq[i].l]=i;
  }
  for(int i=1;i<=now;i++){
    lst[i]=std::max(lst[i],lst[i-1]);
  }
  for(int i=1;i<=now;i++){
    qu=std::priority_queue<int>();
    int ans=0;
    int p=lst[i]+1;
    for(int j=i;j>=1;j--){
      while(seq[p-1].l>=j){
        p--;
        if(seq[p].r<=i){
          ans+=seq[p].w;
          qu.push(-seq[p].w);
        }
        if(qu.size()>k){
          ans+=qu.top();
          qu.pop();
        }
      }
      dp[i]=std::max(dp[i],dp[j-1]+ans);
    }
  }
  printf("%lld\n",sum-dp[now]);
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


