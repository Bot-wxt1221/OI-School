#include <iostream>
#include <cstdio>
#define mod 1000000007ll
#define int long long
inline int read();
int fac[100005];
int inv[100005];
inline int pow(int a,int b){
  if(a==0&&b==0){
    return 1;
  }
  long long ans=1;
  long long cur=a;
  while(b){
    if(b&1){
      ans*=cur;
      ans%=mod;
    }
    cur*=cur;
    cur%=mod;
    b>>=1;
  }
  return ans;
}
int C(int n,int m){
  if(n<m){
    return 0;
  }
  if(n<0||m<0){
    return 0;
  }
  return (((fac[n]*inv[n-m])%mod)*inv[m])%mod;
}
int cnt[1005][1005];
int x[5005];
int y[5005];
int z[5005];
int calc(int x1,int y1,int x2,int y2){
  x2=std::min(x2,1001ll);
  y2=std::min(y2,1001ll);
  x1=std::max(x1,1ll);
  y1=std::max(y1,1ll);
  if(x1>x2||y1>y2){
    return 0;
  }
  return cnt[x2][y2]-cnt[x1-1][y2]-cnt[x2][y1-1]+cnt[x1-1][y1-1];
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  fac[0]=1;
  for(int i=1;i<=10000;i++){
    fac[i]=(fac[i-1]*i)%mod;
  }
  inv[10000]=pow(fac[10000],mod-2);
  for(int i=9999;i>=0;i--){
    inv[i]=(inv[i+1]*(i+1))%mod;
  }
  int n=read();
  int m=read();
  int r=read();
  for(int i=1;i<=n;i++){
    int x=read();
    int y=read();
    ::x[i]=x;
    ::y[i]=y;
    z[i]=read();
    cnt[x][y]++;
  }
  for(int i=1;i<=1001;i++){
    for(int j=1;j<=1001;j++){
      cnt[i][j]+=cnt[i-1][j];
      cnt[i][j]+=cnt[i][j-1];
      cnt[i][j]-=cnt[i-1][j-1];
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    int a=calc(x[i]-r,y[i]-r,x[i]+r,y[i]+r);
    for(int j=i+1;j<=n;j++){
      int b=calc(x[j]-r,y[j]-r,x[j]+r,y[j]+r);
      int c=a+b-calc(std::max(x[i],x[j])-r,std::max(y[i],y[j])-r,std::min(x[i],x[j])+r,std::min(y[i],y[j])+r);
      ans+=(((2*z[i]*z[j])%mod)*(((C(n,m)-C(n-a,m)-C(n-b,m)+C(n-c,m))%mod)+mod))%mod;
      ans%=mod;
    }
    ans+=((z[i]*z[i])%mod)*(C(n,m)-C(n-a,m)+mod)%mod;
    ans%=mod;
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


