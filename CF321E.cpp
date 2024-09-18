#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int map[4005][4005];
int dp[4005][805];
int k;
int getsum(int x1,int y1,int x2,int y2){
  if(x1>x2||y1>y2){
    return 0;
  }
  return map[x2][y2]-map[x1-1][y2]-map[x2][y1-1]+map[x1-1][y1-1];
}
void solve(int l,int r,int ql,int qr){
  if(l>r){
    return ;
  }
  int mid=(l+r)/2;
  int top=std::min(qr,mid-1);
  int tt=0;
  for(int i=ql;i<=top;i++){
    dp[mid][k]=std::min(dp[i][k-1]+getsum(i+1,i+1,mid,mid),dp[mid][k]);
    if(dp[mid][k]==dp[i][k-1]+getsum(i+1,i+1,mid,mid)){
      tt=i;
    }
  }
  solve(l,mid-1,ql,tt);
  solve(mid+1,r,tt,qr);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int kk=read();
  memset(dp,0x3f,sizeof(dp));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      map[i][j]=read();
      map[i][j]+=map[i-1][j];
      map[i][j]+=map[i][j-1];
      map[i][j]-=map[i-1][j-1];
    }
  }
  for(int i=1;i<=n;i++){
    dp[i][1]=map[i][i];
  }
  for(int i=2;i<=kk;i++){
    k=i;
    solve(1,n,1,n);
  }
  printf("%d",dp[n][kk]/2);
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
