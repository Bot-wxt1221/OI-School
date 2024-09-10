#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define mod 998244353
#define int long long
inline int read();
int fac[10005];
bool vised[10005];
int inv[10005];
int dp[10005];
class no{
public:
  int x,y,z;
  no(int a=0,int b=0,int c=0){
    x=a;
    y=b;
    z=c;
    return ;
  }
}seq[10005];
bool operator < (no a,no b){
  if(a.x!=b.x){
    return a.x<b.x;
  }
  if(a.y!=b.y){
    return a.y<b.y;
  }
  if(a.z!=b.z){
    return a.z<b.z;
  }
  return 0;
}
bool operator == (no a,no b){
  return a.x==b.x&&a.y==b.y&&a.z==b.z;
}
inline int pow(int a,int k){
  long long res=1;
  while(k){
    if(k&1){
      #ifdef mod
      res=1ll*res*a%mod;
      #else
      res*=a;
      #endif
    }
    #ifdef mod
    a=1ll*a*a%mod;
    #else
    a*=a;
    #endif
    k>>=1;
  }
  return res;
}
int pree[1005];
int dpp[105];
int C(int a,int b){
  return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int dppp[75][75][75];
int popcount(int x){
  int ans=0;
  for(int i=0;i<64;i++){
    if(x&(1ll<<i)){
      ans++;
    }
  }
  return ans;
}
int pos(int y,int x){
  int ans=1;
  int sum=0;
  int a,b,c;
  int ret=seq[x].x-seq[y].x;
  int tt=popcount(ret);
  a=tt;
  ret=seq[x].y-seq[y].y;
  tt=popcount(ret);
  b=tt;
  ret=seq[x].z-seq[y].z;
  tt=popcount(ret);
  c=tt;
  return dppp[a][b][c];
}
bool chk(int i,int j){
  if((seq[j].x&seq[i].x)!=seq[j].x){
    return 0;
  }
  if((seq[j].y&seq[i].y)!=seq[j].y){
    return 0;
  }
  if((seq[j].z&seq[i].z)!=seq[j].z){
    return 0;
  }
  return 1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int r=read();
  int o=read();
  fac[0]=1;
  for(int i=1;i<=o;i++){
    seq[i].x=read();
    seq[i].y=read();
    seq[i].z=read();
  }
  for(int i=1;i<=10000;i++){
    fac[i]=fac[i-1]*i%mod;
  }
  inv[10000]=pow(fac[10000],mod-2);
  for(int i=10000-1;i>=0;i--){
    inv[i]=inv[i+1]*(i+1)%mod;
  }
  dppp[0][0][0]=1;
  for(int i=0;i<=64;i++){
    for(int j=0;j<=64;j++){
      for(int k=0;k<=64;k++){
        for(int mm=1;mm<=i;mm++){
          dppp[i][j][k]+=dppp[i-mm][j][k]*C(i,mm)%mod;
          dppp[i][j][k]%=mod;
        }
        for(int mm=1;mm<=j;mm++){
          dppp[i][j][k]+=dppp[i][j-mm][k]*C(j,mm)%mod;
          dppp[i][j][k]%=mod;
        }
        for(int mm=1;mm<=k;mm++){
          dppp[i][j][k]+=dppp[i][j][k-mm]*C(k,mm)%mod;
          dppp[i][j][k]%=mod;
        }
      }
    }
  }
  std::sort(seq+1,seq+o+1);
  for(int i=1;i<=o;i++){
    if(seq[i]==seq[i+1]){
      vised[i]=1;
    }
  }
  seq[o+1]=no(n,m,r);
  seq[o+2]=no(0,0,0);
  for(int i=1;i<=o+1;i++){
    if(vised[i]){
      continue;
    }
    dp[i]=-pos(o+2,i);
    int cnt=0;
    for(int k=1;k<i;k++){
       if(vised[k]){
         continue;
       }
      if(chk(i,k)){
        cnt++;
        dp[i]-=dp[k]*pos(k,i);
        dp[i]%=mod;
      }
    }
  }
  int ans=0;
  ans+=dp[o+1];
  ans%=mod;
  ans*=-1;
  ans+=mod;
  ans%=mod;
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
