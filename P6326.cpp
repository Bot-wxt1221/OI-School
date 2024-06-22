#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int w[505];
int c[505];
int d[505];
int fir[505];
int nxt[1005];
int v[1005];
int now,m;
int siz[505];
int mx[505];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
bool vised[505];
int tot;
int mn=0,xx2;
void calcsiz(int now,int fa){
  siz[now]=1;
  int xx=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcsiz(v[i],now);
    siz[now]+=siz[v[i]];
    xx=std::max(xx,siz[v[i]]);
  }
  xx=std::max(xx,tot-siz[now]);
  if(mn==0||xx<xx2){
    mn=now;
    xx2=xx;
  }
  return ;
}

int ans=0;
int dfn[505];
int tdfn[505];
int dp[505][5005];
int siz2[505];
int cur;
void gdfn(int now,int fa){
  dfn[now]=++cur;
  tdfn[cur]=now;
  siz2[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }  
    gdfn(v[i],now);
    siz2[now]+=siz2[v[i]];
  }
  return ;
}
void calc(int now,int fa){
  cur=0;
  gdfn(now,fa);
  for(int i=1;i<=cur+3;i++){
    for(int j=0;j<=5000;j++){
      dp[i][j]=0;
    }
  }
  for(int i=cur;i>=1;i--){
    int mr=d[tdfn[i]];
    mr--;
    int cc=c[tdfn[i]];
    int cw=w[tdfn[i]];
    for(int j=cc;j<=m;j++){
      dp[i][j]=std::max(dp[i][j],dp[i+1][j-cc]+cw);
    }
    for(int j=0;j<=20;j++){
      if(mr>=(1<<j)){
        mr-=(1<<j);
        for(int k=m;k>=(1<<j)*cc;k--){
          dp[i][k]=std::max(dp[i][k],dp[i][k-cc*(1<<j)]+(1<<j)*cw);
        }
      }
    }
    if(mr){
      for(int k=m;k>=mr*cc;k--){
        dp[i][k]=std::max(dp[i][k],dp[i][k-cc*mr]+mr*cw);
      }
    }
    for(int j=0;j<=m;j++){
      dp[i][j]=std::max(dp[i][j],dp[i+siz2[tdfn[i]]][j]);
    }

  }
  ans=std::max(ans,dp[1][m]);
  return ;
}
void dfs(int now,int fa){
  calc(now,fa);
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    mn=0;
    tot=siz[v[i]];
    calcsiz(v[i],now);
    calcsiz(mn,mn);
    dfs(mn,mn);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    m=read();
    now=0;
    for(int i=1;i<=n;i++){
      w[i]=read();
      vised[i]=0;
      fir[i]=-1;
    }
    for(int i=1;i<=n;i++){
      c[i]=read();
    }
    for(int i=1;i<=n;i++){
      d[i]=read();
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    ans=0;
    mn=0;
    tot=n;
    calcsiz(1,1);
    calcsiz(mn,mn);
    dfs(mn,mn);
    printf("%lld\n",ans);
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
