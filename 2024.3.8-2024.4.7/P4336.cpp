#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int u[25][1005][2];
int ma[25][25];
int m[25];
void swap(int x,int y){
  for(int i=1;i<=24;i++){
    std::swap(ma[x][i],ma[y][i]);
  }
  return ;
}
int matrix(int ma[25][25],int n){
  int ans=1,v=1;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      while(ma[i][i]){
        int x=ma[j][i]/ma[i][i];
        for(int k=i;k<=n;k++){
          ma[j][k]+=mod-((x*ma[i][k])%mod);
          ma[j][k]%=mod;
        }
        swap(i,j);
        v=-v;
      }
      swap(i,j);
      v=-v;
    }
  }
  for(int i=1;i<=n;i++){
    ans*=ma[i][i];
    ans%=mod;
  }
  return (ans*v+mod)%mod;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<n;i++){
    int m=read();
    ::m[i]=m;
    for(int j=1;j<=m;j++){
      u[i][j][0]=read();
      u[i][j][1]=read();
    }
  }
  int ans=0;
  for(int sta=0;sta<(1<<(n-1));sta++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        ma[i][j]=0;
      }
    }
    int lef=n-1;
    for(int j=0;j<n-1;j++){
      if(sta&(1<<j)){
        lef--;
      }else{
        continue;
      }
      j++;
      for(int i=1;i<=m[j];i++){
        (ma[u[j][i][0]][u[j][i][1]]+=mod-1)%=mod;
        (ma[u[j][i][1]][u[j][i][0]]+=mod-1)%=mod;
        (ma[u[j][i][0]][u[j][i][0]]+=1)%=mod;
        (ma[u[j][i][1]][u[j][i][1]]+=1)%=mod;
      }
      j--;
    }
    if(lef&1){
      ans-=matrix(ma,n-1);
      ans+=mod;
      ans%=mod;
    }else{
      ans+=matrix(ma,n-1);
      ans%=mod;
    }
  }
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


