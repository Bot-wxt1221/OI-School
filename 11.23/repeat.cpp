#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int seq[100005];
int dp[100005];
int lowbit(int x){
  return x&(-x);
}
class BIT{
public:
  int tree[100005];
  int query(int now){
    int ans=0x3f3f3f3f3f3f3f3f;
    while(now>0){
      ans=std::min(ans,tree[now]);
      now-=lowbit(now);
    }
    return ans;
  }
  void mod(int x,int y){
    while(x<=100000){
      tree[x]=std::min(tree[x],y);
      x+=lowbit(x);
    }
    return ;
  }
}a;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("repeat.in","r",stdin);
	freopen("repeat.out","w",stdout);
	#endif
  int n=read();
  int E=read();
  int T=read();
  for(int i=1;i<=n;i++){
    seq[i]=read();
  }
  memset(a.tree,0x3f,sizeof(a.tree));
  int l=1;
  a.mod(n+1,0);
  dp[1]=T;
  a.mod(n,dp[1]);
  int ans=0x3f3f3f3f3f3f3f3f;
  for(int i=2;i<=n;i++){
    dp[i]=0x3f3f3f3f3f3f3f3f;
    while(2*(seq[i]-seq[l])>T){
      ans=std::min(ans,dp[l-1]-seq[l]*2);
      l++;
    }
    dp[i]=a.query(n-(l-1)+1)+T;
    dp[i]=std::min(dp[i],ans+2*seq[i]);
    a.mod(n-i+1,dp[i]);
  }
  printf("%lld",dp[n]+(E));
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
