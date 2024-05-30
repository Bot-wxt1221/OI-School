#include <iostream>
#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
#define int long long
inline int read();
int fir[500005];
int nxt[1000005];
int v[1000005];
int w[1000005];
int a[500005];
int b[500005];
int now;
int ans;
__gnu_pbds::priority_queue< long long,std::greater<long long> >A[500005],B[500005];
void add(int x,int y,int z){
  w[++now]=z;
  v[now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa,int dep=0){
  for(int i=a[now]+1;i<=b[now];i++){
    A[now].push(dep-100000000000000);
  }
  for(int i=b[now]+1;i<=a[now];i++){
    B[now].push(dep);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now,dep+w[i]);
    A[now].join(A[v[i]]);
    B[now].join(B[v[i]]);
  }
  while(A[now].size()>0&&B[now].size()>0&&A[now].top()+B[now].top()-2*dep<0){
    auto x=A[now].top();
    auto y=B[now].top();
    A[now].pop();
    B[now].pop();
    ans+=x+y-2*dep;
    A[now].push(2*dep-y);
    B[now].push(2*dep-x);
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
  int tot=0;
  for(int i=1;i<=n;i++){
    a[i]=read();
    b[i]=read();
    if(a[i]<b[i]){
      tot+=b[i]-a[i];
    }
  }
  dfs(1,1);
  printf("%lld",ans+tot*100000000000000ll);
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

