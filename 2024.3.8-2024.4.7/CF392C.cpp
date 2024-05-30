#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
inline int read();
class Matrix{
  public:
    int map[105][105];
};
Matrix operator * (const Matrix &a,const Matrix &b){
  Matrix ans;
  for(int i=1;i<=84;i++){
    for(int j=1;j<=84;j++){
      ans.map[i][j]=0;
      for(int k=1;k<=84;k++){
        ans.map[i][j]+=(a.map[i][k]*b.map[k][j])%mod;
        ans.map[i][j]%=mod;
      }
    }
  }
  return ans;
}
Matrix base,cheng;
int map[105][105];
int C(int n,int m){
  if(n==m||m==0||n==0){
    return 1;
  }
  if(map[n][m]){
    return map[n][m];
  }
  return map[n][m]=(C(n-1,m)+C(n-1,m-1))%mod;
}
Matrix pow(Matrix &x,int y){
  if(y==0){
    Matrix ans;
    memset(ans.map,0,sizeof(ans.map));
    for(int i=1;i<=100;i++){
      ans.map[i][i]=1;
    }
    return ans;
  }
  if(y%2==0){
    Matrix ret=pow(x,y/2);
    return ret*ret;
  }
  return pow(x,y-1)*x;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int k=read();
  if(n==1){
    printf("%d",1);
    return 0;
  }
  memset(base.map,0,sizeof(base.map));
  base.map[1][1]=1;
  base.map[1][2]=2;
  base.map[1][3]=(1)%mod;
  for(int i=4;i<=k+3;i++){
    base.map[1][i]=1;
  }
  for(int i=k+4;i<=k*2+3;i++){
    base.map[1][i]=(((1ll<<(i-k-3))%mod)*2)%mod;
  }
  memset(cheng.map,0,sizeof(cheng.map));
  cheng.map[2][1]=1;
  cheng.map[1][2]=1;
  cheng.map[2][2]=1;
  cheng.map[3][3]=1;
  cheng.map[2*k+3][3]=1;
  for(int i=1;i<=k;i++){
    cheng.map[k+3+i][i+3]=1;
  }
  for(int i=1;i<=k;i++){
    cheng.map[1][i+k+3]=((1ll<<(i))%mod)*(C(i,0))%mod;
    cheng.map[2][i+k+3]=(C(i,0));
    for(int j=1;j<=i;j++){
      cheng.map[j+3][i+k+3]=(1ll<<(i-j))%mod*(C(i,j))%mod;
      cheng.map[j+k+3][i+k+3]=C(i,j);
    }
  }
  cheng=pow(cheng,n-1);
  base=base*cheng;
  printf("%lld",base.map[1][3]);
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

