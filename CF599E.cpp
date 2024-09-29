#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
inline int read();
int fir[15];
int a[105];
int b[105];
int c[105];
int nxt[35];
int v[35];
int m,q;
int uu[35];
int vv[35];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int to[(1<<13)+5];
int lowbit(int x){
  return x&(-x);
}
int dp[15][(1<<13)+5];
int cnt=0;
int dfs(int now,int sta){
  if(dp[now][sta]!=-1){
    return dp[now][sta];
  }
  int t=0;
  for(int i=1;i<=13;i++){
    if(i!=now&&sta&(1<<(i-1))){
      t=(1<<(i-1));
    }
  }
  if(t==0){
    return dp[now][sta]=1;
  }
  int &ans=dp[now][sta];
  ans=0;
  for(int k=sta;k;k=(k-1)&(sta)){
    if(k&(1<<(now-1))){
      continue;
    }
    if(k&((t))){
      int tt=0;
      int cnt=0;
      bool yes=0;
      for(int i=1;i<=q;i++){
        if((1<<(c[i]-1))&k){
          if(((1<<(a[i]-1))&k)==0){
            yes=1;
          }
          if(((1<<(b[i]-1))&k)==0){
            yes=1;
          }
        }
        if(c[i]==now){
          if(((1<<(a[i]-1))&k)&&((1<<(b[i]-1))&k)){
            yes=1;
          }
        }
        if(yes){
          continue;
        }
      }
      if(yes){
        continue;
      }
      for(int i=fir[now];i!=-1;i=nxt[i]){
        if((1<<(v[i]-1))&k){
          tt=v[i];
          cnt++;
        }
      }
      if(cnt>=2){
        continue;
      }
      for(int i=1;i<=m;i++){
        if((1<<(uu[i]-1))&k){
          if((1<<(vv[i]-1))&k){
            continue;
          }
          if(vv[i]==now){
            continue;
          }
          yes=1;
        }
        if((1<<(vv[i]-1))&k){
          if((1<<(uu[i]-1))&k){
            continue;
          }
          if(uu[i]==now){
            continue;
          }
          yes=1;
        }
        if(yes){
          continue;
        }
      }
      if(yes){
        continue;
      }
      for(int i=1;i<=13;i++){
        if(((1<<(i-1))&k)&&(cnt==0||tt==i)){
          ans+=dfs(now,sta^k)*dfs(i,k);
        }
      }
    }
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  m=read();
  q=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    to[(1<<(i-1))]=i;
  }
  memset(dp,-1,sizeof(dp));
  int ans=0;
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    uu[i]=x;
    vv[i]=y;
    add(x,y);
    add(y,x);
  }
  for(int i=1;i<=q;i++){
    a[i]=read();
    b[i]=read();
    c[i]=read();
  }
  printf("%lld",dfs(1,(1<<n)-1));
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
