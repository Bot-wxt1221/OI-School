#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int w[100005];
int v[200005];
int nxt[200005];
int fir[100005];
int now;
int dp[100005][2];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int pow(int x,int y){
  int cur=x;
  int ans=1;
  while(y){
    if(y&1){
      ans=ans*cur;
      ans%=mod;
    }
    y>>=1;
    cur=cur*cur%mod;
  }
  return ans;
}
void dfs(int now,int fa){
  dp[now][0]=(mod+1-w[now])%mod;
  dp[now][1]=0;
  int sum=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    dp[now][0]*=(dp[v[i]][0]);
    dp[now][0]%=mod;
    sum+=(dp[v[i]][1]);
    sum%=mod;
  }
  int cheng=dp[now][0]*pow(mod+1-w[now],mod-2)%mod;
  dp[now][1]=sum+(w[now])%mod;
  dp[now][1]%=mod;
  int no=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    no+=(cheng*pow(dp[v[i]][0],mod-2)%mod)*(mod+1-dp[v[i]][0])%mod;
    no%=mod;
  }
  dp[now][1]+=(1-no-cheng)*((mod+1-w[now])%mod)%mod;
  dp[now][1]%=mod;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("treesiz.in","r",stdin);
  freopen("treesiz.out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    int a=read();
    int b=read();
    w[i]=a*pow(b,mod-2)%mod;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dp[1][1]+=mod;
  dp[1][1]%=mod;
  printf("%lld",dp[1][1]);
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
