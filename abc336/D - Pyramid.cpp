#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int a[200005];
int yuan[200005];
int b[200005];
int n;
int dp[200005];
int dp2[200005];
int tree[200005];
int lowbit(int x){
  return x&(-x);
}
int query(int now){
  int ans=0x3f3f3f3f;
  while(now>0){
    ans=std::min(ans,tree[now]);
    now-=lowbit(now);
  }
  return ans;
}
void mod(int x,int y){
  while(x<=200000){
    tree[x]=std::min(tree[x],y);
    x+=lowbit(x);
  }
  return ;
}
bool check(int now){
  for(int i=1;i<=n;i++){
    dp[i]=std::min(dp[i-1]+1,a[i]);
  }
  for(int i=n;i>=1;i--){
    dp2[i]=std::min(dp2[i+1]+1,a[i]);
  }
  for(int i=1;i<=n;i++){
    if(std::min(dp[i],dp2[i])>=now){
      return 1;
    }
  }
  return 0;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
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
      printf("%d",i);
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


