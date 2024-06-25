#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
inline int read();
int map[505][505];
char temp[505][505];
int sum[505][505];
int getsum(int x1,int y1,int x2,int y2){
  return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int m=read();
    int k=read();
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        map[i][j]=read();
      }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
      scanf("%s",temp[i]+1);
      for(int j=1;j<=m;j++){
        if(temp[i][j]=='1'){
          sum[i][j]=1;
        }else{
          sum[i][j]=-1;
        }
        cnt+=map[i][j]*sum[i][j];
        sum[i][j]+=sum[i-1][j];
        sum[i][j]+=sum[i][j-1];
        sum[i][j]-=sum[i-1][j-1];
      }
    }
    int mx=0;
    if(cnt==0){
      printf("YES\n");
      goto end;
    }
    for(int i=1;i<=n-k+1;i++){
      for(int j=1;j<=m-k+1;j++){
        int upd=getsum(i,j,i+k-1,j+k-1);
        if(mx==0){
          mx=upd;
        }else{
          mx=std::__gcd(mx,upd);
        }
      }
    }
    if(mx==0||cnt%mx){
      printf("NO\n");
    }else{
      printf("YES\n");
    }
    end:{};
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
