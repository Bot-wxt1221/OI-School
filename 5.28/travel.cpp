#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define int long long
inline int read();
int fir[25];
int nxt[200005];
int u[200005];
int v[200005];
int num[200005];
int w[200005];
int now=-1;
void add(int x,int y,int z,int z2){
  v[++now]=y;
  u[now]=x;
  nxt[now]=fir[x];
  num[now]=z2;
  fir[x]=now;
  w[now]=z;
  return ;
}
class node{
  public:
    int n,sta,ans;
    node(int a,int b,int c){
      n=a;
      sta=b;
      ans=c;
      return ;
    }
};
bool operator < (node a,node b){
  return a.ans>b.ans;
}
std::priority_queue<node>qu;
bool vised[15][1055];
int dp[15][1055];
int cntt=0;
bool vised2[25];
void dfs(int now,int fa){
  cntt++;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
  return ;
}
int mn=0;
void dfs2(int now,int fa){
  vised2[now]=1;
  cntt++;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(vised2[v[i]]){
      mn=i;
      continue;
    }
    dfs2(v[i],now);
  }
  return ;
}
int ttt;
int add2=0;
void dfs3(int now,int fa,int dep){
  if(now==ttt){
    add2=dep;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(i==mn||(i==(mn^1))){
      continue;
    }
    dfs3(v[i],now,dep+w[i]);
  }
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  int sum=0;
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z,(1ll<<(i-1)));
    add(y,x,z,(1ll<<(i-1)));
    sum+=z;
  }
  if(n<=10&&m<=10){
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    qu.push(node(1,0,0));
    while(qu.size()>0){
      auto tp=qu.top();
      qu.pop();
      if(vised[tp.n][tp.sta]){
        continue;
      }
      vised[tp.n][tp.sta]=1;
      for(int i=fir[tp.n];i!=-1;i=nxt[i]){
        if(dp[v[i]][tp.sta|num[i]]>dp[tp.n][tp.sta]+w[i]){
          dp[v[i]][tp.sta|num[i]]=dp[tp.n][tp.sta]+w[i];
          qu.push(node(v[i],tp.sta|num[i],dp[v[i]][tp.sta|num[i]]));
        }
      }
    }
    if(dp[1][(1<<m)-1]==0x3f3f3f3f3f3f3f3f){
      dp[1][(1<<m)-1]=-1;
    }
    printf("%lld",dp[1][(1<<m)-1]);
  }else if(m==n-1){
    dfs(1,1);
    if(cntt==n){
      printf("%lld",2*sum);
    }else{
      printf("-1");
    }
    return 0;
  }else if(m==n){
    dfs2(1,1);
    if(cntt!=n){
      printf("-1");
    }else{
      ttt=v[mn];
      dfs3(u[mn],u[mn],0);
      sum=2*sum-2*w[mn]-add2+w[mn];
      printf("%lld",sum);
    }
    return 0;
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

