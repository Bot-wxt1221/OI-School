#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[200005];
int nxt[200005];
int v[200005];
int w[200005];
int dp[200005];
bool yes[200005];
int alt[200005];
std::priority_queue<std::pair<int,int> >qu;
int now;
int n,m,s;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int cnt=0;
bool check(int md){
  memset(dp,0x3f,sizeof(dp));
  memset(yes,0,sizeof(yes));
  dp[1]=0;
  qu.push(std::make_pair(0,1));
  while(qu.size()>0){
    auto tp=qu.top();
    qu.pop();
    if(yes[tp.second]){
      continue;
    }
    yes[tp.second]=1;
    for(int i=fir[tp.second];i!=-1;i=nxt[i]){
      if(alt[v[i]]-alt[tp.second]>md){
        continue;
      }
      int ndp=dp[tp.second]+w[i];
      if(ndp>s){
        continue;
      }
      if(ndp>=dp[v[i]]){
        continue;
      }
      dp[v[i]]=ndp;
      qu.push(std::make_pair(-dp[v[i]],v[i]));
    }
  }
  return dp[n]<=s;
} 
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("bicycle.in","r",stdin);
  freopen("bicycle.out","w",stdout);
  #endif
  n=read();
  m=read();
  s=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    alt[i]=read();
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int z=read();
    add(x,y,z);
    add(y,x,z);
  }
  long long l=-2e9,r=2e9;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      r=mid;
    }else{
      l=mid-1;
    }
  }
  for(long long i=l;i<=r;i++){
    if(check(i)){
      printf("%lld",i);
      return 0;
    }
  }
  printf("NO");
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

