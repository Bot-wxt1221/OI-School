#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
int fir[400005];
int a[400005];
int v[800005];
int nxt[800005];
int dp[400005];
int dp2[400005];
bool vised[400005];
bool vised2[400005];
int now;

std::priority_queue<std::pair<int,int> >qu;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dij1(){
  memset(dp,0x3f,sizeof(dp));
  dp[1]=0;
  qu.push(std::make_pair(0,1));
  while(qu.size()>0){
    int tp=qu.top().second;
    qu.pop();
    if(vised[tp]){
      continue;
    }
    vised[tp]=1;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      int nw=std::max(a[v[i]],dp[tp]+1);
      if(dp[v[i]]>nw){
        dp[v[i]]=nw;
        qu.push(std::make_pair(-dp[v[i]],v[i]));
      }
    }
  }
  return ;
}
int n;
void dij2(){
  memset(dp2,0x3f,sizeof(dp2));
  dp2[n]=0;
  qu.push(std::make_pair(0,n));
  while(qu.size()>0){
    int tp=qu.top().second;
    qu.pop();
    if(vised2[tp]){
      continue;
    }
    vised2[tp]=1;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      int nw=std::max(a[v[i]],dp2[tp]+1);
      if(dp2[v[i]]>nw){
        dp2[v[i]]=nw;
        qu.push(std::make_pair(-dp2[v[i]],v[i]));
      }
    }
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dij1();
  dij2();
  int ans=0x3f3f3f3f;
  for(int i=1;i<=n;i++){
    ans=std::min(ans,std::max(dp[i],dp2[i])*2);
    for(int j=fir[i];j!=-1;j=nxt[j]){
      ans=std::min(ans,std::max(dp[i],dp2[v[j]])*2+1);
    }
  }
  printf("%d",ans);
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

