#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
inline int read();
long double g[5005][5005];
int fir[5005];
long double dp[5005];
int nxt[1000005];
int v[1000005];
int now;
class node{
  public:
    int i;
    long double val;
    node(int xx=0,long double yy=0){
      i=xx;
      val=yy;
      return ;
    }
};
bool operator < (node a,node b){
  return a.val<b.val;
}
std::priority_queue<node>qu;
void add(int x,int y){
  now++;
  v[now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  g[1][1]=1;
  g[2][1]=0.5;
  g[2][2]=0;
  for(int i=3;i<=5000;i++){
    g[i][1]=((long double)1)/i;
    for(int j=2;j<=i;j++){
      g[i][j]=g[i-2][j-2]*((long double)(j-2))/i+(g[i-2][j-1])*((long double)(i-j))/i;
    }
  }
  for(int i=1;i<=5000;i++){
    std::sort(g[i]+1,g[i]+i+1);
  }
  int T=read();
  while(T--){
    int n=read();
    int m=read();
    now=1;
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      dp[i]=0;
    }
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      add(x,y);
    }
    dp[n]=1;
    for(int i=n-1;i>=1;i--){
      int tott=0;
      for(int j=fir[i];j!=-1;j=nxt[j]){
        qu.push(node(v[j],dp[v[j]]));
        tott++;
      }
      int uu=tott;
      while(qu.size()>0){
        dp[i]+=dp[qu.top().i]*g[tott][uu];
        uu--;
        qu.pop();
      }
    }
    printf("%.12Lf\n",dp[1]);
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


