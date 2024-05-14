#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int too[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char temp[505][505];
int to(int x,int y){
  return (x-1)*500+y;
}
int fir[1000005];
int nxt[2000005];
int v[2000005];
int w[2000005];
int now;
void add(int y,int x,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dp[1000005];
bool in[1000005];
std::priority_queue<std::pair<int,int> >qu;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  for(int i=1;i<=1000000;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      dp[to(i,j)]=0x3f3f3f3f;
      if(i-1>0){
        add(to(i-1,j),to(i,j),temp[i][j]=='B');
      }
      if(i+1<=n){
        add(to(i+1,j),to(i,j),temp[i][j]=='B');
      }
      if(j-1>0){
        add(to(i,j-1),to(i,j),temp[i][j]=='B');
      }
      if(j+1<=n){
        add(to(i,j+1),to(i,j),temp[i][j]=='B');
      }
    }
  }
  dp[to(1,1)]=0;
  qu.push(std::make_pair(0,to(1,1)));
  while(qu.size()>0){
    auto tt=qu.top().second;
    qu.pop();
    if(in[tt]){
      continue;
    }
    in[tt]=1;
    for(int i=fir[tt];i!=-1;i=nxt[i]){
      int too=dp[tt]+w[i];
      if(too<dp[v[i]]){
        dp[v[i]]=too;
        qu.push(std::make_pair(-dp[v[i]],v[i]));
      }
    }
  }
  int tans=dp[to(n,n)];
  now=0;
  for(int i=1;i<=1000000;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      dp[to(i,j)]=0x3f3f3f3f;
      in[to(i,j)]=0;
      if(i-1>0){
        add(to(i-1,j),to(i,j),temp[i][j]!='B');
      }
      if(i+1<=n){
        add(to(i+1,j),to(i,j),temp[i][j]!='B');
      }
      if(j-1>0){
        add(to(i,j-1),to(i,j),temp[i][j]!='B');
      }
      if(j+1<=n){
        add(to(i,j+1),to(i,j),temp[i][j]!='B');
      }
    }
  }
  dp[to(1,n)]=0;
  qu.push(std::make_pair(0,to(1,n)));
  while(qu.size()>0){
    auto tt=qu.top().second;
    qu.pop();
    if(in[tt]){
      continue;
    }
    in[tt]=1;
    for(int i=fir[tt];i!=-1;i=nxt[i]){
      int too=dp[tt]+w[i];
      if(too<dp[v[i]]){
        dp[v[i]]=too;
        qu.push(std::make_pair(-dp[v[i]],v[i]));
      }
    }
  }
  tans+=dp[to(n,1)];
  printf("%d",tans);
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

