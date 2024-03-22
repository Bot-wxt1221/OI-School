#include <iostream>
#include <cstdio>
#include <stack>
#define int long long
inline int read();
int f[100005];
int fir[100005];
int nxt[500005];
int v[500005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int V;
int dp1[100005][105];
int dp2[100005][105];
int s[100005];
int ans=0;
std::stack<int>st;
void dfs(int now,int fa){
  for(int i=1;i<=V;i++){
    dp1[now][i]=s[now];
    dp2[now][i]=s[now]-f[fa];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    for(int j=0;j<=V;j++){
      ans=std::max(ans,dp1[now][j]+dp2[v[i]][V-j]);
    }
    for(int j=1;j<=V;j++){
      dp1[now][j]=std::max(dp1[now][j],std::max(dp1[v[i]][j],dp1[v[i]][j-1]+s[now]-f[v[i]]));
      dp2[now][j]=std::max(dp2[now][j],std::max(dp2[v[i]][j],dp2[v[i]][j-1]+s[now]-f[fa]));
    }
  }
  for(int i=1;i<=V;i++){
    dp1[now][i]=s[now];
    dp2[now][i]=s[now]-f[fa];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    st.push(i);
  }
  while(st.size()>0){
    int i=st.top();
    st.pop();
    for(int j=0;j<=V;j++){
      ans=std::max(ans,dp1[now][j]+dp2[v[i]][V-j]);
    }
    for(int j=1;j<=V;j++){
      dp1[now][j]=std::max(dp1[now][j],std::max(dp1[v[i]][j],dp1[v[i]][j-1]+s[now]-f[v[i]]));
      dp2[now][j]=std::max(dp2[now][j],std::max(dp2[v[i]][j],dp2[v[i]][j-1]+s[now]-f[fa]));
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
  int n=read();
  V=read();
  for(int i=1;i<=n;i++){
    f[i]=read();
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    s[x]+=f[y];
    s[y]+=f[x];
    add(x,y);
    add(y,x);
  }
  dfs(1,0);
  printf("%lld",ans);
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


