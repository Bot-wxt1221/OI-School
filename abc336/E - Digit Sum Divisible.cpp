#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int dp[25][205][205];
int a[25];
int now;
int n;
int dfs(int len,int x,int y,bool l){
	if(len==0){
    return x==now&&(y==0);
  }
	if(dp[len][x][y]!=-1&&l==0){
    return dp[len][x][y];
  }
  int mx=0;
  if(l){
    mx=a[len];
  }else{
    mx=9;
  }
  int res=0;
	for(int i=0;i<=mx;i++){
		if(i+x>now){
      break;
    }
		res+=dfs(len-1,x+i,(y*10+i)%now,(l&&i==mx));
	}
  if(l){
    return res;
  }else{
    return dp[len][x][y]=res;
  }
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout); 
	#endif
  int n=read();
  int ans=0;
  int len=0;
  while(n){
    a[++len]=n%10;
    n/=10;
  }
  for(int i=1;i<=9*len;i++){
    memset(dp,-1,sizeof(dp));
    now=i;
    ans+=dfs(len,0,0,1);
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


