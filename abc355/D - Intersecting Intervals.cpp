#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[1000005];
  int query(int now){
    int ans=0;
    while(now>0){
      ans+=tree[now];
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=1000002){
      tree[x]+=y;
      x+=lowbit(x);
    }
    return ;
  }
  void clear(int x,int y){
    while(x<=1000002){
      tree[x]=0;
      x+=lowbit(x);
    }
    return ;
  }
}aa;
std::pair<int,int>pa[500005];
int cnt[1000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int tt=0;
  for(int i=1;i<=n;i++){
    int a=read();
    int b=read();
    pa[i]=std::make_pair(a,b);
    cnt[++tt]=a;
    cnt[++tt]=b;
  }
  std::sort(cnt+1,cnt+tt+1);
  tt=std::unique(cnt+1,cnt+tt+1)-cnt-1;
  std::sort(pa+1,pa+n+1);
  for(int i=1;i<=n;i++){
    pa[i].first=std::lower_bound(cnt+1,cnt+tt+1,pa[i].first)-cnt;
    pa[i].second=std::lower_bound(cnt+1,cnt+tt+1,pa[i].second)-cnt;
  }
  int cntt=0;
  for(int i=1;i<=n;i++){
    cntt+=i-1-aa.query(pa[i].first-1);
    aa.mod(pa[i].second,1);
  }
  printf("%lld",cntt);
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

