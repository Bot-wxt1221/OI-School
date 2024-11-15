#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int w[1000005];
int now;
int kk;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int dp[500005][2];
void dfs(int now,int fa){
  int curans=0;
  std::vector<int>vec;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    curans+=dp[v[i]][0];
    vec.push_back(dp[v[i]][1]-dp[v[i]][0]+w[i]);
  }
  std::sort(vec.begin(),vec.end());
  std::reverse(vec.begin(),vec.end());
  for(int i=1;i<std::min(kk,((int)vec.size()+1));i++){
    if(vec[i-1]>0)
    curans+=vec[i-1];
  }
  dp[now][1]=curans;
  if(kk-1<vec.size()){
    if(vec[kk-1]>0)
    curans+=vec[kk-1];
  }
  dp[now][0]=curans;
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    kk=read();
    now=0;
    for(int i=1;i<=n;i++){
      fir[i]=-1;
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      int z=read();
      add(x,y,z);
      add(y,x,z);
    }
    dfs(1,1);
    printf("%lld\n",dp[1][0]);
  }
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
