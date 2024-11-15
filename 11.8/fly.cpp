#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define int long long
inline int read();
class node{
public:
  int x,y;
  int w;
  node(int a=0,int b=0,int c=0){
    x=a;
    b=y;
    w=c;
    return ;
  }
};
bool operator < (node a,node b){
  return a.w>b.w;
}
int fir[505];
int nxt[2500005];
int v[2500005];
int w[2500005];
std::vector<int>ans[505];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dp[505];
int ndp[505];
bool vised[505],yes,vised2[505];
void dfs(int v,int w,int cur){
  std::queue<int>qu;
  qu.push(v);
  ndp[v]=cur;
  while(qu.size()>0){
    int tp=qu.front();
    qu.pop();
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(::w[i]>w&&ndp[::v[i]]>ndp[tp]+w){
        ndp[::v[i]]=ndp[tp]+w;
        qu.push(::v[i]);
      }
    }
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int a=read();
    int b=read();
    int c=read();
    add(a,b,c);
    add(b,a,c);
  }
  memset(dp,0x3f,sizeof(dp));
  dp[1]=0;
  for(int ttt=1;ttt<=n;ttt++){
    yes=0;
    int mn=0x3f3f3f3f3f3f3f;
    int ti=0;
    for(int i=1;i<=n;i++){
      if(mn>dp[i]&&vised2[i]==0){
        mn=dp[i];
        ti=i;
      }
    }
    if(mn==0x3f3f3f3f3f3f3f){
      break;
    }
    vised2[ti]=1;
    memset(vised,0,sizeof(vised));
    memset(ndp,0x3f,sizeof(ndp));
    for(int i=fir[ti];i!=-1;i=nxt[i]){
      dfs(v[i],w[i],w[i]+dp[ti]);
    }
    for(int i=1;i<=n;i++){
      dp[i]=std::min(dp[i],ndp[i]);
    }
  }
  printf("%lld",dp[n]);
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
