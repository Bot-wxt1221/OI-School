#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int mp[405][405];
int left[405][405];
int up[405][405];
int x[400005];
int y[400005];
int hu[205][205];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int TT=0;
  for(int i=1;i<=200;i++){
    for(int j=1;j<=200;j++){
      hu[i][j]=hu[i][j-1]+std::__gcd(i,j);
    }
  }
  while(T--){
    int n=read();
    for(int i=1;i<=400;i++){
      for(int j=1;j<=400;j++){
        mp[i][j]=0;
      }
    }
    for(int i=1;i<=n;i++){
      int x=read();
      int y=read();
      ::x[i]=x;
      ::y[i]=y;
      mp[x][y]=1;
    }
    for(int i=400;i>=1;i--){
      for(int j=400;j>=1;j--){
        if(mp[i][j]){
          left[i][j]=std::max(left[i][j+1],j);
          up[i][j]=std::max(up[i+1][j],i);
        }else{
          left[i][j]=up[i][j]=-0x3f3f3f3f;
        }
      }
    }
    int ans=0;
    int anss=0;
    for(int i=1;i<=n;i++){
      int cnt=0;
      for(int j=i;j<=up[x[i]][y[i]];j++){
        cnt+=hu[j][left[x[i]][y[i]]-y[i]];
      }
      ans+=cnt;
      anss-=cnt*cnt;
    }
    ans*=ans;
    ans+=anss;
    for(int i=1;i<=200;i++){
      for(int j=1;j<=200;j++){
        for(int k=j+1;k<=200;k++){
          if(mp[i][j]&&mp[i][k]){
            if(left[i][j]==left[i][k]){
              ans-=(left[i][k]-k+1)*(left[i][k]-k)*(up[i][j]-i)*(up[i][k]-i)*2;
            }
          }
        }
      }
    }
    for(int i=1;i<=200;i++){
      for(int j=1;j<=200;j++){
        for(int k=j+1;k<=200;k++){
          if(mp[j][i]&&mp[k][i]){
            if(up[j][i]==up[k][i]){
              ans-=(up[k][i]-k+1)*(up[k][i]-k)*(left[k][i]-i)*(left[j][i]-i)*2;
            }
          }
        }
      }
    }
    printf("Case #%lld: %lld\n",++TT,ans);
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


