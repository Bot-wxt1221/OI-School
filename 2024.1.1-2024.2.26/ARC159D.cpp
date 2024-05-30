#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define int long long
inline int read();
class BIT{
  public:
    int tree[500005];
    int lowbit(int x){
      return (x)&(-x);
    }
    int query(int now){
      int ans=-0x3f3f3f3f3f3f3f3f;
      while(now>0){
        ans=std::max(tree[now],ans);
        now-=lowbit(now);
      }
      return ans;
    }
    void mod(int x,int y){
      while(x<=400001){
        tree[x]=std::max(tree[x],y);
        x+=lowbit(x);
      }
      return ;
    }
}a,b;
int l[200005];
int r[200005];
std::map<int,int>mp;
int ne[400005];
int dp[200005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int ans=0;
  int cnt=0;
  for(int i=1;i<=n;i++){
    l[i]=read();
    r[i]=read();
    ne[++cnt]=l[i];
    ne[++cnt]=r[i];
  }
  for(int i=1;i<=400003;i++){
    a.tree[i]=0;
    b.tree[i]=-0x3f3f3f3f3f3f3f3f;
  }
  std::sort(ne+1,ne+cnt+1);
  for(int i=1;i<=cnt;i++){
    if(ne[i]==ne[i-1]){
      continue;
    }else{
      mp[ne[i]]=i+2;
    }
  }
  for(int i=1;i<=n;i++){
    dp[i]=1;
    //rj<li
    dp[i]=std::max(dp[i],a.query(mp[l[i]]-1)+r[i]-l[i]+1);
    //rj>=li
    dp[i]=std::max(dp[i],b.query(400003-mp[l[i]])+r[i]);
    a.mod(mp[r[i]],dp[i]);
    b.mod(400003-mp[r[i]],dp[i]-r[i]);
    ans=std::max(ans,dp[i]);
  }
  printf("%lld",ans);
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


