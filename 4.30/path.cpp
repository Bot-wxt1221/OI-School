#include <cmath>
#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
std::queue<int>qu;
bool inque[50005];
int dp[50005];
std::vector<int>vec;
std::queue<int>have;
std::vector<int>ans;
bool in[50005];
int fir[50005];
int nxt[600005];
int v[600005];
int w[600005];
int now;
void add(int x,int y,int z){
  if(in[x]==0){
    in[x]=1;
    have.push(x);
  }
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("path.in","r",stdin);
  freopen("path.out","w",stdout);
  #endif
  int n=read(),q,T;
  q=read();
  T=read();
  for(int i=1;i<=n;i++){
    dp[i]=0x3f3f3f3f;
    fir[i]=-1;
  }
  dp[1]=0;
  for(int i=1;i<=q;i++){
    int x=read();
    int y=read();
    int z=read();
    if(dp[x]+z>dp[y]){
    }else{
      dp[y]=std::min(dp[y],dp[x]+z);
      qu.push(y);
    }
    std::swap(x,y);
    if(dp[x]+z>dp[y]){
    }else{
      dp[y]=std::min(dp[y],dp[x]+z);
      qu.push(y);
    }
    add(x,y,z);
    add(y,x,z);
    while(qu.size()>0){
      int tp=qu.front();
      inque[tp]=0;
      qu.pop();
      for(int ii=fir[tp];ii!=-1;ii=nxt[ii]){
        if(dp[tp]+w[ii]<dp[v[ii]]&&dp[tp]+w[ii]<=T){
          dp[v[ii]]=dp[tp]+w[ii];
          if(inque[v[ii]]==0){
            inque[v[ii]]=1;
            qu.push(v[ii]);
          }
        }
      }
    }
    if(dp[n]<=T){
      ans.push_back(i);
      now=0;
      while(have.size()>0){
        int tp=have.front();
        have.pop();
        fir[tp]=-1;
        dp[tp]=0x3f3f3f3f;
        in[tp]=0;
      }
      dp[1]=0;
    }
  }
  printf("%d\n",int(ans.size()));
  for(int i=0;i<ans.size();i++){
    printf("%d ",ans[i]);
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

